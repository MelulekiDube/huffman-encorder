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

/**
 * generates the frequency table which is basically the unordermap
 */
void HuffmanTree::generate_frequency_table(std::string ifname, std::string ofname) {
    ifstream infile;
    infile.open(ifname);

    unsigned char tempchar;
    /**
     * Read every charecter and add it to the unordered map
     */
    infile>>tempchar;
    while (!infile.eof()) {
        auto result = char_map.find(tempchar);
        if (result != char_map.end()) {
            int old_value = result->second;
            char_map[tempchar] = ++old_value;
        } else {
            //there is already a result
            char_map.insert(make_pair<char, int>(tempchar, 1));
        }
        infile>>tempchar;
    }
    infile.close();
}

void HuffmanTree::insert() {
    for (const auto & pair : char_map) {
        HuffmanNode tempNode(pair.first, pair.second);
        tree_queue.push(tempNode);
    }
}

std::shared_ptr<HuffmanNode>& HuffmanTree::build() {
    while (tree_queue.size() > 1) {
        HuffmanNode top;
        top.leftNode = make_shared<HuffmanNode>(tree_queue.top());
        tree_queue.pop();
        top.rightNode = make_shared<HuffmanNode>(tree_queue.top());
        tree_queue.pop();
        top.frequency_count = (top.leftNode->frequency_count)+(top.rightNode->frequency_count);
        tree_queue.push(top);
    }
    root = make_shared<HuffmanNode>(tree_queue.top());
    printcodes(root, "");
    return root;
}

void HuffmanTree::printcodes(const shared_ptr<HuffmanNode> &root, string str) {
    if (root.get() == nullptr) return;
    if ((*root).data != '\0') { // this is the leaf which is the las node containing data
        cout << (*root).data << " " << str << endl;
    }
    printcodes(root->leftNode, str + "0");
    printcodes(root->rightNode, str + "1");
}
//      