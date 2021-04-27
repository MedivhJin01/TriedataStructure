//
//  TrieNode.cpp
//  ECE250_Project2
//
//  Created by Haoning Jin on 2021/3/19.
//

#include "TrieNode.hpp"


trienode::trienode(){
    leafnode = false;
    for (int i{0}; i < 26; i++) {
        alphabet[i] = NULL;
    }
}

trienode::~trienode(){
    for (int i{0}; i < 26; i++) {
        clear_children(i);
    }
}

bool trienode::is_leaf(){
    return leafnode;
}

void trienode::set_leaf_node(bool input){
    leafnode = input;
}

trienode* trienode::get_node(int index){
    return alphabet[index];
}

void trienode::set_node(int index){
    alphabet[index] = new trienode();
}

//bool trienode::no_children(trienode *node){
//    for (int i{0}; i < 26; i++) {
//        if (node -> alphabet[i] != NULL) {
//            return false;
//        }
//    }
//    return true;
//}

void trienode::clear_children(int index){
    delete alphabet[index];
    alphabet[index] = nullptr;
}
