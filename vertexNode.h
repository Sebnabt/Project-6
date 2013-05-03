/*
  Sebastian Abt
  Project 6
  CS218
  vertexNode.h
*/

#include <string.h>
#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;


/*
Basic vertexNode Class for Containing the Vertex of the Graph
*/
class vertexNode {
public:
  vertexNode() {
  	this->vertex = " ";
  };

  ~vertexNode() {
  	this->vertex = " ";
  };

  vertexNode(vertexNode &aCopy) {
  	this->vertex = aCopy.getVertex();
  };

  vertexNode(vertexNode* aCopy) {
  	this->vertex = aCopy->getVertex();
  };

  void setVertex(string aVertex) {this->vertex = aVertex;};
  string getVertex() {return this->vertex;};

  void printVertex() { cout << getVertex();};
private:
  string vertex;
};

