#include <iostream>
#include "Node.h"
#include "Utilis.h"

int main() {
  std::cout << "Hello, World!" << std::endl;
  Node *linked_list = nullptr;

  Node::push(&linked_list, 1);
  Node::push(&linked_list, 2);
  Node::push(&linked_list, 3);
  Node::push(&linked_list, 4);
  Node::push(&linked_list, 5);

//  Node::remove(&linked_list, 4);
  josephus(&linked_list, 5, 1);
  Node::display(linked_list);


  return 0;
}
