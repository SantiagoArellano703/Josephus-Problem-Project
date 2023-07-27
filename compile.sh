#!/bin/bash

# Compilar los archivos .cpp en la carpeta "models"
g++ -c Node.cpp -o Node.o
g++ -c Utilis.cpp -o Utilis.o

# Compilar el archivo main.cpp junto con los archivos objeto en "Models"
g++ main.cpp Node.o Utilis.o -o main

# Ejecutar el programa compilado
./main
