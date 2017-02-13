//Josh Howell Binary Search Tree
//Basic Search tree for integers
#include <iostream>
#include <cstring>
#include "Node.h"

using namespace std;

void strToLower(char* a);
void addNode(Node* head, int number);
void printTree(Node* head, int level);
Node* nodeSearch (Node* head, int number);
bool deleteNode (Node* &head, int number, Node* parent);
int main(){
  
  Node* head = NULL;
  bool running = true;
  char input[30];

  while (running == true){
    cin.get(input,30);
    strToLower(input);
    if (!strcmp(input,"add")){
      if (head == NULL){
	head = new Node();
      }
      else{
	cout << "Data for New Node?" << endl;
	int number;
	cin >> number;
	addNode(head,number);
	  
      }
    }
    else if (!strcmp(input,"print")){
      if(head){
	printTree(head,0);
      }
      else
	cout << "Nothing to print" << endl;
    }
    else if(!strcmp(input,"search")){
      if (head){
	cout << "What number are you looking for?" << endl;
	int number;
	cin >> number;
	if (nodeSearch(head,number)){
	  cout << number << " is in the tree" << endl;
	}
	else{
	  cout << number << " is not in the tree" << endl;
	}
      }
      else{
	cout << "You cant search an empty tree!" << endl;
      }
    }
    else if(!strcmp(input,"delete")){
      if (head){
        cout << "What number are you looking for?" << endl;
        int number;
        cin >> number;
        deleteNode(head,number,NULL);
      }
      else{
        cout << "You cant delete a node from an empty tree!" << endl;
      } 
    }	   
    else{
      cout << "I dont know what you mean" << endl;
      cin.clear();
    }
    cin.ignore();
  }
} 

void strToLower(char* a){ //converts words to lower
  while(*a){
    *a = tolower(*a);
    a++;
  }
}
void addNode(Node* head, int number){
  if (number < head->getData()){
    if (head->getLeft()){
      addNode(head->getLeft(),number);
    }
    else{
      head->setLeft(new Node(number));
    }
  }
  if (number > head->getData()){
    if (head->getRight()){
      addNode(head->getRight(),number);
    }
    else{
      head->setRight(new Node(number));
    }
  }
}
void printTree(Node* head, int level){
  level ++;
  if(head->getRight()){
    printTree(head->getRight(), level);
  }
  for (int i = 0; i < level; i++){
    cout << " ";
  }
  cout << head->getData() << endl;
  if(head->getLeft()){
    printTree(head->getLeft(), level);
  } 
}
Node* nodeSearch(Node* head, int number){
  if (number < head->getData()){
    if(head->getLeft()){
      return nodeSearch(head->getLeft(), number);
    }
    else return NULL;
  }
  else if (number > head->getData()){
    if(head->getRight()){
      return nodeSearch(head->getRight(), number);
    }
    else return NULL;
  }
  else return head;
}
bool deleteNode(Node** head, int number, Node* parent){
  if (number < (*head)->getData()){
    if((*head)->getLeft()){
      return deleteNode(((*head)->getLeft()), number, head);
    }
    else return false;
  }
  else if (number > (*head)->getData()){
    if((*head)->getRight()){
      return deleteNode((*head)->getRight(), number,head);
    }
    else return false;
  }
  else{
    
  }
}
