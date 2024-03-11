#include <iostream>
#include <malloc.h>
using namespace std;


struct nodo {
    long long cedula= 0;
    char nombre[50];
    nodo *sig; 


};

nodo *cab, *aux, *aux2; 

int registrar(){
    if(cab==NULL){
        cin.get();
        cab = (struct nodo *) malloc (sizeof(struct nodo));
        cout<<"ingresar nombre del paciente: "; 
        cin.getline(cab->nombre, 50);
        cout<<"ingresar documento del paciente: "; 
        cin>>cab->cedula; 
        cab->sig = NULL;
    } else {
        cin.get();
        aux = (struct nodo *) malloc (sizeof(struct nodo));
        cout<<"ingresar nombre del paciente: "; 
        cin.getline(cab->nombre, 50);
        cout<<"ingresar Documento del paciente: "; 
        cin>>aux->cedula; 
        aux->sig = NULL;
        aux2=cab; 
        while(aux2 ->sig!=NULL) 
            aux2 = aux2->sig;
        aux2->sig = aux;
        aux2 = aux = NULL; 
         free(aux);
         free(aux2);
    }
   return 0;  
} 

int mostrar(){
    int x =0;
    for(aux=cab; aux!=NULL; aux=aux->sig){
        x++;
        cout<<"Nombre del paciente: "<<aux->nombre<<endl;
        cout<<"Documento del paciente: "<<aux->cedula<<endl;
        cout<<"puesto del paciente: "<<x<<endl;
    }
    return 0; 
}

int main (){ 
    int opc=0;
    do{
        cout<<"menu"<<endl;
        cout<<"1. registrar paciente"<<endl;
        cout<<"2. ver lista"<<endl; 
        cout<<"3. salir"<<endl; 
        cin>>opc;
        switch(opc){
            case 1: 
            registrar(); 
            break;
            case 2:
            mostrar(); break; 
            case 3: 
            cout<<"hasta luego"; 
            break; 
            default: cout<<"opcion impedido...";
            break; 
            
        }
    }while(opc!=3); 
}
