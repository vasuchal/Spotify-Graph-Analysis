#include "../catch/catch.hpp"
#include "../components/Song.h"
#include "../components/Songs.h"
#include <vector>
#include "../components/DataAnalysis.h"
#include "../components/Graph.h"
#include <iostream>
#include <math.h>
TEST_CASE("test there is cycle") {
  Songs songs;
  songs.DeserializeFromFile("tests/test_jsons/has_cycle.json");
  DataAnalysis da(songs.SongsList());
  Graph graph(songs.SongsList());
  REQUIRE(graph.hasCycle(0) == true);
}
TEST_CASE("test no cycle") {
  Songs songs;
  songs.DeserializeFromFile("tests/test_jsons/no_cycle.json");
  DataAnalysis da(songs.SongsList());
  Graph graph(songs.SongsList());
  REQUIRE(graph.hasCycle(0) == false);
}