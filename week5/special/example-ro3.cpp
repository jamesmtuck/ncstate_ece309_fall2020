
#include <iostream>

using namespace std;

class Base {
  int * a;
public:
  int b;
  void print() {
    cout << "[ " ;
    for (int i=0;i<10; i++)
      cout << a[i] << ", ";
    cout <<"] ";
    cout << b << endl;
  }
  Base(int aa=0, int bb=0):a(nullptr),b(bb) {
    a = new int [10];
    for (int i=0; i<10; i++) a[i] = aa;
  }
  ~Base() { delete [] a; cout << "Destroy B" << endl; }
  Base(const Base &other) {
    b = other.b;
    a = new int [10];
    for(int i=0; i<10; i++)
      a[i] = other.a[i];
  }
  Base& operator=(const Base &other)
  {
    if ( this == &other) return *this;

    delete [] a;
    
    b = other.b;
    a = new int [10];
    for(int i=0; i<10; i++)
      a[i] = other.a[i];
    
    return *this;
  }
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
  Derived d1(1,2,3,4);

  Derived d2(3,4,5,6);

  Derived d3 = d1;

  d3.print();
  d3 = d2;
  d3.print();
  
  return 0;
}
