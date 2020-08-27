#include <vector>
#include <iostream>

bool find_single_nsquared(std::vector<int> array, int &single)
{
  for(int i=0; i < array.size(); i++)
    {
      // does array[i] have a duplicate or not?
      bool found = false;
      for(int j=i+1; j<array.size(); j++)
	{
	  if (i==j)
	    continue;
	  
	  if (array[i] == array[j])
	    {
	      found = true;
	      break;
	    }
	}

      if (!found) { // no duplicate
	single =  array[i];
	return true;
      }
    }
  
  return false;
}

bool find_single(std::vector<int> array, int &single)
{
  int sum = 0;
  for(int i=0; i < array.size(); i++)
    {
      sum = sum ^ array[i];
      //std::cout << sum << std::endl;
    }
  single = sum;
  // may need to think more about return value
  return true;
}

bool test(std::vector<int> v, int dup)
{
  int ret;
  std::cout << "Beginning a test:" << std::endl;
  find_single(v,ret);
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
  test({1,1,2,2,3} ,3);

  test({3,1,1,2,2} ,3);

  test({1,3,1,2,2} ,3);

  test({1,1,4,2,2} ,4);

  test({1,1,-2,2,2} ,-2);

  return 0;
}
