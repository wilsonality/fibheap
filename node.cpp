//
// Created by wils on 4/4/25.
//

#include "node.h"

Node::Node(Node* p, int k){
  parent = p;
  key = k;
  marked = 0;
};
Node::Node(){}
Node::~Node(){}

void Node::update_key(int n_k){
    key = n_k;
};

void Node::update_parent(Node* n_p){
  parent = n_p;
}
void Node::update_child(Node* n_child, int side){
  // left = 0, right = 1
  if (side == 0){ // update left
    left = n_child;
  }
  if (side == 1){ // update right
    right = n_child;
  }
}