/*
  Sebastian Abt
  Project 6
  CS218
  edgeNode.h
*/

#include "vertexNode.h"

//edgeNode that will contain the following options
//If a weighted graph is created it will store the weight
//if it's unweighted it will not store weight;

class edgeNode {
public:
  edgeNode() {
  	this->id = " ";
  	this->weight = 0;
  };
  ~edgeNode() {
  	this->weight = 0;
  }

  //Weight functions
  void setWeight(int aWeight) {this->weight = aWeight;};
  int getWeight() {return this->weight;};
  void printWeight(){cout << getWeight();};

  //Identification Purposes
  void setID(string aId) {this->id = aId;};
  string getID() {return this->id;};
  void printId() {cout << getID();};

private:
  // Weight of the graph for weighted
  int weight;
  string id;
};
