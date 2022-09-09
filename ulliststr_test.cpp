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





  


  



  
  
  //EXAMPLE 1
  // cout << "before push front"  << endl;
  // trial.push_front("1");
  // cout << "after push front" << endl;
  // cout << trial.get(0) << endl;
  // cout << "before push back " << endl;
  // trial.push_back("6");
  // cout << "after push back" << endl;
  // cout << "should be 1 " << trial.get(0) << endl;
  // cout << "should be 6 " << trial.get(1) << endl;
  // // trial.pop_back();
  // // string const& temp = trial.back();
  // // cout << "should be 1" << temp;


  //Example 1A
  // trial.push_back("1");
  // trial.push_front("7");
  // cout << "shoudl print 7 " << trial.get(0) << endl;
  // cout << "shoudl print 1 " << trial.get(1) << endl;
  // trial.pop_front();
  // cout << "should print 1 " << trial.get(0) << endl;
  // //cout << "should crash " << trial.get(1) << endl; // put in tyr and catch

  






  
  
  



  /// Example 2 - works as of now
  // trial.push_back("6");
  // trial.push_back("2");
  // //trial.push_front("3");

  // cout << trial.get(0) << endl;
  
  // string const& temp = trial.back();
  // cout << "back should be 2 " << temp << endl;

  // string const& temp1 = trial.front();
  // cout << "front should be 6 " << temp1 << endl;


  // // cout << trial.get(0) <<  " " << trial.get(1) << " " << trial.get(2) << " " << endl;
  // cout << " should be 6: " << trial.get(0) <<  " should be 2: " << trial.get(1) << endl;
  // trial.pop_back(); //should remove 2
  // cout << "should be 6: "<< trial.get(0) << endl;
  // trial.push_front("5");
  // cout << "should be 5: " << trial.get(0) << " should be 6: " << trial.get(1) << endl;
  
  
  

 

  
  
  

  return 0;
}
