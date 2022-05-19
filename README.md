# Graph Algorithms in C++ - with Spotify Songs (sc83-archnas2-konjeti3-riyaj3)
### *Data Analysis of the Relation of Various Songs in Spotify Using an Undirected Graph.*
Group: Vasu Chalasani (sc83), Riya Jain (riyaj3), Archna Sobti (archnas2), Neha Konjeti (konjeti3)
## Building and Running
This project can be built on most Linux Systems. <br/>
### Running on Linux (and EWS)
To build and run this project on EWS and Linux you can use the included Makefile. <br/>

```
$ make
$ ./main
```

To run tests for this project on EWS and Linux you can use the included Makefile. <br/>

```
$ make test
$ ./test
```


## Project Description
### Data Usage
We used the genres_v2.csv file from https://www.kaggle.com/mrmorj/dataset-of-songs-in-spotify <br/>
### Project Functionality
This project’s functionality includes: <br/>
- Build an undirected graph out of the dataset.
- Traverse this spotify songs data using Breadth First Search (BFS). 
- Find the shortest path between two songs, based on Dijkstra’s Algorithm. 
- Find the the shortest path, a fast transformation of one song to the next, between two songs
- Detect if cycles exist within a given song set
- Can be used to compute the average song of any dataset

- - - -
### DataAnalysis
#### Files: /src/components/DataAnalysis.h/cpp
The data analysis class handles all of the mathematical calculations for our project. This class can find the average song, the difference between a song and the average song, the “distance” between two songs, and the average difference between two songs. If the “distance” between two songs is greater than the average difference between two songs, then there will not be an edge between the two songs in the graph.
- - - -
### Graph
#### Files: /src/components/Graph.h/cpp

#### Adjacency Matrix
The graph class constructor builds a graph representation of the set of Songs using an adjacency matrix. In this implementation, it is an undirected graph and the matrix stores the weights/distances between two edges rather than booleans. Edges can be added using ***addEdge*** and inputting two vertices.

#### Breadth First Search (BFS)
Takes a starting song index and traverses the songs using a graph object. The output is the song indices of the BFS traversal. These song indices can be converted to names using the getSongNameFromIndex function in the Graph class. 

#### Cycle Detection 
Takes a starting song index and performs a DFS until a cycle is detected and then prints out all of the names of the songs in the cycle and returns a boolean based on if a cycle is found. This information can tell us about groups of songs that are closely related.

#### Dijkstra's Implementation
Takes a starting song index and creates the shortest path from it to all other songs. Other linked methods take in a target song index and find the shortest path from the starting song to the target song. A few wrapper methods takes in song names instead of indices and call upon our implmentation of Dijkstra's. The shortest path reveals the fastest transition between one song and another.
- - - -
### Testing
#### Folder: /tests

#### Deserialization
#### Files: DeserializationTests.cpp, ten_songs.json, single_song.json
This set of tests checks if data is deserialized into a single Song object properly and if data containing ten songs can deserialize properly into an array of Song objects, also an object of the Songs class.

#### DataAnalysis
#### Files: DataAnalysisTests.cpp, ten_songs.json
For DataAnalysis, we tested whether the song edges were created correctly. We made sure that given a test dataset of 10 songs, the distances between one song and the other were correct and that some edges were nonexistent (denoted by a distance of -1).

#### BFS
#### Files: BFSTests.cpp, has_cycle.json, no_cycle.json
The BFS method returns a vector of songs with the order they were traversed in. This actual output is compared to the expected output determined by tracing the traversals by hand. This case is checked on smaller datasets of around 3-4 songs and is checked for graphs with cycles and without cycles. 

#### Cycle Detection 
#### Files: CycleTests.cpp,  has_cycle.json, no_cycle.json
CycleTests tests that cycles are determined accurately. It is tested on smaller datasets of 4 songs and is tested on graphs with both cycles and no cycles. 

#### Dijkstra’s
#### Files: /tests/DijkstraTests.cpp, ten_songs.json
DijkstraTests tests whether the shortest path was found using the source index and the source song name, respectively. For each input type (number and string), a few regular paths, one reverse path (start and end switched), and one path to the same song were tested.
- - - -

