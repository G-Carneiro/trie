#include <fstream>
#include <iostream>
#include <string>

#include "include/trie.h"

int main() {
  using namespace std;
  using namespace structures;
  structures::TrieNode* root = initNode();

  string filename;

  cin >> filename;
  int posProx = 0;

  string line;
  ifstream myfile(filename);
  if (myfile.is_open()) {
    while (getline(myfile, line)) {
      string word;
      int i;
      if (line[0] != '[') {
        posProx += line.length() + 1;
        continue;
      }
      for (i = 1; i < line.length(); i++) {
        if (line[i] == ']') break;
        word += line[i];
      }
      word[i] = '\0';
      int length = line.length();
      insert(root, word, posProx, length);
      posProx += line.length() + 1;
    }
    myfile.close();
  } else {
    printf("Nao abriu arquivo\n");
  }

  string word;
  pair<int, int> p;
  while (1) {
    cin >> word;
    if (word.compare("0") == 0) {
      break;
    }
    p = search(root, word);
    /*if (p.first == 0 && p.second == 0) {
        printf("%s is prefix of words \n", word.c_str());
    }*/

    if (p.first == -1) {
      printf("%s is not prefix \n", word.c_str());
    } else {
      printf("%s is prefix of words \n", word.c_str());
      if (p.second != 0) {
        printf("%s is at (%d,%d) \n", word.c_str(), p.first, p.second);
      }
    }
  }

  return 0;
}
