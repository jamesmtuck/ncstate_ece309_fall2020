#include <iostream>
#include <string>

using namespace std;

int main()
{
  // C++ style
  string one = "he1lo";
  string two = "hello!";

  cin >> one;
  
  for (int x = 0; x < one.length(); x++)
    {
      cout << "one[" << x << "] = " << one[x] << endl;
    }

  if (one.at(0) == 'h' && one.at(1) == 'e' && one.at(2) == 'l')
    {
      cout << "first 3 letters are hel." << endl;
    }

  int pos=string::npos;
  if ( (pos=one.find("e1l")) < one.size() )
    {
      cout << "there's a match at " << pos << "!" << endl;
    }
  
  // C style:
  
  char hello[] = "hello";

  if ( strcmp(hello, "hello") == 0 )
    {
      printf("%s == hello\n", hello);
    }

  if (hello[0] == 'h' && hello[1] == 'e' && hello[2] == 'l')
    {
      cout << "first 3 letters are hel." << endl;
    }

  return 0;
}
