/////////////////////////////////////////////////////////////////
//  order.cpp - demonstrate use of functor to control order    //
//              of an STL set                                  //
//                                                             //
//  ver 2 - now derives from binary_function                   //
//                                                             //
//  Jim Fawcett, CSE 687 - Object Oriented Design, Spring 2001 //
/////////////////////////////////////////////////////////////////

#pragma warning(disable : 4786)
#include <iostream>
#include <string>
#include <set>
using namespace std;

//----< comparison functor >-----------------------------------

template <class T> class compare : public binary_function<T,T,T> {

  public:
    bool operator()(const T &t1, const T &t2);
};

template <class T>
inline bool compare<T>::operator()(const T &t1, const T &t2) {

  return (t1 > t2);
}

//----< test stub >--------------------------------------------

void main() {

  cout << "\n    Demonstrating Control of Order   "
       << "\n                  in                 "
       << "\n  Associative Container with Functor "
       << "\n ====================================\n";

  string array[] = {
    "first  string", "second string", "third  string", 
    "fourth string", "fifth  string", "sixth  string"
  };

  // uses ordering provided by std::string::operator<(...)

  set<string> up;
  up.insert(array[0]);
  up.insert(array[1]);
  up.insert(array[2]);
  up.insert(array[3]);
  up.insert(array[4]);
  up.insert(array[5]);

  set<string>::iterator uit;
  for(uit = up.begin(); uit != up.end(); uit++)
    cout << "\n  " << *uit;

  cout << "\n\n";

//

  // uses ordering provided by functor compare<string>

  set< string, compare<string> > down;
  down.insert(array[0]);
  down.insert(array[1]);
  down.insert(array[2]);
  down.insert(array[3]);
  down.insert(array[4]);
  down.insert(array[5]);

  set< string, compare<string> >::iterator dit;
  for(dit = down.begin(); dit != down.end(); dit++)
    cout << "\n  " << *dit;

  cout << "\n\n";
}

