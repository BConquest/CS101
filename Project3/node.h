#ifndef _node_h_
#define _node_h_

#include <iostream>
using namespace std;

class Node
{
  public:
    Node();

    int getCount();
    void increment();
    Node* insertLetter(char);
    void wordCount(string, string, bool, bool);

  private:
    int count;
    Node* children[26];
};

#endif
