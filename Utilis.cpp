//
// Created by dylan-roman on 7/26/23.
//

#include "Utilis.h"
#include <iostream>
#include <limits>

using namespace std;

int strToInt() {
  int num;
  while (!(cin >> num)) {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Entrada invalida, intente de nuevo: ";
  }

  return num;
}

Node *josephus(Node **linkedList, int n, int k, int start) {
  Node::display(*linkedList);

  if (n == 1)
    return *linkedList;

  int position = (start + k) % n;

  Node::remove(linkedList, position);

  return josephus(linkedList, n - 1, k, position);
}
