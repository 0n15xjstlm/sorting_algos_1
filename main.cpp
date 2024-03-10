#pragma once

#include "sorts/sorts.hpp"

#include <fstream>
#include <iostream>
#include <vector> 
#include <string>
#include <iomanip>

std::ofstream out;

void sortTry(auto someSort) {
  int t = 0;
  std::ifstream in("sorts_in.txt");
  if (!in.is_open()) {
    exit(0);
  }
  in >> t;
  for (int i = 1; i <= t; ++i) {
    int size;
    in >> size;
    std::vector <long long> array(size);
    for (int j = 0; j < size; ++j) {
      in >> array[j];
    }
    SortHelper ans = someSort(array);
    out << "Testcase " << i << "! Size: " << size << ". Assigns: " << ans.assigns <<
                       "; Comparisons: " << ans.comparisons << ".\n";
    out.flush();
  }
  out << '\n';
  out.flush();
}

int main() {
  out.open("sorts.log", std::ios::app);

  out << std::string(50, '-') << '\n';
  out << std::setw(32) << "Selection Sort\n";
  out << std::string(50, '-') << '\n';
  sortTry(sorts::SSort);

  out << std::string(50, '-') << '\n';
  out << std::setw(32) << "Bubble Sort\n";
  out << std::string(50, '-') << '\n';
  sortTry(sorts::BSort);

  out << std::string(50, '-') << '\n';
  out << std::setw(32) << "Swap Insertion Sort\n";
  out << std::string(50, '-') << '\n';
  sortTry(sorts::SISort);

  out << std::string(50, '-') << '\n';
  out << std::setw(32) << "Binary Insertion Sort\n";
  out << std::string(50, '-') << '\n';
  sortTry(sorts::BISort);

  out << std::string(50, '-') << '\n';
  out << std::setw(32) << "Shaker Sort\n";
  out << std::string(50, '-') << '\n';
  sortTry(sorts::ShakerSort);
}