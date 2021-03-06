///////////////////////////////////////////////////////////////
//  iter2c.cpp  - demonstrate stream iterators               //
//                ----------------------------               //
//                Reads lines from vector of strings and     //
//                copies them to cout using stream iterator. //
//                Repeats for array of strings.              //
//                                                           //
//  Jim Fawcett, 4/4/98                                      //
///////////////////////////////////////////////////////////////

#pragma warning(disable : 4786)
#include <iostream>
#include <iterator>
#include <vector>
#include <string>

#pragma warning (disable : 4786)

using namespace std;

void main() {


  vector<string> test;
  test.push_back("first line\n");
  test.push_back("second line\n");
  test.push_back("third and longer line\n");
  test.push_back("fourth and last\n");
  
  ostream_iterator<string> outString(cout);
  copy(test.begin(),test.end(),outString);
  
  cout << endl;

  string array[6] = {
    "first element\n", "second element\n", "third element\n",
    "fourth element\n", "fifth element\n", "sixth element\n"
  };
  copy(array, array+6, outString);

}