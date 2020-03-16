#include "HuffmanTree.h"

int main(int argc, char *argv[]){

    if (argc != 3){
        std::cout << "Invalid number of arguments!\n";
        exit(0);
    }

    std::string inputfile(argv[1]);
    std::string outputfile(argv[2]);

    WYLJUS002::HuffmanTree tree;

    tree.generate_tree(inputfile);

    tree.build_codetable();
    tree.compress_data();

    tree.write_to_file(outputfile);
    tree.write_to_binary_file(outputfile);

    tree.read_from_binary_file(outputfile);

    //tree.decompress_data(); //Bonus feature, not required

}