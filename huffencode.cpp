//Imports


#include "HuffmanTree.h"


//Functions


int main(int argc, char *argv){

    WYLJUS002::HuffmanTree tree;

    tree.data_from_file("testdata.txt");
    tree.generate_freq_map();
    tree.populate_tree();
    tree.build_codetable();

}