#include <iostream>

class W {
};

class X : public W {
};

class Y {
};

W w;
X x;
Y y;

int f(X &a, int i=0)
{
  std::cout << "A" << std::endl;
  return 0;
}

int f(W &b, double d=0.0)
{
  std::cout << "B" << std::endl;
  return 0;
}

int f(Y &c)
{
  std::cout << "C" << std::endl;
  return 0;
}

int main()
{
  f(x,0.0);
  return 0;
}
