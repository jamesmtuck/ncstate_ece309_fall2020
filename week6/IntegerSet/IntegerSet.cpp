#include <iostream>
#include <string>
#include <random>

#include "IntegerSet.h"

bool IntegerSetL::insert(int data)
{
  auto it = list.begin();

  // make sure item not in list
  for(;it!=list.end(); it++) 
    // *it gets a reference to the data in the list
    if ( *it == data )
      return false;

  // add item to list
  list.push_back(data);
  return true;  
}

bool IntegerSetL::find(int data) const
{
  // make sure item not in list
  for(auto it = list.begin(); it!=list.end(); it++) 
    if ( *it == data ) {
      return true;
    }
  return false;  
}

void IntegerSetL::remove(int data)
{
  // make sure item not in list
  for(auto it = list.begin(); it!=list.end(); it++) 
    if ( *it == data ) {
      list.erase(it);
    }
}

IntegerSetHT::IntegerSetHT(int htsize, int dist)
{
   size = htsize;
   probeDistance = dist;
   // allocate table
   table = new int[size];
   // initialize table to be empty
   for(int i=0; i<size; i++)
      table[i] = -1; // -1 means empty
}


bool IntegerSetHT::insert(int data)
{
  int index = hash(data);
  int bucketsProbed=0;

  if (find(data)) return false;
  
  while (bucketsProbed++ < probeDistance) { 
    if (table[index] < 0) {
      table[index] = data;
      return true;
    }
    index = (index+1)%size; // (% size) lets us wrap around to first index
  }
  return false;
}

bool IntegerSetHT::find(int data) const
{
  int index = hash(data);
  int bucketsProbed=0;
  while (table[index] != empty_since_start && bucketsProbed++ < probeDistance) 
    { 
      if (table[index] == data)
	return true;
      index = (index+1)%size; // (% size) lets us wrap around to first index
    }
  return false;
}

void IntegerSetHT::remove(int data)
{
  int index = hash(data);
  int bucketsProbed=0;
  while (table[index] != empty_since_start && bucketsProbed++ < probeDistance) 
    { 
      if (table[index] == data)
	table[index] = empty_after_removal;
      
      index = (index+1)%size; // (% size) lets us wrap around to first index
    }
}



int  main()
{
  IntegerSetL il;
  IntegerSetHT ht;

  
  return 0;
}
