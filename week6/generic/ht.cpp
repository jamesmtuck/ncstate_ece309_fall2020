#include <iostream>
#include <string>
#include <random>
#include <functional>

template <typename Key, typename Hash = std::hash<Key> >
class ht {
  
  enum Status : int {
     empty_since_start = -2,
     empty_after_removal = -1,
     valid = 0
  };

  struct bucket {
    Status status;
    Key data;
    bucket():status(empty_since_start){}
  };

  bucket *table;
  size_t  size;
  Hash h;
  int probeDistance;

  void resize(); // not implemented here
  
public:
  ht(size_t M=100, int d=10):size(M),probeDistance(d) {
    table = new bucket [M];
  }

  void insert(Key key) {
    if (find(key)) return;
    int index = h(key) % size;
    int bucketsProbed=0;    
    while (bucketsProbed++ < probeDistance) { 
      if (table[index].status < valid) {
	table[index].data = key;
	table[index].status = valid;
	return;
      }
      index = (index+1)%size; // (% size) lets us wrap around to first index
    }
  }

  bool find(Key key) {
    int index = h(key) % size;
    int bucketsProbed=0;
    while (table[index].status != empty_since_start &&
	   bucketsProbed++ < probeDistance) 
      { 
	if ( table[index].data == key )
	  return true;
	index = (index+1)%size; // (% size) lets us wrap around to first index
      }
   return false;
  }

  void remove(Key key) {
    int index = h(key) % size;
    int bucketsProbed=0;
    while (table[index].status != empty_since_start
	   && bucketsProbed++ < probeDistance) 
      { 
	if ( table[index].data == key )
	  table[index].status = empty_after_removal;
	
	index = (index+1)%size; // (% size) lets us wrap around to first index
      }
  }
};


int  main()
{
  std::random_device rd;  //Will be used to obtain a seed for the random number engine
  std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
  std::uniform_int_distribution<> distrib(1, 6);
 

  ht<int> h;
  ht<std::string> s;

  h.insert(5);
  h.insert(100);

  for(int i=0; i<100000; i++) {
    h.insert( distrib(gen) % 10000 );
    h.remove( distrib(gen) % 10000 );
  }
  
  s.insert("hello");
  if (s.find("hello")) {
    std::cout << "found hello!" << std::endl;
  }

  return 0;
}
