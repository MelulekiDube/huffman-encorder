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
    insert();
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
    if(tree_queue.size()==1){
        return;
    }else{
        HuffmanNode temp1=tree_queue.top(); tree_queue.pop();
        HuffmanNode temp2 = tree_queue.top(); tree_queue.pop();
        compute(temp1, temp2);
    }
}

HuffmanNode& HuffmanTree::compute(HuffmanNode& lhs, HuffmanNode rhs) {
    HuffmanNode temp;
    temp.frequency_count=lhs.frequency_count+rhs.frequency_count;
    temp.data='0';
    tree_queue.push(temp);
    build();
}
