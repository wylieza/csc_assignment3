#include "HuffmanNode.h"

namespace WYLJUS002{


    //Default Constructor
    HuffmanNode::HuffmanNode(){   
        frequency = -1;
        letter = '\0';
        left = nullptr;
        right = nullptr;
    
    }

    HuffmanNode::HuffmanNode(int freq){
        HuffmanNode(freq, '\0');
    }

    HuffmanNode::HuffmanNode(int freq, char lett){ 
        frequency = freq;
        letter = lett;
        left = nullptr;
        right = nullptr;
    }

    //Move constructor
    HuffmanNode::HuffmanNode(HuffmanNode&& other){
        frequency = other.frequency;
        letter = other.letter;
        left = other.left;
        right = other.right;
    }

    //Copy constructor
    HuffmanNode::HuffmanNode(const HuffmanNode &other){
        frequency = other.frequency;
        letter = other.letter;
        left = other.left;
        right = other.right;

    }

    //Destructor
    HuffmanNode::~HuffmanNode(){
        //Nothing need be done here, using smart pointers
    }


    //Operator overloading

    //Copy assignment operator
    HuffmanNode& HuffmanNode::operator=(const HuffmanNode& other){
        frequency = other.frequency;
        letter = other.letter;
        left = other.left;
        right = other.right;
    }

    //Move assignment operator
    HuffmanNode HuffmanNode::operator=(HuffmanNode&& other){
        frequency = other.frequency;
        letter = other.letter;
        left = other.left;
        right = other.right;
    }


    bool HuffmanNode::operator<(HuffmanNode &noder){
        return this->frequency<noder.frequency;
    }

    bool HuffmanNode::operator>(HuffmanNode &noder){
        return this->frequency>noder.frequency;
    }

    //Traversal
    std::weak_ptr<HuffmanNode> HuffmanNode::get_left(){ //Consider returning weak ptr
        return std::weak_ptr<HuffmanNode>(left);
    }

    std::weak_ptr<HuffmanNode> HuffmanNode::get_right(){ //Consider returning weak ptr
        return std::weak_ptr<HuffmanNode>(right);
        
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
    }

    int HuffmanNode::get_frequency(){
        return frequency;
    }

    char HuffmanNode::get_letter(){
        return letter;
    }
}