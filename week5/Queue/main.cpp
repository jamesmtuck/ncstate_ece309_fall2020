#include <iostream>
#include <string>
#include "Queue.h"

int main()
{
  Queue q;

  q.push("milk");
  q.push("bread");
  q.push("eggs");

  q.pop();
  
  return 0;
}
