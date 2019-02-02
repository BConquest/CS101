#ifndef _huffman_
#define _huffman_

#include <iostream>
#include <fstream>
using namespace std;

class huffman
{
public:

  typedef struct tree
  {
    tree *left;
    tree *right;
    char letter;
  } tree;

  huffman();

  void measureFreq(string fileName);
  void encode(string fileName);
  void printFreq();

  void createHeap();

  void createtree();  
  void inserttree(tree* temp, char key);
  tree* newNode(char key);
  tree newtree(char let);

private:
  int frequency[128];
  string encodings[128];
  typedef struct heap_t heap_t;
  typedef struct heap_el_t heap_el_t;

  heap_t *hp;

  tree *root;
  tree *temp[128];

  void preorder(heap_el_t* temp, string enc);
  void inorder(heap_el_t* temp);

  ofstream inorderType;
  ofstream preorderType;

};

#endif
