// Creado por: Ana Isabella Gómez García
// Fecha: 5 de mayo de 2026
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>
#include <numeric>
#include <chrono>
#include <algorithm>
#include <random>
#include <iomanip>
#include "practicaFinal.h"

using namespace std;
using namespace std::chrono;

// Estructura para calcular las medidas más adelante
struct medidas {
    double media;
    double desviacionEstandar;
    double throughput;
    double tiempoTotal;
};
//Calcular la estadísitcas de los algoritmos
medidas calcularMedidas(const vector<double>& tiempos, int n) {
    if (tiempos.empty()) return {0, 0, 0, 0};

    double suma = accumulate(tiempos.begin(), tiempos.end(), 0.0);
    double media = suma / tiempos.size();

    double varianza = 0;
    for (double t : tiempos) {
        varianza += pow(t - media, 2);
    }
    varianza /= tiempos.size();

    medidas m;
    m.media = media;
    m.desviacionEstandar = sqrt(varianza);
    m.tiempoTotal = suma;
    m.throughput = n / (media / 1000.0);

    return m;
}

// Carga las palabras del dataset
void cargarPalabras(vector<string>& palabras, const string& nombreArchivo) {
    ifstream archivo(nombreArchivo);
    string palabra;
    if (archivo.is_open()) {
        while (archivo >> palabra) {
            palabras.push_back(palabra);
        }
        archivo.close();
    } else {
        cerr << "Error: No se puede abrir el archivo " << nombreArchivo << endl;
    }
}
int main() {
    // Simuladores
    cout << "------------------Simulacion de algortirmos -------------------------" << endl;
    vector<string> datosSimulacion = {"gato", "perro", "buho", "marmota", "raton", "camello", "girafa"};

    // Simulación del Quicksort
    vector<string> pruebaQ = datosSimulacion;
    simularQuicksort(pruebaQ, 0, pruebaQ.size() - 1);

    // Simulación Dial Sort
    vector<string> pruebaD = datosSimulacion;
    simularDialSort(pruebaD);

    cout << "\nSimulacion completada." << endl;
    cout << "Presione ENTER para iniciar las pruebas de rendimiento de cada algoritmo" << endl;
    cin.get();

    // Pruebas de rendimiento de cada algoritmo (Benchmarking)
    cout << "---------------------Comparacion de rendimiento---------- " << endl;
    vector<string> dataset;
    cargarPalabras(dataset, "dataset.txt");

    if (dataset.empty()) {
        cout << "Error: Dataset vacio o no encontrado. Abortando..." << endl;
        return 1;
    }

    int n = dataset.size();
    int iteraciones = 5;
    vector<double> tiemposQuick, tiemposDial;
    random_device rd;
    mt19937 rng(rd());

    cout << "Registros cargados: " << n << endl;
    cout << "Ejecutando " << iteraciones << " iteraciones de prueba" << endl;

    for (int i = 0; i < iteraciones; ++i) {
        // Se aleatoriza el dataset en cada prueba oara que sea justo
        shuffle(dataset.begin(), dataset.end(), rng);

        // --- Test Quicksort ---
        vector<string> copiaQuick = dataset;
        auto startQ = steady_clock::now();
        quickSort(copiaQuick, 0, copiaQuick.size() - 1);
        auto endQ = steady_clock::now();
        tiemposQuick.push_back(duration<double, std::milli>(endQ - startQ).count());

        // --- Test Dial Sort ---
        vector<string> copiaDial = dataset;
        auto startD = steady_clock::now();
        dsort(copiaDial);
        auto endD = steady_clock::now();
        tiemposDial.push_back(duration<double, std::milli>(endD - startD).count());

        cout << "[+] Iteracion " << i + 1 << " finalizada." << endl;
    }

    // Cálculo y muestra de los resultados
    medidas resQuick = calcularMedidas(tiemposQuick, n);
    medidas resDial = calcularMedidas(tiemposDial, n);

    cout << fixed << setprecision(4);
    cout << "\n" << string(70, '=') << endl;
    cout << left << setw(25) << "Metrica" << setw(22) << "Quicksort" << "Dial Sort (DSORT)" << endl;
    cout << string(70, '-') << endl;

    cout << setw(25) << "Media (ms)" << setw(22) << resQuick.media << resDial.media << endl;
    cout << setw(25) << "Desv. Estandar (ms)" << setw(22) << resQuick.desviacionEstandar << resDial.desviacionEstandar << endl;
    cout << setw(25) << "Throughput (reg/s)" << setw(22) << (long)resQuick.throughput << (long)resDial.throughput << endl;
    cout << string(70, '=') << endl;

    return 0;
}