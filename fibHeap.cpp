#include "fibHeap.h"

fibHeap::fibHeap(){
  // initialize num trees
  // default is max 20
  this->num_trees = 20;
};
fibHeap::~fibHeap(){};

void fibHeap::insert(int n_val){
    // node insertion


  	// create a node from parameter
  	Node *new_node = new Node(n_val);
    // then we
};


int fibHeap::find_min(){};


void fibHeap::extract_min(){
  // separate children then delete the node
};


void fibHeap::decrease_key(Node* node){
  // remember to preserve heap properties
};


// private methods
void fibHeap::merge_trees(Node* r_1, Node* r_2){};


void fibHeap::remove_child(Node* node){};


void fibHeap::increase_trees(){
  // should we run out of space for trees
  // we copy node ptrs into an array double the size
};


