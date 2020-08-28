#include "Stack.h"

void Stack::push(Item item)
{
   List::iterator it;// null iterator
   // use insertAfter to insert at head
   list.insertAfter(it,item);
}

void Stack::pop()
{
   List::iterator it; // null iterator
   // user removeAfter to remove from head
   list.removeAfter(it);
}

Item& Stack::peek()
{  //Warning: don’t call on an empty list!
   List::iterator it = list.begin(); // get the head 
   return it.getItem(); // return the head’s item
}

bool Stack::empty()
{
   return list.empty();
}

