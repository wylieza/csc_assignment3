#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "HuffmanTree.h"
#include "HuffmanNode.h"

TEST_CASE("Read in data", "[data_from_file]"){
    WYLJUS002::HuffmanTree tree;

    std::string filename = "testdatafile.txt";
    std::string dataforfile = "the cat sat on the mat";
    std::ofstream file(filename);
    file << dataforfile;
    file.close();

    tree.data_from_file(filename);
    
    REQUIRE(dataforfile.compare(tree.get_data()) == 0);
}

TEST_CASE("Frequency Map Generation", "[generate_freq_map]"){
    WYLJUS002::HuffmanTree tree;

    std::string filename = "testdatafile.txt";
    std::string dataforfile = "the cat sat on the mat";
    std::ofstream file(filename);
    file << dataforfile;
    file.close();

    tree.data_from_file(filename);
    tree.generate_freq_map();
    std::unordered_map<char, int> freq = tree.get_fmap();

    REQUIRE(freq['t'] == 5);
    REQUIRE(freq[' '] == 5);
    REQUIRE(freq['a'] == 3);
    REQUIRE(freq['c'] == 1);
    REQUIRE(freq['x'] == 0);
}

TEST_CASE("Comparison", "[> and < and compare()]"){
    WYLJUS002::HuffmanTree tree;
    WYLJUS002::HuffmanNode nodea(5);
    WYLJUS002::HuffmanNode nodeb(1, 'c');
    WYLJUS002::HuffmanNode nodec(1, 'n');

    SECTION("> Operator"){
        REQUIRE(!(nodea > nodeb));
        REQUIRE(!(nodeb > nodec));
        REQUIRE((nodeb > nodea));
    }    
    
    SECTION("< Operator"){
        REQUIRE((nodea < nodeb));
        REQUIRE(!(nodeb < nodec));
        REQUIRE(!(nodeb < nodea));
    } 

    SECTION("Compare()"){
        REQUIRE(!tree.compare(nodea,nodeb));
        REQUIRE(!tree.compare(nodeb,nodec));
        REQUIRE(tree.compare(nodeb,nodea));
    } 

}

TEST_CASE("Tree Population", "[populate_tree]"){
    REQUIRE(0);
}


TEST_CASE("Tree Destruction", "[populate_tree]"){
    REQUIRE(0); //Get a weak ptr to a leaf node, nullptr the root and then try access the leaf..
}

TEST_CASE("Code Table Generation", "[determine_codetable]"){
    REQUIRE(0);
}

TEST_CASE("Data Compression", "[compress_data]"){
    REQUIRE(0);
}

