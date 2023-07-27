#include <iostream>
#include "Utilis.h"

using namespace std;

int main() {
  cout << "\nBienvenido, este es el problema de Josephus" << endl;
  cout << "Consiste en crear una lista de la cual solo quedará un elemento al final." << endl;
  cout << "El elemento elimina al que se encuentre a su lado, así sucesivamente." << endl;

//  Node *linked_list = nullptr;
  cout << "\n Ingresa la cantidad de elementos: ";
  int n = strToInt();

  Node *linked_list = Node::createDCLL(n);

//  for (int i = 1; i <= n; i++) {
//    Node::push(&linked_list, i);
//  }
//
  Node::josephusReverse(linked_list, 2);


  return 0;
}
