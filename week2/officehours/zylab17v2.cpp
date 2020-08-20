#include <iostream>
#include <string>

using namespace std;

int main()
{
  string line;

  while(1) {
    getline(cin,line);

    if ( line == "Quit" || line == "quit" || line == "q"  )
      break;
    
    // implement the reverse functionality
    for(int i = line.length()-1; i>=0; --i)
      {
	cout << line.at(i);
      }

    cout << endl;
  }

  return 0;
}


    
