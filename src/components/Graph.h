
#include <vector>
#include <string>
#include <list>
#include <unordered_map>
#include "Song.h"

using namespace std;

class Graph {
    public:
        Graph(std::list<Song>& songList);
        void addEdge(int u, int v, double diff);
        void printMatrix();
        void dijkstra(int start);
        int minDistance();
        std::string getSongNameFromIndex(int v);
        std::vector<std::string> getPath();
        void createPathVector(int currentSong);
        void createSongIndexMap(std::list<Song>& songList);
        void dijkstraGivenSong(std::string song);
        void createPathVectorGivenSong(std::string song);
        bool hasCycle(int start); 
        std::vector<int> BFS(int start);
    private:
        int number_of_songs_;
        vector<vector<double>> adj_matrix_;
        vector<Song> songs_;
        std::vector<double> distances_;
        double weight_;
        std::vector<bool> visited_;
        std::vector<int> disjoint_set_;
        std::vector<std::string> path_; 
        std::unordered_map<std::string, int> songToIndexMap_;
};
