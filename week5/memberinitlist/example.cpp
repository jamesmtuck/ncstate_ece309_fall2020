#include <iostream>

class A {
   int a;
public:
   int b;
   A(int x, int y) { a = x; b = y;
     std::cout << "A(x,y)" << std::endl; 
   }
};

class B : public A {
    int c;
public:
  B() : A(1,1) { // member init list
    c = 0;
    std::cout << b << " " << c << std::endl;
  }
};

int main()
{
  B b;
  return 0;
}
