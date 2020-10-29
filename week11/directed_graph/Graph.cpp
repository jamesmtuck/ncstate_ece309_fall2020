#include <iostream>
#include <unordered_map>
#include "Graph.h"

// Add an edge to the graph         
void Graph::addEdge(int v1,int v2) {
   addEdgeImpl(v1,v2);
   if(directed==false) // add it the other way too
      addEdgeImpl(v2,v1);
}

// class constructor, allocate all the nodes
SparseGraph::SparseGraph(int num, bool dir)
  :Graph(num,dir) /*call base class constructor*/ {
  nodes = new Node[numNodes]; // allocate node array, each entry is a node
}   
// Add an edge to the graph         
void SparseGraph::addEdgeImpl(int v1,int v2) {
   vector<int> &edges = nodes[v1].edges;
   if (std::find(edges.begin(),edges.end(),v2) == edges.end()) {
     nodes[v1].edges.push_back(v2); // add v2 to v1’s list
   }
}

// Return node’s adjacency list
vector<int> SparseGraph::getAdjacentTo(int node) 
{
   return nodes[node].edges;
}

DenseGraph::DenseGraph(int num, bool dir)
  :Graph(num,dir) {
  edges = new bool[numNodes*numNodes]; // need num*num bools
  for(int i=0; i<numNodes*numNodes; i++) edges[i] = false;
} 
                   
void DenseGraph::addEdgeImpl(int v1, int v2) {
  edges[index(v1,v2)] = true;
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


  
  /*g.addEdge(0,1);
  g.addEdge(1,4);
  g.addEdge(1,2);
  g.addEdge(4,2);
  g.addEdge(0,3);
  g.addEdge(3,2);*/

  g.addAdjacentTo(0,{1,3});
  g.addAdjacentTo(1,{0,2,4});
  g.addAdjacentTo(2,{4,3});

  for (int j : g.getAdjacentTo(2))
    std::cout << j << ", ";
  
  std::cout << std::endl;

  using node = int;
  using weight = int;

  std::unordered_map<node, std::unordered_map<node, weight> > weightMap;
  //Example
  weightMap[1][2] = 5;

  
  return 0;
}
