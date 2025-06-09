// header for fibonacci heap
#include "node.h"

class fibHeap{
  public:
    fibHeap();
    ~fibHeap();
    int num_trees;
    void insert(int val);
    int find_min();
    void extract_min();
    void decrease_key(Node* node);
    private:
      void merge_trees(Node* r_1, Node* r_2);
      void remove_child(Node* node);
      void increase_trees();
      Node* min_root;
};