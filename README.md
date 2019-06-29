# string_search

string_search compares some string searching algorithms on macOS(clang), Linux(gcc) and Windows(msvc).
The results are used in the code searching tool fsrc (https://github.com/elsamuko/fsrc).

## Results

Mac OS with Clang version 10.0.0 (clang-1000.11.45.5)
~~~~
Searching 7 bytes within 219 bytes.
                        memmem :   208 us
                  string::find :    52 us <
                        strstr :   142 us
   boyer_moore_horspool_search :    91 us
     knuth_morris_pratt_search :   418 us

Searching 11 bytes within 35121 bytes.
                        memmem : 16520 us
                  string::find :  1038 us <
                        strstr : 15909 us
   boyer_moore_horspool_search : 13890 us
     knuth_morris_pratt_search : 74434 us
~~~~

linux with GNU C++ version 9.1.0
~~~~
Searching 7 bytes within 219 bytes.
                        memmem :    70 us
                  string::find :    24 us <
                        strstr :    86 us
   boyer_moore_horspool_search :    42 us
     knuth_morris_pratt_search :   296 us

Searching 11 bytes within 35121 bytes.
                        memmem : 18510 us
                  string::find :   403 us <
                        strstr : 28808 us
   boyer_moore_horspool_search :  7968 us
     knuth_morris_pratt_search : 56441 us
~~~~

Win32 with Microsoft Visual C++ version 1921
~~~~
Searching 7 bytes within 219 bytes.
                  string::find :    37 us
                        strstr :    19 us <
   boyer_moore_horspool_search :    91 us
     knuth_morris_pratt_search :   426 us

Searching 11 bytes within 35121 bytes.
                  string::find :  1680 us
                        strstr :  1589 us <
   boyer_moore_horspool_search : 11702 us
     knuth_morris_pratt_search : 81545 us
~~~~
