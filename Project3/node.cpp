#include "node.h"
#include <iostream>
using namespace std;

Node::Node()
{
  count = 0;
  for(int x = 0; x < 26; x++)
  {
    children[x] = nullptr;
  }
}

int Node::getCount()
{
  return count;
}

void Node::increment()
{
  count++;
}

Node* Node::insertLetter(char letter)
{
  int index = letter -'a';
  if(children[index] == nullptr)
  {
    children[index] = new Node();
  }
  return children[index];
}

void Node::wordCount(string word, string result, bool printZero, bool qMark)
{
  int index = word[0] - 'a';

  if(word == "")
  {
    if(getCount() != 0 || printZero)
    {
      if(qMark)
      {
        cout << "The word " << result << " appears " << getCount()
            << " times in the document." << endl;
      }
      else
      {
        cout << /*"The word " << result <<*/ " appears " << getCount()
            << " times in the document." << endl;
      }
    }
    return ;
  }
  else if(word[0] == '?')
  {
    //Loop through children and check if they are something
    for(int x = 0; x < 26; x++)
    {
      if(children[x] != nullptr)
      {
        children[x]->wordCount(word.substr(1), result + (char)(x+'a'), false, qMark);
      }
    }
    return;
  }
  else if(children[index] == nullptr && printZero)
  {
    if(qMark)
    {
      cout << "The word " << result << " appears 0 times in the document." << endl;
    }
    else
    {
      cout << /*"The word " << result << */" appears 0 times in the document." << endl;
    }
    return;
  }
  else
  {
    return children[index]->wordCount(word.substr(1), result + word[0], printZero, qMark);
  }
}
