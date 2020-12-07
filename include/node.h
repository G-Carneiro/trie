#ifndef INCLUDE_NODE_H
#define INCLUDE_NODE_H

#include <cstdint>

namespace structures {
//! Nodo
/*
   Nodo da estrutura trie.
*/
class Node {
 public:
  //! Construtor
  /*
     Construtor padrão da estrutura nodo.
  */
  Node(void);

  //! Destrutor
  /*!
     Destrutor padrão da estrutura nodo.
  */
  ~Node(void);

 private:
  char letter;
  Node* children[26];  // Pode ser uma 'Linked List' de ponteiros.
  std::size_t position;
  std::size_t length;
};
}  // namespace structures

#endif  // INCLUDE_NODE_H_
