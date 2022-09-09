#include "split.h"
#include <iostream>
#include <cstdlib>

using namespace std;

int main(int argc, char* argv[]){

  // first test
  struct Node* temp2 = new Node(3,nullptr);
  struct Node* temp1 = new Node(2,nullptr);
  struct Node* temp = new Node(-1,nullptr);
  temp->next = temp1;
  temp1->next = temp2;
  struct Node* evens = NULL;
  struct Node* odds = NULL;

  Node* in = temp;

  split(in,odds,evens);
  while(odds != nullptr){
    cerr << "odd value: " << odds->value << " " << endl;
    odds = odds->next;
  }
  while (evens != nullptr){
    cerr << "even value: " << evens->value << " " << endl;
    evens = evens->next;
  }

  // test 2 empty Node
  struct Node* test = NULL;
  struct Node* evens2 = NULL;
  struct Node* odds2 = NULL;
  Node* pass = test;
  split(pass,odds2,evens2);
  while(evens2 != nullptr){
    cerr << "even value: " << evens2->value << " " << endl;
    evens2 = evens2->next;
  }
  while(odds2 != nullptr){
    cerr << "odd value: " << odds2->value << " " << endl;
    odds2 = odds2->next;
  }
  if (odds2 == nullptr && evens2 == nullptr){
    cerr << "empty null linked list passed in" << endl;
  }
  
 



  delete temp2;
  delete temp1;
  delete temp;


  


  return 0;
}