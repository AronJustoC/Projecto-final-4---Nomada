#include <iostream>
#include <string>

using namespace std;

enum TipoProducto { ALIMENTO, ELECTRONICO, ROPA };

union DetalleAdicional {
    char fechaVencimiento[11];
    float voltaje;
    char talla[5];
};

struct Producto {
    int codigo;
    string nombre;
    float precio;
    TipoProducto tipo;
    DetalleAdicional detalle;
};

void agregarProducto() {
    // TODO: Implementar lógica de agregar
}

void listarProductos() {
    // TODO: Implementar lógica de listar
}

void guardarInventario() {
    // TODO: Implementar persistencia en archivos
}

void cargarInventario() {
    // TODO: Implementar carga desde archivos
}

int main() {
    int opcion;
    do {
        cout << "\n\033[1;32m--- SISTEMA DE INVENTARIO ---\033[0m" << endl;
        cout << "1. Agregar producto" << endl;
        cout << "2. Listar productos" << endl;
        cout << "3. Guardar en archivo" << endl;
        cout << "4. Cargar desde archivo" << endl;
        cout << "0. Salir" << endl;
        cout << "Seleccione una opcion: ";
        
        if (!(cin >> opcion)) {
            cin.clear();
            cin.ignore(1000, '\n');
            opcion = -1;
            continue;
        }

        switch (opcion) {
            case 1: agregarProducto(); break;
            case 2: listarProductos(); break;
            case 3: guardarInventario(); break;
            case 4: cargarInventario(); break;
            case 0: cout << "Saliendo..." << endl; break;
            default: cout << "Opción no válida." << endl; break;
        }
    } while (opcion != 0);
    
    return 0;
}
