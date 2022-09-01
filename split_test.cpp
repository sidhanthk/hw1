#include "split.h"
#include <iostream>
#include <cstdlib>

using namespace std;

int main(int argc, char* argv[]){
  struct Node* temp2 = new Node(-17,nullptr);
  struct Node* temp1 = new Node(2,nullptr);
  struct Node* temp = new Node(1,nullptr);
  temp->next = temp1;
  temp1->next = temp2;
  struct Node* evens = NULL;
  struct Node* odds = NULL;

  Node* in = temp;

  split(in,odds,evens);
  while(odds != nullptr){
    cerr << "value: " << odds->value << " ";
    odds = odds->next;
  }


  delete temp2;
  delete temp1;
  delete temp;
  


  return 0;
}