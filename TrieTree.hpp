//
//  TrieTree.hpp
//  ECE250_Project2
//
//  Created by Haoning Jin on 2021/3/19.
//

#ifndef TrieTree_hpp
#define TrieTree_hpp

#include <stdio.h>
#include "TrieNode.hpp"


class trietree{
private:
    trienode* root;
    int size;
    bool firstword;
public:
    trietree();
    ~trietree();
    
    void insert_recursive(string word, trienode* node, int index);
    void insert(string word);
    bool has_children(trienode* node);
//    int num_children(trienode* node);
    bool erase_recursive(string word, trienode* node, int index);
    void erase(string word);
    bool search_recursive(string word, trienode* node, int index);
    void search(string word);
    void print_recursive(trienode* node, string output);
    void print();
    void auto_complete(string prefix);
    bool is_empty();
    void clear_recursive(trienode* current);
    void clear();
    int get_size();
};

class illegal_exception{
};

#endif /* TrieTree_hpp */
