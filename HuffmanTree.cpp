#include "HuffmanTree.h"
#include "HuffmanNode.h"

namespace WYLJUS002{

    //Constructor
    HuffmanTree::HuffmanTree(){
        HuffmanNode rootn;
        root = std::make_shared<HuffmanNode>(rootn);
    }

    //Destructor
    HuffmanTree::~HuffmanTree(){
        root = nullptr;
    }


    //Tree construction
    void HuffmanTree::generate_tree(){
        generate_freq_map();
        populate_tree();
        determine_codetable();
        compress_data();

    }


    void HuffmanTree::generate_tree(std::string fname){
        data_from_file(fname);
        generate_tree();
    }


    void HuffmanTree::data_from_file(std::string fname){
        std::ifstream file(fname);
        std::stringstream strs;
        std::string line;

        if(file){
            while(getline(file, line)){
                strs << line << std::endl;
            }
            data = strs.str(); //TODO -> Remove the last \n from this data

        }else{
            std::cout << "An error occured while trying to open file!";
        }
    }


    void HuffmanTree::generate_freq_map(){
        for (int i = 0; i < data.length(); i++){
            frequencies[(char) data[i]] += 1;
            std::cout << "Letter: " << (char) data[i] << " freq of: " << frequencies[(char) data[i]] << std::endl;
        }
        
    }


    void HuffmanTree::populate_tree(){
        std::priority_queue<HuffmanNode, std::vector<HuffmanNode>, HuffmanTree::compare> node_pqueue;

        //Load up all frequency-letter pairs into priority queue of nodes
        for(auto lfitem : frequencies){
            HuffmanNode n(lfitem.second, lfitem.first); //(frequency, letter)
            node_pqueue.push(n);
        }

        //Pop all the prioritised nodes in order to build up the tree (From bottom up...)
        while(node_pqueue.size() > 1){ //At least two nodes left
            HuffmanNode n;

            HuffmanTree::root->set_left(std::make_shared<HuffmanNode>(node_pqueue.top()));
            node_pqueue.pop();

            HuffmanTree::root->set_right(std::make_shared<HuffmanNode>(node_pqueue.top()));
            node_pqueue.pop();

            root->set_frequency(root->get_left().lock()->get_frequency() + root->get_right().lock()->get_frequency());

            if(node_pqueue.size() > 0){
                node_pqueue.push(*root);
            }
        }

    }


    void HuffmanTree::determine_codetable(){
        
    }


    void HuffmanTree::compress_data(){
        
    }

    bool HuffmanTree::compare::operator()(HuffmanNode &a, HuffmanNode &b){
        return &a < &b;
    }








}