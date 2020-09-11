
#include <iostream>

using namespace std;

class Base {
  int a;
public:
  int b;
  void print() {
    cout << a << " " << b << endl;
  }
  Base(int aa=0, int bb=0):a(aa),b(bb) { }
};

class Derived : public Base {
  int c;
public:
  int d;

  Derived(int a=0, int b=0, int ac=0, int ad=0):Base(a,b),c(ac),d(ad) {}
  
  void print()
  {
    Base::print();
    cout << c << " " << d << endl;
  }
};

int main()
{
  Derived d(1,2,3,4);
  d.print();

  Derived d2;

  d2 = d;

  d2.print();
  
  return 0;
}
