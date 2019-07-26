# string_search

string_search compares some string searching algorithms on macOS(clang), Linux(gcc) and Windows(msvc).
The results are used in the code searching tool fsrc (https://github.com/elsamuko/fsrc).

## Results


linux with GNU C++ version 9.1.0
~~~~
Search for an existing substring with 11 bytes within 671 bytes.
                       fromStd :    12 us <
                  string::find :    13 us
                        ssestr :    36 us
                        memmem :    35 us
                        strstr :    49 us
                   string_view :   136 us
   boyer_moore_horspool_search :   148 us
     knuth_morris_pratt_search :   951 us

11 bytes within 35121 bytes.
                       fromStd :   398 us
                  string::find :   395 us <
                        ssestr :  1633 us
                        memmem : 17729 us
                        strstr : 27439 us
                   string_view :  7433 us
   boyer_moore_horspool_search :  7893 us
     knuth_morris_pratt_search : 54721 us

Search for an non-existing substring with 11 bytes within 671 bytes.
                       fromStd :   283 us
                  string::find :   305 us
                        ssestr :   104 us <
                        memmem :   224 us
                        strstr :   259 us
                   string_view :   502 us
   boyer_moore_horspool_search :   189 us
     knuth_morris_pratt_search :  1852 us

11 bytes within 35121 bytes.
                       fromStd : 17904 us
                  string::find : 18032 us
                        ssestr :  2759 us <
                        memmem : 10362 us
                        strstr : 12204 us
                   string_view : 36686 us
   boyer_moore_horspool_search :  9776 us
     knuth_morris_pratt_search : 106612 us
~~~~

Mac OS with Clang version 10.0.0 (clang-1000.11.45.5)
~~~~
Search for an existing substring with 11 bytes within 671 bytes.
                       fromStd :    45 us
                  string::find :    35 us
                        ssestr :    72 us
                        memmem :   309 us
                        strstr :   302 us
                   string_view :    33 us <
   boyer_moore_horspool_search :   217 us
     knuth_morris_pratt_search :  1982 us

11 bytes within 35121 bytes.
                       fromStd :  1360 us
                  string::find :  1510 us
                        ssestr :  3212 us
                        memmem : 19257 us
                        strstr : 17397 us
                   string_view :  1061 us <
   boyer_moore_horspool_search : 10319 us
     knuth_morris_pratt_search : 115153 us

Search for an non-existing substring with 11 bytes within 671 bytes.
                       fromStd :   810 us
                  string::find :   858 us
                        ssestr :   165 us <
                        memmem :  2124 us
                        strstr :  1060 us
                   string_view :   705 us
   boyer_moore_horspool_search :   310 us
     knuth_morris_pratt_search :  3253 us

11 bytes within 35121 bytes.
                       fromStd : 41648 us
                  string::find : 42447 us
                        ssestr :  4940 us <
                        memmem : 87611 us
                        strstr : 69308 us
                   string_view : 48631 us
   boyer_moore_horspool_search : 20411 us
     knuth_morris_pratt_search : 205513 us
~~~~

~~~~
Search for an existing substring with11 bytes within 671 bytes.
                       fromStd :    49 us <
                  string::find :    52 us
                        strstr :    53 us
                   string_view :    51 us
   boyer_moore_horspool_search :   284 us
     knuth_morris_pratt_search :  1349 us

11 bytes within 35121 bytes.
                       fromStd :  1644 us
                  string::find :  1791 us
                        strstr :  1621 us <
                   string_view :  1779 us
   boyer_moore_horspool_search : 11151 us
     knuth_morris_pratt_search : 81693 us

Search for an non-existing substring with11 bytes within 671 bytes.
                       fromStd :   408 us
                  string::find :   400 us
                        strstr :    99 us <
                   string_view :   404 us
   boyer_moore_horspool_search :   261 us
     knuth_morris_pratt_search :  2610 us

11 bytes within 35121 bytes.
                       fromStd : 31951 us
                  string::find : 31756 us
                        strstr :  3897 us <
                   string_view : 32915 us
   boyer_moore_horspool_search : 13979 us
     knuth_morris_pratt_search : 154277 us
~~~~
