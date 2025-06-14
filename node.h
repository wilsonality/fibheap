
#ifndef NODE_H
#define NODE_H

// nodes have int* values, two children

class Node{
    public:
      Node();
      Node(int k);
      ~Node();
    int get_key();
    private:
      friend class fibheap;
      Node* parent;
      Node* child;
      Node* prev;
      Node* next;
      bool marked;
      int key;
      int rank;

};




#endif //NODE_H
