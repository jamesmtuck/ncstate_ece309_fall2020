#include <vector>

using std::vector;

class Graph {
protected:                 
  int numNodes;                      // number of nodes

public:
  Graph(int num):numNodes(num){}     // create a graph with num nodes
  virtual void addEdge(int v1,int v2) {}

  virtual void addAdjacentTo(int node, vector<int> adj) { 
     for (int to: adj) addEdge(node,to);
  }

  virtual vector<int> getAdjacentTo(int node) { return {}; }
};

class SparseGraph : public Graph {
protected:
  class Node {                     // represents each node
  public:
    vector<int> edges;          // adjacency list
  };
  Node *nodes;                     // array of nodes
public:
  SparseGraph(int num);                 // create a graph with num nodes
  void addEdge(int v1,int v2) override; // add edge from v1 to v2
  vector<int> getAdjacentTo(int node) override;
};


class DenseGraph : public Graph {
protected:
  bool *edges; // interpret as a 2-D array, edge[i][j] => edge[N*i + j]
  int index(int i, int j) { return i*numNodes+j; }
public:
  DenseGraph(int num);                    // create a graph with num nodes
  void addEdge(int v1,int v2) override;   // add edge from v1 to v2
  vector<int> getAdjacentTo(int node) override;
};
