/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   HuffmanNode.h
 * Author: Meluleki
 *
 * Created on April 2, 2018, 4:38 PM
 */

#ifndef HUFFMANNODE_H
#define HUFFMANNODE_H

#include <cstdlib>
#include <memory>
#include <queue>
#include <unordered_map>
#include <iterator>

namespace DBXMEL004 {

    class HuffmanNode {
    public:
        HuffmanNode(); // Default constructor 
        HuffmanNode(const char& d, const int & fc);
        HuffmanNode(const HuffmanNode& orig); // Copy constructor
        HuffmanNode(HuffmanNode && moveFrom); // move constructor
        HuffmanNode& operator=(const HuffmanNode& coyFrom); //Assignment operator
        HuffmanNode& operator=(HuffmanNode&& moveFrom); //move assignment
        ~HuffmanNode(); //Destructor 
        //        //to be moved
        bool operator<(const HuffmanNode& a) const;
        bool operator!()const;
        char data; // character of that the node represents
        int frequency_count; // the frequency count of the current char
        std::shared_ptr<HuffmanNode> rightNode;
        std::shared_ptr<HuffmanNode> leftNode;
    };

    struct comparator : public std::binary_function<HuffmanNode, HuffmanNode, bool> {

        bool operator()(const HuffmanNode& a, const HuffmanNode& b) {
            return a < b;
        }
    };

    typedef std::pair<char, int> mypair;

    class HuffmanTree {
    public:
        HuffmanTree();
        ~HuffmanTree();
        void generate_frequency_table(std::string ifname, std::string ofname);
        void insert(void);
        void printcodes(const std::shared_ptr<HuffmanNode>& root, std::string str);
        std::shared_ptr<HuffmanNode>& build();


        std::priority_queue <HuffmanNode, std::vector<HuffmanNode>, comparator> tree_queue;
        std::unordered_map<char, int> char_map;
        std::shared_ptr<HuffmanNode> root;
    };
};
#endif /* HUFFMANNODE_H */

