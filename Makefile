build:
	g++ -g FloydMarshall.cpp -o FloydMarshall
	g++ -g  FloydMarshallRecursive.cpp -o FloydMarshallRecursive
	g++ -g  FloydMarshallTiled.cpp -o FloydMarshallTiled
	g++ -g  DijkstrasAdjacencyArray.cpp -o DijkstrasAdjacencyArray
	g++ -g  DijkstrasControl.cpp -o DijkstrasControl
build/debug:
	g++ -g FloydMarshall.cpp -o FloydMarshall
	g++ -g  FloydMarshallRecursive.cpp -o FloydMarshallRecursive
	g++ -g  FloydMarshallTiled.cpp -o FloydMarshallTiled
	g++ -g  DijkstrasAdjacencyArray.cpp -o DijkstrasAdjacencyArray
	g++ -g  DijkstrasControl.cpp -o DijkstrasControl
build/debug:
clean:
	rm FloydMarshallRecursive
	rm FloydMarshall