#ifndef USER_H_
#define USER_H_


#include <string>
#include <iostream>
#include <sstream>
#include "draft.h"

using namespace std;

/*Es la definicion de una clase de un usuario, donde se van a guardar sus drafts*/
class User
{
    private:
        string nombre;
        Draft *drafts[10];
        int numero_drafts=0;

    public:
        User();
        void setNombre(string);
        void ComenzarDraft(int);
        void mostrarDraft(int);
        void agregarCarta(int,string,int);
        void casoPrueba(int);

};
// Constructor
User::User()
{
    nombre="";
}

//Cambiar nombre del usuario
void User::setNombre(string nombre_usuario){
    nombre = nombre_usuario;
}

/*
ENTRADA: numero de draft donde se esta trabajando
SALIDA: no tiene

Inicializa un draft. Primero lo crea. Despues lo llena
de lands (plains), y luego muestra la deck vacia*/
void User::ComenzarDraft(int n)
{
    drafts[n] = new Draft();
    drafts[n] -> llenar_lands(60);
    drafts[n] -> mostrar_deck();
}

/*
ENTRADA: numero de draft donde se esta trabajando
SALIDA: no tiene

Primero ordena las cartas, para luego mostrarlas al usuario.*/

void User::mostrarDraft(int n){
    cout << "Asi se ven en orden tus cartas:" << endl;
    drafts[n]->sort_cartas();
    drafts[n] ->mostrar_deck();
}

/*
ENTRADA: numero de draft donde se esta trabajando,
nombre de la carta a agregar, coste de la carta
SALIDA: no tiene

Ordena la lista (y asi no cambia las cartas de antes), y luego cambia una land
por la nueva carta */
void User::agregarCarta(int n,string nombre_carta, int coste){
    drafts[n] -> sort_cartas();
    drafts[n] -> agregar_carta(nombre_carta,coste);
}

void User::casoPrueba(int n){
    drafts[n] = new Draft;
    drafts[n] ->casoPrueba();
    cout << "Asi se ve el ejemplo antes del Sort:" << endl;
    drafts[n] ->mostrar_deck();
}
#endif
