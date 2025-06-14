/** node class implementation
* operations are handled by fibheap,
* so no functions are implementated in the node class
 */

#include "node.h"

Node::Node(int k){
  key = k;
  marked = 0;
  rank = 0;
};
Node::Node(){}

Node::~Node(){}

int Node:: get_key(){
  return key;
}