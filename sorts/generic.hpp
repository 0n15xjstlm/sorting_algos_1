#pragma once

#include <vector>
#include <ostream>
#include <istream>

struct SortHelper {
  long long assigns, comparisons;
};

template <typename T>
std::ostream &operator<<(std::ostream &os, std::vector <T> &a) {
  for (T x : a) {
    os << x << ' ';
  }
  return os;
}

template <typename T>
std::istream &operator>>(std::istream &is, std::vector <T> &a) {
  for (T x : a) {
    is >> x;
  }
  return is;
}