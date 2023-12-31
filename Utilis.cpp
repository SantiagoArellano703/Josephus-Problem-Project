//
// Created by dylan-roman on 7/26/23.
//

#include "Utilis.h"
#include <iostream>
#include <limits>

using namespace std;

int strToInt(bool notOne) {
  int num;
  while (!(cin >> num) || num == 1 && notOne) {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Entrada invalida, intente de nuevo: ";
  }

  return num;
}

int solveJosephus(int n, int k) {
  if (n == 1) {
    return 1;
  } else {
    return ((solveJosephus(n - 1, k) + k) % n + 1);
  }
}

int solveJosephusReverse(int n, int k) {
  int solution = solveJosephus(n, k);
  int solutionReverse = (n - solution + 2) % n;
  return solutionReverse;
}