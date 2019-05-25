## string_search

Mac OS with Clang version 10.0.0 (clang-1000.11.45.5)
~~~~
                        memmem : 116 us
                  string::find :  72 us
                        strstr :  74 us
   boyer_moore_horspool_search :  33 us <
     knuth_morris_pratt_search : 156 us
~~~~

linux with GNU C++ version 9.1.0
~~~~
                        memmem :  36 us
                  string::find :  38 us
                        strstr :  52 us
   boyer_moore_horspool_search :  19 us <
     knuth_morris_pratt_search : 106 us
~~~~

Win32 with Microsoft Visual C++ version 1920
~~~~
                  string::find :  55 us
                        strstr :  15 us <
   boyer_moore_horspool_search :  35 us
     knuth_morris_pratt_search : 176 us
~~~~
