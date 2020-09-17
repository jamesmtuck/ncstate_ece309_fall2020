#include <iostream>
#include <string>
#include <random>

#include <functional>

int  main()
{
  int x;

  std::hash<std::string> hstr;

  std::cout << hstr("hello world!") << std::endl;
  std::cout << hstr("hello world?") << std::endl;

  std::hash<int*> hi;
  std::cout << std::hex << hi(&x) << " " << (int64_t)&x << std::endl;

  
  return 0;
}
