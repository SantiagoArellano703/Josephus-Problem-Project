//
// Created by dylan-roman on 7/26/23.
//

#include "Utilis.h"

using namespace std;

Node *josephus(Node **linkedList, int n, int k, int start) {
  Node::display(*linkedList);

  if (n == 1)
    return *linkedList;

  int position = (start + k);
//  int position = (start + k) % n;

  if (position > n)
    position++;

  Node::remove(linkedList, position);

  return josephus(linkedList, n - 1, k, position);
}
