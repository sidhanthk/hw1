/* Write your test code for the ULListStr in this file */
#include "ulliststr.h"
#include <iostream>
using namespace std;


int main(int argc, char* argv[])
{
  ULListStr trial;

  
  
  //EXAMPLE THAT I NEED HELP JUST DOUBLE CHECKING I AM CORRECT.
  // trial.push_front("1");
  // cout<<"line 15"<<endl;
  // cout << trial.get(0) << endl;
  // trial.push_back("6");
  // cout << trial.get(0) << endl;
  


  trial.push_back("6");
  trial.push_back("2");
  //trial.push_front("3");

  cout << trial.get(0) << endl;
  
  string const& temp = trial.back();
  cout << "back" << temp << endl;

  string const& temp1 = trial.front();
  cout << "front" << temp1 << endl;


  // cout << trial.get(0) <<  " " << trial.get(1) << " " << trial.get(2) << " " << endl;
  cout << trial.get(0) <<  " " << trial.get(1) << endl;
  trial.pop_back();
  // cout << trial.get(0) <<  " " << trial.get(1) << endl;
  // trial.pop_front();
  
  

 
  cout << trial.get(0) << endl;
  cout << trial.size() << endl;

  
  
  

  return 0;
}
