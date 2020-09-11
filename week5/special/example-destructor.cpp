#include <iostream>

using namespace std;

class Base {
public:
  virtual ~Base(){}
};

class Derived : public Base {
   int *a;
public:
   Derived():Base() {
     a = new int [10];
   }
  ~Derived() { delete [] a; std::cout << "Delete Derived!" << endl;}
};

// in main:

int main()
{
  Base *b = new Derived();
  delete b;
  return 0;
}
