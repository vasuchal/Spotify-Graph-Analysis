#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include "components/Song.h"
#include "components/Songs.h"
#include "components/DataAnalysis.h"
#include <map>
#include <vector>
#include <utility>
#include <float.h>
#include <cfloat>
#include "components/Graph.h"

// TODO: Add namespace for all and Songs class
// TODO: Test BFS 
int main()
{   
    Songs songs;
    songs.DeserializeFromFile("genres_v2.json");


    // TODO: Move this to another testing data analysis testing file
    // TESTING DATA ANALYSIS, GRAPH
    DataAnalysis da(songs.SongsList());

// Code to be run in main for demo :
    Graph graph(songs.SongsList());
    graph.printMatrix();
    std::cout << graph.hasCycle(0) << std::endl;
    graph.BFS(0);

    // Print names for Dijkstra's shortest path
    graph.dijkstra(0);
    graph.createPathVector(9);
    std::cout << "First Path: " << std::endl;
    std::vector<std::string> path = graph.getPath();
    for (unsigned i = 0; i < path.size(); i++) {
        std::cout << path[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Second Path: " << std::endl;
    graph.dijkstra(9);
    graph.createPathVector(0);
    path = graph.getPath();
    for (unsigned i = 0; i < path.size(); i++) {
        std::cout << path[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Third Path: " << std::endl;
    graph.dijkstra(0);
    graph.createPathVector(0);
    path = graph.getPath();
    for (unsigned i = 0; i < path.size(); i++) {
        std::cout << path[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Fourth Path: " << std::endl;
    graph.dijkstraGivenSong("Pathology");
    graph.createPathVectorGivenSong("Pathology");
    path = graph.getPath();
    for (unsigned i = 0; i < path.size(); i++) {
        std::cout << path[i] << " ";
    }
    std::cout << std::endl;
}
