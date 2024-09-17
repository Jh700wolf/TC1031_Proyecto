#ifndef DRAFT_H_
#define DRAFT_H_


#include <string>
#include <iostream>
#include <sstream> //Para el uso de Strings

using namespace std;

/*Es la definicion de una clase de un draft, donde se van a guardar sus cartas
aqui se guardan en dos arreglos, uno con el coste y el otro con el nombre.*/
class Draft
{
private:
    string nombre;
    string nombres_cartas[60];
    int costes_mana[60];
    int lugarInsert = 59;
public:
    Draft();
    Draft(string);
    ~Draft();
    void llenar_lands(int);
    void mostrar_deck();
    void agregar_carta(string,int);
    void sort_cartas();
    void swap_carta(int,int);

};

Draft::Draft()
{
    nombre="";
}

Draft::~Draft()
{
}

Draft::Draft(string nombre_){
    nombre=nombre_;
}

//LLena el arreglo de tierras
void Draft::llenar_lands(int limite){
    for (int i=0;i<=59;i++){
        nombres_cartas[i]="Plains";
        costes_mana[i]=0;
    }
}

//Muestra todo el arreglo
void Draft::mostrar_deck(){
    for (int i=0;i<=59;i++){
        cout << "Coste: " << costes_mana[i];
        cout << " Nombre: " << nombres_cartas[i] << endl;
    }
}

//Funcion auxiliar del sort_cartas, para hacer el swap en ambos
//arreglos.
void Draft::swap_carta(int a, int b){
    int aux_coste = costes_mana[a];
    string aux_nombre = nombres_cartas[a];
    costes_mana[a] = costes_mana[b];
    nombres_cartas[a] = nombres_cartas[b];
    costes_mana[b]=aux_coste;
    nombres_cartas[b]=aux_nombre;

}

/*Se uso e  esta actividad un bubble sort, expecificamente
por el hecho de que el cambio de un arreglo debe de actuar en el otro.
Se ordena de mayor a menor, y asi las cartas nuevas se agregan hasta abajo.-*/
void Draft::sort_cartas(){
    for (int i=0;i<=59;i++){
        for(int j=59; j>i;j--){
            if (costes_mana[j]>costes_mana[j-1]){
                swap_carta(j,j-1);
            }
        }
    }
}

void Draft::agregar_carta(string nombre, int coste){
    nombres_cartas[lugarInsert] = nombre;
    costes_mana[lugarInsert] = coste;
}
#endif 
