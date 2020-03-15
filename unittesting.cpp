#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "HuffmanTree.h"
#include "HuffmanNode.h"
#include <cstdio>

TEST_CASE("Read in data", "[data_from_file]"){
    WYLJUS002::HuffmanTree tree;

    std::string filename = "testdatafile.txt";
    std::string dataforfile = "the cat sat on the mat";
    std::ofstream file(filename);
    file << dataforfile;
    file.close();

    tree.data_from_file(filename);

    std::remove(filename.c_str());
    
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

    std::remove(filename.c_str());

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
        REQUIRE(nodea > nodeb);
        REQUIRE(!(nodeb > nodec));
        REQUIRE(!(nodeb > nodea));
    }    
    
    SECTION("< Operator"){
        REQUIRE(!(nodea < nodeb));
        REQUIRE(!(nodeb < nodec));
        REQUIRE(nodeb < nodea);
    } 

    SECTION("Compare()"){
        WYLJUS002::HuffmanTree::compare cmp;
        REQUIRE(cmp(nodea,nodeb));
        REQUIRE(!cmp(nodeb,nodec));
        REQUIRE(!cmp(nodeb,nodea));
    } 
}

TEST_CASE("Tree Population", "[populate_tree]"){
    WYLJUS002::HuffmanTree tree;

    std::string filename = "testdatafile.txt";
    std::string dataforfile = "the cat sat on the mat";
    std::ofstream file(filename);
    file << dataforfile;
    file.close();

    tree.generate_tree(filename);

    std::remove(filename.c_str());
    
    REQUIRE(tree.get_root()->get_frequency() == 22);
    REQUIRE(tree.get_root()->get_letter() == '\0');

    REQUIRE(tree.get_root()->get_left().lock()->get_left().lock()->get_left().lock()->get_left().lock()->get_frequency() == 1);
    REQUIRE(tree.get_root()->get_left().lock()->get_left().lock()->get_left().lock()->get_left().lock()->get_letter() == 'm');

    REQUIRE(tree.get_root()->get_right().lock()->get_right().lock()->get_right().lock()->get_right().lock()->get_frequency() == 2);
    REQUIRE(tree.get_root()->get_right().lock()->get_right().lock()->get_right().lock()->get_right().lock()->get_letter() == 'e');
}


TEST_CASE("Tree Destruction", "[populate_tree]"){ //Memory cleanup and tree collapse

    std::weak_ptr<WYLJUS002::HuffmanNode> wptr;
    if(1){
        WYLJUS002::HuffmanTree tree;

        std::string filename = "testdatafile.txt";
        std::string dataforfile = "the cat sat on the mat";
        std::ofstream file(filename);
        file << dataforfile;
        file.close();

        tree.generate_tree(filename);

        std::remove(filename.c_str());

        wptr = tree.get_root()->get_left().lock()->get_left().lock()->get_left().lock()->get_left();
        REQUIRE(!wptr.expired());

    }
    REQUIRE(wptr.expired());

    

}

TEST_CASE("Code Table Generation", "[determine_codetable]"){
    WYLJUS002::HuffmanTree tree;

    std::string filename = "testdatafile.txt";
    std::string dataforfile = "the cat sat on the mat";
    std::ofstream file(filename);
    file << dataforfile;
    file.close();

    tree.generate_tree(filename);
    tree.build_codetable();

    std::unordered_map<char, std::string> ctbl = tree.get_ctbl();

    std::remove(filename.c_str());

    REQUIRE(ctbl['m'].compare("0000") == 0);
    REQUIRE(ctbl['o'].compare("0001") == 0);
    REQUIRE(ctbl['e'].compare("1111") == 0);
    REQUIRE(ctbl[' '].compare("10") == 0);
    REQUIRE(ctbl['t'].compare("01") == 0);
}

TEST_CASE("Data Compression", "[compress_data]"){
    WYLJUS002::HuffmanTree tree;

    std::string filename = "testdatafile.txt";
    std::string dataforfile = "aaaaabbbc";
    std::ofstream file(filename);
    file << dataforfile;
    file.close();

    tree.generate_tree(filename);
    tree.build_codetable();
    tree.compress_data();

    std::remove(filename.c_str());

    REQUIRE(tree.get_cdata().compare("1111101010100") == 0);
}

