build:
	g++ -g FloydMarshall.cpp -o FloydMarshall
	g++ -g  FloydMarshallRecursive.cpp -o FloydMarshallRecursive
build/debug:
	g++ -g FloydMarshall.cpp -o FloydMarshall
	g++ -g  FloydMarshallRecursive.cpp -o FloydMarshallRecursive
clean:
	rm FloydMarshallRecursive
	rm FloydMarshall