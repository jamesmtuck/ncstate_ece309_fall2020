#include <iostream>

using namespace std;

class Complex {
private:
   double real;
   double imag;
public:
  Complex():real(0), imag(0) {}
  
  Complex(double re, double im) 
  {
    real = re; imag = im;
  }
  Complex operator+(Complex &rhs)
  {
    Complex c;
    c.real = real+rhs.real;
    c.imag = imag+rhs.imag;
    return c;
  }

  
  void print()
  {
    cout << real << " + " << imag <<"j";
  }

};


int main()
{
  Complex j(0,1);
  Complex x = j;


  std::cout << "j = " ; j.print();
  std::cout << "\n"; // newline
  std::cout << "x = " ; x.print();

  Complex y(1,0);
  Complex c;

  c = y + y; // assign y to c

  std::cout << "\nc = "; c.print();
  std::cout << "\n";
  
  return 0;
}
