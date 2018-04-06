/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   newtestclass.hpp
 * Author: Meluleki
 *
 * Created on Apr 6, 2018, 11:29:44 AM
 */

#ifndef NEWTESTCLASS_HPP
#define NEWTESTCLASS_HPP

#include <cppunit/extensions/HelperMacros.h>

class newtestclass : public CPPUNIT_NS::TestFixture {
    CPPUNIT_TEST_SUITE(newtestclass);

    CPPUNIT_TEST(testHuffmanNode);
    CPPUNIT_TEST(testHuffmanNode2);
    CPPUNIT_TEST(testHuffmanNode3);
    CPPUNIT_TEST(testCompare);

    CPPUNIT_TEST_SUITE_END();

public:
    newtestclass();
    virtual ~newtestclass();
    void setUp();
    void tearDown();

private:
    void testHuffmanNode();
    void testHuffmanNode2();
    void testHuffmanNode3();
    void testCompare();

};

#endif /* NEWTESTCLASS_HPP */

