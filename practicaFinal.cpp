// Creado por Ana Isabella Gómez García
// Fecha: 5 de mayo de 2026
#include "practicaFinal.h"
using namespace std;
#include <iostream>
#include <vector>
#include <string>
// Simulador de Quicksort
void simularQuicksort(std::vector<std::string>& arr, int low, int high) {
    if (low < high) {
        cout << "Separando el rango [" << low << " a " << high << "]: ";
        for(int i=low; i<=high; ++i) cout << arr[i] << " ";
        cout << "\n";

        int pi = partition(arr, low, high);

        cout << " -> Pivote colocado en el indice " << pi << "\n\n";

        simularQuicksort(arr, low, pi - 1);
        simularQuicksort(arr, pi + 1, high);
    }
}
// Simulador del dialsort
void simularDialSort(std::vector<std::string>& arr) {
    cout << "--- Simulacion Dial Sort (Estado Inicial) ---" << endl;
    for (const auto& s : arr) cout << "[" << s << "] ";
    cout << "\n" << endl;
    dsort(arr);

    cout << "--- Resultado Final despues de Dial Sort ---" << endl;
    for (const auto& s : arr) cout << "[" << s << "] ";
    cout << endl;
}
int partition(std::vector<std::string>& arr, int low, int high) {
    std::string pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return (i + 1);
}
// Implementación del Quicksort
void quickSort(std::vector<std::string>& arr, int low, int high) {
    while (low < high) {
        int piv= partition(arr, low, high);
        if (piv-low<high-piv) {
            quickSort(arr, low, piv-1);
            low = piv+1;
        }else {
            quickSort(arr, piv+1, high);
            high= piv-1;
        }

    }
}
// Implementacion del dialsort
void dsort(std::vector<std::string>& arr) {
    if (arr.empty()) return;
    size_t maxLen = 0;
    for (const std::string& s : arr) {
        if (s.length() > maxLen) maxLen = s.length();
    }
    for (int pos = maxLen - 1; pos >= 0; pos--) {
        std::vector<std::string> output(arr.size());
        int count[257] = {0};
        for (const std::string& s : arr) {
            unsigned char c = (pos < s.length()) ? (unsigned char)s[pos] + 1 : 0;
            count[c]++;
        }

        for (int i = 1; i < 257; i++) {
            count[i] += count[i - 1];
        }
        for (int i = arr.size() - 1; i >= 0; i--) {
            unsigned char c = (pos < arr[i].length()) ? (unsigned char)arr[i][pos] + 1 : 0;
            output[count[c] - 1] = arr[i];
            count[c]--;
        }

        arr = output;
    }
}
