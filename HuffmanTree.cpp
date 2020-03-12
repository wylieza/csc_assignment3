#include "HuffmanTree.h"

namespace WYLJUS002{

    //Constructor
    HuffmanTree::HuffmanTree(){

    }


    //Tree construction
    void HuffmanTree::generate_tree(){
        generate_freq_map();
        populate_tree();
        determine_codetable();
        compress_data();

    }


    void HuffmanTree::generate_tree(std::string fname){
        data_from_file(fname);
        generate_tree();
    }


    void HuffmanTree::data_from_file(std::string fname){
        std::ifstream file(fname);
        std::stringstream strs;
        std::string line;

        if(file){
            while(getline(file, line)){
                strs << line << std::endl;
            }
            data = strs.str(); //TODO -> Remove the last \n from this data

        }else{
            std::cout << "An error occured while trying to open file!";
        }
    }


    void HuffmanTree::generate_freq_map(){
        for (int i = 0; i < data.length(); i++){
            frequencies[(char) data[i]] += 1;
            std::cout << "Letter: " << (char) data[i] << " freq of: " << frequencies[(char) data[i]] << std::endl;
        }
        
    }

    void HuffmanTree::populate_tree(){


    }


    void HuffmanTree::determine_codetable(){
        
    }


    void HuffmanTree::compress_data(){
        
    }








}