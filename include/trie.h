#ifndef STRUCTURES_TRIE_H
#define STRUCTURES_TRIE_H

#include <stdio.h>
#include <string>

#define ALPHABET_SIZE 26

namespace structures {

struct TrieNode {
  struct TrieNode* children[ALPHABET_SIZE];
  int pos, len;
};

struct TrieNode* initNode() {
  auto tNode = new TrieNode;

  tNode->pos = 0;
  tNode->len = 0;

  for (int i = 0; i < ALPHABET_SIZE; i++) tNode->children[i] = NULL;

  return tNode;
}

void insert(struct TrieNode* root, std::string key, int pos, int len) {
  auto it = root;

  for (int i = 0; i < key.length(); i++) {
    int index = key[i] - 'a';
    if (!it->children[index]) it->children[index] = initNode();

    it = it->children[index];
  }

  it->pos = pos;
  it->len = len;
}

std::pair<int, int> search(struct TrieNode* root, std::string key) {
  std::pair<int, int> p;
  auto it = root;

  for (int i = 0; i < key.length(); i++) {
    int index = key[i] - 'a';
    if (!it->children[index]) {
      p.first = -1;
      p.second = -1;
      return p;
    }

    it = it->children[index];
  }

  if (it && it->len == 0) {
    p.first = 0;
    p.second = 0;
    return p;
  }

  p.first = it->pos;
  p.second = it->len;

  if (p.first != -1) {
	  // Find number of words in which string is prefix of
  }

  return p;
}

}  // namespace structures

#endif
