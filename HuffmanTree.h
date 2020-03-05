#ifndef HUFFMANTREE
#define HUFFMANTREE

#include <fstream> //File reading
#include <sstream> //String stream
#include <iostream> //cout function

namespace WYLJUS002{


class HuffmanTree{
    private:
    std::shared_ptr<int> root = nullptr;
    std::string data;
    std::string compressed_data;


    public:

    //Constructor
    HuffmanTree();


    //Tree construction
    void generate_tree(); //Build up the tree using freq's in unordered map
    void generate_tree(std::string fname); //Build up the tree using freq's in unordered map
    void data_from_file(std::string fname); //Read input from file into data string
    void generate_freq_map(); //Generate the frequency map based on string
    void populate_tree(); //Generate the nodes in the tree
    void determine_codetable(); //Assign the nodes with huffman codes
    void compress_data(); //Compress the data and return it 



    
};
}

#endif