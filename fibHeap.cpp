#include "fibHeap.h"

fibHeap::fibHeap(){
  // initialize num trees
  this->num_trees = 2;
};
fibHeap::~fibHeap(){};

void fibHeap::insert(int n_val){
    // node insertion
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
    num_trees = num_trees*2;
    Node* new_arr[num_trees];
    copy(trees, trees + (num_trees/2), new_arr);
    trees = new_arr; // exchg ptrs
};


