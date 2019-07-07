#include <iostream>
#include "Trie.h"

trie_node::trie_node() noexcept = default;

trie_node *trie_node::create_trie(void) {
    trie_node *new_trie = new trie_node();
    for (size_t i = 0; i < 256; i++) {
        new_trie->next[i] = nullptr;
    }
    return new_trie;
}
// when we want to find a string we will look for query+'\0'

bool trie_node::find(const char *query) {
    const char *query_next = query;
    trie_node *current_node = this;
    while (*query_next != '\0') {
        if (current_node->next[(int) *query_next] == nullptr) {
            return false;
        } else {
            current_node = current_node->next[(int) *query_next];
            query_next += 1;
        }
    }
    return current_node->next[(int) '\0'] != nullptr;
}

int trie_node::insert(const char *new_string) {
    const char *next_char = new_string;
    trie_node *current_node = this;
    trie_node *new_trie;
    while (*next_char != '\0') {
        if (current_node->next[(int) *next_char] != nullptr) {
            current_node = current_node->next[(int) *next_char];
            next_char += 1;
        } else {
            new_trie = create_trie();
            current_node->next[(int) *next_char] = new_trie;
            current_node = new_trie;
            next_char += 1;
        }
    }
    if (current_node->next[(int) '\0'] == nullptr) {
        current_node->next[(int) '\0'] = create_trie();
        return 1;
    } else {
        return 0;
    }
}
