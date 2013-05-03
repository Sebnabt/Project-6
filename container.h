/*
  Sebastian Abt
  Project 6
  CS218
  container.h
*/

#include "edgeNode.h"

const int edges = 10;
const int increaseEdges = 5;

class container
{
public:
  container();
  ~container();
  container(const container&);
  
  vertexNode *vNode;
  edgeNode *edgeArray;
  edgeNode *copyArray;
  
  bool isFull();
  bool isEmpty();
  bool deleteEdgeArray();
  bool insertNode(vertexNode*);
  bool removeNode(vertexNode*);
  void insertEdge(edgeNode*);
  int resize(int);
  bool removeEdge(edgeNode*);
  bool findEdge(string);
  edgeNode getEdge(string);
  int getCurrentSize() {return this->currentSize;};
private:
  int currentSize;
  int maxSize;

};

