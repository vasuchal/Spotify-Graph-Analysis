#include "Graph.h"
#include "DataAnalysis.h"
#include <unordered_map>
#include <vector>
#include <iostream>
#include <stack>
#include <queue>
#include <map>

using namespace std;

Graph::Graph(std::list<Song>& songList) {
    vector<vector<double>> vec(songList.size(), vector<double> (songList.size(), -1));
    distances_.resize(songList.size());
    visited_.resize(songList.size());
    disjoint_set_.resize(songList.size(), -1);

    DataAnalysis da(songList); // used to analyze data and retrieve transformed songs vector 
    createSongIndexMap(songList);

    number_of_songs_ = songList.size();
    adj_matrix_ = vec;
    weight_ = da.getAverageDifference();  // gives weight to distinguish by for if edges are close enough to be connected 
    songs_ = da.getSongs();
    for (unsigned int i = 0; i < songs_.size(); i++) {
        for (unsigned int j = i + 1; j < songs_.size(); j++) { 
                double diff = da.getScoreDifference(songs_[i], songs_[j]);
                if (diff <= weight_) {
                    // graph is undirected so edges are added both ways
                    addEdge(i, j, diff);
                    addEdge(j, i, diff);
                }
        } 
    }

}

void Graph::createSongIndexMap(std::list<Song>& songList) {
    int i = 0;
    for (Song song : songList) {
        songToIndexMap_.insert(std::make_pair(song.Name(), i));
        i++;
    }
}

void Graph::addEdge(int u, int v, double diff) {
    adj_matrix_[u][v] = diff;
}

void Graph::printMatrix() {
    for (vector<double> edges: adj_matrix_) {
        for (double edge: edges) {
            std::cout << edge << " ";
        }
        std::cout << "" << std::endl;
    }
}

// Find the closest non-visited node/song
int Graph::minDistance() {
    int min = INT_MAX;
    int min_index = -1;

    for (int v = 0; v < number_of_songs_; v++) {
        if (visited_[v] == false && distances_[v] <= min) {
            min = distances_[v];
            min_index = v;
        }
    }
    return min_index;
}

void Graph::createPathVectorGivenSong(std::string song) {
    int index = songToIndexMap_[song];
    createPathVector(index);
}

void Graph::createPathVector(int currentSong) {
    if (disjoint_set_[currentSong] == -1) {
        path_.push_back(songs_[currentSong].Name());
        return;
    }

    createPathVector(disjoint_set_[currentSong]);

    path_.push_back(songs_[currentSong].Name());
}

std::vector<std::string> Graph::getPath() {
    return path_;
}

void Graph::dijkstra(int start) {
    path_.clear();
    // Set the source to -1, indicating this is the root in the disjoint set
    disjoint_set_[start] = -1;

    // Initialize all distances to infinity and initialize all nodes/songs as not visited
    for (int i = 0; i < number_of_songs_; i++) {
        visited_[i] = false;
        distances_[i] = INT_MAX;
    }

    distances_[start] = 0;

    for (int count = 0; count < number_of_songs_ - 1; count++) {
        // Go to the nearest unexplored song/node
        int u = minDistance();
        visited_[u] = true;

        // Update the distances of the connected nodes to "u"
        for (int v = 0; v < number_of_songs_; v++) {

            // If the connected edge is not visited and the new distance is less than the current weight
            // of the node, set u as the node's parent and update the distance to that connected node
            if (!visited_[v] && adj_matrix_[u][v] != -1 &&
                distances_[u] + adj_matrix_[u][v] < distances_[v]) {
                disjoint_set_[v] = u;
                distances_[v] = distances_[u] + adj_matrix_[u][v];
            }
        }
    }
}

void Graph::dijkstraGivenSong(std::string song) {
    int index = songToIndexMap_[song];
    dijkstra(index);
}

// DFS Cycle Detection 
bool Graph::hasCycle (int start) {
    // use map to store paths to print out detected cycle
        std::map<int, int> m;
        vector<bool> visited_(songs_.size(), false);
        stack <pair<int, int> > s;
        visited_[start] = true;
        s.push(make_pair(start, -1));

        while (!s.empty())
        {
            int vertex = s.top().first;
            int connected_vertex = s.top().second;
            s.pop();


            for (unsigned int i = 1; i < adj_matrix_.size(); i++) {
                if (adj_matrix_[vertex][i] != -1) {
                    int neighbor_vert = i;
                    if (!visited_[neighbor_vert]) {
                        m[neighbor_vert] = vertex;
                        s.push(make_pair(neighbor_vert, vertex));
                        visited_[neighbor_vert] = true;
                    }
                    // cycle was detected, print statements are in place to display all songs in cycle 
                    else if (neighbor_vert != connected_vertex) {
                        std::cout << getSongNameFromIndex(vertex) << std::endl;
                        int nv = neighbor_vert; 
                        while (nv != start) {
                            std::cout << getSongNameFromIndex(nv) << std::endl;
                            nv = m[nv];
                        }
                        std::cout << getSongNameFromIndex(start) << std::endl;
                        return true;
                    }
                }
            }
        }
    return false;
}

// Performs BFS traversal on songs list
std::vector<int> Graph::BFS(int start) {
    vector<int> traversed_nodes; 
    vector<bool> visited_(songs_.size(), false);
    queue <int> q;
    visited_[start] = true;
    q.push(start);


    while (!q.empty())
    {
        int vertex = q.front();
        std::cout << songs_[vertex].Name() << std::endl;
        q.pop();
        traversed_nodes.push_back(vertex);

        for (unsigned int i = 1; i < adj_matrix_.size(); i++) {
            if (adj_matrix_[vertex][i] != -1) {
                int neighbor_vert = i;
                if (!visited_[neighbor_vert]) {
                    q.push(neighbor_vert);
                    visited_[neighbor_vert] = true;
                }
            }
        }
    }

    return traversed_nodes;
}

std::string Graph::getSongNameFromIndex(int v) {
    return songs_[v].Name();
}
