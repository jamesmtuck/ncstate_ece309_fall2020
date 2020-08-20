

class Complex {
private:
  double real;
  double imag;

  void private_update(double r, double i) {
    real = r;
    imag = i;
  }

  
public:
  Complex(double r, double i)
  {
    real = r;
    imag = i;
  }

  void add(Complex another) {
    real += another.real;
    imag += another.imag;
  }

  void make_imaginary() {
    imag = 1;
  }

  void update(double r, double i)
  {
    private_update(r,i);
  }
  
};

int main()
{
  Complex c(1,0);
  c.update(1,0);

  Complex d(0,1);

  d.add(c);

  Complex *ptr = new Complex(1,1);
  (*ptr).update(1,0);
  ptr->update(1,0);

  

  return 0;
}
