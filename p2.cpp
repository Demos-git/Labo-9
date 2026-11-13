#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(int argc, char* argv[]) {
    if (argc > 2) {
        cerr << "Uso: " << argv[0] << " [archivo]" << endl;
        return 1;
    }

    const string nombreArchivo = (argc == 2) ? argv[1] : "archivo.txt";
    ifstream archivo(nombreArchivo);

    if (!archivo.is_open()) {
        cerr << "No se pudo abrir el archivo: " << nombreArchivo << endl;
        return 1;
    }

    size_t contador = 0;
    string linea;
    while (getline(archivo, linea)) {
        ++contador;
    }

    cout << "El archivo \"" << nombreArchivo << "\" contiene " << contador << " líneas." << endl;
    archivo.close();
    return 0;
}