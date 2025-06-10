#include "fibHeap.h"
#include "node.h"

fibHeap::fibHeap(){
  // initialize num trees
  // default is max 20
  this->num_trees = 20;
  Node* min_root = NULL;
};
fibHeap::~fibHeap(){
  // destructs object
};

void fibHeap::insert(int val){
    // node insertion

    /** first, check if it's already there
	* hashmap.getvalue(val) if not null,
	* we do not add this to the tree
	* create a node from parameter
	**/

  	Node* new_node = new Node(val);
    // check if heap is empty
    if (min_root == NULL){
      min_root = new_node;
      return;
    }

    // we add it to root linked list

    if (min_root->prev == NULL){}
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


void fibHeap::remove_child(Node* node){
  /** this function disconnects node from neighbors
  *   and from its parent
  *   after function returns, it's disconnected from heap
  */
  if (node->prev != 0){
    // if we have a child before this
    node->prev->next = node->next;
    }
  if (node->next != 0){
    // if we have a child after this
    node->next->prev = node->prev;
  }
  if (node->parent != 0){
    node->parent->child = 0;
  }
  return;
};


void fibHeap::increase_trees(){
  // should we run out of space for trees
  // we copy node ptrs into an array double the size
};


