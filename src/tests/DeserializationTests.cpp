#include "../catch/catch.hpp"
#include "../components/Song.h"
#include "../components/Songs.h"
#include <vector>
#include "../components/DataAnalysis.h"
#include "../components/Graph.h"
#include <iostream>
#include <math.h>
TEST_CASE("test deserialization of Songs array") {
  Songs songs;
  songs.DeserializeFromFile("tests/test_jsons/ten_songs.json");
  REQUIRE(songs.SongsList().size() == 10);
}

TEST_CASE("test deserialization of single Song object") {
  Song song;
  song.DeserializeFromFile("tests/test_jsons/single_song.json");

  REQUIRE(Approx(song.Key()) == 2.000000);
  REQUIRE(Approx(song.Danceability()) == 0.831000 );
  REQUIRE(Approx(song.Energy()) == 0.814000);
  REQUIRE(Approx(song.Loudness()) == -7.364000);
  REQUIRE(Approx(song.Valence()) == 0.389000);
  REQUIRE(Approx(song.Speechiness()) == 0.42000);
  REQUIRE(Approx(song.Acousticness()) == 0.059800);
  REQUIRE(Approx(song.Liveness()) == 0.055600);
  REQUIRE(Approx(song.Instrumentalness()) == 0.013400);
}