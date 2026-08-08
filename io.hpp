/*
 * Clix's Fast IO
 */

#pragma once

#include "svec.hpp"

#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>

#include <array>
#include <charconv>
#include <concepts>
#include <cstddef>
#include <stdexcept>
#include <string>
#include <string_view>
#include <vector>

namespace clix {

struct io {
private:
  const char *data{nullptr};
  std::size_t size{0}, pos = {0};
  bool owns_mmap{false};
  std::vector<char> fallback_buf;

  void init() {
    struct stat st;

    if (fstat(STDIN_FILENO, &st) == 0 && S_ISREG(st.st_mode) &&
        st.st_size > 0) {
      void *addr = mmap(nullptr, st.st_size, PROT_READ,
                        MAP_PRIVATE | MAP_POPULATE, STDIN_FILENO, 0);

      if (addr != MAP_FAILED) {
        data = static_cast<const char *>(addr);
        size = st.st_size;
        owns_mmap = true;
        madvise(addr, size, MADV_SEQUENTIAL);
        return;
      }
    }

    char buf[1 << 16];
    std::size_t n;

    while ((n = ::read(STDIN_FILENO, buf, sizeof buf)) > 0)
      fallback_buf.insert(fallback_buf.end(), buf, buf + n);

    data = fallback_buf.data();
    size = fallback_buf.size();
  }

  static constexpr bool is_space(char c) {
    return c == ' ' || c == '\n' || c == '\r' || c == '\t';
  }

  void skip_ws() {
    while (pos < size && is_space(data[pos]))
      ++pos;
  }

  std::string_view read_token() {
    auto start = pos;
    while (pos < size && !is_space(data[pos]))
      ++pos;

    return {data + start, pos - start};
  }

public:
  io() { init(); }

  ~io() {
    if (owns_mmap && data)
      munmap(const_cast<char *>(data), size);
  }

  io(const io &) = delete;
  io &operator=(const io &) = delete;

  // io.read(&var);
  template <typename T> bool read(T *out) {
    skip_ws();

    if (pos >= size)
      return false;

    if constexpr (std::is_same_v<T, std::string_view>) {
      *out = read_token();
    }

    else if constexpr (std::is_same_v<T, std::string>) {
      *out = std::string(read_token());
    }

    else if constexpr (std::is_same_v<T, char>) {
      *out = data[pos++];
    }

    else if constexpr (std::integral<T> || std::floating_point<T>) {
      std::string_view tok = read_token();
      auto res = std::from_chars(tok.data(), tok.data() + tok.size(), *out);

      if (res.ec != std::errc{})
        throw std::runtime_error("clix::io: parse failure");
    }

    else {
      static_assert(!sizeof(T), "clix::io::read: unsupported type");
    }

    return true;
  }

  // type var = io.read();
  template <typename T> T read() {
    T v{};
    read(&v);
    return v;
  }

  // io.read(vec, 3);
  template <typename T> void read(std::vector<T> &v, std::size_t n) {
    v.resize(n);
    for (auto &x : v)
      read(&x);
  }

  // io.read(arr, 5);
  template <typename T, std::size_t ArrSize>
  void read(std::array<T, ArrSize> &arr, std::size_t n) {
    if (n > ArrSize) [[unlikely]]
      throw std::runtime_error("clix::io::read: n (" + std::to_string(n) +
                               ") exceeds array capacity (" +
                               std::to_string(ArrSize) + ")");

    for (std::size_t i = 0; i < n; ++i)
      read(&arr[i]);
  }

  template <typename T, std::size_t ArrSize>
  void read(clix::svec<T, ArrSize> &arr, std::size_t n) {
    if (n > ArrSize) [[unlikely]]
      throw std::runtime_error("clix::io::read: n (" + std::to_string(n) +
                               ") exceeds clix::svec capacity (" +
                               std::to_string(ArrSize) + ")");

    for (std::size_t i = 0; i < n; ++i)
      read(&arr[i]);
  }

  // auto arr = io.read<u64, 2>(); ... arr[0];
  // auto [x, y, z] = io.read<u32, 5>();
  template <typename T, std::size_t N> std::array<T, N> read() {
    std::array<T, N> arr;
    for (auto &x : arr)
      read(&x);
    return arr;
  }

  // auto [a, b, c] = io.read<u32, u64, f64>();
  template <typename... Ts>
    requires(sizeof...(Ts) > 1)
  std::tuple<Ts...> read() {
    std::tuple<Ts...> t;
    std::apply([this](auto &...xs) { (this->read(&xs), ...); }, t);
    return t;
  }
};

} // namespace clix

inline clix::io io;
