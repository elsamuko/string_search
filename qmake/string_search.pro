MAIN_DIR =..
DESTDIR=$${MAIN_DIR}
SRC_DIR  =../src
INCLUDEPATH += $${SRC_DIR}

SOURCES += $${SRC_DIR}/string_search.cpp

# via https://mischasan.wordpress.com/2011/07/16/convergence-sse2-and-strstr/
HEADERS += $${SRC_DIR}/ssestr.hpp

# via https://github.com/gcc-mirror/gcc/blob/master/libstdc%2B%2B-v3/include/bits/basic_string.tcc#L1199
HEADERS += $${SRC_DIR}/stdstr.hpp

include( setup.pri )
linux: include( linux.pri )
win32: include( win.pri )
macx:  include( mac.pri )

include( boost.pri )
