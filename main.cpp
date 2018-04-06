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
#include "HuffmanNode.h"
using namespace std;
using namespace DBXMEL004;
/*
 * 
 */
int main(int argc, char** argv) {
    HuffmanTree t ("test", "out");
    t.generate_frequency_table();
}



