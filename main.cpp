/*
ORGANIZADOR DE CARTAS DE MTG
Autor: José Pablo Gonzalez
Descripción:
Este código va a servir para poder almacenar una lista de cartas obtenidas en un draft. 
Se van a tener varios objetos de drafts, y cada uno va a tener un arreglo de costes y 
otro arreglo de cartas.

*/


#include <string>
#include <iostream>
#include <sstream> //Para el uso de Strings
#include "user.h" //Biblioteca de usuarios de mi proyecto

using namespace std;

int main()
{
    cout << "Bienvenido a el organizador de Drafts de MTG" << endl;
    cout << "En este programa se va a guardar toda la infro de las cartas elegidas" << endl;
    cout << "Dame un nombre del jugador: " << endl;
    string jugador;
    cin >> jugador;
    User usuario;
    usuario.setNombre(jugador);
    cout << "Perfecto, ahora vamos a comenzar el primer draft:" << endl;
    
    int draft_usado=0;
    usuario.ComenzarDraft(draft_usado);
    bool ciclo = true;
    while (ciclo == true){
        //Para ver 
        cout << "Quieres (0) agregar una carta, (1) ver tus cartas?, (2) Salir, o (3) Crear Caso Prueba (es una deck ya hecha)? " << endl;
        int des;
        cin >> des;
        /*En esta primera opcion, se van a agregar cartas hasta abajo, esto
        para que puedas agregar las cartas sin cambiar otras cartas.
        */
        if (des == 0)
        {
            string nombre;
            int coste;
            cout << "Dame el nombre de la carta a agregar:" << endl;
            cin >> nombre;
            cout << "Dame el costo de la carta a agregar:" << endl;
            cin >> coste;
            usuario.agregarCarta(draft_usado,nombre, coste);

        }
        /*Aqui te muestra la deck ya organizada, usando el sort explicado
        antes.*/
        else if (des==1)
        {
            usuario.mostrarDraft(draft_usado);
        }
        /*La ultima es para salir de la aplicacion*/
        else if (des==2)
        {
            break;
        }
        else if (des==3)
        {
            draft_usado+=1;
            usuario.casoPrueba(draft_usado);
        }
    }
    

}
