#include <iostream>
#include <string>
class BTNode {
public:
  BTNode(int d,BTNode *l=nullptr, BTNode *r=nullptr)
    :data(d), left(l), right(r)
  {}
  int data;
  BTNode *left;
  BTNode *right;
};


void TreeTraversalHelper(BTNode *node, int tab=0)
{
  std::string tabs(tab*3,' ');

  if(node==NULL) {
    std::cout << tabs << "got a null!" << std::endl;
    return; // base case, stop at NULL nodes
  }
  std::cout << tabs << "First arrived at node " << node->data << std::endl;
  
   std::cout << tabs << "Visit left side of " << node->data << std::endl;
   TreeTraversalHelper(node->left, tab+1);

   std::cout << tabs << "Visit: " << node->data << std::endl;
   
   std::cout << tabs << "Visit right side of " << node->data << std::endl;
   TreeTraversalHelper(node->right, tab+1);

   std::cout << tabs << "Done with " << node->data << std::endl;
}

int main()
{
  BTNode *root = new BTNode(100,
			    new BTNode(25),
			    new BTNode(150, new BTNode(125)));
  
  TreeTraversalHelper(root);

  std::cout << std::endl << "End of program." << std::endl;

  return 0;
}
