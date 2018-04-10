/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "HuffmanNode.h"
#include <fstream>
#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <valarray>

using namespace std;
using namespace DBXMEL004;

HuffmanTree::HuffmanTree() {
}

HuffmanTree::~HuffmanTree() {
    
}

std::shared_ptr<HuffmanNode>& HuffmanTree::build(maxheap heap) {
    while (heap.size() > 1) {
        HuffmanNode top;
        top.leftNode = make_shared<HuffmanNode>(heap.top());
        heap.pop();
        top.rightNode = make_shared<HuffmanNode>(heap.top());
        heap.pop();
        top.frequency_count = (top.leftNode->frequency_count)+(top.rightNode->frequency_count);
        heap.push(top);
    }
    root = make_shared<HuffmanNode>(heap.top());
    return root;
}
//      