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
public:
  int &c;
  B(int &r) : A(1,1), c(r) { // member init list
    c = 0;
    std::cout << b << " " << c << std::endl;
  }
};

int main()
{
  int x = 0;
  B b(x);

  b.c = 5; // same as x
  std::cout << x << std::endl;
  
  return 0;
}
