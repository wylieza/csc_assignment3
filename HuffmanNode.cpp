#include "HuffmanNode.h"

namespace WYLJUS002{

    //Default Constructor
    HuffmanNode::HuffmanNode(){
        internal = true;
        frequency = -1;
        letter = '\0';
        left = nullptr;
        right = nullptr;
    }

    HuffmanNode::HuffmanNode(int freq){
        internal = true;
        frequency = freq;
        left = nullptr;
        right = nullptr;
    }

    HuffmanNode::HuffmanNode(int freq, char lett){
        internal = false;
        frequency = freq;
        letter = lett;
        left = nullptr;
        right = nullptr;
    }

    //Move constructor



    //Copy constructor



    //Destructor




    //Copy assignment operator



    //Move assignment operator



    //Traversal
    std::shared_ptr<HuffmanNode> HuffmanNode::get_left(){ //Consider returning weak ptr
        return std::make_shared<HuffmanNode>(HuffmanNode::left);
    }

    std::shared_ptr<HuffmanNode> HuffmanNode::get_right(){ //Consider returning weak ptr
        return std::make_shared<HuffmanNode>(HuffmanNode::right);
        
    }


    //Getters and Setters
    void HuffmanNode::set_left(std::shared_ptr<HuffmanNode> left){
        this->left = left;
    }

    void HuffmanNode::set_right(std::shared_ptr<HuffmanNode> right){
        this->right = right;
    }

    void HuffmanNode::set_frequency(int freq){
        frequency = freq;
    }

    void HuffmanNode::set_letter(char lett){
        letter = lett;
        internal = false;
    }

    int HuffmanNode::get_frequency(){
        return frequency;
    }

    char HuffmanNode::get_letter(){
        return letter;
    }
}