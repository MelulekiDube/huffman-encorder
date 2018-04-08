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
        /**
         * needs buid
         * compress
         */
        HuffmanTree(std::string ifname, std::string ofname);
        void generate_frequency_table(void);
        void insert(void);
        void build(void);
        void compute(HuffmanNode &lhs, HuffmanNode &rhs);
        std::priority_queue <HuffmanNode, std::vector<HuffmanNode>, comparator> tree_queue;
        void printcodes(const HuffmanNode &lhs, std::string str);
        std::string infile_name, outfile_name;
        std::unordered_map<char, uint32_t> char_map;
    };
};
#endif /* HUFFMANNODE_H */

