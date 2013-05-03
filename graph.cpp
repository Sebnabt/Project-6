/*
  Sebastian Abt
  Project 6
  CS218
  graph.cpp
*/

#include "graph.h"

//Constructor
graph::graph() {
  for(int i = 0; i < startSize; i++) {
  	this->graphArray[i] = new container();
  }
  currentNodes = 0;
  currentEdges = 0;
  maxSize = startSize;
  locationHolder = 0;
}
//Destructor
graph::~graph() {
  for(int i = 0; i < startSize; i++) {
  	delete this->graphArray[i];
  }
  delete graphArray;

  currentNodes = 0;
  currentEdges = 0;
  maxSize = startSize;
  locationHolder = 0;
}
//Copy Constructor
graph::graph(const graph& aCopy) {
  for(int i = 0; i < aCopy.maxSize; i++) {
  	this->graphArray[i] = aCopy.graphArray[i];
  }
  currentNodes = aCopy.currentNodes;
  currentEdges = aCopy.currentEdges;
  maxSize = aCopy.maxSize;
  locationHolder = aCopy.locationHolder;
}
//Insert Node into Graph
void graph::insertNode() {
  string name = " ";
  cout << endl;
  cout << "Welcome to the Insert Node Method.\n";
  cout << "To create the Node, please give it a name.\n";
  cout << "Name: "; cin >> name;

  if (insertD(name) == true && isFull() == false) {
  	this->currentNodes = currentNodes + 1;
  	cout << "The Node " << name << " was successfully inserted.\n";
  }
  else if (isFull() == true) {
  	cout << "I'm sorry but the array is currently full of Nodes.\n";	
  }
  else {
  	cout << "I'm sorry but it wasn't inserted." << endl;
  }
}
//Insert Edge into Graph
void graph::insertEdge() {
  string id = " "; string vNode = " ";
  int weight = 0; int nCount = 0;
  bool quit = false;
  cout << "Welcome to the Insert Edge Method.\n";
  cout << "To insert an edge, there must be more than 1 node in the graph.\n";
  while (quit == false) {
  	if (currentNodes < 1) {
  		cout << "I'm sorry but you need to add a node into the graph.\n";
  		quit = true;
  		break;
  	}

  	if (nCount == 0) {
  		quit = true;
  	}

  	cout << "How many nodes would you like connected to this new edge?\n";
  	cout << "Node Count: "; cin >> nCount;

  	if (nCount == 0) {
  		quit = true;
  	}


  	if (nCount > currentNodes) {
  		cout << "I'm sorry but there are only " << currentNodes << " and you entered " << nCount << ".\n";
  		cout << "Please try entering a correct number of nodes to connect to this graph.\n";
  	}
  		
  	if (hasWeight == true) {
  		cout << "Please enter a name and weight for the edge.\n";
  		cout << "Edge Name: "; cin >> id;
  		cout << "\nWeight Amount: "; cin >> weight;
  					
  	}
  	else if(hasWeight == false) {
  		cout << "Please enter a name for the edge.\n";
  		cout << "Edge Name: "; cin >> id;
  		weight = 0;
  	}

  	while(nCount != 0){
  		bool firstNode = true;
  		cout << "Please enter the node you would like to connect to: "; cin >> vNode;
  		if (searchN(vNode) == true) {
  			cout << "Node found.\n";
  			
  			if (insertE(id,vNode,weight) == true) {
  				cout << "Edge was succesfully inserted to node << " << vNode << "\n";
  				this->currentEdges = currentEdges + 1;
  				nCount--;	
  			}
  		}
  			
  		else {
  			cout << "Node wasn't found\n";

  		}
  	}
  }
}
//Delete Node from Graph
void graph::deleteNode() {
  string name = " ";
  cout << "Welcome to the Delete Node Method.\n";
  cout << "To remove your node, please enter it's ID.\n";
  cout << "Name: "; cin >> name;

  if (searchN(name) == true) {
  	cout << "Node Found...\n";
  	cout << "Begining removal.\n";
  	if (deleteD(name) == true) {
  		cout << "Node with name " << name << " was removed\n";
  	}
  	else {
  		cout << "Node wasn't removed.\n";
  	}
  }
  else {
  	cout << "Node couldn't be found.\n";
  }
}
//Delete Edge from Graph
void graph::deleteEdge() {
  string name = " ";
  cout << "Welcome to the Delete Edge Method.\n";
  cout << "To remove your node, please enter it's ID.\n";
  cout << "Name: "; cin >> name;

  if (searchE(name) == true) {
  	cout << "Edge Found...\n";
  	cout << "Begining removal.\n";
  	if (deleteE(name) == true) {
  		cout << "Edge with name " << name << " was removed\n";
  	}
  	else {
  		cout << "Edge wasn't removed.\n";
  	}
  }
  else {
  	cout << "Edge couldn't be found.\n";
  }
}
//Search Graph for Node
void graph::searchNode() {
  string searchedNode = " ";
  cout << "Welcome to the Search Method. To find your node please type it's ID.\n";
  cout << "Node: "; cin >> searchedNode;

  if (searchN(searchedNode) == true) {
  	cout << "The Node: " << searchedNode << " exists.";
  }
  else {
  	cout << "The Node: " << searchedNode << " doesn't exist.";
  }
}
//Weighted or Not
void graph::settingOfWeight() {
  string in = " ";
  while(true) {
  	cout << "Would you like this to be a weighted graph? Yes or No?\n";
  	cout << "Yes or No? "; cin >> in;
  
  	if (in[0] == 'Y' || in[0] == 'y') {
  		cout << "Weight is turned on.\n";
  		hasWeight = true;
  		break;
  	}
  	else if (in[0] == 'N' || in[0] == 'n') {
  		cout << "Weight is turned off.\n";
  		hasWeight = false;
  		break;
  	}
  	else {
  		cout << "Wrong command entered.";
  		cout << "\n Please try again.\n";
  	}
  }
}
//Displaying Graph
void graph::printGraph() {
  if (hasWeight == true) {
  	cout << "Printing Nodes with Edge ID's and Weights." << endl << endl;
  	for(int i = 0; i <= currentNodes; i++) {
  		graphArray[i]->vNode->printVertex();
  		cout << " | ";
  		
  		for(int x = 0; x < graphArray[i]->getCurrentSize(); x++) {
  			if (graphArray[i]->edgeArray[x].getID() != " ") {
  				cout << "->";
  			}
  			if (graphArray[i]->edgeArray[x].getID() != " ") {
  				cout << "[ ";
  				graphArray[i]->edgeArray[x].printId();
  				cout << " | ";
  				graphArray[i]->edgeArray[x].printWeight();
  				cout << " ]";
  			}
  			
  		}
  		cout << "\n";
  	}

  }
  else {
  	cout << "Printing Nodes with Edge ID's" << endl << endl;
  	for(int i = 0; i < currentNodes; i++) {
  		cout << endl;
  		graphArray[i]->vNode->printVertex();
  		cout << " | ";
  		
  		for(int x = 0; x <= graphArray[i]->getCurrentSize(); x++) {
  			if (graphArray[i]->edgeArray[x].getID() != " ") {
  				cout << "->";
  			}
  			if (graphArray[i]->edgeArray[x].getID() != " ") {
  				graphArray[i]->edgeArray[x].printId();
  				
  			}
  		}
  	}
  }
  cout << endl << endl << endl;
}


