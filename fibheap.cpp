#include "fibheap.h"
#include "node.h"
#include <unordered_map>
#include <stdio.h>

fibheap::fibheap(){
  // initialize num trees
  // default is max 20
  this->num_trees = 20;
  min_root = 0;
};
fibheap::~fibheap(){
  // destructs object
};

void fibheap::insert(int val){
    // node insertion

    /** first, check if it's already there
	* hashmap.getvalue(val) if not null,
	* we do not add this to the tree
	* if it's not already in the heap, then we
	* create a node from parameter
	**/
    if (hashmap.find(val) == hashmap.end()){
      // if we already have a node for this value, return
      return;
    }

  	Node* new_node = new Node(val);
    // check if heap is empty, if so make it a first root
    if (min_root == 0){
      min_root = new_node;
      return;
    }


    // we add it to root linked list
	if (min_root->prev != 0){
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
    return;
};


int fibheap::find_min(){
  // subprogram for when we extract min
  // is this necessary? i don't think so

  return -1;
};


void fibheap::extract_min(){
  // orphan children then delete the node
  // then we find the new min_root


  while (min_root->child != 0){
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
    second_root->prev = 0;
    second_root->next = 0;
  }

  // now we can disconnect min_root and remove from map

  hashmap.erase(min_root->key);
  delete min_root;


  /** after we cut off the old root, we need to merge trees
	* so we scan for trees of the same rank
	* then we use the merge function on them
	*/

};


void fibheap::decrease_key(Node* node, int new_val){
// get rid of duplicate try block
  /** if we create a duplicate key, erase node
 	* else check heap properties,
	* if they are violated, we need to orphan our children
	*/

  try {
    // if new_val already exists, we erase this node
    Node* node_2 = hashmap.at(new_val);
    // if we are able to get here, new_val is already here
  // now we must erase this node: disconnect from parents, then orphan all children
    while (node->child != 0){
      orphan(node->child);
    }
    // now node has no children
    // we can disconnect from parent and delete from map
    node->parent->child = 0;
    hashmap.erase(node->key);
    delete node;
    return;
  }
  catch(const std::out_of_range& e){
    // if new_val is not in hashmap
    // change node->key
    // check if heap properties violated
    node->key = new_val;

    /** compare to parent, if not less, do nothing
     *  if less, then we cut off at node
     *   possibly recursive if parent is marked
     */
    if (node->key < node->parent->key){
      // heap violated, parent larger than node
      // orphan function handles the recursion
      orphan(node);
    }
  }

  try {
  if (hashmap.find(new_val) == hashmap.end()){
    // we need to delete the node
    while (node->child != 0){
      orphan(node->child);
      // we can just cut off nodes
    }
    // now node has no children
    // we can disconnect from parent and delete from map
    node->parent->child = 0;
    hashmap.erase(node->key);
    delete node;
    return;
  }
  } catch (...){
    // since new_val is not already in heap
    // change node->key
    // check if heap properties violated
    node->key = new_val;

    /** compare to parent, if not less, do nothing
     *  if less, then we cut off at node
     *   possibly recursive if parent is marked
     */
    if (node->key < node->parent->key){
      // heap violated, parent larger than node
      // orphan function handles the recursion
      orphan(node);
    }
  }

  return;
};


// private methods
void fibheap::merge_trees(Node* r_1, Node* r_2){
  /** subroutine of extract min
  * r_1 and r_2 are nodes in root list with same rank
  * we must consolidate these trees, then check again
  * for more trees of the same rank
  */

  // we must find the smaller root and add it as a child
  Node* smaller = 0;
  Node* larger = 0;

  if (r_1->key < r_2->key){
    // if r_1 smaller
    smaller = r_1;
    larger = r_2;

  } else {
    // if r_2 smaller (they are never equal)
    smaller = r_2;
    larger = r_1;
  }
  /** we use a switch case for the logic of adopting larger,
	* depending on smaller's rank **/

    switch(smaller->rank){
      case 0:
        smaller->child = larger;
        break;
      case 1:
        smaller->child->prev = larger;
    	larger->prev = smaller->child;
        break;
      default:
        // connect larger to the last child
        smaller->child->prev->next = larger;
        // connect larger to the first child
        smaller->child->prev = larger;
    }
    smaller->rank++;
    return;
  }


void fibheap::orphan(Node* node){
  /** this function unmarks node
  *   disconnects node from parent
  *   and from its siblings
  *   after function returns, it's disconnected from heap
  *   then it is added to root list
  *   sometimes we call this on nodes that have no parents
  */
  // unmark it node
  node->marked = 0;
  if (node->prev != 0){
    // if we have a child before this
    node->prev->next = node->next;
    }
  if (node->next != 0){
    // if we have a child after this
    node->next->prev = node->prev;
  }
	// disconnect from parent and make parent point to next child
    // also decrement parent rank
    if (node->parent != 0){
      node->parent->child = node->next;
      node->parent->rank--;
      // mark parent
      if (node->parent->marked == 1){
        // if parent already marked, remove it from grandparent
        orphan(node->parent->parent);
      }
    }


    // add to root list
    if (min_root->prev == 0){
      // if there was only one root
      min_root->next = node;
      min_root->prev = node;
      node->prev = min_root;
      node->next = min_root;
      return;
    }
    // otherwise, if there are multiple roots already
    // insert node into the circular linked list of roots
    min_root->prev = node;
    min_root->prev->next = node;
    node->prev = min_root->prev;
    node->next = min_root;

    // check if it's smaller than current min
    if (min_root->key > node->key){
      min_root = node;
    }
  return;
};


void fibheap::increase_trees(){
  // should we run out of space for trees
  // we copy node ptrs into an array double the size
};