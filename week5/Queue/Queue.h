#include "List.h"

class Queue : public List {
 public:
  Queue(){}
  void push(Item item) {
    append(item);
  }

  Item &peek() {
    iterator it = begin();
    return it.getItem();
  }
    
  void pop() {
    removeAfter(iterator(nullptr));   
  }

  using List::empty;
};
