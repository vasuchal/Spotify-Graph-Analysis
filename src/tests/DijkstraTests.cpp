#include "../catch/catch.hpp"
#include "../components/Song.h"
#include "../components/Songs.h"
#include <vector>
#include "../components/DataAnalysis.h"
#include <iostream>
#include "cmath"
#include "../components/Graph.h"
#include <string>
#include <algorithm>

TEST_CASE("Dijkstra Tests") {
  Songs songs;
  songs.DeserializeFromFile("tests/test_jsons/ten_songs.json");

  Graph graph(songs.SongsList());

  SECTION("0 to 9: Regular traversal") {
    graph.dijkstra(0);
    std::vector<std::string> path;
    path.push_back("Mercury: Retrograde");
    path.push_back("Pathology");
    path.push_back("Andromeda");
    graph.createPathVector(9);
    std::vector<std::string> actual_path = graph.getPath();

    for (unsigned i = 0; i < path.size(); i++) {
      REQUIRE(path[i].compare(actual_path[i]) == 0);
    }
  }

  SECTION("2 to 8: Regular traversal") {
    graph.dijkstra(2);
    std::vector<std::string> path1;
    path1.push_back("Symbiote");
    path1.push_back("I Put My Dick in Your Mental");
    graph.createPathVector(8);
    std::vector<std::string> actual_path = graph.getPath();
    
    for (unsigned i = 0; i < path1.size(); i++) {
      REQUIRE(path1[i].compare(actual_path[i]) == 0);
    }
  }
  
  SECTION("1 to 8: Regular traversal") {
    graph.dijkstra(1);
    std::vector<std::string> path2;
    path2.push_back("Pathology");
    path2.push_back("Symbiote");
    path2.push_back("I Put My Dick in Your Mental");
    graph.createPathVector(8);
    std::vector<std::string> actual_path = graph.getPath();

    for (unsigned i = 0; i < path2.size(); i++) {
      REQUIRE(path2[i].compare(actual_path[i]) == 0);
    }
  }
  
  SECTION("3 to 7: Regular traversal") {
    graph.dijkstra(3);
    std::vector<std::string> path3;
    path3.push_back("ProductOfDrugs (Prod. The Virus and Antidote)");
    path3.push_back("Symbiote");
    path3.push_back("T.R.U. (Totally Rotten Underground)");
    graph.createPathVector(7);
    std::vector<std::string> actual_path = graph.getPath();

    for (unsigned i = 0; i < path3.size(); i++) {
      REQUIRE(path3[i].compare(actual_path[i]) == 0);
    }
  }

  SECTION("0 to 6: Regular traversal") {
    graph.dijkstra(0);
    std::vector<std::string> path5;
    path5.push_back("Mercury: Retrograde");
    path5.push_back("Symbiote");
    path5.push_back("kamikaze (+ pulse)");
    graph.createPathVector(6);
    std::vector<std::string> actual_path = graph.getPath();

    for (unsigned i = 0; i < path5.size(); i++) {
      REQUIRE(path5[i].compare(actual_path[i]) == 0);
    }
  }

  SECTION("6 to 0: Checking path for backwards traversal compared to previous test") {
    graph.dijkstra(6);
    std::vector<std::string> path6;
    path6.push_back("kamikaze (+ pulse)");
    path6.push_back("Symbiote");
    path6.push_back("Mercury: Retrograde");
    graph.createPathVector(0);
    std::vector<std::string> actual_path = graph.getPath();

    for (unsigned i = 0; i < path6.size(); i++) {
      REQUIRE(path6[i].compare(actual_path[i]) == 0);
    }
  }

  SECTION("1 to 1, Checking path to itself") {
    graph.dijkstra(1);
    std::vector<std::string> path4;
    path4.push_back("Pathology");
    graph.createPathVector(1);
    std::vector<std::string> actual_path = graph.getPath();

    for (unsigned i = 0; i < path4.size(); i++) {
      REQUIRE(path4[i].compare(actual_path[i]) == 0);
    }
  }
}

TEST_CASE("Dijkstra Tests Using Song Names") {
  Songs songs;
  songs.DeserializeFromFile("tests/test_jsons/ten_songs.json");

  Graph graph(songs.SongsList());

  SECTION("0 to 9: Regular traversal") {
    graph.dijkstraGivenSong("Mercury: Retrograde");
    std::vector<std::string> path;
    path.push_back("Mercury: Retrograde");
    path.push_back("Pathology");
    path.push_back("Andromeda");
    graph.createPathVectorGivenSong("Andromeda");
    std::vector<std::string> actual_path = graph.getPath();

    for (unsigned i = 0; i < path.size(); i++) {
      REQUIRE(path[i].compare(actual_path[i]) == 0);
    }
  }
  
  SECTION("3 to 7: Regular traversal") {
    graph.dijkstraGivenSong("ProductOfDrugs (Prod. The Virus and Antidote)");
    std::vector<std::string> path3;
    path3.push_back("ProductOfDrugs (Prod. The Virus and Antidote)");
    path3.push_back("Symbiote");
    path3.push_back("T.R.U. (Totally Rotten Underground)");
    graph.createPathVectorGivenSong("T.R.U. (Totally Rotten Underground)");
    std::vector<std::string> actual_path = graph.getPath();

    for (unsigned i = 0; i < path3.size(); i++) {
      REQUIRE(path3[i].compare(actual_path[i]) == 0);
    }
  }

  SECTION("0 to 6: Regular traversal") {
    graph.dijkstraGivenSong("Mercury: Retrograde");
    std::vector<std::string> path5;
    path5.push_back("Mercury: Retrograde");
    path5.push_back("Symbiote");
    path5.push_back("kamikaze (+ pulse)");
    graph.createPathVectorGivenSong("kamikaze (+ pulse)");
    std::vector<std::string> actual_path = graph.getPath();

    for (unsigned i = 0; i < path5.size(); i++) {
      REQUIRE(path5[i].compare(actual_path[i]) == 0);
    }
  }

  SECTION("6 to 0: Checking path for backwards traversal compared to previous test") {
    graph.dijkstraGivenSong("kamikaze (+ pulse)");
    std::vector<std::string> path6;
    path6.push_back("kamikaze (+ pulse)");
    path6.push_back("Symbiote");
    path6.push_back("Mercury: Retrograde");
    graph.createPathVectorGivenSong("Mercury: Retrograde");
    std::vector<std::string> actual_path = graph.getPath();

    for (unsigned i = 0; i < path6.size(); i++) {
      REQUIRE(path6[i].compare(actual_path[i]) == 0);
    }
  }

  SECTION("1 to 1, Checking path to itself") {
    graph.dijkstraGivenSong("Pathology");
    std::vector<std::string> path4;
    path4.push_back("Pathology");
    graph.createPathVectorGivenSong("Pathology");
    std::vector<std::string> actual_path = graph.getPath();

    for (unsigned i = 0; i < path4.size(); i++) {
      REQUIRE(path4[i].compare(actual_path[i]) == 0);
    }
  }
}