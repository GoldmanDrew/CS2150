#Drew Goldman
#dag5wd
#11/11/2020
#Makefile

CXX=clang++ $(CXXFLAGS)

CXXFLAGS=-Wall -O2 -g -std=c++11

OFILES= huffmanNode.o huffmanTree.o heap.o

.SUFFIXES: .o .cpp

all:	encoder decoder

encoder: huffmanenc.o $(OFILES)
	$(CXX) $(OFILES) huffmanenc.o -o encoder

decoder: huffmandec.o $(OFILES)
	$(CXX) $(OFILES) huffmandec.o -o decoder

clean:
	-rm -f *.o *~