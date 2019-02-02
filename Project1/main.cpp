/*
Bryant conquest

01/29/2018

  This program is for searching through a file and finding user words.
*/

#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <locale>
#include "node.h"
using namespace std;

int main(int argc, char* argv[])
{
  //Making sure there are enough arguments
  if(argc != 2)
  {
    if(argc == 1) cout << "No File Found to test" << endl;
    if(argc >= 3) cout << "To many arguments found" << endl;
    exit (EXIT_FAILURE);
  }

  string filename = argv[1];

  ifstream inputfile(filename);

  char prevLet, currLet;

  prevLet = '!';

  Node *root = new Node();
  Node *curr = root;
  int totalWord = 0;
  int uniqueWord = 0;
  while(inputfile.get(currLet))
  {
      if(isalpha(currLet))
      {
        currLet = tolower(currLet);
        curr = curr->insertLetter(currLet);
      }
      else if(!isalpha(currLet) && isalpha(prevLet))
      {
        curr->increment();
        totalWord++;
        if(curr->getCount() == 1)
        {
          uniqueWord++;
        }
        curr = root;
      }
      prevLet = currLet;
  }


  cout << "The number of words found in the file was " << totalWord << endl;
  cout << "The number of unique words found in the file was " << uniqueWord << endl;

  string uWord;
  cout << "Please enter a word: ";
  cin >> uWord;

  while(uWord != "END")
  {
  //  locale loc;
  //  uWord = tolower(uWord, loc);
    int length = uWord.length();
    bool flag = false; //if there is a question mark

    for(int x = 0; x < length; x++)
    {
      if(uWord[x] == '?')
      {
        flag = true;
      }
    }

    if(!flag)
    {
      //For no question mark
      cout << "The word " << uWord;
      root->wordCount(uWord, "", true, flag);
    }
    else
    {
      root->wordCount(uWord, "", true, flag);
    }
    cout << "Please enter a word: ";
    cin >> uWord;
  }


  return 0;
}
