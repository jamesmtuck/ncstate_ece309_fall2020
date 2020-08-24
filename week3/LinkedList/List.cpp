#include <iostream>
#include <string>

using Item = std::string;

class ListNode
{
public:
  Item item;
  ListNode *next;
  ListNode(Item a):item(a),next(nullptr) {}
};

class List
{
private:
  ListNode *head;
  ListNode *tail;

public:
  List():head(nullptr),tail(nullptr) {}

  void append(Item a);
  bool empty() { return head==nullptr; }
  bool remove(Item &copy);

  // declared public inside List
  class iterator {
  private:
    ListNode *node; // private, implementation details hidden
  public: 
    iterator(ListNode *n=nullptr) { node = n; }
    Item& getItem() { return node->item; }
    void next() { node = node->next; }
    bool operator==(const iterator &other) {
      return node == other.node;
    }
    // check if two iterators are not equal
    bool operator != (const iterator &other) {
      return node != other.node;
    }
    iterator& operator++() 
    {
      next();
      return *this;
    }

  };
  iterator begin() { return iterator(head); }  // in List
  iterator end() { return iterator(nullptr); } // in List
};

void List::append(Item a) 
{
  ListNode *node = new ListNode(a);
  if (head==nullptr) { 
    // list is empty, so set head and 
    // tail to be node
    head = node;
    tail = node;
  } else {
    // put new node at end of list
    tail->next = node;
    tail = node;
  }
}


bool List::remove(Item &copy) 
{
  if (!empty()) // if list is not empty
    {
      copy = head->item; // return copy
      ListNode *tmp = head->next;
      delete head; // delete the node
      head = tmp;  // update the head
      if (tmp==nullptr) // removed last element 
	tail = nullptr;
      return true;
    }
  return false; // nothing in list
}


int main()
{
  List l;

  l.append("milk");
  l.append("eggs");
  l.append("coffee");
  l.append("bread");

  Item rm;
  int i=1;
  while(l.remove(rm))
    {
      std::cout << i++ << ". " << rm << std::endl;
    }

  l.append("milk");
  l.append("eggs");
  l.append("coffee");
  l.append("bread");

  List::iterator it = l.begin();

  while(it!=l.end()) {
    Item &a = it.getItem();
    std::cout << a << std::endl;
    ++it;
  }
  
  return 0;
}
