#include <iostream>
using namespace std;

struct Nodo {
    int id;
    string nombre;
    float peso;
    Nodo* sig;
    Nodo* ant;
};
 
Nodo* head = NULL;
Nodo* tail = NULL;
int contador = 0;
void insertarInicio(int id, string nombre, float peso) {
    Nodo* nuevo = new Nodo();
    nuevo->id = id;
    nuevo->nombre = nombre;
    nuevo->peso = peso;

    if (head == NULL) {
        head = tail = nuevo;
        nuevo->sig = NULL;
        nuevo->ant = NULL;
    } else {
        nuevo->sig = head;
        nuevo->ant = NULL;
        head->ant = nuevo;
        head = nuevo;
    }
    contador++;
}
