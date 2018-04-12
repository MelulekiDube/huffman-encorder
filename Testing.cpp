/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "HuffmanNode.h"
#include <vector>

TEST_CASE("operators Gives less than value", "[HuffmanNode]") {
    DBXMEL004::HuffmanNode a('a', 15);
    DBXMEL004::HuffmanNode b('a', 15);
    DBXMEL004::HuffmanNode c('a', 20);
    DBXMEL004::HuffmanNode d('a', 5);

    SECTION("Testing the less than operator") {
        REQUIRE((a < b) == false);
        REQUIRE((a < c) == false);
        REQUIRE((a < d) == true);
    }
}

TEST_CASE("Testing the constructors and assignments", "[HuffmanNode]") {

    SECTION("Default constructor") {

        WHEN("default constructor used") {
            DBXMEL004::HuffmanNode node;

            THEN("Default values are /0 and 0") {
                REQUIRE((node.data) == -1);
                REQUIRE((node.frequency_count == 0));
            }

            THEN("right and left are pointing to nullptr") {
                REQUIRE(!node.leftNode);
                REQUIRE(!node.rightNode);
            }
        }
    }

    SECTION("Copy constructs") {

        WHEN("Copy constructor is called") {
            DBXMEL004::HuffmanNode node('a', 5);
            DBXMEL004::HuffmanNode node2(node);

            THEN("The two nodes are now equal") {
                REQUIRE(((node.data == node2.data)&&(node.frequency_count == node2.frequency_count)));
            }
        }
    }

    SECTION("Copy assignment doesn't destroy the old object") {

        WHEN("Copy assignment is called") {
            DBXMEL004::HuffmanNode node('a', 5);
            DBXMEL004::HuffmanNode node2;
            node2 = node;

            THEN("The two nodes are now equal") {
                REQUIRE(((node.data == node2.data)&&(node.frequency_count == node2.frequency_count)));
            }
        }
    }

    SECTION("Move constructor destroys the old object") {

        WHEN("Move constructor is called") {
            char c = 'a';
            int f = 6;
            DBXMEL004::HuffmanNode node(c, f);
            node.leftNode = std::make_shared<DBXMEL004::HuffmanNode>(node);
            REQUIRE(node.leftNode.get()); // first check if the left node has something as of now.
            DBXMEL004::HuffmanNode testNode(std::move(node)); // force move from the node node to new node testNode

            THEN("Node node must have frequency count =0 and data ='\0'") {
                REQUIRE(testNode.data == c); //check if data is moved to the new node
                REQUIRE(testNode.frequency_count == f); //  check if frequency is moved
                REQUIRE(node.data ==0); // check if the data is 0 as to the move constructor
                REQUIRE(node.frequency_count == 0); // check if the frequency is now 0 as to the move constructor
                REQUIRE(testNode.leftNode.get()); //check if the left node is not null
                REQUIRE(!node.leftNode.get()); // check if the left node for node is now null after the move
            }
        }
    }

    SECTION("Move assignments destroys the old object") {

        WHEN("Move assignement is called") {
            char c = 'a';
            int f = 6;
            DBXMEL004::HuffmanNode node(c, f);
            node.leftNode = std::make_shared<DBXMEL004::HuffmanNode>(node);
            REQUIRE(node.leftNode.get()); // first check if the left node has something as of now.
            DBXMEL004::HuffmanNode testNode;
            testNode = (std::move(node)); // force move from the node node to new node testNode

            THEN("Node node must have frequency count =0 and data ='\0' leaft and right nodes must be null") {
                REQUIRE((testNode.data == c)); //check if data is moved to the new node
                REQUIRE(testNode.frequency_count == f); //  check if frequency is moved
                REQUIRE(node.data == 0); // check if the data is 0 as to the move constructor
                REQUIRE(node.frequency_count == 0); // check if the frequency is now 0 as to the move constructor
                REQUIRE(testNode.leftNode.get()); //check if the left node is not null
                REQUIRE(!node.leftNode.get()); // check if the left node for node is now null after the move
            }
        }
    }
}

TEST_CASE("HuffmanTree", "[HuffmanTree]") {
    DBXMEL004::code_map charmap;
    charmap.insert(std::make_pair<char, int>('a', 5));
    charmap.insert(std::make_pair<char, int>('b', 9));
    charmap.insert(std::make_pair<char, int>('c', 12));
    charmap.insert(std::make_pair<char, int>('d', 13));
    charmap.insert(std::make_pair<char, int>('e', 16));
    charmap.insert(std::make_pair<char, int>('f', 45));
    DBXMEL004::maxheap heap;
    for (const auto & pair : charmap) {
        DBXMEL004::HuffmanNode tempNode(pair.first, pair.second);
        heap.push(tempNode);
    }
    DBXMEL004::HuffmanTree tree;
    tree.build(heap);
    REQUIRE((tree.root->data==-1));
    REQUIRE((tree.root->frequency_count==100));
    REQUIRE((tree.root->leftNode->data=='f'));
}

