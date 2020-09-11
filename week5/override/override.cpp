#include <iostream>
class Base {
public:
  void f(int x) { std::cout << "Base::f()\n"; }
  void f(double d) { std::cout << "Base::f(d)\n";}
};

class Derived : public Base {
public:
  void f() { std::cout << "Derived::f()\n"; }
};

int main() {
  Derived d; 
  d.f(); // which one?
  return 0;
}
