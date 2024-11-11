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
#include <fstream> //Para guardar o crear drafts en un archivo
#include "user.h" //Biblioteca de usuarios de mi proyecto

using namespace std;

int main()
{
    cout << "Bienvenido a el organizador de Drafts de MTG" << endl;
    cout << "En este programa se va a guardar toda la info de las cartas elegidas" << endl;
    cout << "Dame un nombre del jugador: " << endl;
    string jugador;
    cin >> jugador;
    User usuario;
    usuario.setNombre(jugador);
    int draft_usado=0;
    fstream archDraft("DraftsGuardados.txt"); //Investigacion externa para el append de datos.
    if (archDraft.is_open()){
        string nom, tipo, color;
        int draft, coste, mana;
        while(archDraft >> draft){
            usuario.ComenzarDraft(draft);
            for(int i=0;i<40;i++){
                archDraft >> nom;
                archDraft >> tipo;
                archDraft >> color;
                archDraft >> coste;
                archDraft >> mana;
                usuario.agregarCarta(draft, nom, tipo, color, coste, mana);
            }
            usuario.deckinicio(draft);
            draft_usado++;

        }

    }

    usuario.ComenzarDraft(draft_usado);
    cout << "Perfecto, ahora vamos a comenzar el primer draft:" << endl;
    bool ciclo = true;
    while (ciclo == true){
        //Para ver 
        cout << "Quieres (0) agregar una carta, (1) ver tus cartas, (2) Salir, (3) Crear Caso Prueba (es una deck ya hecha)";
        cout <<", (4) Terminar deck, (5) Mostrar deck anterior" << endl;
        cout << "No uses espacios, usa _ si lo necesitas."<<endl;
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
            usuario.guardarDeck(draft_usado);
            cout << "Voy a crear un deck nuevo: "<<endl;
            draft_usado+=1;
            usuario.ComenzarDraft(draft_usado);
        }

        else if (des==5){
            int deckElegida;
            cout << "Elige la deck que quieres volver a visitar, no podras cambiarla pero si verla."<<endl;
            cout << "En nuevas entregas podras ver los resultados de victorias y perdidas"<<endl;
            cin >> deckElegida;
            usuario.deckinicio(deckElegida);
        }
    }
    

}
