//
//  TrieDriver.cpp
//  ECE250_Project2
//
//  Created by Haoning Jin on 2021/3/28.
//

#include <iostream>
#include <string>
#include <cmath>
#include "TrieTree.hpp"


int main(){
    trietree tree;
    std::string line;


    while (true) {

        if ( std::cin.eof() ) {
            break;
        }

        getline(std::cin, line);
        if (line == "exit") {
            break;
        }

        std::size_t pos = line.find(" ");
        std::string cmd = line.substr(0, pos);
        std::string para = line.substr(pos + 1);

        if (cmd == "i") {
            tree.insert(para);
        }

        if (cmd == "e") {
            tree.erase(para);
        }

        if (cmd == "s") {
            tree.search(para);
        }

        if (cmd == "print") {
            tree.print();
        }

        if (cmd == "autocomplete") {
            para.pop_back();
            tree.auto_complete(para);
        }

        if (cmd == "empty") {
            bool check = tree.is_empty();
            if (check == true) {
                std::cout << "empty 1" << std::endl;
            }
            else std::cout << "empty 0" << std::endl;
        }

        if (cmd == "clear") {
            tree.clear();
            std::cout << "success" << std::endl;
        }

        if (cmd == "size") {
            int size = tree.get_size();
            std::cout << "number of words is " << size << std::endl;
        }

    }
    return 0;
}
