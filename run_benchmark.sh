
touch benchmark_results.txt
echo "------ 1024 Floyd Warshall -------" > benchmark_results.txt

perf stat -B --output  benchmark_results.txt --append -e cache-references,cache-misses,cycles,instructions,branches,faults,migrations,L1-dcache-load-misses,L1-dcache-loads,L1-dcache-stores,L1-icache-load-misses,LLC-loads,LLC-load-misses,LLC-stores,LLC-store-misses,LLC-prefetches ./FloydMarshall 1024

perf stat -B --output  benchmark_results.txt --append -e cache-references,cache-misses,cycles,instructions,branches,faults,migrations,L1-dcache-load-misses,L1-dcache-loads,L1-dcache-stores,L1-icache-load-misses,LLC-loads,LLC-load-misses,LLC-stores,LLC-store-misses,LLC-prefetches ./FloydMarshallRecursive 1024 

perf stat -B --output  benchmark_results.txt --append -e cache-references,cache-misses,cycles,instructions,branches,faults,migrations,L1-dcache-load-misses,L1-dcache-loads,L1-dcache-stores,L1-icache-load-misses,LLC-loads,LLC-load-misses,LLC-stores,LLC-store-misses,LLC-prefetches ./FloydMarshallTiled 1024 

echo "------ 2048 Floyd Warshall -------" > benchmark_results.txt

perf stat -B --output  benchmark_results.txt --append -e cache-references,cache-misses,cycles,instructions,branches,faults,migrations,L1-dcache-load-misses,L1-dcache-loads,L1-dcache-stores,L1-icache-load-misses,LLC-loads,LLC-load-misses,LLC-stores,LLC-store-misses,LLC-prefetches ./FloydMarshall 2048

perf stat -B --output  benchmark_results.txt --append -e cache-references,cache-misses,cycles,instructions,branches,faults,migrations,L1-dcache-load-misses,L1-dcache-loads,L1-dcache-stores,L1-icache-load-misses,LLC-loads,LLC-load-misses,LLC-stores,LLC-store-misses,LLC-prefetches ./FloydMarshallRecursive 2048 

perf stat -B --output  benchmark_results.txt --append -e cache-references,cache-misses,cycles,instructions,branches,faults,migrations,L1-dcache-load-misses,L1-dcache-loads,L1-dcache-stores,L1-icache-load-misses,LLC-loads,LLC-load-misses,LLC-stores,LLC-store-misses,LLC-prefetches ./FloydMarshallTiled 2048

echo "------ 1024 Floyd Warshall -------" > benchmark_results.txt

perf stat -B --output  benchmark_results.txt --append -e cache-references,cache-misses,cycles,instructions,branches,faults,migrations,L1-dcache-load-misses,L1-dcache-loads,L1-dcache-stores,L1-icache-load-misses,LLC-loads,LLC-load-misses,LLC-stores,LLC-store-misses,LLC-prefetches ./DijkstrasAdjacencyList 1024 

perf stat -B --output  benchmark_results.txt --append -e cache-references,cache-misses,cycles,instructions,branches,faults,migrations,L1-dcache-load-misses,L1-dcache-loads,L1-dcache-stores,L1-icache-load-misses,LLC-loads,LLC-load-misses,LLC-stores,LLC-store-misses,LLC-prefetches ./DijkstrasAdjacencyArray 1024

echo "------ 2048 Floyd Warshall -------" > benchmark_results.txt

perf stat -B --output  benchmark_results.txt --append -e cache-references,cache-misses,cycles,instructions,branches,faults,migrations,L1-dcache-load-misses,L1-dcache-loads,L1-dcache-stores,L1-icache-load-misses,LLC-loads,LLC-load-misses,LLC-stores,LLC-store-misses,LLC-prefetches ./DijkstrasAdjacencyList 2048

perf stat -B --output  benchmark_results.txt --append -e cache-references,cache-misses,cycles,instructions,branches,faults,migrations,L1-dcache-load-misses,L1-dcache-loads,L1-dcache-stores,L1-icache-load-misses,LLC-loads,LLC-load-misses,LLC-stores,LLC-store-misses,LLC-prefetches ./DijkstrasAdjacencyArray 2048