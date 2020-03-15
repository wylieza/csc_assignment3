>>> Huffman Encoding Application <<<


--- Instructions for use ---
The data to be encoded should be placed in a text file in the same directory as the
executable. When suppling the input and output file names, the extensions should be included.

The program will save the huffman encoded data into a file with the name given by the output
file argument. The program will then attempt to change the extension from the one given to
.hdr to save a second file containing the encoding table.

Example:
./huffencode input_data.txt output_data.txt

Produces three output files:
output_data.txt -> Containing the huffman encoded data
output_data.hdr -> Containing the encoding table
output_data.raw -> Containing the huffman encoded data as a bit-stream

-- Program Arguments --

<input filename> <output filename>


--- MAKEFILE ---
The makefile will allow the program to be compiled, run and binaries to be cleaned.
Unit testing may also be performed using the make file

Command -> Action
_________________________________________________________________________________________________
>> Standard Commands <<
make                            -> Compile all source code
make clean                      -> Remove all binaries
make run args="<Custom args>"   -> Runs the huffencode binary with the argument(s) given between ""

>> Unit Testing <<
make unittesting                -> This will compile, but not execute the unit tests
make unittest                   -> Execute the 'unittesting' binary (Perform the unit tests)

_________________________________________________________________________________________________

Note: The application can also be executed in the terminal using ./huffencode <input filename> <output filename>


--- Source Code Description ---
>> huffencode.cpp <<
This is the 'driver' and contains the main() method. This source code interperates the arguments given
by the user and then calls apon the appropriate methods in the HuffmanTree class to perform the
huffman encoding. It does this through an instance of the HuffmanTree class 'tree'.

>> HuffmanTree.h <<
This header file contains the HuffmanTree class declaration. This class is responsible for the
construction, management and destruction of the HuffmanTree used to encode the supplied data
string.

>> HuffmanTree.cpp <<
This source constitutes all the definitions of the methods declared in the HuffmenTree class.

>> HuffmanNode.h <<
This header file contains the HuffmanNode class declaration. This class is used to instantiate
nodes that are used to build the HuffmanTree. Essential the building block for a simple binary
tree.

>> HuffmanNode.cpp <<
This source constitutes all the definitions of the methods declared in the HuffmenNode class.

>> unittesting.cpp <<
This file contains all the unit tests. Including the unit tests for the additional work
sections of the assignment.


--- Student Details ---
Work of Justin Wylie
Student number: WYLJUS002