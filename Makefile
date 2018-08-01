#Makefile for the Assingment 3
#28 March 2018
#Meluleki Dube

CPP =g++
CPPFLAGS =-std=c++11
SRC=HuffmanNode.cpp HuffmanTree.cpp HuffmanEncoding.cpp main.cpp Testing.cpp
TARGET=huffencode.run
OBJECTS=HuffmanNode.o HuffmanTree.o HuffmanEncoding.o main.o
TESTSRC= HuffmanNode.cpp HuffmanTree.cpp HuffmanEncoding.cpp
TESTARG=huffencode_testing.run
TESTOBJECT=Testing.o HuffmanNode.o HuffmanTree.o HuffmanEncoding.o


$(TARGET):$(OBJECTS)
	$(CPP) $(OBJECTS) -o $@ $(CPPFLAGS)
$(OBJECTS): $(SRC)
	$(CPP) -c $(SRC) $(CPPFLAGS)
	
test:$(TARGET)
	$(CPP) $(TESTOBJECT) $(CPPFLAGS) -o $(TESTARG)
run:
	./$(TARGET)
	
run_TEST:
	./$(TESTARG)
	
clean:
	rm -f -r *.o *.run
	