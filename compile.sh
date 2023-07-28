#!/bin/bash

# Compilar los archivos .cpp 
g++ -c Node.cpp -o Node.o
g++ -c Utilis.cpp -o Utilis.o

# Compilar el archivo main.cpp junto con los demás archivos
g++ main.cpp Node.o Utilis.o -o main

# Ejecutar el programa compilado
./main
