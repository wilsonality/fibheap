
#ifndef NODE_H
#define NODE_H

// nodes have int* values, two children

class Node{
    public:
      Node();
      Node(Node* p, int k);
      ~Node();
      void update_key(int n_k);
      void link_parent(Node* n_p);
      void add_child(Node* n_child, int side);
      int get_key();
    private:
      friend class fibHeap;
      Node* parent;
      Node* child;
      Node* prev;
      Node* next;
      bool marked;
      int key;
      int rank;

};




#endif //NODE_H
