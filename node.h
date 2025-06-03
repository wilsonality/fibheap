//
// Created by wils on 4/4/25.
//

#ifndef NODE_H
#define NODE_H

// nodes have int* values, two children

class Node{
    public:
      Node();
      Node(Node* p, int k);
      ~Node();
      void update_key(int n_k);
      void update_parent(Node* n_p);
      void update_child(Node* n_child, int side);
      int get_key();
    private:
      friend class fibHeap;
      Node* parent;
      Node* left;
      Node* right;
      bool marked;
      int key;

};




#endif //NODE_H
