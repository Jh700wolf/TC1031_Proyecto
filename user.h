#ifndef USER_H_
#define USER_H_


#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include "draft.h"

using namespace std;

/*Es la definicion de una clase de un usuario, donde se van a guardar sus drafts*/

class User
{
    private:
        string nombre;
        Draft *drafts[100];
        int numero_drafts=0;

    public:
        User();
        void setNombre(string);
        void ComenzarDraft(int);
        void mostrarDraft(int);
        void mostrarDraftMP(int);
        void agregarCarta(int,string,string,string,int,int);
        void casoPrueba(int);
        void terminarDeck(int);
        void guardarDeck(int);
        void deckinicio(int);
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

Inicializa un draft en la posicion n. Empieza a escribirlo en el archivo.txt*/
void User::ComenzarDraft(int n)
{
    drafts[n] = new Draft();
}

/*
ENTRADA: numero de draft donde se esta trabajando
SALIDA: no tiene

Primero ordena las cartas, para luego mostrarlas al usuario de forma de head a tail
y de tail a head. Complejidad en las funciones de draft.*/

void User::mostrarDraft(int n){
    cout << "Asi se ven en orden tus cartas:" << endl;
    drafts[n]->sortDeckCost();
    drafts[n]->mostrarDeckadelante();
    drafts[n]->mostrarDeckatras();
}

void User::mostrarDraftMP(int n){
    cout << "Asi se ven en orden tus cartas:" << endl;
    drafts[n]->sortDeckManaP();
    drafts[n]->mostrarDeckPips();
}

void User::deckinicio(int n){
    cout << "Se estan cargando las decks"<<endl;
    cout << "Deck cargada:" << n << endl;
    drafts[n]->sortDeckCost();
    drafts[n]->mostrarDeckadelante();
}
/*
ENTRADA: numero de draft donde se esta trabajando,
nombre de la carta a agregar, tipo de carta, color,coste de la carta
mana pips de la carta.
SALIDA: no tiene

Inserta una carta nueva al final de la lista, conectada al tail.*/
void User::agregarCarta(int n,string nombre_carta, string tipo_carta, string color_, int coste, int manapips){
    drafts[n] -> insertCard(nombre_carta, tipo_carta,color_, coste, manapips);
}

/*Esta funcion unicamente sirve de apoyo al evaluador, para que no 
tengan que crear de carta por carta y puedan ver el proyecto
funcionando*/
void User::casoPrueba(int n){
    drafts[n] = new Draft;
    drafts[n] ->casoPrueba();
    cout << "Asi se ve el ejemplo antes del Sort:" << endl;
    drafts[n] ->mostrarDeckadelante();
}

void User::terminarDeck(int n){
    drafts[n]->llenarLands();
    cout << "Tu deck ya esta completa, asi se ve:"<<endl;
    drafts[n]->mostrarDeckadelante();

}

void User::guardarDeck(int n){
    drafts[n]->sortDeckCost();
    fstream archDraft("DraftsGuardados.txt",ios::app);
        if (archDraft.is_open()){
            archDraft << n <<endl;
            archDraft.close();
            drafts[n]->guardarCartas();
            
        }
        else{
            cout<<"Problema al abrir el archivo"<< endl;
        }
}

#endif
