//Imports


#include "HuffmanTree.h"


//Functions


int main(int argc, char *argv[]){

    if (argc != 3){
        std::cout << "Invalid number of arguments!\n";
        exit(0);
    }
    
    std::string inputfile(argv[1]);
    std::string outputfile(argv[2]);

    WYLJUS002::HuffmanTree tree;

    tree.data_from_file(inputfile);
    tree.generate_freq_map();
    tree.populate_tree();
    tree.build_codetable();
    tree.compress_data();
    tree.write_to_file(outputfile);
    tree.decompress_data();

}