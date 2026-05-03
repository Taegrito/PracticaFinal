// Ana Isabella Gómez García
// Fecha: 5 de mayo de 2026
#ifndef INC_2026_10_PRACTICA1_H
#define INC_2026_10_PRACTICA1_H

#include <vector>
#include <string>

//Algoritmos de ordenamiento para ordenar las palabras en orden alfabetico
void quickSort(std::vector<std::string>& arr, int low, int high);
int partition(std::vector<std::string>& arr, int low, int high);

void dsort(std::vector<std::string>& arr);

void simularQuicksort(std::vector<std::string>& arr, int low, int high);
void simularDialSort(std::vector<std::string>& arr);
#endif