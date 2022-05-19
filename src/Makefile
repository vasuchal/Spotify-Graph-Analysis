EXENAME = main
TEST = test
CXX = clang++
CXXFLAGS = -std=c++0x -g -O0 -Wall -Wextra

all : $(EXENAME)

$(EXENAME): JSONBase.cpp components/Song.cpp main.cpp components/Songs.cpp components/DataAnalysis.cpp components/Graph.cpp
	$(CXX) $(CXXFLAGS) JSONBase.cpp components/Songs.cpp components/Song.cpp components/DataAnalysis.cpp components/Graph.cpp main.cpp -o $(EXENAME)
test: catch/catch.hpp JSONBase.cpp components/Songs.cpp components/Song.cpp components/DataAnalysis.cpp components/Graph.cpp tests/DijkstraTests.cpp tests/CycleTests.cpp tests/DeserializationTests.cpp tests/BFSTests.cpp 
	$(CXX) $(CXXFLAGS) JSONBase.cpp components/Songs.cpp components/Song.cpp components/DataAnalysis.cpp components/Graph.cpp tests/DijkstraTests.cpp tests/CycleTests.cpp tests/DeserializationTests.cpp tests/BFSTests.cpp tests/DataAnalysisTests.cpp catch/catchmain.cpp -o test
.PHONY: clean
clean:
	rm -f $(EXENAME)
