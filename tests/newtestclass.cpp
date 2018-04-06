/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   newtestclass.cpp
 * Author: Meluleki
 *
 * Created on Apr 6, 2018, 11:29:45 AM
 */

#include "newtestclass.hpp"
#include "HuffmanNode.h"


CPPUNIT_TEST_SUITE_REGISTRATION(newtestclass);

newtestclass::newtestclass() {
}

newtestclass::~newtestclass() {
}

void newtestclass::setUp() {
}

void newtestclass::tearDown() {
}

void newtestclass::testHuffmanNode() {
    DBXMEL004::HuffmanNode huffmanNode();
    if (true /*check result*/) {
        CPPUNIT_ASSERT(false);
    }
}

void newtestclass::testHuffmanNode2() {
    const HuffmanNode& orig;
    DBXMEL004::HuffmanNode huffmanNode(orig);
    if (true /*check result*/) {
        CPPUNIT_ASSERT(false);
    }
}

void newtestclass::testHuffmanNode3() {
    HuffmanNode&& moveFrom;
    DBXMEL004::HuffmanNode huffmanNode(moveFrom);
    if (true /*check result*/) {
        CPPUNIT_ASSERT(false);
    }
}

void newtestclass::testCompare() {
    const HuffmanNode& a;
    const HuffmanNode& b;
    DBXMEL004::HuffmanNode huffmanNode;
    bool result = huffmanNode.compare(a, b);
    if (true /*check result*/) {
        CPPUNIT_ASSERT(false);
    }
}

