#include "Node.h"
#include <iostream>

using namespace std;

Node* Node::getLeft(){
  return left;
}
Node* Node::getRight(){
  return right;
}
int Node::getData(){
  return data;
}
void Node::setLeft(Node* node){
  left = node;
}
void Node::setRight(Node* node){
  right = node;
}
Node::Node(int number){
  data = number;
}
Node::Node(){
  cout << "Data for New Node?" << endl;
  cin >> data;
}
Node::~Node(){
  delete &data;
}


