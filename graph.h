/*
  Sebastian Abt
  Project 6
  CS218
  graph.h
*/

#include "container.h"

const int startSize = 100;

class graph
{
public:
  //Constructor
  graph();
  //Destructor
  ~graph();
  //Copy Constructor
  graph(const graph&);
  //Insert Node into Graph
  void insertNode();
  //Insert Edge into Graph
  void insertEdge();
  //Delete Node from Graph
  void deleteNode();
  //Delete Edge from Graph
  void deleteEdge();
  //Search Graph for Node
  void searchNode();
  //Weighted or Not
  void settingOfWeight();
  //Displaying Graph
  void printGraph();
  //Resize Array
  void reSizeArray();
  //Is the Graph Full and need to be resized
  bool isFull();
  //Size of Graph
  void sizeofGraph();
  //Delete Graph
  void deleteGraph();

  int getLocationHolder() {return this->locationHolder;};
  void resetLocationHolder() {this->locationHolder = 0;};
  int nodesExisting() {return this->currentNodes;};
  int edgesExisting() {return this->currentEdges;};

private:
  container *graphArray[startSize];
  //Size ID's for Array Graph
  int currentNodes;
  int currentEdges;
  int maxSize;
  int locationHolder;

  //if there is a weight it will be true, other wise false
  bool hasWeight;

  //Private Functions
  //Delete Graph
  
  //Insert Node
  bool insertD(string);
  //Insert Edge
  //1st String for Id, 2nd String for 1st Node, int for weight
  bool insertE(string, string, int);
  //Delete Node
  bool deleteD(string);
  //Delete Edge
  bool deleteE(string);
  //Search Node
  bool searchN(string);
  //Search and return vertex node
  vertexNode searchVertexNode(string);
  //Search Edge
  bool searchE(string);
  //Search and return edge
  edgeNode searchEdgeNode(string);
  //Search for other edges and return their location
  int searchEdgeLocation(edgeNode);
  //ReSize Array Functions
  int newSize(int) const;
};

