# Drew Goldman dag5wd Lab Section 103

CXX=clang++ $(CXXFLAGS)
CXXFLAGS=-Wall # Enable all warnings
DEBUG=-g
OBJECTS = hashTable.o timer.o wordPuzzle.o
a.out: $(OBJECTS)
	$(CXX) $(DEBUG) $(OBJECTS) -o a.out
	@echo "Wordsearch puzzle compiled :)"

hashTable.o: hashTable.cpp hashTable.h

timer.o: timer.cpp timer.h

wordPuzzle.o: wordPuzzle.cpp timer.h hashTable.h

.PHONY: clean
clean:
	-rm -f *.o *~ a.out
