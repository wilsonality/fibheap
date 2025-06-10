#include "fibHeap.h"
#include "node.h"
#include <unordered_map>

fibHeap::fibHeap(){
  // initialize num trees
  // default is max 20
  this->num_trees = 20;
  Node* min_root = NULL;
  std::unordered_map<int, Node*> hashmap;
};
fibHeap::~fibHeap(){
  // destructs object
};

void fibHeap::insert(int val){
    // node insertion

    /** first, check if it's already there
	* hashmap.getvalue(val) if not null,
	* we do not add this to the tree
	* if it's not already in the heap, then we
	* create a node from parameter
	**/

  	Node* new_node = new Node(val);
    // check if heap is empty, if so make it a first root
    if (min_root == NULL){
      min_root = new_node;
      return;
    }


    // we add it to root linked list
	if (min_root->prev != NULL){
    	Node* second_last = min_root->prev;

    	// connect new node to second last
	    new_node->prev = second_last;
    	second_last->next = new_node;

    	// connect min_root to new node
    	new_node->next = min_root;
    	min_root->prev = new_node;
    }
    if (min_root->key > val){
      // now we check if the new root is less than min_root
      // if old min is more than new node
      min_root = new_node;
    }
};


int fibHeap::find_min(){
  // subprogram for when we extract min
  // is this necessary? i don't think so

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


void fibHeap::orphan(Node* node){
  /** this function disconnects node from parent
  *   and from its siblings
  *   after function returns, it's disconnected from heap
  *   then it can be added to rootlist
  */
  if (node->prev != 0){
    // if we have a child before this
    node->prev->next = node->next;
    }
  if (node->next != 0){
    // if we have a child after this
    node->next->prev = node->prev;
  }
	// disconnect from parent, and mark parent
    node->parent->child = 0;
    if (node->parent->marked == 1){
      // if parent already marked, remove it from grandparent
      orphan(node->parent->parent);
    }

    // add to root list
  return;
};


void fibHeap::increase_trees(){
  // should we run out of space for trees
  // we copy node ptrs into an array double the size
};


