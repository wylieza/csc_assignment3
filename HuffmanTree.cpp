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

    std::string HuffmanTree::get_data(){
        return this->data;
    }


    void HuffmanTree::generate_freq_map(){
        for (int i = 0; i < data.length(); i++){
            frequencies[(char) data[i]] += 1;
            //std::cout << "Letter: " << (char) data[i] << " freq of: " << frequencies[(char) data[i]] << std::endl;
        }
        
    }

    std::unordered_map<char, int> HuffmanTree::get_fmap(){
        return frequencies;
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
        compressed_data = cdstream.str();
        int uncompressed_size = data.length();
        int compressed_size = data.length()/8 + (data.length()%8? 1:0);
        std::cout << "\n>>> Data compression statistics <<<\nOriginal Data Size: " << uncompressed_size << " bytes\n";
        std::cout << "Compressed Data Size: " << compressed_size << " bytes\n";
        std::cout << "Compression Ratio: " << (double) compressed_size/ (double) uncompressed_size << std::endl << std::endl;

    }


    void HuffmanTree::write_to_file(std::string fname){
        std::ofstream ofile;

        //save compressed data
        ofile.open(fname);
        if(ofile){
            ofile << compressed_data;
            ofile.close();
        }else{
            std::cout << "An error occured during file write out!\n";
        }

        //save code table
        std::stringstream hdrfname;
        if(fname.find('.') != std::string::npos){
            hdrfname << fname.substr(0, fname.find('.')) << ".hdr";
        }else{
            hdrfname << fname << ".hdr";
        }
        ofile.open(hdrfname.str());
        if(ofile){
            for(auto lcitem : codetbl){
                if (lcitem.first == '\n'){
                    ofile << "Letter: \\n" << " - Code: " << lcitem.second << std::endl;
                }else{
                    ofile << "Letter: " << lcitem.first << "  - Code: " << lcitem.second << std::endl;
                }
            }
            ofile.close();
        }else{
            std::cout << "An error occured during file write out!\n";
        }
    }


    void HuffmanTree::write_to_binary_file(std::string fname){
        
    }


    void HuffmanTree::read_from_binary_file(std::string fname){
        
    }


    void HuffmanTree::decompress_data(){ //Easter egg functionality - not required!
        int index = 1;
        std::string temp = compressed_data;
        std::string decoded = "";

        //Create a decodetbl
        std::unordered_map<std::string, char> decodetbl;
        for(auto lcitem : codetbl){
            decodetbl[lcitem.second] = lcitem.first;
        }

        //debug stats
        int last;

        //Match up codes to letters
        while(temp.length() > 0){
            if(decodetbl.find(temp.substr(0, index)) != decodetbl.end()){
                decoded.push_back(decodetbl[temp.substr(0, index)]);
                temp = temp.substr(index, temp.length());
                index = 1;
            }else{
                index++;
            }
        }

        //std::cout << "Message >" << decoded << "< end \n";
    }

    bool HuffmanTree::compare::operator()(HuffmanNode &a, HuffmanNode &b){
        return a > b;
    }







}