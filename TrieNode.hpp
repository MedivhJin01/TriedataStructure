//
//  TrieNode.hpp
//  ECE250_Project2
//
//  Created by Haoning Jin on 2021/3/19.
//

#ifndef TrieNode_hpp
#define TrieNode_hpp

#include <stdio.h>
#include <iostream>
#include <string>


using namespace std;

class trienode{

private:
    bool leafnode;
    trienode* alphabet[26];
public:
    trienode();
    ~trienode();
    bool is_leaf();
    void set_leaf_node(bool input);
    trienode* get_node(int index);
    void set_node(int index);
//    bool no_children(trienode* node);
    void clear_children(int index);
};



#endif /* TrieNode_hpp */
