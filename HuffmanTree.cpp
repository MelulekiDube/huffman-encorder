/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "HuffmanNode.h"
#include <fstream>
#include <iostream>
#include <unordered_map>
using namespace std;
using namespace DBXMEL004;

HuffmanTree::HuffmanTree(std::string ifname, std::string ofname)
: infile_name(ifname), outfile_name(ofname) {

}

void HuffmanTree::generate_frequency_table() {
    ifstream infile;
    infile.open(infile_name);

    unsigned char tempchar;
    while (!infile.eof()) {
        infile>>tempchar;
        auto result = char_map.find (tempchar);
        if(result==char_map.end()){
            //no result is found that is the key is unique
             char_map.insert(make_pair<char, int>(tempchar, 1));
        }else{
           //there is already a result
            int old_value= result->second;
            
        }
    }

}