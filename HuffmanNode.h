#ifndef HUFFMANNODE
#define HUFFMANNODE

#include <memory> //Req. for sharedptr
#include <iostream> //Couting

namespace WYLJUS002{

class HuffmanTree;

class HuffmanNode{
    friend HuffmanTree;

    private:

    std::shared_ptr<HuffmanNode> left;
    std::shared_ptr<HuffmanNode> right;
    char letter;
    int frequency;


    public:

    //Constructors

    HuffmanNode();
    HuffmanNode(int freq);
    HuffmanNode(int freq, char lett);

    //CC
    HuffmanNode(const HuffmanNode &node);

    //Move constructor
    HuffmanNode(HuffmanNode&& other);

    //Destructor
    ~HuffmanNode();

    //Operator overloading
    
    //Move assignment
    HuffmanNode operator=(HuffmanNode&& other);


    //Copy assignment
    HuffmanNode& operator=(const HuffmanNode& other);

    bool operator<(HuffmanNode &noder);
    bool operator>(HuffmanNode &noder);

    //Utility functions

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