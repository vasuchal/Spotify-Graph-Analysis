### Video Link: https://drive.google.com/file/d/1bZLgTn6wwHBda3-AAlqfyS9SUZSwenf_/view?usp=sharing
# Deliverables
* Quantify how similar songs are by giving them a score
* Create a graph that connects songs that are similar enough based on a threshold and does not connect songs that do not meet that threshold
* Be able to show the shortest transition of one song to another in a dataset using Dijkstra’s shortest path algorithm
* Detect cycles to determine groups of songs that are similar
 
## Quantifying Song Similarity 
To quantify song similarity, we had to come up with an equation that allowed us to compare them. By finding the absolute difference between two songs in a few key categories (i.e. key, danceability, etc.) we felt best contributed to a song’s composition, we could then determine how different two songs were. We then gave each pair of songs a “difference factor” that was given by adding up the differences in each individual category. This “difference factor” can be characterized by edges in our graph. By finding this factor for every pair of songs in our dataset, we could then create an average difference between two songs that would act as a threshold, which is explained in the next section.
 
As confirmation that our method of quantification worked, we tested song similarity for a dataset of 10 songs. We created a python script (linked below) that returned the difference factors for each pair of songs. We then tested these expected values against those given by our method that compares two songs.

Python Script: https://docs.google.com/document/u/1/d/1Bw0XEEDDaeaZaFGbIpb5M3cVtEWXxK3YQavKKs5r4nI/edit?usp=sharing
 
## Create a Graph Based on Song Similarity 
We chose to use an adjacency matrix when implementing the graph storing the Songs and decided on this data structure because, since our Songs vector is a fixed size, most of our operations focused on checking if edges existed and adding edges which happens in O(1) time. Instead of booleans, our adjacency matrix is optimized to store the distance/weights between two edges if connected. If not, a distance of -1 is stored. By using a helper function to display the adjacency matrix, we discovered the connections between songs and the score differences between them. We discovered that there wasn’t necessarily only one connected component in the songs graph. Depending on the difference factor we picked and the range of the songs, we saw the number of connected components diverge and the quantity of cycles differ. 

<img src="https://media.github-dev.cs.illinois.edu/user/12724/files/d397a131-88b1-40a4-b2ae-69e1e6c122c5" height="200">
 
## Dijkstra’s Shortest Path Algorithm Based on Quantified Similarity 
Using the information given by our graph, we then implemented Dijkstra’s shortest path algorithm that can take in either an index of a song or a song name. From Dijkstra’s shortest path algorithm, we discovered which songs are “on the path” or “transition songs” between our start and target songs.
 
To allow for song names to be entered as valid input for Dijkstra’s, we created a map of song names to indices in the graph constructor. Then, we created a wrapper method that takes in a string for the song name, gets the corresponding index from the map, and calls on our function that actually executes Dijkstra’s shortest path algorithm.
 
As confirmation that our shortest path algorithm is correct, we put all of our songs and their difference factors into this website linked below (1). The testing we did on quantifying song similarity was helpful since we could determine what edges were in the graph. We removed any edges with a weight that was larger than the calculated threshold (given by the average difference between two songs). This linked document (2) shows the output given by our python script mentioned above, which we then standardized for the website.
 
We then chose a few test cases (a few regular traversals between two songs, a “backwards” traversal, and a path to the same song). The results given by the website were what we tested against. We also tested these three key cases for when a song name is input for Dijkstra’s.

If you make and run ./main, you should get the following output for the three test cases mentioned above: 

<img width="335" alt="Screen Shot 2021-12-12 at 5 39 34 PM" src="https://media.github-dev.cs.illinois.edu/user/12785/files/f37c4883-dc59-46de-baf4-108d6e366146">

The first path resembles a regular traversal from song 0 to song 9. Essentially, we input the songs by index into the dijkstra algorithm.

<img width="337" alt="Screen Shot 2021-12-12 at 5 39 42 PM" src="https://media.github-dev.cs.illinois.edu/user/12785/files/a21d5c86-8f29-4209-8b30-2e7bc71e0e91">

The second path is from song 9 to song 0 to resemble a backwards traversal of the first path.

<img width="334" alt="Screen Shot 2021-12-12 at 5 39 49 PM" src="https://media.github-dev.cs.illinois.edu/user/12785/files/9219a6e2-de44-4680-887d-ea81ca724b00">

The third path is from song 0 to song 0. We are just showing here the path to the same song.

<img width="338" alt="Screen Shot 2021-12-12 at 5 39 57 PM" src="https://media.github-dev.cs.illinois.edu/user/12785/files/13aace61-4545-44d5-88cb-9da61a0d5fc5">

The fourth path also resembles a path to the same song, but by using a song name as an input rather than its index.

(1) Dijkstra's Website: https://wjholden.com/dijkstra

(2) Document Outlining Python Output (and Our Standardization of This for Input for Dijkstra's Website): https://docs.google.com/document/d/1l-E_kI0y8Pfq50GvuT28v7FruOETPYn0uUZts6lhS9I/edit
 
## Classify and Analyze Song Similarity Using Cycle Detection and BFS Traversal Algorithms 
We used a DFS Cycle Detection algorithm which returns whether the given graph has a cycle or not and prints the cycle detected. Finally, we implemented a BFS traversal and decided to store and return the order the songs were traversed using a vector. We discovered through implementing the BFS traversal the most closely related and also loosely related. 
<img src="https://media.github-dev.cs.illinois.edu/user/12724/files/c1ef8b76-395f-44cd-bb45-a29077b819a8" height="200">

<img src="https://media.github-dev.cs.illinois.edu/user/12724/files/d18010f9-e939-4f4f-b2b4-ae502d748f6a" height="75">

<img src="https://media.github-dev.cs.illinois.edu/user/12724/files/fd2e215d-9ec9-4fe3-a755-994dcd0f7a5c" height="200">


### Linked Files:
Proposal: Proposal.md

Development: Development.md
