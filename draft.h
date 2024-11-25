#ifndef DRAFT_H_
#define DRAFT_H_


#include <string>
#include <iostream>
#include <sstream> //Para el uso de Strings

using namespace std;
/*Aqui se define la clase de Carta, la cual almacena todos los valores
importantes de una carta. Ademas, trae sus uniones de prev y next para la lista
doblemente ligada. Se selecciono este metodo, ya que en este proyecto se debe de 
acomodar las cartas de distintas formas de acuerdo a coste
o a mana pips, y los arboles se desharian muy facilmente.*/
class Carta{
    private:
    //Valores para el usuario
        string nombre;
        string tipo;
        string color;
        int coste;
        int manaPips;
    //Valores para el sistema
        Carta *prev;
        Carta *next;
    public:
        Carta();
        Carta(string, string, string, int, int);
        Carta(string, string, string, int, int, Carta*, Carta*); 
        friend class Draft;   
};

//Constructor vacio de Carta
Carta::Carta(){
    nombre="";
    tipo="";
    color="";
    coste=0;
    manaPips=0;
    prev=0;
    next=0;
}
//Constructor de carta, con apuntadores vacios.
Carta::Carta(string nom_, string tipo_, string color_,int cost, int manap){
    nombre=nom_;
    tipo=tipo_;
    color=color_;
    coste=cost;
    manaPips=manap;
    prev=0;
    next=0;
}
//Copiador de carta, aqui en caso de ser necesario mas adelante.
Carta::Carta(string nom_, string tipo_, string color_,int cost, int manap, Carta *p, Carta *n){
    nombre=nom_;
    tipo=tipo_;
    color=color_;
    coste=cost;
    manaPips=manap;
    prev=p;
    next=n;
}

/*Es la definicion de una clase de un draft, donde se van a guardar sus cartas
en una lista doblemente ligada. Tiene un head y un tail.*/
class Draft
{
private:
    string nombre;
    Carta *head;
    Carta *tail;
    int size;

public:
    Draft();
    bool vacia();
    void insertCard(string, string, string, int, int);
    void llenarLands();
    void mostrarDeckadelante();
    void mostrarDeckatras();
    void mostrarDeckPips();
    void sortDeckCost();
    void sortDeckManaP();
    Carta* SortMerge(Carta*);
    Carta* Cortar(Carta*);
    Carta* JuntarDeck(Carta*,Carta*);
    Carta* SortMergeManaP(Carta*);
    Carta* JuntarDeckManaP(Carta*,Carta*);
    void casoPrueba();
    void guardarCartas();
};

//Constructor vacio
Draft::Draft(){
    nombre = "";
    head=0;
    tail=0;
    size=0;
}
//Checa si la lista esta vacia, usando el apuntador head como señal.
bool Draft::vacia(){
    return (head==0);
}

//Inserta una carta hasta el final. Aqui no se acomodan las cartas. La complejidad de esta 
//funcion es de o(1), ya que o lo pone como primera carta o usa tail para ponerla al final. 
void Draft::insertCard(string nombre_, string tipo_, string color_, int coste_, int manapips_){
    Carta *nuevaCarta, *p;
    nuevaCarta = new Carta(nombre_,tipo_, color_,coste_,manapips_);
    if (vacia()){
        nuevaCarta->next=0;
        nuevaCarta->prev=0;
        tail=nuevaCarta;
        head=nuevaCarta;
        size++;
        return;
    }
    p=tail;
    p->next=nuevaCarta;
    nuevaCarta->prev=p;
    nuevaCarta->next=0;
    tail=nuevaCarta;
    size++;
}
//Se usa para llenar la deck de lands. Es una funcion o(n), ya que usa un
//while para ir agregando tierra por tierra hasta llegar al final de una deck normal.
void Draft::llenarLands(){
    if (size < 40){
        while (size<40){
            insertCard("Basic_Land","Basic_Land","Incoloro",0,0);
        }
    }
}

//Se muestra toda la lista de acuerdo al coste. Es una funcion o(n), ya que se recorren todos los elementos
//de esta lista desde el head al tail. 
void Draft::mostrarDeckadelante(){
    Carta *p;
    cout << "Asi se ve tu deck de la carta mas cara a la mas barata:"<<endl;
    p=head;
    while (p!=0){
        cout << "Carta: "<< p->nombre <<" Tipo: "<<p->tipo<< " Color: "<< p->color<<" Coste: "<<p->coste<<endl;
        p=p->next;
    }
}

//Se muestra toda la lista de acuerdo al coste. Es una funcion o(n), ya que se recorren todos los elementos
//de esta lista desde el tail al head.
void Draft::mostrarDeckatras(){
    Carta *p;
    cout << "Barato a caro: "<<endl;
    p=tail;
    while (p!=0){
        cout << "Carta: "<< p->nombre <<" Tipo: "<<p->tipo<< " Coste: "<<p->coste<<endl;
        p=p->prev;
    }
}

