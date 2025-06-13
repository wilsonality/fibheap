#include "fibHeap.h"
#include "node.h"
#include <unordered_map>
#include <stdio.h>

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

    if (hashmap.at(val) != NULL){
      // if we already have a node for this value, return
      return;
    }

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
  // orphan children then delete the node
  // then we find the new min_root


  while (min_root->child != NULL){
    // while min root has a child, orphan it
    // this adds it to the root list
    orphan(min_root->child);

  }

  Node* second_root = min_root->next;
  Node* last_root = min_root->prev;

  // we need to link them, if they are different
  if (second_root != last_root){
    second_root->prev = last_root;
    last_root->next = second_root;
  }
  if (second_root == last_root){
    second_root->prev = NULL;
    second_root->next = NULL;
  }

  // now we can disconnect min_root and remove from map

  hashmap.erase(min_root->key);
  delete min_root;


  // after we cut off the old root, we need to merge trees

};


void fibHeap::decrease_key(Node* node){
  // remember to preserve heap properties
  printf("running decrease_key on node: %d\n", node->key);
  return;
};


// private methods
void fibHeap::merge_trees(Node* r_1, Node* r_2){
  /** subroutine of extract min
  * r_1 and r_2 are nodes in root list with same rank
  * we must consolidate these trees, then check again
  * for more trees of the same rank
  */

  // we must find the smaller root and add it as a child
  Node* smaller = null;
  Node* larger = null;

  if (r_1->key < r_2->key){
    // if r_1 smaller
    Node* smaller = r_1;
    Node* larger = r_2;

  } else{
    // if r_2 smaller (they are never equal)
    Node* smaller = r_2;
    Node* larger = r_1;
  }

  if (smaller->child == NULL){
      // if smaller has no children, add bigger and rank++
	  // incorporate r_2 as a child of r_1
      smaller->child = r_2;
      smaller->rank++;
      return;
    }
};


void fibHeap::orphan(Node* node){
  /** this function disconnects node from parent
  *   and from its siblings
  *   after function returns, it's disconnected from heap
  *   then it is added to root list
  */
  if (node->prev != 0){
    // if we have a child before this
    node->prev->next = node->next;
    }
  if (node->next != 0){
    // if we have a child after this
    node->next->prev = node->prev;
  }
	// disconnect from parent and make parent point to next child

    node->parent->child = node->next;

    // and mark parent
    if (node->parent->marked == 1){
      // if parent already marked, remove it from grandparent
      orphan(node->parent->parent);
    }

    // add to root list
    if (min_root->prev == NULl){
      // if there was only one root
      min_root->next = node;
      min_root->prev = node;
      node->prev = min_root;
      node->next = min_root;
      return;
    }
    // otherwise, if there are multiple roots already
    Node* last_root = min_root->prev;

    // insert node into the circular linked list of roots
    min_root->prev = node;
    last_root->next = node;
    node->prev = last_root;
    node->next = min_root;
  return;
};


void fibHeap::increase_trees(){
  // should we run out of space for trees
  // we copy node ptrs into an array double the size
};