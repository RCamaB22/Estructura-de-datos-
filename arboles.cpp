#include<iostream>
#include<stdlib.h>
#include<malloc.h>
#include<string>

using namespace std;

struct estudiante{
    unsigned long long genero; 
    unsigned long long codigo;
    unsigned long long fecha;
    unsigned long long doc;  
    char nombre[150];
    string nombre1;
    estudiante *izq;
    estudiante *derec;  
    
}*raiz, *aux, *aux2; 

void registro();
void registro2();
void buscar();
void mostrar();
void adjust();

int main(){
   system("cls");
    int opc = 0;
    do{
    cout<<"menu"<<endl;
    cout<<"1. Registrar estudiante"<<endl;
    cout<<"2. Mostrar listado"<<endl;
    cout<<"3. Buscar y eliminar estudiante"<<endl;
    cout<<"4. Configuracion"<<endl;
    cout<<"5. Salir"<<"\n";
    cout<<"Elija su opcion: ";
    cin>>opc;
        switch(opc){
            case 1: registro();system("cls"); break;
            case 2: mostrar();system("cls"); break;
            case 3: buscar();system("cls"); break;
            case 4: adjust();system("cls"); break;
            case 5: cout<<"Adios"<<endl;
            default: cout<<"opcion invalida"<<endl;
        }
    }while(opc!=5);
}

void registro(){
    if(raiz==NULL){
    raiz = (struct estudiante *)malloc(sizeof(struct estudiante));
    cout<<"ingrse el codigo del estudiante: \n";
    cin>>raiz->codigo;
    cout<<"ingrse la fecha de nacimiento del estudiante: \n";
    cin>>raiz->fecha;
    cout<<"ingrse el documento del estudiante: \n";
    cin>>raiz->doc;
    cin.get();
    cout<<"ingrse el nombre (completo) del estudiante: \n";
    cin.getline(raiz->nombre, 150);
    raiz->derec=NULL;
    raiz->izq=NULL;
    }
    else{
        aux = (struct estudiante *)malloc(sizeof(struct estudiante));
        cout<<"ingrse el codigo del estudiante: \n";
        cin>>aux->codigo;
        cout<<"ingrse la fecha de nacimiento del estudiante: \n";
        cin>>aux->fecha;
        cout<<"ingrse el documento del estudiante: \n";
        cin>>aux->doc;
        cin.get();
        cout<<"ingrse el nombre (completo) del estudiante: \n";
        cin.getline(aux->nombre, 150);
        aux->derec=NULL;
        aux->izq=NULL;
        aux2=raiz;
        do{
            if(aux2->codigo>=aux2->codigo){
                aux2=aux2->derec;
            }else{
                if(aux2->codigo<=aux2->codigo){
                    aux2=aux2->izq;
                }
            }
        }while(aux2->derec && aux2->izq ==NULL);

            if(aux2->codigo>=aux2->codigo){
                aux2->derec=aux;
            }else{
                if(aux2->codigo<=aux2->codigo){
                    aux2->izq=aux;
                }
            }
            aux=NULL;
            aux2=NULL;
            free(aux);
            free(aux2);
    }
    system("pause");
    system("cls");
    return;
}

void registro2(){
        if(raiz==NULL){
    raiz = (struct estudiante *)malloc(sizeof(struct estudiante));
    raiz->codigo=raiz->codigo;
    raiz->fecha=raiz->codigo;
    raiz->doc=raiz->doc;
    raiz->nombre1=raiz->nombre;
    raiz->derec=NULL;
    raiz->izq=NULL;
    }
    else{
        aux = (struct estudiante *)malloc(sizeof(struct estudiante));
        aux->codigo=aux->codigo;
        aux->fecha=aux->fecha;
        aux->doc=aux->doc;
        aux->nombre1=aux->nombre;
        aux->derec=NULL;
        aux->izq=NULL;
        aux2=raiz;
        do{
            if(aux2->fecha>=aux2->codigo){
                aux2=aux2->derec;
            }else{
                if(aux2->fecha<=aux2->fecha){
                    aux2=aux2->izq;
                }
            }
        }while(aux2->derec && aux2->izq ==NULL);

            if(aux2->fecha>=aux2->codigo){
                aux2->derec=aux;
            }else{
                if(aux2->fecha<=aux2->fecha){
                    aux2->izq=aux;
                }
            }
            aux=NULL;
            aux2=NULL;
            free(aux);
            free(aux2);
    }
    system("pause");
    system("cls");
    return;
}

void buscar(){}
void mostrar(){}
void adjust(){} 

void Inorder(estudiante *root);
void Preorder(estudiante *root);
void Postorder(estudiante *root);
void eliminar(unsigned long long codigo);

void Inorder(estudiante *root) {
    if (root != NULL) {
        Inorder(root->izq);
        cout << "Codigo: " << root->codigo << ", Nombre: " << root->nombre << endl;
        Inorder(root->derec);
    }
}

void Preorder(estudiante *root) {
    if (root != NULL) {
        cout << "Codigo: " << root->codigo << ", Nombre: " << root->nombre << endl;
        Preorder(root->izq);
        Preorder(root->derec);
    }
}

void Postorder(estudiante *root) {
    if (root != NULL) {
        Postorder(root->izq);
        Postorder(root->derec);
        cout << "Codigo: " << root->codigo << ", Nombre: " << root->nombre << endl;

    } 
}

void eliminar (){} 
 

 