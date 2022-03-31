build:
	g++ -g FloydMarshall.cpp -o FloydMarshall
	g++ -g  FloydMarshallRecursive.cpp -o FloydMarshallRecursive
	g++ -g  FloydMarshallTiled.cpp -o FloydMarshallTiled
build/debug:
	g++ -g FloydMarshall.cpp -o FloydMarshall
	g++ -g  FloydMarshallRecursive.cpp -o FloydMarshallRecursive
	g++ -g  FloydMarshallTiled.cpp -o FloydMarshallTiled
clean:
	rm FloydMarshallRecursive
	rm FloydMarshall