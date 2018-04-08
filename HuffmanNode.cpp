/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   HuffmanNode.cpp
 * Author: Meluleki
 * 
 * Created on April 2, 2018, 4:38 PM
 */

#include "HuffmanNode.h"

using namespace DBXMEL004;
using namespace std;

/**
 * Default constructor of the HuffmanNode
 */
HuffmanNode::HuffmanNode():data('\0'){
    
}

/**
 * Copy Constructor for the class HuffmanNode
 * @param orig
 */
HuffmanNode::HuffmanNode(const HuffmanNode& orig) : data(orig.data), frequency_count(orig.frequency_count),
rightNode(orig.rightNode), leftNode(orig.leftNode) {

}
/**
 * Move constructor 
 * @param moveFrom
 */
HuffmanNode::HuffmanNode(HuffmanNode&& moveFrom) :
data(moveFrom.data), frequency_count(moveFrom.frequency_count), rightNode(moveFrom.rightNode), leftNode(moveFrom.leftNode) {
    moveFrom.data = 0;
    moveFrom.frequency_count = 0;
    moveFrom.leftNode.reset();
    moveFrom.rightNode.reset();
}

/**
 * Assignment operator
 * @param coyFrom
 * @return 
 */
HuffmanNode& HuffmanNode::operator=(const HuffmanNode& orig) {
    if (this != &orig) {
        data = orig.data;
        frequency_count = orig.frequency_count;
        rightNode.reset(orig.rightNode.get());
        leftNode.reset(orig.leftNode.get());
    }
}

/**
 * Move assignment function used on assignment
 * @param moveFrom reference u moving from
 * @return the new object
 */
HuffmanNode& HuffmanNode::operator=(HuffmanNode&& moveFrom) {
    //check if self assignment move
    if ((&moveFrom != this)) {
        data = moveFrom.data;
        frequency_count = moveFrom.frequency_count;
        leftNode.reset(moveFrom.leftNode.get());
        rightNode.reset(moveFrom.rightNode.get());
        moveFrom.data = 0;
        moveFrom.frequency_count = 0;
        moveFrom.leftNode.reset();
        moveFrom.rightNode.reset();
    }
    return *this;
}
/**
 * Destructor for the class HuffmanNode
 */
HuffmanNode::~HuffmanNode() {
    leftNode.reset();
    rightNode.reset();
}

/**
 * Method to compare two nodes.. Supposed to be moved
 * @param a first node we comparing
 * @param b second node for comparisons
 * @return if the frequency count for a is less than that of b
 */
//bool HuffmanNode::compare(const HuffmanNode& a, const HuffmanNode& b) {
//   
//}

/**
 * Overloading the operator to make sure that the < will compare the frequency counts
 * @param compare_to value being compared to
 * @return bool value to answer if the current frequency_count is less than the one we comparing to
 */
bool HuffmanNode::operator<(const HuffmanNode& a) const {
    return this->frequency_count> a.frequency_count;
}

bool HuffmanNode::operator!() const{
    bool checkdata=(data=='\0');
    bool checknodes=((!rightNode.get())&&(!leftNode.get()));
    return checkdata &&checknodes;
}
