build:
	clang++ -g FloydMarshall.cpp -o FloydMarshall
	clang++ -g  FloydMarshallRecursive -o FloydMarshallRecursive
build/debug:
	clang++ -g FloydMarshall.cpp -o FloydMarshall
	clang++ -g  FloydMarshallRecursive -o FloydMarshallRecursive
clean:
	rm FloydMarshallRecursive
	rm FloydMarshall