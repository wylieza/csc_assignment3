#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "HuffmanTree.h"
#include "HuffmanNode.h"


TEST_CASE("Frequency Map Generation", "[generate_freq_map]"){
    WYLJUS002::HuffmanTree tree;

    std::string filename = "testdatafile.txt";
    std::ofstream file(filename);
    file << "This is a test string";
    file.close();

    REQUIRE(1);
}

TEST_CASE("Compare (>) Operator Overload", "[>]"){
    REQUIRE(1);
}

TEST_CASE("Compare (<) Operator Overload", "[<]"){
    REQUIRE(1);
}

TEST_CASE("Compare Function", "[compare]"){
    REQUIRE(1);
}

TEST_CASE("Tree Population", "[populate_tree]"){
    REQUIRE(1);
}


TEST_CASE("Tree Destruction", "[populate_tree]"){
    REQUIRE(1); //Get a weak ptr to a leaf node, nullptr the root and then try access the leaf..
}

TEST_CASE("Code Table Generation", "[determine_codetable]"){
    REQUIRE(1);
}

TEST_CASE("Data Compression", "[compress_data]"){
    REQUIRE(1);
}

