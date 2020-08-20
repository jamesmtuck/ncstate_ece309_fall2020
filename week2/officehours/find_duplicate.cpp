#include <vector>
#include <iostream>

int find_duplicate(std::vector<int> array)
{
  for(int i=0; i < array.size(); i++)
    {
      int at_i = array[i];
      
      for(int j=i+1; j < array.size(); j++)
	{
	  int at_j = array[j];
	  if (at_i == at_j) {
	    return at_i;
	  }	  
	}
    }
  
  return 0;
}

bool test(std::vector<int> v, int dup)
{
  int ret = find_duplicate(v);
  if (ret==dup)
    {
      std::cout << "Correct.\n";
    }
  else
    {
      std::cout << "Incorrect.\n";
    }
  return false;
}


int main()
{
  test({1,2,3,4,5,1},1);
  test({1,1,3,4,5,6},1);
  test({1,2,3,6,5,6},6);
  test({1,2,3,6,5,6,1,8},1);

  return 0;
}
