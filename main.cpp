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
        cout << "Quieres (0) agregar una carta, (1) ver tus cartas, (2) Salir, (3) Crear Caso Prueba (es una deck ya hecha), (4) Terminar deck" << endl;
        int des;
        cin >> des;
        /*En esta primera opcion, se van a agregar cartas hasta el final. Complejidad en draft.h
        NO USAR ESPACIOS POR PRECAUCION!!!!
        */
        if (des == 0)
        {
            string nombre;
            string tipo;
            string color;
            int coste;
            int manapips;
            cout << "Vas a agregar una carta, no uses espacios."<<endl;
            cout << "Dame el nombre de la carta a agregar:" << endl;
            cin >> nombre;
            cout << "Dame el tipo de carta a agregar:" <<endl;
            cin >> tipo;
            cout << "Dame el color de la carta" <<endl;
            cin >> color;
            cout << "Dame el costo de la carta a agregar:" << endl;
            cin >> coste;
            cout << "Dame el número de mana pips de la carta a agregar:" <<endl;
            cin >> manapips;
            usuario.agregarCarta(draft_usado, nombre, tipo, color, coste, manapips);

        }
        /*Aqui te muestra la deck ya organizada, usando el sort explicado
        antes.*/
        else if (des==1)
        {
            usuario.mostrarDraft(draft_usado);
        }
        /*Es para salir de la aplicacion*/
        else if (des==2)
        {
            break;
        }
        /*Genera los casos de prueba*/
        else if (des==3)
        {
            draft_usado+=1;
            usuario.casoPrueba(draft_usado);
        }
        /*Completa una deck con tierras.*/
        else if (des==4){
            usuario.terminarDeck(draft_usado);
        }
    }
    

}
