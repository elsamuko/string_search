
QMAKE_CXXFLAGS_RELEASE += -msse2 -Ofast -march=native
QMAKE_LFLAGS_RELEASE += -flto

LIBS += -lstdc++fs -lpthread -lrt

# sudo add-apt-repository ppa:ubuntu-toolchain-r/test
# sudo apt update
# sudo apt install g++-9
QMAKE_CC = gcc-9
QMAKE_CXX = g++-9
