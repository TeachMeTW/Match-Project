/**
 * Generate report for an integration test.
 *
 * Copyright (c) 2021, Robin Lee Simpson
 */

#include <iostream>
#include <algorithm>
#include <tuple>
#include <vector>
#include <cstdio>
#include "data/data.h"
#include "match/match.h"

#define G(pf, i) std::get<i>(pf)

// Refers to what you implement in match
double score(const Profile &, const Profile &);
bool sort2(const std::tuple<uint32_t, uint32_t,
  double>& a, const std::tuple<uint32_t, uint32_t, double>& b) {
  return (std::get<2>(a) < std::get<2>(b));
}

int main() {
  // Tuple is like an ad-hoc struct, holding disparate entities
  // Convenient when returning multiple values from function
  typedef std::tuple<uint32_t, uint32_t, double> Entry;

  // Vector is a contiguous list of entities
  // Just like array, but of variable length
  std::vector<Profile> up = profiles(100);

  // Easiest is to return indeces rather than IDs
  std::vector<Entry> ut;
  for (auto p : Match::pairs(up)) {
    ut.push_back({
      up[p.first].id, up[p.second].id, score(up[p.first], up[p.second])
    });
  }

  // Sort by male ID
  sort(ut.begin(), ut.end());
  // Print results
  // 0 = male id, 1 = female id, 2 = score
  std::cout << "\nReport Pairing (Alphabetical order to the male id):\n\n";
  for (uint32_t i = 0; i < ut.size(); i++) {
    std::cout << "Male id: " << std::get<0>(ut[i]) << " | "
              << "Female id: " << std::get<1>(ut[i]) << " | "
              << "Score: " << std::get<2>(ut[i]) << "\n";
  }
  sort(ut.begin(), ut.end(), sort2);
  std::cout << "\nReport Pairing (Order to the lowest score):\n\n";
  for (uint32_t i = 0; i < ut.size(); i++) {
    std::cout << "Male id: " << std::get<0>(ut[i]) << " | "
              << "Female id: " << std::get<1>(ut[i]) << " | "
              << "Score: " << std::get<2>(ut[i]) << "\n";
  }
}
