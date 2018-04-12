/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "HuffmanNode.h"
#include "catch.hpp"
#include <fstream>
#include <sstream>
#include <iostream>
#include <cstddef>
#include <algorithm>

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
    tempchar = (unsigned char) infile.get();
    while (!infile.eof()) {
        auto result = char_map.find(tempchar);
        if (result != char_map.end()) {
            int old_value = result->second;
            char_map[tempchar] = ++old_value;
        } else {
            //there is already a result
            char_map.insert(make_pair<char, int>(tempchar, 1));
        }
        char_map.insert(make_pair<char, int>('\0', 1));
        tempchar = (unsigned char) infile.get();
    }
    infile.close();
    insert_to_queue();
    write_codes_tofile(ofname);
}

void HuffmanEncoding::insert_to_queue() {
    for (const auto & pair : char_map) {
        HuffmanNode tempNode(pair.first, pair.second);
        tree_queue.push(tempNode);
    }
    compute_codes(t.build(tree_queue), 0, 0);
    //    compress();
}

void HuffmanEncoding::compute_codes(const std::shared_ptr<HuffmanNode>& root, int code, int bits) {
    if (!root.get()) return;
    if ((*root).data != -1) { // this is the leaf which is the las node containing data
        code_for_char temp = {root->data, code, bits};
        codedmap.push_back(temp);
    }
    code <<= 1;
    compute_codes(root->leftNode, code, bits + 1);
    compute_codes(root->rightNode, code + 1, bits + 1);

}

void HuffmanEncoding::encode(std::string ifname, std::string ofname) {
    char char_to_encode;
    int file_size;
    ifstream inputfile(ifname);
    byte byte_array[1024];
    int array_index = 0;
    int bit_indx = 0;
    byte_array[array_index] = 0;
    //    char_to_encode=inputfile.get();
    while (!inputfile.eof()) {
        char_to_encode = inputfile.get();
        int index = getIndex(char_to_encode);
        int bits_left = codedmap[index].bit_length;
        int charcode = codedmap[index].coded_char;
        while (bits_left > 0) {
            int coded_init = (charcode << bit_indx) & Bit_mask;
            byte_array[array_index] |= coded_init;
            int bits_added = min(bits_left, (w8_bits - bit_indx));
            bits_left -= bits_added;
            charcode >>= bits_added;
            bit_indx += bits_added;
            file_size += bits_added;
            if (bit_indx == w8_bits) {
                array_index += 1;
                if (array_index >= 1024) {
                    array_index %= 1024;
                    write_to_file(byte_array, ofname);
                }
                byte_array[array_index] = 0;
                bit_indx = 0;
            }
        }
    }
    inputfile.close();
    write_to_file(byte_array, ofname);
}

int HuffmanEncoding::getIndex(const char& dat) {
    int count = 0;
    for (auto it : codedmap) {
        if (it.data == dat) return count;
        count++;
    }
    return count;
}

void HuffmanEncoding::write_codes_tofile(string ofname) {
    ofstream outfile;
    stringstream ss;
    ss << ofname << ".hdr";
    outfile.open(ss.str());
    outfile << codedmap.size() << endl;
    for (const auto & it : codedmap) {
        outfile << int(it.data) << " " << it.coded_char << " " << it.bit_length << endl;
    }
    outfile.close();
}

void HuffmanEncoding::write_to_file(byte* arr, const std::string& offname) {
    ofstream outfile;
    stringstream ss;
    ss << offname << ".bin";
    outfile.open(ss.str(), ios::binary);
    for (int index = 0; index < 1024; ++index) {
        if (uint8_t(arr[index].to_ullong()) == 0) return;
        outfile << (uint8_t) arr[index].to_ulong();
    }
    outfile.close();
}

void HuffmanEncoding::compress(std::string inname, std::string ofname) {
    char char_to_encode;
    ifstream inputfile(inname);
    stringstream ss;
    ss<<ofname<<".txt";
    ofstream outfile(ss.str());
    char_to_encode = inputfile.get();
    while (!inputfile.eof()) {
        int index = getIndex(char_to_encode);
        int charcode = codedmap[index].coded_char;
        outfile << bitset<8>(charcode);
        char_to_encode = inputfile.get();
    }
    inputfile.close();
    outfile.close();
}


