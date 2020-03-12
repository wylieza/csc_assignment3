GCC = g++

huffencode: huffencode.o HuffmanTree.o
	$(GCC) -o huffencode huffencode.o HuffmanTree.o -std=c++11

HuffmanTree.o: HuffmanTree.cpp HuffmanTree.h
	$(GCC) -c -o HuffmanTree.o HuffmanTree.cpp -std=c++11

huffencode.o: huffencode.cpp
	$(GCC) -c -o huffencode.o huffencode.cpp -std=c++11

HuffmanNode.o: HuffmanNode.cpp HuffmanNode.h
	$(GCC) -c -o HuffmanNode.o HuffmanNode.cpp -std=c++11

run: huffencode
	./huffencode $(ARGS)

clean:
	rm -rf huffencode huffencode.o HuffmanTree.o