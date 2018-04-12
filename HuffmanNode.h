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
#include <bitset>

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
    typedef std::bitset<8> byte;
    typedef std::pair<char, int> mypair;
    typedef std::priority_queue <HuffmanNode, std::vector<HuffmanNode>, comparator> maxheap;
    typedef std::unordered_map<char, int> code_map;

    typedef struct {
        char data;
        int coded_char;
        int bit_length;
    } code_for_char;

    class HuffmanTree {
    public:
        std::shared_ptr<HuffmanNode> root;
        HuffmanTree();
        ~HuffmanTree();
        std::shared_ptr<HuffmanNode>& build(maxheap tree);
    };

    class HuffmanEncoding {
    public:
        maxheap tree_queue;
        std::vector<code_for_char> codedmap;
        code_map char_map;
        HuffmanTree t;
        int w8_bits = 8;
        int Bit_mask = (1 << w8_bits) - 1;
        void generate_frequency_table(std::string ifname, std::string ofname);
        void insert_to_queue(void);
        void compute_codes(const std::shared_ptr<HuffmanNode>& root, int code, int bits);
        void encode(std::string ifname, std::string ofname);
        void decode(std::string ifname, std::string ofname);
        void write_to_file(byte* arr, const std::string& offname);
        void write_codes_tofile(std::string fileName);
        int getIndex(const char & dat);
        void encode_str(std::string s);
        void compress(std::string inname, std::string ofname);
    };
};
#endif /* HUFFMANNODE_H */

