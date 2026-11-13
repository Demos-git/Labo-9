#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main () {
    string frase;
    ofstream archivo("diario.txt", ios::app);

    if (!archivo) {
        cerr << "No se pudo abrir el archivo diario.txt" << endl;
        return 1;
    }

    cout << "Escribe una frase para tu diario: ";
    getline(cin, frase);

    archivo << frase << endl; 
    archivo.close(); 

    ifstream archivoLectura("diario.txt");
    if (!archivoLectura) {
        cerr << "No se pudo abrir el archivo diario.txt para lectura" << endl;
        return 1;
    }

    cout << "\nContenido del diario:\n";
    string linea;
    while (getline(archivoLectura, linea)) {
        cout << linea << endl; 
    }

    archivoLectura.close();
    return 0;
}