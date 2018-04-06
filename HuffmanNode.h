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
        char data; // character of that the node represents
        int frequencey_count; // the frequency count of the current char
        std::shared_ptr<HuffmanNode> rightNode, leftNode;
    };

    struct Compare : public std::binary_function<HuffmanNode, HuffmanNode, bool> {

        bool compare(const HuffmanNode& a, const HuffmanNode& b) {
            return a < b;
        }
    };
    

};
#endif /* HUFFMANNODE_H */

