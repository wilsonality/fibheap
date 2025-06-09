#include "fibHeap.h"
#include "node.h"

fibHeap::fibHeap(){
  // initialize num trees
  // default is max 20
  this->num_trees = 20;
};
fibHeap::~fibHeap(){};

void fibHeap::insert(int val){
    // node insertion

    /** first, check if it's already there
	* hashmap.getvalue(val) if not null,
	* we do not add this to the tree
	* create a node from parameter
	**/

  	Node* new_node = new Node(val);

    // consolidate trees
};


int fibHeap::find_min(){
  // subprogram for when we extract min

  return -1;
};


void fibHeap::extract_min(){
  // separate children then delete the node
};


void fibHeap::decrease_key(Node* node){
  // remember to preserve heap properties
};


// private methods
void fibHeap::merge_trees(Node* r_1, Node* r_2){
  // subroutine of extract_min
  // r_1 and r_2 are nodes in root list

  // we must find the smaller root and add it as a child
};


void fibHeap::remove_child(Node* node){};


void fibHeap::increase_trees(){
  // should we run out of space for trees
  // we copy node ptrs into an array double the size
};


