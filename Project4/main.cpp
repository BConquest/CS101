/*
Bryant Conquest
4/20/2018

This Program Takes in a file and uses huffman encoding to shorten it
*/

#include <iostream>
#include <fstream>
#include "huffMan.h"
using namespace std;

bool fileExists(string fileName);


int main(int argc, char * argv[])
{
  if(argc != 2)
  {
    cout << "Invalid Input: ./encode <File Name>" << endl;
    cout << argc << endl;
    return 1;
  }

  string unencodedFile = argv[1];

  if(!fileExists(unencodedFile))
  {
    cout << "File does not exist" << endl;
    return 1;
  }

  huffman binaryTree;

  binaryTree.measureFreq(unencodedFile);
  //binaryTree.printFreq();

  binaryTree.createHeap();
  binaryTree.createtree();

  binaryTree.encode(unencodedFile);


  return 0;
}

bool fileExists(string fileName)
{
     fstream temp;
     temp.open(fileName);
     if(temp.is_open())
          return true;
     else
          return false;
}
