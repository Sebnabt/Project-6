/*
  Sebastian Abt
  Project 6
  CS218
  main.cpp
*/
#include "graph.h"

void reset (string a) {
  a = " ";
}
void main() {
  graph *aGraph = new graph();
  bool inProgram = true;
  string entrance = " ";
  bool weightedon = true;
  cout << "Welcome to the Graph Program, keepin mind that this program does have limited features.\n";
  cout << "To enter the program, please type (Y)es.\n";
  cout << "To leave the program, please type (Q)uit.\n";
  cin >> entrance;

  while(true) {
  	if (entrance[0] == 'e' || entrance[0] == 'E') {
  		
  		string command = " ";
  		string nodeorEdge = " ";
  		aGraph->settingOfWeight();
  		while(inProgram == true) {
  			cout << "The Following commands can be used: \n";
  			cout << "Type (I)nsert to insert a Node or an Edge.\n";
  			cout << "Type (D)elete to delete the graph, a node, or an edge.\n";
  			cout << "Type (P)rint to print the list.\n";
  			cout << "Type (S)earch(N)ode to find a particular node.\n";
  			cout << "Type (S)ize to get the Size of the graph.\n";
  			cout << "Type (C)lear to clear the screen.\n";

  			cout << "Command: "; cin >> command;

  			if (command[0] == 'i' || command[0] == 'I') {
  				
  				command = "x";
  				while (command == "x") {
  					cout << "Would you like to insert a (N)ode or an (E)dge, (Q)uit to leave insert?\n";
  					cin >> nodeorEdge;
  					if (nodeorEdge[0] == 'n' || nodeorEdge[0] == 'N') {
  						aGraph->insertNode();
  					}
  					else if (nodeorEdge[0] == 'e' || nodeorEdge[0] == 'E') {
  						aGraph->insertEdge();
  					}
  					else if (nodeorEdge[0] == 'q' || nodeorEdge[0] == 'Q') {
  						command = " ";
  					}
  					reset(nodeorEdge);
  				}
  			}
  			else if (command[0] == 'd' || command [0] == 'D') {
  				
  				command = "y";
  				while (command == "y") {
  					cout << "Would you like to delete a (N)ode, (E)dge or the (G)raph? Or (Q)uit to leave.\n";
  					cin >> nodeorEdge;
  					if (nodeorEdge[0] == 'n' || nodeorEdge[0] == 'N') {
  						aGraph->deleteNode();
  					}
  					else if (nodeorEdge[0] == 'e' || nodeorEdge[0] == 'E') {
  						aGraph->deleteEdge();
  					}
  					else if (nodeorEdge[0] == 'g' || nodeorEdge[0] == 'G') {
  						aGraph->deleteGraph();
  					}
  					else if (nodeorEdge[0] == 'q' || nodeorEdge[0] == 'Q') {
  						command = " ";
  					}
  					reset(nodeorEdge);
  				}
  			}
  			else if (command[0] == 'p' || command [0] == 'P') {
  				aGraph->printGraph();
  				reset(command);
  			}
  			else if (command[0] == 's' || command [0] == 'S') {
  				aGraph->sizeofGraph();
  				reset(command);
  			}
  			else if (command[0] == 'q' || command [0] == 'Q') {
  				delete aGraph;
  				inProgram = true;
  				break;
  			}
  			else if (command[0] == 'sn' || command [0] == 'SN') {
  				aGraph->searchNode();
  				reset(command);
  			}
  			else if (command[0] == 'c' || command [0] == 'C') {
  				cout << system("CLS");
  				reset(command);
  			}
  			else {
  				cout << "Wrong command entered.\n";
  				reset(command);
  			}
  		}
  	}
  	else if(entrance[0] == 'n' || entrance[0] == 'N') {
  		cout << "Thank you for using this program.\n";
  		cout << "Please press q to leave";
  		string q = " ";
  		cin >> q;
  		break;
  	}
  	else {
  		cout << "To enter the program, please type (E)ntrance.\n";
  		cout << "To leave the program, please type (Q)uit.\n";
  		cin >> entrance;
  	}
  }
}
