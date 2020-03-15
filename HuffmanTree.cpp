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
        build_codetable();
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
            data = strs.str();
            data = data.substr(0, data.length()-1); //Remove the last \n

        }else{
            std::cout << "An error occured while trying to open file!";
        }
    }


    void HuffmanTree::generate_freq_map(){
        for (int i = 0; i < data.length(); i++){
            frequencies[(char) data[i]] += 1;
            //std::cout << "Letter: " << (char) data[i] << " freq of: " << frequencies[(char) data[i]] << std::endl;
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
        //Smallet node is the left child
        while(node_pqueue.size() > 1){ //At least two nodes left
            HuffmanNode n;

            HuffmanTree::root->set_left(std::make_shared<HuffmanNode>(node_pqueue.top()));
            node_pqueue.pop();
            //std::cout << "Left freq: " << root->get_left().lock()->get_frequency() << std::endl;

            HuffmanTree::root->set_right(std::make_shared<HuffmanNode>(node_pqueue.top()));
            node_pqueue.pop();
            //std::cout << "Right freq: " << root->get_right().lock()->get_frequency() << std::endl;

            root->set_frequency(root->get_left().lock()->get_frequency() + root->get_right().lock()->get_frequency());

            if(node_pqueue.size() > 0){
                node_pqueue.push(*root);
            }
        }
    }

    void HuffmanTree::build_codetable(){
        std::string code;

        build_codetable(root, code);
    }


    void HuffmanTree::build_codetable(const std::shared_ptr<HuffmanNode> &node, std::string code){
        if(node->get_letter() == '\0'){
            code.push_back('0');
            build_codetable(node->get_left().lock(), code);
        }else{
            codetbl[(char) node->get_letter()] = code;
            std::cout << "letter: >" << node->get_letter() << "< frequency: " << frequencies[node->get_letter()] << " code: " << code << "<---\n";
        }
        if(node->get_letter() == '\0'){
            code[code.length()-1] = '1';
            build_codetable(node->get_right().lock(), code);
        }
        
    }

    void HuffmanTree::compress_data(){
        std::stringstream cdstream;
        for(auto dat : data){
            cdstream << codetbl[dat];
        }
        std::cout << "Compressed stream >" << cdstream.str() << "< done\n";
    }

    void HuffmanTree::decompress_data(){
        int index = 0;
        std::string temp = compressed_data;

        //Create a decodetbl
        

        while(temp.size() > 0){
            if(codetbl.find(temp.substr(0, index)) == codetbl.end()){

            }
        }
    }

    bool HuffmanTree::compare::operator()(HuffmanNode &a, HuffmanNode &b){
        //std::cout << "comparing: " << a.get_frequency() << " > " << b.get_frequency() << std::endl;
        //return a.get_frequency() > b.get_frequency();
        return a > b;
    }







}