#include <iostream>

using namespace std;

class Complex {
private:
   double real;
   double imag;

  int array[100];
public:
  Complex():real(0), imag(0) {}
  
  Complex(double re, double im) 
  {
    real = re; imag = im;
  }
  void add(Complex c)
  {
    real += c.real;
    imag += c.imag;
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

  c = y; // assign y to c

  std::cout << "\nc = "; c.print();
  std::cout << "\n";
  
  return 0;
}
