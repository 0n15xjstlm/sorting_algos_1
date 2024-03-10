#pragma once
#include "generic.hpp"
#include <vector>
#include <algorithm>

namespace sorts {
SortHelper ShakerSort(std::vector <long long> &a) {
  long long assigns, comparisons;
  assigns = comparisons = 0;

  int start = 0, end = a.size() - 1;
  bool swapped = true;
  while (swapped) {
    swapped = false;

    for (int i = start; i < end; ++i) {
      if (a[i] > a[i + 1]) {
        std::swap(a[i], a[i + 1]);
        assigns += 3;
        swapped = true;
      }
      ++comparisons;
    }

    for (int i = end; i > start; --i) {
      if (a[i] > a[i + 1]) {
        std::swap(a[i], a[i + 1]);
        assigns += 3;
        swapped = true;
      }
      ++comparisons;
    }
  }

  return {assigns, comparisons};
}

std::pair <int, SortHelper> BinarySearch(std::vector <long long> &a, int lhs, 
  int rhs, long long x) {
  long long assigns, comparisons;
  assigns = comparisons = 0;

  --lhs, ++rhs;
  while (lhs < rhs - 1) {
    size_t mid = (lhs + rhs) / 2;

    if (x >= a[mid]) {
      rhs = mid;
    } else {
      lhs = mid;
    }
    ++comparisons;
  }

  if (lhs == -1) {
    return {-1, {assigns, comparisons}};
  }
  return {rhs, {assigns, comparisons}};
}

SortHelper BISortUtil(std::vector <long long> &a, int lhs, int rhs) {
  long long assigns, comparisons;
  assigns = comparisons = 0;

  int selected = a[rhs];
  for (int i = rhs; i > lhs; --i) {
    a[i] = a[i - 1];
    ++assigns;
  }
  a[lhs] = selected;
  ++assigns;

  return {assigns, comparisons};
}

SortHelper BISort(std::vector <long long> &a) {
  long long assigns, comparisons;
  assigns = comparisons = 0;

  for (int i = 1; i < a.size(); ++i) {
    auto ptr1 = BinarySearch(a, 0, i - 1, a[i]);
    assigns += ptr1.second.assigns;
    comparisons += ptr1.second.comparisons;

    if (ptr1.first == -1) {
      SortHelper temp = BISortUtil(a, 0, i);
      assigns += temp.assigns;
      comparisons += temp.comparisons;
    } else {
      SortHelper temp = BISortUtil(a, ptr1.first, i);
      assigns += temp.assigns;
      comparisons += temp.comparisons;
    }
  }

  for (int i = 0, j = a.size() - 1; i < j; ++i, --j) {
    std::swap(a[i], a[j]);
    assigns += 3;
  }

  return {assigns, comparisons};
}

SortHelper SISort(std::vector <long long> &a) {
  long long assigns, comparisons;
  assigns = comparisons = 0;

  for (int i = 1; i < a.size(); ++i) {
    int j = i;
    while (j && a[j] < a[j - 1]) {
      std::swap(a[j], a[j - 1]);
      --j;
      assigns += 3;
      comparisons++;
    }
  }

  return {assigns, comparisons};
}

SortHelper SSort(std::vector <long long> &a) {
  long long assigns, comparisons;
  assigns = comparisons = 0;

  for (int i = a.size() - 1; i >= 0; --i) {
    long long max = -(1ll << 62), ptr = 0;
    for (int j = 0; j <= i; ++j) {
      if (max < a[j]) {
        max = a[j];
        ptr = j;
        ++assigns;
      }
      ++comparisons;
    }
    std::swap(a[ptr], a[i]);
    assigns += 3;
  }

  return {assigns, comparisons};
}

SortHelper BSort(std::vector <long long> &a) {
  long long assigns, comparisons;
  assigns = comparisons = 0;

  int last_swap = a.size() - 1;
  for (int i = 1; i < a.size(); ++i) {
    bool is_sorted = true;
    int curr_swap = -1;
    
    for (int j = 0; j < last_swap; ++j) {
      if (a[j] > a[j + 1]) {
        std::swap(a[j], a[j + 1]);
        is_sorted = false;
        curr_swap = j;
        assigns += 3;
      }
      ++comparisons;
    }

    if (is_sorted) break;
    last_swap = curr_swap;
  }
  
  return {assigns, comparisons};
}
};