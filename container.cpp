/*
  Sebastian Abt
  Project 6
  CS218
  container.cpp
*/
#include "container.h"


container::container() {
  this->vNode = new vertexNode();

  this->edgeArray = new edgeNode[edges];
  
  for(int i = 0; i < edges; i++) {
  	edgeArray[i] = *new edgeNode();
  }
  
  currentSize = -1;
  maxSize = edges;
}


container::~container() {
  delete this->vNode;
  for(int i = 0; i < edges; i++) {
  	delete &this->edgeArray[i];
  }
  currentSize = -1;
  maxSize = edges;
}
container::container(const container& aCopy) {
  for(int i = 0; i < maxSize; i++) {
  	edgeArray[i] = aCopy.edgeArray[i];
  }
  currentSize = aCopy.currentSize;
  maxSize = aCopy.maxSize;
}

bool container::isFull() {
  if (this->currentSize == this->maxSize)
  	return true;
  else
  	return false;
}

bool container::isEmpty() {
  if (this->currentSize == -1)
  	return true;
  else
  	return false;
}
bool container::insertNode(vertexNode *anNode) {
  if (this->vNode->getVertex() == " ") {
  	this->vNode = anNode;
  	return true;
  }
  else
  	return false;
}

bool container::removeNode(vertexNode *anNode) {
  if (this->vNode->getVertex() == anNode->getVertex()) {
  	delete this->vNode;
  	vNode = NULL;
  	return true;
  }
  else {
  	return false;
  }
}
void container::insertEdge(edgeNode *anEdge) {
  if (isFull() == false) {
  	currentSize = currentSize + 1;
  	edgeArray[currentSize] = *anEdge;
  }
  else {
  	int newCurrentSize = resize(this->currentSize);
  	
  	copyArray = new edgeNode[newCurrentSize];
  	//allocate memory for copy array
  	for (int i = 0; i < newCurrentSize; i++) {
  		copyArray[i] = *new edgeNode();
  	}
  	//Begin to copy the edges into the resized array
  	for (int i = 0; i < this->currentSize; i++) {
  		copyArray[i] = edgeArray[i];
  	}
  	
  	this->maxSize = newCurrentSize;

  	delete [] this->edgeArray;

  	edgeArray = copyArray;

  	//reallocate memory
  	delete [] this->copyArray;
  	delete this->copyArray;

  	//add in new edge
  	insertEdge(anEdge);
  }
}

int container::resize (int aSize) {
  int newSize = 0;
  return (newSize = aSize + increaseEdges);
}

bool container::removeEdge(edgeNode *tobeRemoved) {
  //First we need to find it
  edgeNode *temp = new edgeNode();
  for(int i = 0; i < this->currentSize; i++) {
  	*temp = edgeArray[i];
  	//if we found it good
  	if( temp->getID() == tobeRemoved->getID()) {
  		delete temp;
  		edgeArray[i] = *new edgeNode();
  		currentSize = currentSize - 1;
  		return true;
  	}
  }
  return false;
}

bool container::findEdge(string anEdge) {
  string temp = " ";
  for(int i = 0; i < this->currentSize; i++) {
  	temp = edgeArray[i].getID();
  	
  	if(temp == anEdge) {
  		return true;
  	}
  }

  return false;
}

edgeNode container::getEdge(string aId) {
  edgeNode *holder = new edgeNode;
  for (int i = 0; i < this->currentSize; i++) {
  	*holder = edgeArray[i];
  	if(aId == holder->getID()) {
  		return *holder;
  		delete holder;
  	}
  }

  holder = NULL;

  return *holder;
}

bool container::deleteEdgeArray() {
  for(int i = 0; i < this->maxSize; i++) {
  	delete &this->edgeArray[i];
  }
  delete [] edgeArray;
  delete edgeArray;
  edgeArray = NULL;
  
  if (this->edgeArray != NULL) {
  	return false;
  }
  else {
  	return true;
  }
}
