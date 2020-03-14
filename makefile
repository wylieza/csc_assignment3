GCC = g++
CARGS = #-fno-stack-protector

huffencode: huffencode.o HuffmanTree.o HuffmanNode.o
	$(GCC) -o huffencode huffencode.o HuffmanTree.o HuffmanNode.o -std=c++11 $(CARGS)

HuffmanTree.o: HuffmanTree.cpp HuffmanTree.h
	$(GCC) -c -o HuffmanTree.o HuffmanTree.cpp -std=c++11 $(CARGS)

huffencode.o: huffencode.cpp
	$(GCC) -c -o huffencode.o huffencode.cpp -std=c++11 $(CARGS)

HuffmanNode.o: HuffmanNode.cpp HuffmanNode.h
	$(GCC) -c -o HuffmanNode.o HuffmanNode.cpp -std=c++11 $(CARGS)

unittesting: unittesting.o huffencode.o HuffmanTree.o HuffmanNode.o
	$(GCC) -o unittesting unittesting.o
	./unittesting

unittesting.o: unittesting.cpp
	$(GCC) -c -o unittesting.o unittesting.cpp

run: huffencode
	./huffencode $(ARGS)

clean:
	rm -rf huffencode huffencode.o HuffmanTree.o