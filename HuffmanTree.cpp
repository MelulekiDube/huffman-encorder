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

HuffmanTree::HuffmanTree(std::string ifname, std::string ofname)
: infile_name(ifname), outfile_name(ofname) {

}

/**
 * generates the frequency table which is basically the unordermap
 */
void HuffmanTree::generate_frequency_table() {
    ifstream infile;
    infile.open(infile_name);

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
        HuffmanNode tempHuff;
        tempHuff.frequency_count = pair.second;
        tempHuff.data = pair.first;
        tree_queue.push(tempHuff);
    }
}

void HuffmanTree::build() {
    while (tree_queue.size() > 1) {

        //         Extract the two minimum
        // freq items from min heap
        HuffmanNode top;
        top.leftNode = make_shared<HuffmanNode>(tree_queue.top());
        tree_queue.pop();
        top.rightNode = make_shared<HuffmanNode>(tree_queue.top());
        tree_queue.pop();
        // 
        top.frequency_count = (*top.leftNode).frequency_count + (*top.leftNode).frequency_count;
        cout << tree_queue.top().leftNode;
        tree_queue.push(top);
    }
    printcodes(tree_queue.top(), "");
}

void HuffmanTree::printcodes(const HuffmanNode& root, string str) {
    if (!root) return;
    if (root.data != 0) cout << root.data << str << endl;
    HuffmanNode& lnode = *root.leftNode;
    HuffmanNode& rnode = *root.rightNode;
    printcodes(lnode, str += '0');
    printcodes(rnode, str += '1');
}
//  