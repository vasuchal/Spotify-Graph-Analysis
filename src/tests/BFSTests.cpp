#include "../catch/catch.hpp"
#include "../components/Song.h"
#include "../components/Songs.h"
#include <vector>
#include "../components/DataAnalysis.h"
#include "../components/Graph.h"
#include <iostream>
#include <math.h>

TEST_CASE("test BFS traversal with cycle graph") {
  Songs songs;
  songs.DeserializeFromFile("tests/test_jsons/has_cycle.json");
  DataAnalysis da(songs.SongsList());
  Graph graph(songs.SongsList());
  std::vector<int> expected({0,2,3,1});
  REQUIRE(graph.BFS(0) == expected);
}
TEST_CASE("test BFS traversal with no cycle graph") {
  Songs songs;
  songs.DeserializeFromFile("tests/test_jsons/no_cycle.json");
  DataAnalysis da(songs.SongsList());
  Graph graph(songs.SongsList());
  std::vector<int> expected({0,2,1});
  REQUIRE(graph.BFS(0) == expected);
}