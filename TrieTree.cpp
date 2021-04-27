//
//  TrieTree.cpp
//  ECE250_Project2
//
//  Created by Haoning Jin on 2021/3/19.
//

#include "TrieTree.hpp"

trietree::trietree(){
    root = new trienode;
    size = 0;
    firstword = 1;
}

trietree::~trietree(){
    clear();
    delete root;
    root = nullptr;
}

void trietree::insert_recursive(string word, trienode *node, int index){
    int offset = word[index] - 'a';
    if (index < word.length()) {
        if (node -> get_node(offset) == NULL) {
            node -> set_node(offset);
        }
        insert_recursive(word, node -> get_node(offset), index + 1);
    }
    else{
        node -> set_leaf_node(true);
        
    }
}


void trietree::insert(string word){
    try {
        for (int i{0}; i < word.length(); i++) {
            if (word[i] < 97 or word[i] > 122) {
                throw illegal_exception();
            }
        }
        
        trienode* current = root;
        if (search_recursive(word, current, 0) == true) {
            std::cout << "failure" << std::endl;
            return;
        }
        insert_recursive(word, current, 0);
        std::cout << "success" << std::endl;
        size += 1;
    }
    catch (illegal_exception) {
        std::cout << "illegal argument" << std::endl;
    }

}


bool trietree::search_recursive(string word, trienode* node, int index){
    int offset = word[index] - 'a';
    if (index < word.length()) {
        if (node -> get_node(offset) == nullptr) {
            return false;
        }
        else{
            return search_recursive(word, node -> get_node(offset), index + 1);
        }
    }
    else{
        return node -> is_leaf();
    }
}

void trietree::search(string word){
    try {
        for (int i{0}; i < word.length(); i++) {
            if (word[i] < 97 or word[i] > 122) {
                throw illegal_exception();
            }
        }
        trienode* current = root;
        if(search_recursive(word, current, 0)){
            std::cout << "found " << word << std::endl;
            return;
        }
        std::cout << "not found" << std::endl;
    } catch (illegal_exception) {
        std::cout << "illegal argument" << std::endl;
    }
}


bool trietree::has_children(trienode *node){
    for (int i{0}; i < 26; i++) {
        if (node -> get_node(i) != NULL) {
            return true;
        }
    }
    return false;
}

//int trietree::num_children(trienode *node){
//    int num{0};
//    for (int i{0}; i < 26; i++) {
//        if (node -> get_node(i) != nullptr) {
//            num += 1;
//        }
//    }
//    return num;
//}


bool trietree::erase_recursive(string word, trienode *node, int index){
    int offset = word[index] - 'a';
    trienode* next = node -> get_node(offset);
    if (index == word.length()) {
        if (node -> is_leaf()) {
            node -> set_leaf_node(false);
            return has_children(node);
        }
    }
    if (!erase_recursive(word, next, index + 1)) {
        next -> clear_children(offset);
    }
    return true;
}


void trietree::erase(string word){
    try {
        for (int i{0}; i < word.length(); i++) {
            if (word[i] < 97 or word[i] > 122) {
                throw illegal_exception();
            }
        }
        trienode* current = root;
        if ((search_recursive(word, current, 0) == false) or (is_empty() == true)) {
            std::cout << "failure" << std::endl;
            return;
        }
        erase_recursive(word, current, 0);
        size -= 1;
        std::cout << "success" << std::endl;
        
    } catch (illegal_exception) {
        std::cout << "illegal argument" << std::endl;
    }
}

void trietree::print_recursive(trienode *node, string output){
    if (node -> is_leaf()) {
        if (firstword) {
            std::cout << output;
            firstword = 0;
        }
        else{
            std::cout << ' ' << output;
        }
    }
    
    for (int i{0}; i < 26; i++) {
        if (node -> get_node(i) != nullptr) {
            output += 'a' + i;
            print_recursive(node -> get_node(i), output);
            output.pop_back();
        }
    }
}

void trietree::print(){
    if (size == 0) {
        return;
    }
    string output;
    trienode* current = root;
    print_recursive(current, output);
    std::cout << std::endl;
    firstword = 1;
}

void trietree::auto_complete(string prefix){
    if (is_empty()) {
        return;
    }
    trienode* current = root;
    for (int i{0}; i < prefix.length(); i++) {
        int offset = prefix[i] - 'a';
        if (current -> get_node(offset) != nullptr) {
            current = current -> get_node(offset);
        }
        else return;
    }
    print_recursive(current, prefix);
    firstword = 1;
    std::cout << std::endl;
}

void trietree::clear_recursive(trienode* node){
    if (root == nullptr or node == root) {
        return;
    }
    for (int i{0}; i < 26; i++) {
        if (node -> get_node(i) != nullptr) {
            clear_recursive(node -> get_node(i));
        }
    }
    node = nullptr;
}

void trietree::clear(){
    trienode* temp = root;
    size = 0;
    clear_recursive(temp);
    for (int i{0}; i < 26; i++) {
        root -> clear_children(i);
    }
}

bool trietree::is_empty(){
    if (size != 0) {
        return false;
    }
    return true;
}

int trietree::get_size(){
    return size;
}

