#include "HuffmanNode.h"

namespace WYLJUS002{


    //Default Constructor
    HuffmanNode::HuffmanNode(){
        //std::cout << "Default constructor called\n";        
        frequency = -1;
        letter = '\0';
        left = nullptr;
        right = nullptr;
    
    }


    HuffmanNode::HuffmanNode(int freq){
        HuffmanNode(freq, '\0');
    }

    HuffmanNode::HuffmanNode(int freq, char lett){
        //std::cout << "Non-default constructor called\n"; 
        frequency = freq;
        letter = lett;
        left = nullptr;
        right = nullptr;
    }

    //Move constructor



    //Copy constructor
    HuffmanNode::HuffmanNode(const HuffmanNode &node){
        //std::cout << "Copy constructor called\n"; 
        this->frequency = node.frequency;
        this->letter = node.letter;
        this->left = node.left;
        this->right = node.right;

    }



    //Destructor
    HuffmanNode::~HuffmanNode(){
        //Should I set left and right to nullptrs?
    }



    //Copy assignment operator



    //Move assignment operator


    //Operator overloading

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