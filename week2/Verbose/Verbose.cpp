#include <iostream>
#include <string>

class Verbose {
  std::string msg;
public:

  Verbose(std::string m)
  {
    msg = m; std::cout << msg << ": I’m born!\n";
  }
  ~Verbose()
  {
    std::cout << msg << ": I’m gone!\n";
  }
};

Verbose global("global");


int main() {
  Verbose local("local"); // local variable on the stack

  std::cout << "Start main()\n";

  Verbose *heap = new Verbose("heap");
  
  std::cout << "End main()\n";
  
  return 0; 
}
