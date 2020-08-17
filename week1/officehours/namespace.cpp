#include <iostream>

namespace std {
  int x;
}

namespace example {
  int x;
}

using namespace std;
using namespace example;

int main() {

 
  example::x = 0;

  return 0;
}

