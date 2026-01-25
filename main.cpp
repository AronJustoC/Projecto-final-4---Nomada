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

void agregarProducto(Producto *&inventario, int &cantidad, int &capacidad) {
  // TODO: Implementar lógica de agregar
  if (cantidad == capacidad) {
    int nuevaCapacidad = (capacidad == 0) ? 1 : capacidad * 2;
    Producto *nuevoArreglo = new Producto[nuevaCapacidad];

    if (inventario != nullptr) {
      for (int i = 0; i < cantidad; i++) {
        nuevoArreglo[i] = inventario[i];
      }
      delete[] inventario;
    }

    inventario = nuevoArreglo;
    capacidad = nuevaCapacidad;

    cout << "--- Log: La capacidad a aumentado a " << capacidad << " ---"
         << endl;
  }

  cout << "Codigo: ";
  cin >> inventario[cantidad].codigo;
  cout << "Nombre del producto: ";
  cin.ignore();
  getline(cin, inventario[cantidad].nombre);
  cout << "Precio: ";
  cin >> inventario[cantidad].precio;

  int opcionTipo;
  cout << "Tipo (0: Alimento, 1: Electronico, 2: Ropa): ";
  cin >> opcionTipo;
  inventario[cantidad].tipo = static_cast<TipoProducto>(opcionTipo);
  switch (inventario[cantidad].tipo) {
  case ALIMENTO:
    cout << "Fecha de vencimiento (dd/mm/aaaa): ";
    cin >> inventario[cantidad].detalle.fechaVencimiento;
    break;
  case ELECTRONICO:
    cout << "Voltaje (en voltios): ";
    cin >> inventario[cantidad].detalle.voltaje;
    break;
  case ROPA:
    cout << "Talla (S, M, L, XL, etc.): ";
    cin >> inventario[cantidad].detalle.talla;
    break;
  default:
    break;
  }

  cantidad++;
}

void listarProductos(Producto *inventario, int cantidad) {
  if (cantidad == 0) {
    cout << "\nEl inventario está vacío." << endl;
    return;
  }

  cout << "\n--- LISTA DE PRODUCTOS ---" << endl;
  for (int i = 0; i < cantidad; i++) {
    cout << "Código: " << inventario[i].codigo << " | "
         << "Nombre: " << inventario[i].nombre << " | "
         << "Precio: $" << inventario[i].precio << " | ";

    switch (inventario[i].tipo) {
    case ALIMENTO:
      cout << "Tipo: Alimento | Vence: " << inventario[i].detalle.fechaVencimiento;
      break;
    case ELECTRONICO:
      cout << "Tipo: Electrónico | Voltaje: " << inventario[i].detalle.voltaje << "V";
      break;
    case ROPA:
      cout << "Tipo: Ropa | Talla: " << inventario[i].detalle.talla;
      break;
    }
    cout << endl;
  }
}

void guardarInventario() {
  // TODO: Implementar persistencia en archivos
}

void cargarInventario() {
  // TODO: Implementar carga desde archivos
}

int main() {
  Producto *inventario = nullptr;
  int opcion;

  int capacidad = 0;
  int cantidad = 0;

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
    case 1:
      agregarProducto(inventario, cantidad, capacidad);
      break;
    case 2:
      listarProductos(inventario, cantidad);
      break;
    case 3:
      guardarInventario();
      break;
    case 4:
      cargarInventario();
      break;
    case 0:
      cout << "Saliendo..." << endl;
      break;
    default:
      cout << "Opción no válida." << endl;
      break;
    }
  } while (opcion != 0);

  delete[] inventario;

  return 0;
}
