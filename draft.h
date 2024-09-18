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
    string nombres_cartas[40];
    int costes_mana[40];
    int lugarInsert = 39;
public:
    Draft();
    Draft(string);
    ~Draft();
    void llenar_lands(int);
    void mostrar_deck();
    void agregar_carta(string,int);
    void sort_cartas();
    void swap_carta(int,int);
    void casoPrueba();

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
    for (int i=0;i<=39;i++){
        nombres_cartas[i]="Plains";
        costes_mana[i]=0;
    }
}

//Muestra todo el arreglo
void Draft::mostrar_deck(){
    for (int i=0;i<=39;i++){
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
    for (int i=0;i<=39;i++){
        for(int j=39; j>i;j--){
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

void Draft::casoPrueba()
{
    costes_mana[0]=3;
    nombres_cartas[0]="Rocco_Street_Chef";
    costes_mana[1]=1;
    nombres_cartas[1]="Shock";
    costes_mana[2]=4;
    nombres_cartas[2]="Krenko_Mob_Boss";
    costes_mana[3]=2;
    nombres_cartas[3]="Rampant_Growth";
    costes_mana[4]=2;
    nombres_cartas[4]="Fblthp_The_Lost";
    costes_mana[5]=3;
    nombres_cartas[5]="Cancel";
    costes_mana[6]=9;
    nombres_cartas[6]="Omnicience";
    costes_mana[7]=4;
    nombres_cartas[7]="Smothering_Tithe";
    costes_mana[8]=3;
    nombres_cartas[8]="Murder";
}
#endif 
