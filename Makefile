build:
	g++ -std=c++11 -g FloydMarshall.cpp -o FloydMarshall
	g++ -std=c++11 -g  FloydMarshallRecursive.cpp -o FloydMarshallRecursive
	g++ -std=c++11 -g  FloydMarshallTiled.cpp -o FloydMarshallTiled
	g++ -std=c++11 -g  DijkstrasAdjacencyArray.cpp -o DijkstrasAdjacencyArray
	g++ -std=c++11 -g  DijkstrasAdjacencyList.cpp -o DijkstrasAdjacencyList
	g++ -std=c++11 -g  DijkstrasAdjacencyArrayArray.cpp -o DijkstrasAdjacencyArrayArray
clean:
	rm FloydMarshallRecursive
	rm FloydMarshall
	rm FloydMarshallTiled
	rm DijkstrasAdjacencyArray
