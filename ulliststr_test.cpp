/* Write your test code for the ULListStr in this file */
#include "ulliststr.h"
#include <iostream>
using namespace std;


int main(int argc, char* argv[])
{
  // push to front example 1
  ULListStr trial;
  trial.push_front("1");
  for(int i = 0; i < 8; i++){
    trial.push_front("3");
  }
  cout << "printing size expecting 9: " << trial.size() << endl;
  cout << "expecting 3: " << trial.get(0) << endl;
  cout << "expecting 1: " << trial.get(8) << endl;

  //example 2 creating new node push_back 
  ULListStr test1;
  test1.push_back("1");
  test1.push_front("7");
  cout << "should print 7: " << test1.get(0) << endl;
  cout << "should print 1: " << test1.get(1) << endl;
  cout << "size shold be 2: " << test1.size();
  test1.pop_back();
  cout << "should print 7 " << test1.get(0) << endl;


//example 3 creating new node push_front then push_back then pop front original node to make push_back only node
  ULListStr test4;
  test4.push_front("5");
  test4.push_back("4");
  cout << "should print 5: " << test4.get(0) << endl;
  cout << "should print 4: " << test4.get(1) << endl;
  test4.pop_front();
  cout << "should print 4: " << test4.get(0) << endl;


// example edge case with empty
  try{
    ULListStr test;
    test.get(0);
  }
  catch(exception& t){
    cout << t.what() <<endl;
  }


  return 0;
}
