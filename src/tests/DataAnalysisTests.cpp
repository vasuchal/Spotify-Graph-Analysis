#include "../catch/catch.hpp"
#include "../components/Song.h"
#include "../components/Songs.h"
#include "../components/DataAnalysis.h"
#include <iostream>
#include "cmath"
#include "../components/Graph.h"
#include <string>
#include <algorithm>

TEST_CASE("getScoreDifference() for 10 songs") {
  Songs songs;
  songs.DeserializeFromFile("tests/test_jsons/ten_songs.json");
  DataAnalysis da(songs.SongsList());

  double song1_total[10] = { 0, 2.75492287, 2.6004607, 2.38346387, 1.06630202, 2.6188929, 
  -1, -1, 2.54817582, -1 };
  double song2_total[10] = { 2.75492287, 0, 2.59252852, -1, 2.74965452, -1, 
  1.94345054, 1.61737442, -1, 2.81952124 };
  double song3_total[10] = { 2.6004607, 2.59252852, 0, 2.45020492, 2.71989046, -1,
  2.07874863, 2.18369049, 2.68111994, -1 };
  double song4_total[10] = { 2.38346387, -1, 2.45020492, 0, 2.5076483, 2.7690251, 
  -1, -1, 1.94445365, -1 };
  double song5_total[10] = { 1.06630202, 2.74965452, 2.71989046, 2.5076483,  0, 2.60476486,
  -1, -1, 2.66829534, -1 };
  double song6_total[10] = { 2.6188929, -1, -1, 2.7690251, 2.60476486, 0, 
  -1, -1, -1, -1 };
  double song7_total[10] = { -1, 1.94345054, 2.07874863, -1, -1, -1, 
  0, 1.33906684, -1, -1 };
  double song8_total[10] = { -1, 1.61737442, 2.18369049, -1, -1, -1, 
  1.33906684, 0, -1, -1 };
  double song9_total[10] = { 2.54817582, -1, 2.68111994, 1.94445365, 2.66829534, -1,
  -1, -1, 0, -1 };
  double song10_total[10] = { -1, 2.81952124, -1, -1, -1, -1,
  -1, -1, -1, 0 };
  
  std::vector<Song> songs_ = da.getSongs();
    for (unsigned int i = 0; i < 10; i++) {
      for (unsigned int j = 0; j < 10; j++) {
        if (i == 0) {
          if (song1_total[j] != -1) {
            REQUIRE (abs(song1_total[j] - da.getScoreDifference(songs_[i], songs_[j])) < 0.005);
          }
        } else if (i == 1) {
          if (song2_total[j] != -1) {
            REQUIRE (abs(song2_total[j] - da.getScoreDifference(songs_[i], songs_[j])) < 0.005);
          }
        } else if (i == 2) {
          if (song3_total[j] != -1) {
            REQUIRE (abs(song3_total[j] - da.getScoreDifference(songs_[i], songs_[j])) < 0.005);
          }
        } else if (i == 3) {
          if (song4_total[j] != -1) {
            REQUIRE (std::abs(song4_total[j] - da.getScoreDifference(songs_[i], songs_[j])) < 0.005);
          }
        } else if (i == 4) {
          if (song5_total[j] != -1) {
            REQUIRE (std::abs(song5_total[j] - da.getScoreDifference(songs_[i], songs_[j])) < 0.005);;
          }
        } else if (i == 5) { 
          if (song6_total[j] != -1) {
            REQUIRE (std::abs(song6_total[j] - da.getScoreDifference(songs_[i], songs_[j])) < 0.005);;
          }
        } else if (i == 6) {
          if (song7_total[j] != -1) {
            REQUIRE (std::abs(song7_total[j] - da.getScoreDifference(songs_[i], songs_[j])) < 0.005);;
          }
        } else if (i == 7) {
          if (song8_total[j] != -1) {
            REQUIRE (std::abs(song8_total[j] - da.getScoreDifference(songs_[i], songs_[j])) < 0.005);;
          }
        } else if (i == 8) { 
          if (song9_total[j] != -1) {
            REQUIRE (std::abs(song9_total[j] - da.getScoreDifference(songs_[i], songs_[j])) < 0.005);;
          }
        } else if (i == 9) {
          if (song10_total[j] != -1) {
            REQUIRE (std::abs(song10_total[j] - da.getScoreDifference(songs_[i], songs_[j])) < 0.005);;
          }
        } 
    }
  }
}