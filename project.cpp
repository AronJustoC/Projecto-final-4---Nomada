#include <iostream>
#include <string>
using namespace std;

int opcion;

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

void agregarProducto() {}

void listarProdurto() {}

void guardar() {}

void cagar() {}

int main() {
  // ingrese codigo;
  do {
    cout << "\033[1;32m--- SISTEMA DE INVENTARIO ---\033[0m" << endl;
    cout << "1. Agregar producto" << endl;
    cout << "0. Salir" << endl;
    cin >> opcion;
  } while (opcion != 0);
  return 0;
}
