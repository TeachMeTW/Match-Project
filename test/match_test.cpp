/**
 * Unit tests.
 *
 * Copyright (c) 2021, Robin Lee Simpson.
*/

#include <tuple>
#include <bits/stdc++.h>
#include <vector>
#include <gtest/gtest.h> 
#include <type_traits>
#include "../match/match.h"
#include "../data/data.h"

#define G(pf, i) std::get<i>(pf)
// Write your unit tests here
// Be sure to test at least some of the key requirements in README
// Use the Orvile unit tests as guide

// creates the profiles
std::vector<Profile> up = profiles(100);
// creates the matches
auto matches = Match::pairs(up);
// Grabs the top 2 matched values
auto& Profile1 = up[matches.begin()->first];
auto& Profile2 = up[matches.begin()->second];

// checks if pairs is matched with male and female
TEST(Matching, isMatchWithMaleFemale) {
    ASSERT_NE(Profile1.gender, Profile2.gender);
}
// checks if the matches are equal
TEST(Matching, areEqualMatches) {
    ASSERT_EQ(matches.size(), 50);
}

// Tests if Country matches
TEST(Matching, isMatchCountry) {
    std::cout << "Matching Country" << std::endl;
    auto& cv1 = std::get<0>(Profile1.country);
    auto& cv2 = std::get<0>(Profile2.country);
    // Just for viewing data
    std::cout << "Match value for P1: " << std::get<1>(Profile1.country) << std::endl;
    std::cout << "Match value for P2: " << std::get<1>(Profile2.country) << std::endl;
    EXPECT_EQ(cv1, cv2);
}

// Tests if Diet Matches
TEST(Matching, isMatchDiet) {
    std::cout << "Matching Diet" << std::endl;
    auto& diet1 = std::get<0>(Profile1.diet);
    auto& diet2 = std::get<0>(Profile2.diet);
    // Just for viewing data
    std::cout << "Match value for P1: " << std::get<1>(Profile1.diet) << std::endl;
    std::cout << "Match value for P2: " << std::get<1>(Profile2.diet) << std::endl;
    EXPECT_EQ(diet1, diet2);
}

// Tests if Language matches
TEST(Matching, isMatchLanguage) {
    std::cout << "For Matching Language" << std::endl;
    auto& lang1 = std::get<0>(Profile1.language);
    auto& lang2 = std::get<0>(Profile2.language);
    // Just for viewing data
    std::cout << "Match value for P1: " << std::get<1>(Profile1.language) << std::endl;
    std::cout << "Match value for P2: " << std::get<1>(Profile2.language) << std::endl;
    EXPECT_EQ(lang1, lang2);
}

// Tests if Religion Matches
TEST(Matching, isMatchReligion) {
    std::cout << "Matching Religion" << std::endl;
    auto& rel1 = std::get<0>(Profile1.religion);
    auto& rel2 = std::get<0>(Profile2.religion);
    // Just for viewing data
    std::cout << "Match value for P1: " << std::get<1>(Profile1.religion) << std::endl;
    std::cout << "Match value for P2: " << std::get<1>(Profile2.religion) << std::endl;
    EXPECT_EQ(rel1 , rel2);
}
int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  std::cout<<"\n\n----------running basic_test.cpp---------\n\n"<<std::endl;
  return RUN_ALL_TESTS();
}
