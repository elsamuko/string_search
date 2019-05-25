## string_search

Mac OS with Clang version 10.0.0 (clang-1000.11.45.5)
~~~~
                        memmem : 255 us
                  string::find :  70 us
                        strstr : 131 us
   boyer_moore_horspool_search :  63 us <
     knuth_morris_pratt_search : 489 us
~~~~

linux with GNU C++ version 9.1.0
~~~~
                        memmem :  94 us
                  string::find :  24 us <
                        strstr : 144 us
   boyer_moore_horspool_search :  41 us
     knuth_morris_pratt_search : 301 us
~~~~

Win32 with Microsoft Visual C++ version 1920
~~~~
                  string::find :  46 us
                        strstr :  21 us <
   boyer_moore_horspool_search :  66 us
     knuth_morris_pratt_search : 458 us
~~~~
