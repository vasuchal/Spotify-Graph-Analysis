# Development Log
## Group Meeting Notes
#### Tuesday 11/9
* Dataset: [Dataset of songs in Spotify](https://www.kaggle.com/mrmorj/dataset-of-songs-in-spotify)
* Converted CSV to JSON
* Considering using MatPlotPlusPlus for graph visualization
* Considering using Nlohmann library for deserialization
* Split up into two groups to deserialize data and try getting a sample visualization to work
  * Deserialization: Neha & Vasu
  * Graph Visualization: Riya & Archna

#### Tuesday 11/16
* Rewrote project proposal
* Graph Visualization Research:
  * [Examples](https://alandefreitas.github.io/matplotplusplus/plot-types/graphs/undirected-graph/)
  * Also watched a video about coding 3D graphs like this using the Python library
* Two groups
  * Deserialization and Data Parsing: Neha & Vasu
  * Object Classes: Riya & Archna

#### Sunday 11/21
* Deserialization will be completed within the next two days! Probably will be done by tomorrow at 6 PM
  * Chose RapidJSON instead of Nlohmann
* Ten Graph Algorithms Visually Explained
  * Graph algorithms detailed explanation
* Will be keeping same pairs for graph algorithms
  * Dijikstra’s Algorithm - Archna & Riya
    * Remember to keep in mind that sometimes there isn’t a shortest path since the songs may be in two different groups/components
    * Keep track of the path
    * Belman Ford - alternative
* DFS Cycle Detection - Vasu & Neha
    * Brent’s - alternative
* BFS Traversal - Vasu & Neha

#### Tuesday 11/23 + Sunday 11/28
* Updated group members on each pair's progress through detailed notes in pair logs below 


## Pair Meeting Notes
### Riya and Archna

* 11/25
  * Worked on data analysis class
  * Have a few errors, but it should be fixed soon
* 12/2
  * Worked on understanding Dijkstra’s algorithm by watching a few YouTube videos and learning about different implementations, which we then referenced to help with development
     * How to implement Dijkstra's Algorithm in C++: https://www.educative.io/edpresso/how-to-implement-dijkstras-algorithm-in-cpp
     * Printing Paths in Dijkstra's Shortest Path Algorithm: https://www.geeksforgeeks.org/printing-paths-dijkstras-shortest-path-algorithm/
     * C++ Program to Implement Adjacency Matrix: https://www.tutorialspoint.com/cplusplus-program-to-implement-adjacency-matrix
  * Dijkstra’s will be completed on Saturday (hopefully)!
* 12/4
  * Completed Dijkstra’s
* 12/6
  * Started testing getScoreDifference from DataAnalysis class
    * Wrote script to help with this
      * Script link: https://docs.google.com/document/d/1Bw0XEEDDaeaZaFGbIpb5M3cVtEWXxK3YQavKKs5r4nI/edit?usp=sharing
  * Will test Dijkstra’s shortest path tomorrow (Tuesday)
    * https://wjholden.com/dijkstra
* 12/7
  * Finished testing getScoreDifference from DataAnalysis class
  * Started testing Dijkstra’s shortest path
    * Came upon some bugs, so we’re planning on going to office hours tomorrow
* 12/8
  * Debugged Dijkstra’s pathing to account for nonexistent edges and cleaned up code
* 12/9
  * Debugged Dijkstra’s segmentation fault (infinite loop between two nodes due to the source incorrectly not being set to -1)
  * Debugged some tests that were comparing the path with the wrong vector of songs, incorrect song spelling, etc.
* 12/10
  * Cleaned up Dijkstra tests by moving some into sections
  * Fixed merge conflicts with main
  * Added a mapping method in Graph that is called on when the graph is constructed
  * Made class variables consistent

### Vasu and Neha

* 11/22 
  * Add rapid JSON library
  * Worked Deserialize songs JSON into Song objects (includes all of the song’s characteristics such as key, tone, danceability, instrumentalness, etc) and a vector containing Song objects 
  * Archna joined in as well to stay in the loop 
* 11/25 
  * Work to debug Data Analysis memory errors and type errors 
  * Create function to determine necessary song weights and adjust it based on the song set and size
* 12/2 + 12/3 
  * Build out Graph class template
  * Implement adjacency matrix using Data Analysis metrics from previous work day’s functions
* 12/4
  * Implement and informally test cycle detection
  * Make note to test in official cases for various classes and algorithms 
* 12/6
  * Implement BFS and informally test with smaller subsets of songs
  * Clean up unused code in code base and write documentation for our functions and main’s code
  * Add TODOs for testing and next steps in main
* 12/8
  * Added ability to print cycles out through the DFS cycle detection algorithm
  * Will meet tomorrow (12/9) to test and clean and modularize codebase
* 12/9	
  * Write test cases for Song and Songs deserialization 
  * Modularized files and tests into folders
  * Get rid of syntactical warnings 
  * Write test cases for BFS
  * Add documentation to all of the functions as needed

## Final Group Meeting Notes
#### Friday 12/10
* Discussed final clean up steps
* Wrote README.md
* Started writing a video script (that would be finished asynchronously by Sunday)
* Discussed how the report would be written (that would be finished asynchronously by Sunday)

#### Sunday 12/12
* Recorded individual pair recordings and group introduction/conclusion
* Edited video
