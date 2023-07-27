#include <iostream>
#include "Node.h"
#include "Utilis.h"

using namespace std;

int main() {
  cout << "\nBienvenido, este es el problema de Josephus.\n" << endl;
  cout << "Consiste en crear una lista de la cual solo quedará un elemento al final." << endl;
  cout << "El elemento elimina al que se encuentre a 'k' posiciones a partir de él, \nasí sucesivamente." << endl;
  cout << "El minimo de 'k' es 1, esto significa que el elemento elimina \nal que está a su lado." << endl;


  Node *linked_list = nullptr;
  cout << "\nIngresa la cantidad de elementos: ";
  int n = strToInt();

  for (int i = 1; i <= n; i++) {
    Node::push(&linked_list, i);
  }

  int k;
  do{
    cout << "Ingresa el paso con que quieres que se elimine: ";
    k = strToInt();
  }while(k<1);

  int numBackward;
  do{
    cout << "Sentido en que quieres que se elimine \n1) Horario \n2) Antihorario \nIngresa el numero: ";
    numBackward = strToInt();
  }while(numBackward>2 || numBackward<1);
  
  bool backward;
  if(numBackward == 1){
    backward = false;
  }else{backward=true;}

  cout << "Ingresa la posición que crees que sobrevive: ";
  int survivorUser = strToInt();
  int survivor = solveJosephus(n, k);
  //int survivorBackward = n-survivor+k+1;

  if(survivorUser==survivor){
    cout<<"\nExcelente! La posición que sobrevive es la "<<survivor<<endl;
  }else{
    cout<<"\nLo siento, la posición que sobrevive es la "<<survivor<<endl;
  }

  cout<<"\n-------------------------------------------------"<<endl;
  cout<<"Observa como se realizó la eliminación "<<endl;
  josephus(&linked_list, n, k, backward);


  return 0;
}
