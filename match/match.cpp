/**
 * Match implementation.
 *
 * Copyright (c) 2021, Robin Lee Simpson
 */
#include <functional>
#include <iostream>
#include <tuple>
#include <algorithm>
#include <set>
#include "match.h"
#include "../data/data.h"

// Some helpful macros, use them if you wish

// get tuple
#define G(pf, i) std::get<i>(pf)
// checks profile for match
#define S(p1, p2, f) (G(p1.f, 0) == G(p2.f, 0) ? G(p1.f, 1) + G(p2.f, 1) : 0)
// finds a value
#define A(s, i) (s.find(i) == s.end())

double score(const Profile &p1, const Profile &p2) {
  // Calculate total score for the pair
  return S(p1, p2, Profile::country) + S(p1, p2, Profile::diet)
  + S(p1, p2, Profile::drinking) + S(p1, p2, Profile::language)
  + S(p1, p2, Profile::religion) + S(p1, p2, Profile::smoking);
}

// I was going to use this for sorting but figured out a different method
/* struct greater {
  template<class T>
  bool operator()(T const &a, T const &b) const { return a > b;}
}; */

bool sorting(const std::tuple<uint32_t, uint32_t,
  double>&a, const std::tuple<uint32_t, uint32_t, double>&b) {
  return (G(a, 2) > G(b, 2));
}

std::map<uint32_t, uint32_t> Match::pairs(std::vector<Profile> &profiles) {
  // Suggested data structures, replace if/as necessary
  typedef std::tuple<uint32_t, uint32_t, double> Pairing;
  std::vector<uint32_t> males, females;
  std::vector<Pairing> pairings;
  std::set<uint32_t> picked;
  std::map<uint32_t, uint32_t> pairs;

  // Break into separate lists of males and females
  for (uint32_t i = 0; i < profiles.size(); i++) {
    (profiles[i].gender == MALE ? males : females).push_back(i);
  }
  // Generate list of all possible pairings
  // cycles through the vectors of male and female
  for (uint32_t ml : males) {
    for (uint32_t fm : females) {
      /* pushes back to pairings vector
      by taking total score of male + female profiles */
      pairings.push_back(Pairing(ml, fm, score(profiles[ml], profiles[fm])));
    }
  }

  // Sort pairings in descending order of score
  std::sort(pairings.begin(), pairings.end(), sorting);

  // Pick starting at the top upto required number of pairs
  // Be sure not to pick the same member twice (hint: use std::set)
  for (auto i : pairings) {
    auto ml = G(i, 0);  // returns male id
    auto fm = G(i, 1);  // returns female id
    // checks if element is present
    if ((picked.count(ml) != 1) && (picked.count(fm) != 1)) {
      picked.insert(ml);
      picked.insert(fm);
      pairs.insert({ ml, fm });
    }
    // cycles through and sees if pick size is equal to profile size
    if (picked.size() == profiles.size()) {break;}
  }
  // Return pair of male/female indexes into profiles
  return pairs;
}