//Esta función utiliza bubble sort para acomodar las cartas de acuerdo al coste. Tiene una complejidad
// de o(n**2) conforme al tiempo, pero una espacial de o(1). El peor de los casos es si las cartas
// estan acomodadas de forma opuesta, lo que te lleva a recorrerla varias veces y cambiar de uno en uno
//todos los valores.
void Draft::sortDeckCost(){
    if (vacia()){
        return;
    }
    head=SortMerge(head);
    Carta *p=head;

    while (p->next&&p)
    {
        p=p->next;
    }

    tail=p;
    }

Carta* Draft::SortMerge(Carta *a){
    if (!a || !a->next){
        return a;
    }
    Carta *mitad, *Head_;
    mitad = Cortar(a);
    Head_=SortMerge(a);
    mitad=SortMerge(mitad);
    return JuntarDeck(Head_, mitad);

}

Carta* Draft::SortMergeManaP(Carta *a){
    if (!a || !a->next){
        return a;
    }
    Carta *mitad, *Head_;
    mitad = Cortar(a);
    Head_=SortMerge(a);
    mitad=SortMerge(mitad);
    return JuntarDeckManaP(Head_, mitad);

}

Carta* Draft::Cortar(Carta *a){
    Carta *p,*q, *aux;
    p=q=a;
    while (q->next && q->next->next){
        q=q->next->next;
        p=p->next;
    }
    aux = p->next;
    p->next=nullptr;
    return aux;

}
Carta* Draft::JuntarDeck(Carta *a, Carta *b){
    if (!a){
        return b;
    }
    else if (!b){
        return a;
    }
    if (a->coste<b->coste){

        a->next=JuntarDeck(a->next, b);
        if(a->next){
            a->next->prev=a;
        }
        a->prev=nullptr;

        return a;
    }
    else{
        b->next=JuntarDeck(a, b->next);
        if (b->next){
            b->next->prev=b;
        }
        
        b->prev=nullptr;

        return b; 
    }
}

Carta* Draft::JuntarDeckManaP(Carta *a, Carta *b){
    if (!a){
        return b;
    }
    else if (!b){
        return a;
    }
    if (a->manaPips<b->manaPips){

        a->next=JuntarDeck(a->next, b);
        if(a->next){
            a->next->prev=a;
        }
        a->prev=nullptr;

        return a;
    }
    else{
        b->next=JuntarDeck(a, b->next);
        if (b->next){
            b->next->prev=b;
        }
        
        b->prev=nullptr;

        return b; 
    }
}



//Funcion para probar el sistema rapidamente.
void Draft::casoPrueba(){
    insertCard("Krenko_Mob_Boss","Creature","Red",4,2);
    insertCard("Even_the_Score", "Instant", "Blue",3,3);
    insertCard("Utvara_Hellkite","Creature","Red",8,2);
    insertCard("Necromantic_Selection","Sorcery","Black",7,3);
    insertCard("Grow_from_the_Ashes","Sorcery","Green",3,1);
    insertCard("Stitch_Together","Sorcery","Black",2,2);
    insertCard("Flameblast_Dragon","Creature","Red",6,2);
    llenarLands();
}

/*Esta función utiliza bubble sort para acomodar las cartas de acuerdo al numero de pips de un color. 
Tiene una complejidad de o(n**2) conforme al tiempo, pero una espacial de o(1). El peor de los casos es si las cartas
estan acomodadas de forma opuesta, lo que te lleva a recorrerla varias veces y cambiar de uno en uno
todos los valores.
*/
void Draft::sortDeckManaP(){
    if (vacia()){
        return;
    }
    head=SortMergeManaP(head);
    Carta *p=head;

    while (p->next&&p)
    {
        p=p->next;
    }

}
void Draft::mostrarDeckPips(){
    sortDeckManaP();
    Carta *p;
    cout << "Asi se ve tu deck de la carta con mas mana pips a las que casi no tienen:"<<endl;
    cout << "Toma en consideracion esto para ver si la carta es Splasheable o no." <<endl;
    p=head;
    while (p!=0){
        cout << "Carta: "<< p->nombre <<" Tipo: "<<p->tipo<< " Color: "<< p->color<<" Coste: "<<p->coste<<endl;
        p=p->next;
    }
}

void Draft::guardarCartas(){
    Carta *p;
    fstream archDraft("DraftsGuardados.txt",ios::app); //Investigacion externa para el append de datos.
    if (archDraft.is_open()){
        p=head;
        while (p!=0){
            archDraft << p->nombre <<" "<<p->tipo<< " "<< p->color<<" "<<p->coste<< 
            " " << p->manaPips<<endl;
            p=p->next;
        }
        archDraft.close();
    }

}
#endif
