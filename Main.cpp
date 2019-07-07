//
// Created by botour on 07.07.19.
//
#include <iostream>
#include "src/Trie.h"
#include <vector>

int main () {
    trie_node* head = trie_node::create_trie();
    head->insert("Burhan\0");
    std::cout << head->find("Burhano\0") << std::endl;

    head->insert("Burhano\0");
    std::cout << head->find("Burhano\0") << std::endl;
}
