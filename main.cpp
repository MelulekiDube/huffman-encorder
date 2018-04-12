/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Meluleki
 *
 * Created on April 2, 2018, 2:35 PM
 */
#include <string>
#include <iostream>
#include "HuffmanNode.h"
using namespace std;
using namespace DBXMEL004;
/*
 * 
 */
int main(int argc, char** argv) {
    string in=argv[1];
    string out=argv[2];
    cout<<"We are compressing your files for you quick quick"<<endl;
    HuffmanEncoding h;
    h.generate_frequency_table(argv[1], argv[2]);
    h.encode(argv[1], argv[2]);
    h.compress(argv[1], argv[2]);
    cout<<"Done encrypted file are in "<<argv[2]<<".bin and "<<argv[2]<<".txt"<<endl;
}

