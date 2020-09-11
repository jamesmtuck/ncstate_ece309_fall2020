#include <iostream>
#include <string>

#include "List.h"

using namespace std;

int main()
{
  List<string> l;
  List<int> l2;

  l.append("milk");
  l.append("eggs");
  l.append("coffee");
  l.append("bread");

  l2.append(1);
  l2.append(2);
  l2.append(3);
  
  auto it = l.begin();
  it = l.begin();
  while(it!=l.end()) {
    string &a = it.getItem();
    std::cout << a << std::endl;
    ++it;
  }
  
  return 0;
}
