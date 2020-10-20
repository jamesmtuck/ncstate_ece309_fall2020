#include <iostream>
#include "Graph.h"

// class constructor, allocate all the nodes
SparseGraph::SparseGraph(int num)
  :Graph(num) /*call base class constructor*/ {
  nodes = new Node[numNodes]; // allocate node array, each entry is a node
}   
// Add an edge to the graph         
void SparseGraph::addEdge(int v1,int v2) {
   vector<int> &edges = nodes[v1].edges;
   if (std::find(edges.begin(),edges.end(),v2) == edges.end()) {
     nodes[v1].edges.push_back(v2); // add v2 to v1’s list
     // since edges are bi-directional, we add it both ways:
     nodes[v2].edges.push_back(v1); // add v1 to v2’s list
   }
}

// Return node’s adjacency list
vector<int> SparseGraph::getAdjacentTo(int node) 
{
   return nodes[node].edges;
}

DenseGraph::DenseGraph(int num)
:Graph(num) {
  edges = new bool[numNodes*numNodes]; // need num*num bools
  for(int i=0; i<numNodes*numNodes; i++) edges[i] = false;
} 
                   
void DenseGraph::addEdge(int v1, int v2) {
  edges[index(v1,v2)] = true;
  edges[index(v2,v1)] = true;
}
// Return node’s adjacency list
vector<int> DenseGraph::getAdjacentTo(int node) 
{
   vector<int> adj;
   for(int i=0; i<numNodes; i++) {
      if (edges[index(node,i)]) {
         adj.push_back(i);
      }
   }
   return adj;
}


int main() {
  
  Graph &g = *(new SparseGraph(5));

  g.addEdge(0,1);
  g.addEdge(1,4);
  g.addEdge(1,2);
  g.addEdge(4,2);
  g.addEdge(0,3);
  g.addEdge(3,2);

  g.addAdjacentTo(0,{1,3});
  g.addAdjacentTo(1,{0,2,4});
  g.addAdjacentTo(2,{4,3});

  for (int j : g.getAdjacentTo(2))
    std::cout << j << ", ";
  
  std::cout << std::endl;
  
  return 0;
}
