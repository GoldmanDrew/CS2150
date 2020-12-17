# Drew Goldman dag5wd Lab Section 103

CXX=clang++ $(CXXFLAGS)
CXXFLAGS=-Wall # Enable all warnings
DEBUG=-g
OBJECTS = TreeCalc.o TreeCalcTest.o TreeNode.o
a.out: $(OBJECTS)
	$(CXX) $(DEBUG) $(OBJECTS) -o a.out
	@echo "Trees compiled :)"

TreeCalc.o: TreeCalc.cpp TreeCalc.h TreeNode.h

TreeCalcTest.o: TreeCalcTest.cpp TreeCalc.h TreeNode.h

TreeNode.o: TreeNode.cpp TreeNode.h

.PHONY: clean
clean:
	-rm -f *.o *~ a.out
