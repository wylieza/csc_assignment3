#ifndef HUFFMANTREE
#define HUFFMANTREE

#include <fstream> //File reading
#include <sstream> //String stream
#include <iostream> //cout function
#include <unordered_map> //Unordered map - freq counter
#include <memory>
#include <queue> //Priority queue
#include <bitset> //For printing binary

namespace WYLJUS002{

class HuffmanNode;

class HuffmanTree{
    private:
    std::shared_ptr<HuffmanNode> root = nullptr;
    std::string data;
    std::string compressed_data;
    std::string raw_in_cdata;
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
    std::shared_ptr<HuffmanNode> get_root(); //UNITTESTING
    void build_codetable();
    void build_codetable(const std::shared_ptr<HuffmanNode> &node, std::string code); //Assign the nodes with huffman codes
    std::unordered_map<char, std::string> get_ctbl(); //UNITTESTING
    void compress_data(); //Compress the data
    std::string get_cdata(); //UNITTESTING
    void write_to_file(std::string fname); //Writes the message to file and writes the code table to file
    void write_to_binary_file(std::string fname); //Writes the message in compressed bidanry form
    void read_from_binary_file(std::string fname); //Reads in the data from the binary file
    std::string get_binary_fdata(); //UNITTESTING
    //void decompress_data(); //Bonus functionality, not required

    struct compare{
        bool operator()(HuffmanNode &a, HuffmanNode &b);
    };
    
};

}

#endif