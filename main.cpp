#include <iostream>
#include "Utilis.h"

using namespace std;

int main() {
  int close = 1;
  cout << "\nBienvenido, este es el problema de Josephus.\n" << endl;
  cout << "Consiste en crear una lista de la cual solo quedará un elemento al final." << endl;
  cout << "El elemento elimina al que se encuentre a 'k' posiciones a partir de él, \nasí sucesivamente." << endl;
  cout << "El minimo de 'k' es 1, esto significa que el elemento elimina \nal que está a su lado." << endl;


  do{
    cout << "\nA continuacion coloca los datos con que deseas realizar el problema...";
    cout << "\nIngresa la cantidad de elementos: ";
    int n = strToInt();

    Node *linked_list = Node::createDCLL(n);

    int k;
    do {
      cout << "Ingresa el paso con que quieres que se elimine: ";
      k = strToInt();
    } while (k < 1);

    int numBackward;
    do {
      cout << "Sentido en que quieres que se elimine \n1) Horario \n2) Antihorario \nIngresa el numero: ";
      numBackward = strToInt();
    } while (numBackward > 2 || numBackward < 1);

    bool backward;
    if (numBackward == 1) {
      backward = false;
    } else { backward = true; }

    cout << "Ingresa la posición que crees que sobrevive: ";
    int survivorUser = strToInt();

    int survivor;
    if(!backward){
      survivor = solveJosephus(n, k);
    }else{
      survivor = solveJosephusReverse(n,k);
    }
    

    if (survivorUser == survivor) {
      cout << "\nExcelente! La posición que sobrevive es la " << survivor << endl;
    } else {
      cout << "\nLo siento, la posición que sobrevive es la " << survivor << endl;
    }

    cout << "Presiona enter para continuar...";
    cin.ignore();
    cin.get();

    cout << "\n-------------------------------------------------" << endl;
    cout << "Observa como se realizó la eliminación " << endl;
    if (backward) {
      Node::josephusReverse(linked_list, k);
    } else {
      Node::josephus(linked_list, k);
    }

    do{
      cout<<"\n¿Deseas salir del programa? \n1) Si \n2) No \nIngresa el numero: ";
      close = strToInt();
    }while(close<1 || close>2); 
  }while(close == 2);
  
  return 0;
}
