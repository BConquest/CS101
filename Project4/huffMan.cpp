#include "huffMan.h"
#include "minheap.cpp"

huffman::huffman()
{
  for(int i = 0; i < 128; i++)
    frequency[i] = 0;

  hp = create_heap(128);

  inorderType.open("inorder");
  preorderType.open("/preorder");

  root = nullptr;
}

void huffman::measureFreq(string fileName)
{
  fstream inputFile;
  inputFile.open(fileName);
  char ch;
  while(!inputFile.eof())
  {
    inputFile.get(ch);
    int charInt;
    charInt = ch;
    frequency[charInt] += 1;
  }
}

void huffman::encode(string fileName)
{
  fstream inputFile;
  inputFile.open(fileName);
  ofstream out;
  out.open("code.txt");
  char ch;
  while(!inputFile.eof())
  {
    inputFile.get(ch);
    out << encodings[ch];
  }
  out.close();
}

void huffman::printFreq()
{
    for(int i = 0; i < 128; i++)
    {
      if(frequency[i] != 0)
      {
      cout << (char)i << "-" << frequency[i] << " " << i << "\n";
      }
    }

    cout << endl;
}

void huffman::createHeap()
{
  for(int i = 11; i <= 127; i++)
  {
    if(frequency[i] > 0)
    {
      insert((char) i, frequency[i], hp);
    }
  }
  /*
  cout <<"Here the heap" <<endl;
  for (int i=0; i < hp->current_size; i++) {
    cout << hp->heap[i].freq << " "<< hp->heap[i].key << endl;
  }
  cout <<"There the heap" <<endl;
  */
  return;
}

void huffman::createtree()
{
  
  int i = 0;
  while(hp->current_size > 1)
  { 
    i += 1;
    heap_el_t *a, *b;
    a = delete_min(hp);
    b = delete_min(hp);

    int c = a->freq + b->freq;

    char let = 127 + i;
    heap_el_t* temp = new heap_el_t;
    temp-> key = let;
    temp->freq = c;
    temp->left = a;
    temp->right = b;
    insert(temp, hp);
    
  }
  
  preorder(hp->heap, "");
  cout << "\n";
  inorder(hp->heap);

  inorderType.close();
  preorderType.close();
}

void huffman::preorder(heap_el_t* temp, string enc)
{
  if(temp==nullptr)
  {
    return;
  }

  preorderType << temp->key << " ";

  if (temp->key >= 0 && temp->key <128)
    encodings[temp->key] = enc;

  preorder(temp->left, "0" + enc);
  preorder(temp->right, "1" + enc);
}

void huffman::inorder(heap_el_t* temp)
{
  if(temp==nullptr)
  {
    return;
  }

  inorder(temp->left);
  inorderType << temp->key << " ";
  inorder(temp->right);
}