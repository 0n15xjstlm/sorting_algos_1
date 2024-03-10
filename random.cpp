#pragma once

#include <fstream>
#include <algorithm>
#include <ctime>
#include <random>
#include <vector>
#include <iostream>
#include "sorts/generic.hpp"

std::mt19937 rnd(time(nullptr));  
std::fstream out("sorts_in.txt");

long long kInf = (1ll << 62);

long long rng(long long lo = 0, long long hi = kInf) {
  long long number = rnd() % (hi - lo + 1);
  return (number >= lo ? number : number + lo);
}

void GenerateVector(int size, std::vector <long long> &a) {
  for (int j = 0; j < size; ++j) {
    a[j] = rng(10, 69420);
  }
}

int main() {
  int cases_count = 10;
  out << 70 << '\n';

  if (!out.is_open()) {
    std::cerr << "Couldn't open file.\nClosing the program now...\n";
    return -1;
  }

  std::vector <int> sizes = {10, 69, 420, 777, 1010, 1337, 5228, 9011, 69'420, 123'123};

  for (int size : sizes) {
    std::vector <long long> array(size);
    for (int i = 0; i < 7; ++i) {
      GenerateVector(size, array);
      out << size << '\n' << array << '\n';
    }
  }
}

