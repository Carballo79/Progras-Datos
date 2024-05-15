#include <iostream>
#include <string>

using namespace std;

const int CAPACIDAD_MEMORIA_CACHE = 20;

struct Cliente {
    int cedula;
    string nombre;
};

Cliente memoriaCache[CAPACIDAD_MEMORIA_CACHE];

void insertarCliente(int cedula, const string& nombre) {
    // Desplazar los elementos hacia la derecha para hacer espacio para el nuevo cliente
    for (int i = CAPACIDAD_MEMORIA_CACHE - 1; i > 0; --i) {
        memoriaCache[i] = memoriaCache[i - 1];
    }
    // Insertar el nuevo cliente en la primera posición
    memoriaCache[0] = {cedula, nombre};
}

void mostrarMemCache() {
    cout << "Memoria cache:\n";
    for (int i = 0; i < CAPACIDAD_MEMORIA_CACHE; ++i) {
        if (memoriaCache[i].cedula != 0) {
            cout << memoriaCache[i].cedula << ": " << memoriaCache[i].nombre << endl;
        }
    }
}

int main() {
    // Ejemplo de inserción de cliente
    insertarCliente(1234, "Juan Perez");
    mostrarMemCache();

    insertarCliente(5678, "Maria Lopez");
    mostrarMemCache();

    insertarCliente(9012, "Pedro Ramirez");
    mostrarMemCache();

    return 0;
}