//Size of Graph
void graph::sizeofGraph() {
  cout << endl;
  cout << "The Aspects of the Graph is:\n";
  cout << "Max Size is: " << maxSize << "\n";
  cout << "Current amount of Nodes: " << currentNodes << "\n";
  cout << "Current amount of Edges: " << currentEdges << "\n";
  cout << endl;
}

//Private Functions
//Delete Graph
void graph::deleteGraph() {
  container *newArray[startSize];
  //Creates new graph
  for(int i = 0; i < startSize; i++) {
  	newArray[i] = new container();
  }
  //Deletes old graph
  for(int i = 0; i < this->maxSize; i++) {
  	cout << "Deleting Node at location " << i << "\n";
  	delete graphArray[i];
  }
  delete graphArray;

  //reset all graph variables
  currentNodes = -1;
  currentEdges = -1;
  maxSize = startSize;
  locationHolder = 0;


  cout << "New Graph has been created.\n";
  *graphArray = *newArray;
}
//Insert Node
bool graph::insertD(string aName) {
  cout << "Creating New Node with name " << aName << "\n";
  
  vertexNode *newNode = new vertexNode();
  newNode->setVertex(aName);
  cout << "New Node Created.\n";
  
  if(graphArray[currentNodes] != NULL) {
  	//Places the Node into the Array at the spot where there is currently free
  	graphArray[currentNodes]->insertNode(newNode);
  	return true;
  }
  else {
  	cout << "New Node could not be created.\n";
  	cout << "Deleting Node.\n";
  	delete newNode;
  	return false;
  }

  
}
//Insert Edge
bool graph::insertE(string eId, string vNode, int aWeight) {
  vertexNode *fNode = new vertexNode(); //First Node
  vertexNode *holder = new vertexNode();//used for searching
  
  edgeNode *insertedEdge = new edgeNode();

  insertedEdge->setID(eId);
  insertedEdge->setWeight(aWeight);

  *fNode = searchVertexNode(vNode);
  if (this->graphArray[getLocationHolder()]->vNode->getVertex() != fNode->getVertex()) {
  	cout << "Node doesn't Exist.\n";
  	delete fNode;
  	delete holder;
  	delete insertedEdge;
  	return false;
  }
  else {
  	cout << "Edge Inserted into Node.\n";
  	graphArray[getLocationHolder()]->insertEdge(insertedEdge);
  	return true;
  }
  
}
//Delete Node
bool graph::deleteD(string aName) {
  bool quit = false;
  cout << "Deleting Node and Edges that connect to Node.\n";

  vertexNode *holder = new vertexNode();

  *holder = searchVertexNode(aName);

  //First remove all edges from the Array
  while (quit == false) {
  	
  	if (this->graphArray[locationHolder]->deleteEdgeArray() == true) {
  		cout << "Edges have been removed.\n";
  		quit = true;
  	}
  }

  if(holder->getVertex() == graphArray[locationHolder]->vNode->getVertex()) {
  	if (graphArray[locationHolder]->removeNode(holder) == true) {
  		cout << "Node has been removed.\n";
  		delete holder;
  		return true;
  	}
  	else {
  		cout << "Node couldn't be removed.\n";
  		delete holder;
  		return false;
  	}
  }
  else { 
  	return false;
  }
}
//Delete Edge
bool graph::deleteE(string eId) {
  cout << "Deleting Edge with id: " << eId << "\n";

  edgeNode *holder = new edgeNode();
  edgeNode *tempHolder = new edgeNode();
  
  *holder = searchEdgeNode(eId);
  

  if (holder == NULL) {
  	cout << "Edge Doesn't exist\n";
  	return false;
  }

  while (tempHolder != NULL && holder != NULL) {
  	*holder = graphArray[locationHolder]->getEdge(eId);
  	if (graphArray[locationHolder]->removeEdge(holder) == true) {
  		delete holder;
  		holder = NULL;
  	}
  	
  	for(int i = 0; i < currentNodes; i++) {
  		*tempHolder = graphArray[i]->edgeArray[searchEdgeLocation(searchEdgeNode(eId))];
  		if (tempHolder != NULL) {
  			//will officially remove the edge from the array
  			if (graphArray[i]->removeEdge(tempHolder) == true) {
  				cout << "Deleteing Edge.\n";
  				delete tempHolder;
  				tempHolder = new edgeNode();
  			}
  			//need to remove the edge so that we can do a search again
  			else {
  				delete tempHolder;
  				tempHolder = new edgeNode();
  			}
  		}

  	}
  	cout << "All Edges with " << eId << " have been removed.\n";
  }
  return true;
}
//Search Node
bool graph::searchN(string searchingN) {
  string temp = " ";
  for (int i = 0; i < this->currentNodes; i++) {
  	temp = graphArray[i]->vNode->getVertex();
  	if (searchingN == temp) {
  		return true;
  	}
  }
  return false;
}
//Search and return vertex node
vertexNode graph::searchVertexNode(string searchDelete) {
  string temp = " ";
  vertexNode *holder = new vertexNode;
  for (int i = 0; i < this->currentNodes; i++) {
  	temp = graphArray[i]->vNode->getVertex();
  	if (searchDelete == temp) {
  		holder = new vertexNode(graphArray[i]->vNode);
  		this->locationHolder = i;
  		return *holder;
  	}
  }
  delete holder;
  return 0;
}
//Search Edge
bool graph::searchE(string searchingEdge) {
  string temp = " ";
  for (int i = 0; i < this->currentNodes; i++) {
  	temp = graphArray[i]->findEdge(searchingEdge);
  	if (searchingEdge == temp) {
  		return true;
  	}
  }
  return false;
}
//Search Edge with Return
edgeNode graph::searchEdgeNode(string searchingEdge) {
  string temp = " ";
  edgeNode *holder = new edgeNode;
  for (int i = 0; i < this->currentNodes; i++) {
  	temp = graphArray[i]->findEdge(searchingEdge);
  	if (searchingEdge == temp) {
  		holder = new edgeNode(graphArray[i]->getEdge(searchingEdge));
  		locationHolder = i;
  		return *holder;
  	}
  }
  holder = NULL;
  return *holder;
}
//Search for other Edge and return that edge's location
int graph::searchEdgeLocation (edgeNode searchEdge) {
  string aId = " ";
  string temp = " ";
  edgeNode *holder = new edgeNode();
  for (int i = 0; i < this->currentNodes; i++) {
  	temp = searchEdge.getID();
  	*holder = graphArray[i]->getEdge(temp);

  	if(holder == NULL) {
  		return 0;
  	}
  	if(holder->getID() == temp) {
  		return i;
  	}
  }
  return 0;
}

//Is the Graph Full?
bool graph::isFull() {
  if (this->currentNodes == this->maxSize)
  	return true;
  else
  	return false;
}
