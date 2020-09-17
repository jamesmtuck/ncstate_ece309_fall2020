#include <list>

using std::list;

// ABC for IntegerSet
class IntegerSet {
public:
   virtual bool insert(int) = 0;
   virtual bool find(int) const = 0;
   virtual void remove(int) = 0;
};

class IntegerSetL : public IntegerSet {
   list<int> list;
public:
   bool insert(int) override;
   bool find(int) const override;
   void remove(int) override;
};

class IntegerSetHT : public IntegerSet {
protected:
   enum Status : int {
     empty_since_start = -2,
     empty_after_removal = -1,
     valid = 0
   };   
  
   int size;
   int hash(int key) const { return (key * 997) % size; }
   int *table;  // pointer to the table
   int probeDistance;
   
 public:
   IntegerSetHT(int htsize=1000, int dist=10);
   // override ABC
   bool insert(int) override; //override keyword asks compiler to do extra checks
   bool find(int) const override;
   void remove(int) override;
};


