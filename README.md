## Implementation of Optimizing Graph Algorithms for Improved Cache Performance

reference: http://www.cs.hongik.ac.kr/~jsp/parkTPDS04.pdf


```c++
 Performance counter stats for './FloydMarshall':

        84,435,496      cache-references                                              (17.95%)
         4,108,988      cache-misses              #    4.866 % of all cache refs      (18.32%)
    47,946,303,273      cycles                                                        (18.47%)
    69,916,717,332      instructions              #    1.46  insn per cycle           (27.78%)
     5,422,992,711      branches                                                      (37.03%)
             1,146      faults                                                      
                43      migrations                                                  
        13,688,294      L1-dcache-load-misses     #    0.04% of all L1-dcache hits    (46.05%)
    38,598,744,594      L1-dcache-loads                                               (45.85%)     
         7,538,198      L1-icache-load-misses                                         (45.70%)
        82,971,449      LLC-loads                                                     (45.26%)
         3,906,814      LLC-load-misses           #    4.71% of all LL-cache hits     (17.88%)
        69,786,160      LLC-stores                                                    (17.88%)         

      16.243511341 seconds time elapsed

      16.168478000 seconds user
       0.051924000 seconds sys

 Performance counter stats for './FloydMarshallRecursive':

       125,240,497      cache-references                                              (18.05%)
           489,855      cache-misses              #    0.391 % of all cache refs      (18.25%)
    48,377,223,028      cycles                                                        (18.26%)
    70,038,586,375      instructions              #    1.45  insn per cycle           (27.42%)
     5,465,402,996      branches                                                      (36.63%)
             1,146      faults                                                      
                22      migrations                                                  
        58,228,811      L1-dcache-load-misses     #    0.15% of all L1-dcache hits    (45.88%)
    38,897,119,194      L1-dcache-loads                                               (45.70%)     
         2,468,009      L1-icache-load-misses                                         (45.70%)
       124,463,377      LLC-loads                                                     (45.47%)
           321,641      LLC-load-misses           #    0.26% of all LL-cache hits     (17.99%)
           932,054      LLC-stores                                                    (18.08%)
      16.549241820 seconds time elapsed

      16.521336000 seconds user
       0.007989000 seconds sys
       
 Performance counter stats for './FloydMarshallTiled':

        94,536,131      cache-references                                              (18.02%)
           260,144      cache-misses              #    0.275 % of all cache refs      (18.14%)
    48,998,640,908      cycles                                                        (18.38%)
    70,057,554,803      instructions              #    1.43  insn per cycle           (27.81%)
     5,463,144,006      branches                                                      (37.20%)
             1,145      faults                                                      
                44      migrations                                                  
        75,670,563      L1-dcache-load-misses     #    0.20% of all L1-dcache hits    (46.23%)
    38,501,755,737      L1-dcache-loads                                               (46.07%)     
         4,261,538      L1-icache-load-misses                                         (45.79%)
        93,782,008      LLC-loads                                                     (45.18%)
           150,877      LLC-load-misses           #    0.16% of all LL-cache hits     (17.81%)
           303,861      LLC-stores                                                    (18.00%)            

      16.868847160 seconds time elapsed

      16.799205000 seconds user
       0.047940000 seconds sys
       
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