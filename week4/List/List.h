// List.h

using Item = std::string;

class List
{
private:
  class ListNode
  {
  public:
    Item item;
    ListNode *next;
    ListNode(Item a, ListNode *n=nullptr):item(a),next(n) {}
  };
  
  ListNode *head;
  ListNode *tail;

public:

  // declared public inside List
  class iterator {
  private:
    ListNode *node; // private, implementation details hidden
  public: 
    iterator(ListNode *n=nullptr) { node = n; }
    Item &getItem() { return node->item; }
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

    friend class List;
  };
  
  iterator begin() { return iterator(head); }  // in List
  iterator end() { return iterator(nullptr); } // in List

  List():head(nullptr),tail(nullptr) {}
  List(const List &other);
  
  void append(Item a);
  bool empty() { return head==nullptr; }
  bool remove(Item &copy);

  void removeAfter(iterator it) ;
  void insertAfter(iterator it, Item item);
};
