#include <iostream>
#include <fstream>
using namespace std;

int main() {
    const int CANTIDAD = 5;
    ofstream archivo("numeros.txt");
    if (!archivo) {
        cerr << "No se pudo abrir el archivo numeros.txt" << endl;
        return 1;
    }

    int numero;
    cout << "Introduce cinco numeros enteros:" << endl;
    for (int i = 0; i < CANTIDAD; i++) {
        cout << "Numero " << (i + 1) << ": ";
        if (!(cin >> numero)) {
            cerr << "Entrada invalida. Debes introducir un numero entero." << endl;
            return 1;
        }
        archivo << numero << endl;
    }
    archivo.close();

    ifstream archivoLectura("numeros.txt");
    if (!archivoLectura) {
        cerr << "No se pudo abrir el archivo numeros.txt para lectura" << endl;
        return 1;
    }

    int suma = 0;
    int contador = 0;
    while (archivoLectura >> numero) {
        suma += numero;
        contador++;
    }
    archivoLectura.close();

    if (contador != CANTIDAD) {
        cerr << "No se pudieron leer los cinco numeros del archivo." << endl;
        return 1;
    }

    cout << "La suma de los numeros es: " << suma << endl;
    return 0;
}