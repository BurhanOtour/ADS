//
// Created by botour on 07.07.19.
//

#ifndef ADS_TRIE_H
#define ADS_TRIE_H


struct trie_node {
    trie_node() = default;
    trie_node* next[256];
    char c;


    static trie_node* create_trie(void);
    bool find(const char* query);
    int insert(const char* new_string);
};
#endif //ADS_TRIE_H
