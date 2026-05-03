# Práctica Final: Comparación entre algoritmos DialSort y Quicksort
**Estudiante:** Ana Isabella Gómez García

**Fecha:** 5 de mayo de 2026

**Sistema operativo:** Windows 11

**Compilador:** clang-tidy

**Herramientas:** Clion 2025 3.2

En este proyecto se implementan dos algoritmos: Quicksort y dialsort, con el fin de ordenar un conjunto de palabras en orden alfábetico. Este proyecto tiene como fin comparar estos dos algoritmos y determinar cual de ellos tienen un mejor rendimiento, contiene tambien un simulador para comprender el funcionamiento de cada uno de estos.
## Explicación del proyecto
Este proyecto es un estudio del rendimiento entre dos algoritmos de ordenamiento que se van a aplicar a grandes volumenes de datos de tipo String.

* _Quicksort:_ Este algoritmo está basado en la estrategia "divide y vencerás", donde toma uno de los elementos del conjunto de datos y lo toma como pivote; este algoritmo tiene una complejidad promedio de  $O(n \log n

* _DialSort:_ Este algoritmo organiza por distribució, ordenan las palabras analizando sus caracteres de forma posicional; este algoritmo es especialmente bueno para ordenar cadenas de texto.ç

## Ejecución del proyecto
1. **_Clonar este repositorio:_** Puedes clonar este repositorio a través de este link
   ```bash
   git clone https://github.com/Taegrito/PracticaFinal.git
2. **_Compilar:_**
   Asegúrate de tener un compilador de C++, esto es debido a que este proyecto contiene varios archivos, así que se hará mucho más fácil poder abrir el archivo.
3. **_Ejecución:_**
   Una vez compilado se puede correr el programa de la siguiente manera:
   - _En Windows:_ programa.exe
   - _En Linux/Mac:_ ./programa
## Funcionamiento (simulación)
El programa cuenta con un simulador visual inicial. Con un conjunto pequeño de datos, el sistema muestra:

1. _Paso a paso del Quicksort:_ Cómo se eligen los pivotes y se crean las particiones.

2. _Paso a paso del Dial Sort:_ Cómo se distribuyen las palabras en cubetas según cada carácter.

Esto permite verificar la lógica antes de proceder a la prueba de rendimiento masiva.

## Resultados obtenidos:
Este es el promedio de los resultados obtenidos en general, aunque estos pueden variar de acuerdo de Hardware:

| Algoritmo |   |Tiempo medio (ms)|  |Throughput (reg/s)|

| :--- |               |:--- |               |:--- |

|Quicksort|          |40194.8157|           |4975|

|DialSort|           |1476.3349|            |135471|

## Reporte técnico
Para una explicación más profunda sobre la complejidad temporal, espacial y análisis de varianza de las pruebas, consulte el archivo ReporteTecnico.pdf adjunto en este repositorio.
