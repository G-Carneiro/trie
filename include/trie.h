#ifndef STRUCTURES_TRIE_H
#define STRUCTURES_TRIE_H

#include <stdio.h>

#include <string>
#include <vector>

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

bool leave(struct TrieNode* root) {
  for (int i = 0; i < ALPHABET_SIZE; i++) {
    if (root->children[i] != nullptr) {
      return false;
    }
  }
  return true;
}

int prefix(struct TrieNode* it) {
  if (it == nullptr) {
    return 0;
  }

  int leaves = 0;
  if (leave(it)) {
	  leaves++;
  } else {
	  for (int i = 0; i < ALPHABET_SIZE; i ++) {
		  leaves += prefix(it->children[i]);
	  }
  }

  return leaves;
}

std::vector<int> search(struct TrieNode* root, std::string key) {
  std::vector<int> p(3);
  auto it = root;

  for (int i = 0; i < key.length(); i++) {
    int index = key[i] - 'a';
    if (!it->children[index]) {
      p.at(0) = -1;
      p.at(1) = -1;
      return p;
    }

    it = it->children[index];
  }

  if (it && it->len == 0) {
    p.at(0) = 0;
    p.at(1) = 0;
    return p;
  }

  p.at(0) = it->pos;
  p.at(1) = it->len;
  p.at(2) = prefix(it);

  return p;
}


}  // namespace structures

#endif
