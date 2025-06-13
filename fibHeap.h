#include "node.h"
#include <unordered_map>


class fibHeap{
  public:
    fibHeap();
    ~fibHeap();
    int num_trees;
    void insert(int val);
    int find_min();
    void extract_min();
    void decrease_key(Node* node, int new_val);
    private:
      void merge_trees(Node* r_1, Node* r_2);
      void orphan(Node* node);
      void increase_trees();
      Node* min_root;
      std::unordered_map<int, Node*> hashmap;
};