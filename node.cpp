//
// Created by wils on 4/4/25.
//

#include "node.h"

Node::Node(int k){
  key = k;
  marked = 0;
  rank = 0;
};
Node::Node(){}
Node::~Node(){}

void Node::update_key(int n_k){
    key = n_k;
};

void Node::link_parent(Node* n_p){
  parent = n_p;
}
void Node::add_child(Node* n_child, int side){
  // if child pointer is not NULL, go to right of child until it is
  if (this->child == NULL){
    // if no prevoius children, just insert this child
    this->child = n_child;
    // increase rank, as we added a child
    rank++;
    return;
  }

  Node* c_ptr = this->child;

  while (c_ptr->next != NULL){
    // scan right for last child
    c_ptr = c_ptr->next;
  }
  // now there is no next

  // append n_child to the end
  c_ptr->next = n_child;
  // loop it back to the first one
  n_child->next = this->child;
  rank++;
  return;

}