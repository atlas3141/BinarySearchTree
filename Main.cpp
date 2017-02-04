//Josh Howell Binary Search Tree
//Basic Search tree for integers
#include <iostream>
#include <cstring>
#include "Node.h"

using namespace std;

void strToLower(char* a);
void addNode(Node* head, int number);
void printTree(Node* head, int level);

int main(){

  Node* head = NULL;
  bool running = true;
  char input[30];

  while (running == true){
    cin.get(input,30);
    strToLower(input);
    cin.ignore();
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
