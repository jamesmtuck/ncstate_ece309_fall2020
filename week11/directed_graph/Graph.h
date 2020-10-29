#include <vector>

using std::vector;

class Graph {
protected:                 
  int numNodes;
  bool directed;  // number of nodes
  virtual void addEdgeImpl(int src, int dst) = 0;
public:
  Graph(int num, bool dir=false)
    :numNodes(num),directed(dir){}  // create a graph with num nodes
  
  virtual void addEdge(int v1,int v2);
  virtual void addAdjacentTo(int node, vector<int> adj) {
    for (int i: adj)
      addEdge(node,i);
  }
  virtual vector<int> getAdjacentTo(int node) = 0;

  bool isDirected() const { return directed; }
};


class SparseGraph : public Graph {
protected:
  class Node {                     // represents each node
  public:
    vector<int> edges;          // adjacency list
  };
  Node *nodes;                     // array of nodes
  void addEdgeImpl(int v1, int v2) override;   // add edge from v1 to v2
public:
  SparseGraph(int num, bool dir=false);                 // create a graph with num nodes
  vector<int> getAdjacentTo(int node) override;
};


class DenseGraph : public Graph {
protected:
  bool *edges; // interpret as a 2-D array, edge[i][j] => edge[N*i + j]
  int index(int i, int j) { return i*numNodes+j; }
  void addEdgeImpl(int v1,int v2) override;   // add edge from v1 to v2
public:
  DenseGraph(int num, bool dir=false);                    // create a graph with num nodes
  vector<int> getAdjacentTo(int node) override;
};

