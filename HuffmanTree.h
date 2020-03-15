#ifndef HUFFMANTREE
#define HUFFMANTREE

#include <fstream> //File reading
#include <sstream> //String stream
#include <iostream> //cout function
#include <unordered_map> //Unordered map - freq counter
#include <memory>
#include <queue> //Priority queue

namespace WYLJUS002{

class HuffmanNode;

class HuffmanTree{
    private:
    std::shared_ptr<HuffmanNode> root = nullptr;
    std::string data;
    std::string compressed_data;
    std::unordered_map<char, int> frequencies;
    std::unordered_map<char, std::string> codetbl;


    public:

    //Constructor
    HuffmanTree();

    //Destructor
    ~HuffmanTree();


    //Tree construction
    void generate_tree(); //Build up the tree using freq's in unordered map
    void generate_tree(std::string fname); //Build up the tree using freq's in unordered map
    void data_from_file(std::string fname); //Read input from file into data string
    std::string get_data(); //UNITTESTING
    void generate_freq_map(); //Generate the frequency map based on string
    std::unordered_map<char, int> get_fmap(); //UNITTESTING
    void populate_tree(); //Generate the nodes in the tree
    void build_codetable();
    void build_codetable(const std::shared_ptr<HuffmanNode> &node, std::string code); //Assign the nodes with huffman codes
    void compress_data(); //Compress the data
    void write_to_file(std::string fname); //Writes the message to file and writes the code table to file
    void write_to_binary_file(std::string fname); //Writes the message in compressed bidanry form
    void read_from_binary_file(std::string fname); //Reads in the data from the binary file
    void decompress_data();

    struct compare{
        bool operator()(HuffmanNode &a, HuffmanNode &b);
    };
    
};

}

#endif