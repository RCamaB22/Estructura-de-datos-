ruben camacho, pedro manyoma.
#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

struct Estudiante {
    unsigned long long codigo;
    unsigned long long fecha;
    unsigned long long doc;
    unsigned long long genero;
    char nombre[150];
    Estudiante *izq;
    Estudiante *derec;
} *raiz = NULL, *aux = NULL, *aux2 = NULL;

void registro();
void mostrar();
void contarGenero(int &masculino, int &femenino, int &no_responde);
void Inorder(Estudiante *root);
void Preorder(Estudiante *root);
void Postorder(Estudiante *root);
void eliminar(unsigned long long codigo);
Estudiante* eliminarNodo(Estudiante* root, unsigned long long codigo);

int main() {
    system("cls");
    int opc = 0;
    do {
        cout << "Menu" << endl;
        cout << "1. Registrar estudiante" << endl;
        cout << "2. Mostrar listado" << endl;
        cout << "3. Contar estudiantes por género" << endl;
        cout << "4. Buscar y eliminar estudiante" << endl;
        cout << "5. Configuracion" << endl;
        cout << "6. Salir" << endl;
        cout << "Elija su opcion: ";
        cin >> opc;
        switch (opc) {
            case 1: registro(); system("cls"); break;
            case 2: mostrar(); system("cls"); break;
            case 3: {
                        int masculino = 0, femenino = 0, no_responde = 0;
                        contarGenero(masculino, femenino, no_responde);
                        cout << "Estudiantes masculinos: " << masculino << endl;
                        cout << "Estudiantes femeninos: " << femenino << endl;
                        cout << "Estudiantes que no responden: " << no_responde << endl;
                        system("pause");
                        system("cls");
                        break;
                    }
            case 4: {
                        unsigned long long codigo;
                        cout << "Ingrese el código del estudiante a eliminar: ";
                        cin >> codigo;
                        raiz = eliminarNodo(raiz, codigo);
                        system("cls");
                        break;
                    }
            case 5: cout << "Configuracion (aun no implementado)" << endl; system("cls"); break;
            case 6: cout << "Adios" << endl; break;
            default: cout << "Opcion invalida" << endl;
        }
    } while (opc != 6);
    return 0;
}

void mostrar() {
    cout << "Mostrando listado de estudiantes:" << endl;
    cout << "------------------------------" << endl;
    Inorder(raiz);
    system("pause");
    system("cls");
}

void contarGenero(int &masculino, int &femenino, int &no_responde) {
    if (raiz != NULL) {
        Estudiante *actual = raiz;
        contarGeneroRec(actual, masculino, femenino, no_responde);
    }
}

void contarGeneroRec(Estudiante *root, int &masculino, int &femenino, int &no_responde) {
    if (root != NULL) {
        contarGeneroRec(root->izq, masculino, femenino, no_responde);
        if (root->genero == 1)
            masculino++;
        else if (root->genero == 2)
            femenino++;
        else if (root->genero == 3)
            no_responde++;
        contarGeneroRec(root->derec, masculino, femenino, no_responde);
    }
}

void Inorder(Estudiante *root) {
    if (root != NULL) {
        Inorder(root->izq);
        cout << "Código: " << root->codigo << ", Nombre: " << root->nombre << ", Género: " << root->genero << endl;
        Inorder(root->derec);
    }
}

void Preorder(Estudiante *root) {
    if (root != NULL) {
        cout << "Código: " << root->codigo << ", Nombre: " << root->nombre << ", Género: " << root->genero << endl;
        Preorder(root->izq);
        Preorder(root->derec);
    }
}

void Postorder(Estudiante *root) {
    if (root != NULL) {
        Postorder(root->izq);
        Postorder(root->derec);
        cout << "Código: " << root->codigo << ", Nombre: " << root->nombre << ", Género: " << root->genero << endl;
    }
}

void registro() {
    Estudiante *nuevo = new Estudiante;
    cout << "Ingrese el código del estudiante: ";
    cin >> nuevo->codigo;
    cout << "Ingrese la fecha de nacimiento del estudiante (AAAAMMDD): ";
    cin >> nuevo->fecha;
    cout << "Ingrese el documento del estudiante: ";
    cin >> nuevo->doc;
    cout << "Ingrese el género del estudiante (1: Masculino, 2: Femenino, 3: No responder): ";
    cin >> nuevo->genero;
    cin.ignore();
    cout << "Ingrese el nombre (completo) del estudiante: ";
    cin.getline(nuevo->nombre, 150);
    nuevo->izq = nuevo->derec = NULL;

    if (raiz == NULL) {
        raiz = nuevo;
    } else {
        Estudiante *padre = NULL, *actual = raiz;
        while (actual != NULL) {
            padre = actual;
            if (nuevo->codigo < actual->codigo) {
                actual = actual->izq;
            } else {
                actual = actual->derec;
            }
        }
        if (nuevo->codigo < padre->codigo) {
            padre->izq = nuevo;
        } else {
            padre->derec = nuevo;
        }
    }
    system("pause");
    system("cls");
}

Estudiante* eliminarNodo(Estudiante* root, unsigned long long codigo) {
    if (root == NULL) return root;

    if (codigo < root->codigo)
        root->izq = eliminarNodo(root->izq, codigo);
    else if (codigo > root->codigo)
        root->derec = eliminarNodo(root->derec, codigo);
    else {
        if (root->izq == NULL) {
            Estudiante *temp = root->derec;
            delete root;
            return temp;
        } else if (root->derec == NULL) {
            Estudiante *temp = root->izq;
            delete root;
            return temp;
        }
        Estudiante* temp = minValorNodo(root->derec);
        root->codigo = temp->codigo;
        strcpy(root->nombre, temp->nombre);
        root->fecha = temp->fecha;
        root->doc = temp->doc;
        root->genero = temp->genero;
        root->derec = eliminarNodo(root->derec, temp->codigo);
    }
    return;
}
