# Drew Goldman dag5wd Lab Section 103

CXX=clang++ $(CXXFLAGS)
CXXFLAGS=-Wall # Enable all warnings
DEBUG=-g
OBJECTS = BinaryNode.o BinarySearchTree.o BSTPathTest.o
a.out: $(OBJECTS)
	$(CXX) $(DEBUG) $(OBJECTS) -o a.out
	@echo "Trees compiled :)"

BinaryNode.o: BinaryNode.cpp BinaryNode.h

BinarySearchTree.o: BinarySearchTree.cpp BinaryNode.h BinarySearchTree.h

BSTPathTest.o: BSTPathTest.cpp BinarySearchTree.h BinaryNode.h

.PHONY: clean
clean:
	-rm -f *.o *~ a.out
