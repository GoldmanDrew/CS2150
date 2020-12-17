#Drew Goldman
#dag5wd
#11/14/2020
#Makefile

CXX = clang++

CXXFLAGS = -Wall

DEBUG=-g

# All of the .o files
OBJECTS = topological.o

# Compile our files ==> a.out
a.out: $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(DEBUG) $(OBJECTS) -o a.out
	doxygen

topological.o: topological.cpp

# This will clean up (remove) all our object files.  The -f option
# tells rm to forcily remove the files (i.e. don't ask if they should
# be removed or not).  This removes object files (*.o) and Emacs
# backup files (*~)
clean:
	-rm -f *.o *~
