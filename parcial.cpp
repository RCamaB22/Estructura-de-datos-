rubenalbertocamachoB

#include <iostream>
#include <malloc.h>
#include <cstring>
using namespace std;

struct Producto {
    int id_producto;
    char nombre[50];
    int cantidad;
    float precio;
    Producto* sig;
};

Producto* cabecera = NULL;
Producto* final = NULL;

void registrarProducto() {
    Producto* nuevo = new Producto;
    nuevo->sig = NULL;

    cout << "Ingrese ID del producto: ";
    cin >> nuevo->id_producto;
    cin.ignore();

    cout << "Ingrese nombre del producto: ";
    cin.getline(nuevo->nombre, 50);

    cout << "Ingrese cantidad: ";
    cin >> nuevo->cantidad;

    cout << "Ingrese precio por unidad: ";
    cin >> nuevo->precio;

    if (cabecera == NULL) {
        cabecera = nuevo;
        final = nuevo;
    } else {
        final->sig = nuevo;
        final = nuevo;
    }
}

void mostrarInventario() {
    if (cabecera == NULL) {
        cout << "El inventario está vacío." << endl;
    } else {
        Producto* temp = cabecera;
        cout << "Inventario:" << endl;
        while (temp != NULL) {
            cout << "ID: " << temp->id_producto << ", Nombre: " << temp->nombre << ", Cantidad: " << temp->cantidad << ", Precio por unidad: $" << temp->precio << endl;
            temp = temp->sig;
        }
    }
}

void buscarProductoPorId(int id) {
    Producto* temp = cabecera;
    while (temp != NULL) {
        if (temp->id_producto == id) {
            cout << "ID: " << temp->id_producto << ", Nombre: " << temp->nombre << ", Cantidad: " << temp->cantidad << ", Precio por unidad: $" << temp->precio << endl;
            return;
        }
        temp = temp->sig;
    }
    cout << "Producto no encontrado." << endl;
}

void eliminarProducto(int id) {
    if (cabecera == NULL) {
        cout << "El inventario está vacío." << endl;
        return;
    }

    Producto* temp = cabecera;
    Producto* anterior = NULL;

    while (temp != NULL) {
        if (temp->id_producto == id) {
            if (anterior == NULL) {
                cabecera = temp->sig;
            } else {
                anterior->sig = temp->sig;
            }
            delete temp;
            cout << "Producto eliminado." << endl;
            return;
        }
        anterior = temp;
        temp = temp->sig;
    }
    cout << "Producto no encontrado." << endl;
}

void calcularValorTotalInventario() {
    float total = 0;
    Producto* temp = cabecera;
    while (temp != NULL) {
        total += temp->cantidad * temp->precio;
        temp = temp->sig;
    }
    cout << "El valor total del inventario es: $" << total << endl;
}

void calcularPromedioPrecios() {
    if (cabecera == NULL) {
        cout << "El inventario está vacío." << endl;
        return;
    }

    float total_precios = 0;
    int num_productos = 0;
    Producto* temp = cabecera;
    while (temp != NULL) {
        total_precios += temp->precio;
        num_productos++;
        temp = temp->sig;
    }
    float promedio = total_precios / num_productos;
    cout << "El promedio de precios por unidad es: $" << promedio << endl;
}

void venderProducto(int id, int cantidad) {
    Producto* temp = cabecera;
    while (temp != NULL) {
        if (temp->id_producto == id) {
            if (temp->cantidad >= cantidad) {
                float total_pagar = cantidad * temp->precio;
                temp->cantidad -= cantidad;
                cout << "Venta realizada. Total a pagar: $" << total_pagar << endl;
            } else {
                cout << "No hay suficientes unidades en el inventario para completar la venta." << endl;
            }
            return;
        }
        temp = temp->sig;
    }
    cout << "Producto no encontrado en el inventario." << endl;
}

int main() {
    int opcion;

    do {
        cout << "\nMenu:" << endl;
        cout << "1. Registrar Producto" << endl;
        cout << "2. Mostrar Inventario" << endl;
        cout << "3. Buscar Producto por ID" << endl;
        cout << "4. Eliminar Producto" << endl;
        cout << "5. Calcular Valor Total del Inventario" << endl;
        cout << "6. Calcular Promedio de Precios" << endl;
        cout << "7. Vender Producto" << endl;
        cout << "8. Salir" << endl;
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                registrarProducto();
                break;
            case 2:
                mostrarInventario();
                break;
            case 3: {
                int id;
                cout << "Ingrese ID del producto a buscar: ";
                cin >> id;
                buscarProductoPorId(id);
                break;
            }
            case 4: {
                int id;
                cout << "Ingrese ID del producto a eliminar: ";
                cin >> id;
                eliminarProducto(id);
                break;
            }
            case 5:
                calcularValorTotalInventario();
                break;
            case 6:
                calcularPromedioPrecios();
                break;
            case 7: {
                int id, cantidad;
                cout << "Ingrese ID del producto a vender: ";
                cin >> id;
                cout << "Ingrese cantidad de unidades a vender: ";
                cin >> cantidad;
                venderProducto(id, cantidad);
                break;
            }
            case 8:
                cout << "Saliendo del programa..." << endl;
                break;
            default:
                cout << "Opción no válida. Intente nuevamente." << endl;
                break;
        }

    } while (opcion != 8);

    return 0;
}
