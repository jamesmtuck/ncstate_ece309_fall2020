#include <vector>

using std::vector;

class Graph {
public:
  class edge {
  public:
    edge(int n, int w=0):dst(n),weight(w){}
    int dst;
    int weight;
    bool operator==(edge other) {
      return dst == other.dst;
    }
  };
  
protected:                 
  int numNodes;
  bool directed;  // number of nodes
  virtual void addEdgeImpl(int src, int dst, int w=0) = 0;
public:
  Graph(int num, bool dir=false)
    :numNodes(num),directed(dir){}  // create a graph with num nodes
  
  virtual void addEdge(int v1,int v2,int w=0);
  virtual void addAdjacentTo(int node, vector<edge> adj) {
    for (edge e: adj)
      addEdge(node,e.dst,e.weight);
  }
  virtual vector<edge> getAdjacentTo(int node) = 0;

  bool isDirected() const { return directed; }
};


class SparseGraph : public Graph {
protected:
  class Node {                     // represents each node
  public:
    vector<edge> edges;          // adjacency list
  };
  Node *nodes;                     // array of nodes
  void addEdgeImpl(int v1, int v2, int w=0) override;   // add edge from v1 to v2
public:
  SparseGraph(int num, bool dir=false);                 // create a graph with num nodes
  vector<edge> getAdjacentTo(int node) override;
};


class DenseGraph : public Graph {
protected:
  bool *edges; // interpret as a 2-D array, edge[i][j] => edge[N*i + j]
  int  *weights;
  int index(int i, int j) { return i*numNodes+j; }
  void addEdgeImpl(int v1,int v2,int w=0) override;   // add edge from v1 to v2
public:
  DenseGraph(int num, bool dir=false);                    // create a graph with num nodes
  vector<edge> getAdjacentTo(int node) override;
};

