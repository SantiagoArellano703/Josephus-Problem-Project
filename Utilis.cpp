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