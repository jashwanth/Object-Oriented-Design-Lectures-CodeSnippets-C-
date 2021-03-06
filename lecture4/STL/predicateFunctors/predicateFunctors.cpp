/////////////////////////////////////////////////////////////////
// predicateFunction.cpp - demonstrates use of predicates      //
//                         with an STL algorithm               //
//                                                             //
//  ver 2 - now derives from binary_function                   //
//                                                             //
// Jim Fawcett, CSE687 - Object Oriented Design, Spring 2003   //
/////////////////////////////////////////////////////////////////

#include <list>
#include <iostream>
#include <algorithm>
#include <functional>  // added for VS2012
using namespace std;

//----< predicate function template -----------------------------

template <typename T>
bool isPositiveFunction(T& val) { return (val > 0); }

template bool isPositiveFunction<int>(int& val);  // forces instantiation

//----< predicate functor template -----------------------------

template <typename T>
class isPositiveFunctor : public unary_function<T,bool>
{
public:
  bool operator()(T val) const { return (val > 0); }
};
//----< test >--------------------------------------------------

void main( )
{
  int array[7] = { 1,2,1,0,-1,-2,-3 };
  list<int> li(&array[0],&array[7]);

  // unary function pointer used in algorithm

  list<int>::iterator iter = li.begin();
  while(iter != li.end())
  {
    iter = find_if(iter, li.end(), isPositiveFunction<int>);
    if(iter != li.end())
      cout << "\n  positive element = " << *iter++;
  }
  cout << "\n\n";

  // unary predicate functor used in algorithm

  iter = li.begin();
  while(iter != li.end())
  {
    iter = find_if(iter, li.end(), not1(isPositiveFunctor<int>()));
    if(iter != li.end())
      cout << "\n  non-positive element = " << *iter++;
  }
  cout << "\n\n";
}
