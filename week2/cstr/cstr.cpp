#include <iostream>
#include <string.h>

class cstr {
private:
  char *array;
  int size;
  char dummy;

public:
  cstr():array(nullptr),size(0) {}

  cstr(int n):size(n)
  {
    array = new char [n+1]; // add 1 for null character
    for (int i=0; i<n; i++)
      array[i] = ' ';
    array[n] = 0;
  }

  cstr(const char* str) {
    array = strdup(str);
    size = strlen(array);
  }

  const char * getArray() { return array; }
  int getSize() { return size; }

  char & get(int i) {
    if (i < 0 || i >= size) {
      // dummy location
      return dummy;
    }
    
    return array[i];
  }

  void print(bool newline=true)
  {
    for(int i=0; i<size; i++)
      std::cout << array[i];
    if (newline)
      std::cout << std::endl;
  }
};

int main()
{
  cstr t ("hello!");

  t.get(0) = 'H';
  t.get(100) = 'X';
  t.print();
  
  return 0;
}
