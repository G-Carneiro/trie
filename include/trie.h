//! Copyright [2020] <Gabriel Medeiros Lopes Carneiro>
#ifndef TRIE_H
#define TRIE_H

#include <cstdint>  // std::size_t
#include <stdexcept>  // C++ Exceptions
#include <string>

#include "linked_list.h"

#define ALPHABET_SIZE 26

using namespace std;

namespace structures {
//! class Trie
template<typename T>
class Trie {
 public:
    //! destrutor
    ~Trie();
    //! inserção de chaves
    void insert(string key, int position, int size);
    //! busca
    int* search(string key);
    //! retorna número de prefixos


 private:
    class Node {
     public:
        explicit Node(const T& letter):
                letter{letter}
        {}

        int prefix(Node* node, int num_of_prefix) {
            if (node == nullptr) {
                return 1;
            }
            for (int i = 0; i < 26; i++) {
                if (node->children[i] != nullptr) {
                    num_of_prefix += prefix(node->children[i], num_of_prefix);
                }
            }
            return num_of_prefix;
        }

        int position() {
            return position_;
        }

        void position(int position) {
            position_ = position;
        }

        int size() {
            return size_;
        }

        void size(int size) {
            size_ = size;
        }

     private:
        T letter;
        Node* children[ALPHABET_SIZE];
        int position_{0};
        int size_{0};
    };

    Node *root{nullptr};
};

}  // namespace structures

#endif

template<typename T>
int* structures::Trie<T>::search(string key) {
    int *search_output = new int[3];
    Node* aux = root;
    for (int i = 0; i < key.length(); i++) {
        int index = key[i] - 'a';
        if (!aux->children[index]) {
            search_output[0] = -1;
            search_output[1] = -1;
            search_output[2] = -1;
            return search_output;
        }

        aux = aux->children[index];
    }

    if (aux && aux->size() == 0) {
        search_output[0] = 0;
        search_output[1] = 0;
        search_output[2] = 0;
        return search_output;
    }
    int num_of_prefix = 0;
    search_output[0] = aux->position();
    search_output[1] = aux->size();
    search_output[2] = aux->prefix(aux, num_of_prefix);

    return search_output;
}

template<typename T>
void structures::Trie<T>::insert(string key, int position, int size) {
    Node* aux = root;
    for (int i = 0; i < key.length(); i++) {
        int index = key[i] - 'a';
        /*if (!aux->children[index])
            aux->children[index] = initNode();*/

        aux = aux->children[index];
    }

    aux->position(position);
    aux->size(size);
}

template<typename T>
structures::Trie<T>::~Trie<T>() {
    root = nullptr;
}

