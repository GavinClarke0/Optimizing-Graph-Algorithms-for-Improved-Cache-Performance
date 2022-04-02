## Implementation of Optimizing Graph Algorithms for Improved Cache Performance

reference: http://www.cs.hongik.ac.kr/~jsp/parkTPDS04.pdf


```c++

 Performance counter stats for './FloydMarshall':

        76,515,635      cache-references                                              (79.95%)
         3,079,906      cache-misses              #    4.025 % of all cache refs      (79.94%)
    47,660,570,924      cycles                                                        (40.11%)
    69,913,367,848      instructions              #    1.47  insn per cycle           (60.07%)
     5,414,338,100      branches                                                      (79.99%)
             1,149      faults                                                      
                11      migrations                                                  

      15.469804382 seconds time elapsed

      15.447001000 seconds user
       0.003994000 seconds sys


 Performance counter stats for './FloydMarshallRecursive':

       123,919,661      cache-references                                              (80.06%)
           241,695      cache-misses              #    0.195 % of all cache refs      (79.96%)
    47,119,508,631      cycles                                                        (39.98%)
    70,057,280,700      instructions              #    1.49  insn per cycle           (60.05%)
     5,459,356,529      branches                                                      (79.99%)
             1,149      faults                                                      
                 2      migrations                                                  

      15.268183083 seconds time elapsed

      15.240372000 seconds user
       0.011987000 seconds sys

 Performance counter stats for './FloydMarshallTiled':

        91,409,309      cache-references                                              (79.97%)
            73,955      cache-misses              #    0.081 % of all cache refs      (79.94%)
    47,675,782,251      cycles                                                        (40.09%)
    70,050,251,192      instructions              #    1.47  insn per cycle           (60.03%)
     5,449,523,273      branches                                                      (80.00%)
             1,148      faults
                 8      migrations

    15.421036311 seconds time elapsed

    15.392539000 seconds user
     0.011987000 seconds sys
     
Performance counter stats for './DijkstrasAdjacencyArray':

         4,199,756      cache-references                                              (81.99%)
           473,884      cache-misses              #   11.284 % of all cache refs      (75.34%)
       844,979,447      cycles                                                        (42.67%)
       917,275,995      instructions              #    1.09  insn per cycle           (65.98%)
       134,620,308      branches                                                      (82.44%)
             4,218      faults
                 0      migrations

     0.292359688 seconds time elapsed

     0.287457000 seconds user
     0.003992000 seconds sys

 Performance counter stats for './DijkstrasControl':

         6,920,275      cache-references                                              (79.04%)
           839,687      cache-misses              #   12.134 % of all cache refs      (81.09%)
       532,940,632      cycles                                                        (39.87%)
       713,429,748      instructions              #    1.34  insn per cycle           (60.83%)
       127,941,620      branches                                                      (79.71%)
            15,758      faults
                 1      migrations

    0.191409886 seconds time elapsed

    0.125418000 seconds user
    0.064732000 seconds sys
```