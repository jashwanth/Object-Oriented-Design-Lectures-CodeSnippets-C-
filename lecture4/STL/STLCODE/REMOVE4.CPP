//  remove4.cpp - Erase all the zero elements in a vector.
//                This is an effective method.

#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

void showVec(const vector<int> &v) {

  cout << "\n  ";
  int i;
  for(i=0; i<v.size()-1; i++)
    cout << v[i] << ", ";
  cout << v[v.size()-1] << "\n\n";

}

void main() {

  vector<int> v;
  v.push_back(5);
  v.push_back(1);
  v.push_back(0);
  v.push_back(-1);
  v.push_back(0);
  v.push_back(3);
  v.push_back(0);
  v.push_back(0);
  v.push_back(-4);
  v.push_back(0);
  showVec(v);

  vector<int>::iterator new_end;
  new_end = remove(v.begin(),v.end(),0);
  v.erase(new_end,v.end());
    
  showVec(v);
}