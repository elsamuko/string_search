## string_search

Mac OS with Clang version 10.0.0 (clang-1000.11.45.5)
~~~~
                         memmem : 114 us
                   string::find :  75 us <
                         strstr :  74 us
    boyer_moore_horspool_search : 110 us
      knuth_morris_pratt_search : 302 us
~~~~

linux with GNU C++ version 7.4.0
~~~~
                        memmem :  37 us
                  string::find :  37 us <
                        strstr :  52 us
   boyer_moore_horspool_search :  53 us
     knuth_morris_pratt_search : 117 us
~~~~

Win32 with Microsoft Visual C++ version 1920
~~~~
                  string::find :  50 us
                        strstr :  14 us <
   boyer_moore_horspool_search : 137 us
     knuth_morris_pratt_search : 387 us
~~~~
