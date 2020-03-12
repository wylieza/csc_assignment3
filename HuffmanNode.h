#ifndef HUFFMANNODE
#define HUFFMANNODE

#include <memory> //Req. for sharedptr

namespace WYLJUS002{

class HuffmanTree;

class HuffmanNode{
    friend HuffmanTree;

    private:

    std::shared_ptr<HuffmanNode> left;
    std::shared_ptr<HuffmanNode> right;

    bool internal;
    char letter;
    int frequency;
    std::string code;


    public:

    HuffmanNode();
    HuffmanNode(int freq);
    HuffmanNode(int freq, char lett);

    std::weak_ptr<HuffmanNode> get_left();

    std::weak_ptr<HuffmanNode> get_right();

    void set_left(std::shared_ptr<HuffmanNode> left);

    void set_right(std::shared_ptr<HuffmanNode> right);

    void set_frequency(int freq);

    void set_letter(char lett);

    int get_frequency();

    char get_letter();

};
}

#endif