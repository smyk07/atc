/*
 * Clix's Static Vector
 */

#pragma once

#include <array>
#include <cstddef>
#include <stdexcept>

namespace clix {

template <typename T, std::size_t N> struct svec {
private:
  std::array<T, N> data_{};
  std::size_t size_{0};

public:
  constexpr svec() = default;

  template <typename... Args>
  explicit constexpr svec(Args &&...args)
    requires(sizeof...(Args) <= N)
      : data_{std::forward<Args>(args)...}, size_(sizeof...(Args)) {}

  constexpr void push_back(const T &value) {
    if (size_ >= N) [[unlikely]]
      throw std::out_of_range("clix::svec: capacity exceeded");

    data_[size_++] = value;
  }

  constexpr void pop_back() {
    if (size_ == 0) [[unlikely]]
      throw std::out_of_range("clix::svec: attempting to pop empty array");

    --size_;
  }

  constexpr void pop_back(std::size_t k) {
    if (k > size_) [[unlikely]]
      throw std::out_of_range("clix::svec: pop count exceeds size");

    size_ -= k;
  }

  constexpr std::size_t size() const noexcept { return size_; }
  constexpr std::size_t capacity() const noexcept { return N; }

  constexpr T &operator[](std::size_t i) {
    if (i >= N) [[unlikely]]
      throw std::out_of_range("clix::svec: index exceeds capacity");
    if (i >= size_) [[likely]]
      size_ = i + 1;
    return data_[i];
  }

  constexpr const T &operator[](std::size_t i) const {
    if (i >= N) [[unlikely]]
      throw std::out_of_range("clix::svec: index exceeds capacity");
    return data_[i];
  }

  using iterator = typename std::array<T, N>::iterator;
  using const_iterator = typename std::array<T, N>::const_iterator;

  constexpr iterator begin() noexcept { return data_.begin(); }
  constexpr iterator end() noexcept { return data_.begin() + size_; }

  constexpr const_iterator begin() const noexcept { return data_.begin(); }
  constexpr const_iterator end() const noexcept {
    return data_.begin() + size_;
  }

  constexpr const_iterator cbegin() const noexcept { return data_.begin(); }
  constexpr const_iterator cend() const noexcept {
    return data_.begin() + size_;
  }

  using reverse_iterator = std::reverse_iterator<iterator>;
  using const_reverse_iterator = std::reverse_iterator<const_iterator>;

  constexpr reverse_iterator rbegin() noexcept {
    return reverse_iterator(end());
  }
  constexpr reverse_iterator rend() noexcept {
    return reverse_iterator(begin());
  }

  constexpr const_reverse_iterator rbegin() const noexcept {
    return const_reverse_iterator(end());
  }
  constexpr const_reverse_iterator rend() const noexcept {
    return const_reverse_iterator(begin());
  }

  constexpr const_reverse_iterator crbegin() const noexcept {
    return const_reverse_iterator(cend());
  }
  constexpr const_reverse_iterator crend() const noexcept {
    return const_reverse_iterator(cbegin());
  }

  constexpr void reverse() noexcept(std::is_nothrow_swappable_v<T>) {
    reverse(begin(), end());
  }

  constexpr T *data() noexcept { return data_.data(); }
  constexpr const T *data() const noexcept { return data_.data(); }

  constexpr void clear() noexcept { size_ = 0, data_[0] = T{}; }
};

} // namespace clix
