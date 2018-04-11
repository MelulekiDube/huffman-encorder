/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "HuffmanNode.h"
#include <fstream>
#include <iostream>
#include <bitset>
using namespace std;
using namespace DBXMEL004;

/**
 * generates the frequency table which is basically the unordermap
 */

void HuffmanEncoding::generate_frequency_table(std::string ifname, std::string ofname) {
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

void HuffmanEncoding::insert_to_queue() {
    for (const auto & pair : char_map) {
        HuffmanNode tempNode(pair.first, pair.second);
        tree_queue.push(tempNode);
    }
    compute_codes(t.build(tree_queue), 0);
    for(const auto it:codedmap){
        cout<<it.first<<" "<<std::bitset<4>(it.second)<<endl;
    }
}

void HuffmanEncoding::compute_codes(const std::shared_ptr<HuffmanNode>& root, int a) {
    if (!root.get()) return;
    if ((*root).data != '\0') { // this is the leaf which is the las node containing data
        pair<char, int> temp(root->data, a);
        codedmap.insert(temp);
    }
    a<<=1;
    compute_codes(root->leftNode, a+0);
    compute_codes(root->rightNode, a+1);
    
}
