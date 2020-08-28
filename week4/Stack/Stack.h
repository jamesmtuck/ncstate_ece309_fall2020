// Stack.h

#include "List.h"

class Stack {
private:
   List list; // use singly linked list
public:
   Stack() {}
   void push(Item);
   void pop();
   Item& peek();
   bool empty();
};
