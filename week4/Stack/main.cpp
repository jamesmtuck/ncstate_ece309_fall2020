#include "Stack.h"
#include <iostream>

using namespace std;

int main()
{
  Stack stack;

  while(true) {
    string s;

    cin >> s;
    if (s=="quit")
      break;

    stack.push(s);
  }

  while(!stack.empty()) {
    cout << stack.peek() << endl;
    stack.pop();
  }

  return 0;
}
