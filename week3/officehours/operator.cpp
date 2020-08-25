#include <iostream>
#include <string>

using namespace std;

class Apple {
public:
  int x;
  Apple(int a=0) { x = a; }

  Apple operator+(Apple other) {
    if (this == &other)
      {
	std::cout << "adding apple to itself" ;
      }

    
    Apple result(x + other.x);
    return result;
  }

  /*Apple& operator= (const Apple &other)
  {
    if (this == &other)
      // you're done
      return *this;
  }


  Apple& operator+= (const Apple &other)
  {
    if (this == &other)
      // you're done
      return *this;
      }*/
};


//operator+

ostream& operator << (ostream& out, Apple &a)
{
  out << "Apple(" << a.x << ")";
  return out;
}


int main()
{
  Apple a;
  Apple b(1);

  a+1;
  
  (cout << a) << endl;
  
  return 0;
}
