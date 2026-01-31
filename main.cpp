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

void insertarFinal(int id, string nombre, float peso) {
    Nodo* nuevo = new Nodo();
    nuevo->id = id;
    nuevo->nombre = nombre;
    nuevo->peso = peso;

    if (head == NULL) {
        head = tail = nuevo;
        nuevo->sig = NULL;
        nuevo->ant = NULL;
    } else {
        tail->sig = nuevo;
        nuevo->ant = tail;
        nuevo->sig = NULL;
        tail = nuevo;
    }
    contador++;
}

void mostrarAdelante() {
    if (head == NULL) {
        cout << "Lista vacia" << endl;
        return;
    }
    Nodo* aux = head;
    while (aux != NULL) {
        cout << "[" << aux->id << "] "
             << aux->nombre << " - "
             << aux->peso << "kg" << endl;
        aux = aux->sig;
    }
}

void mostrarAtras() {
    if (tail == NULL) {
        cout << "Lista vacia" << endl;
        return;
    }
    Nodo* aux = tail;
    while (aux != NULL) {
        cout << "[" << aux->id << "] "
             << aux->nombre << " - "
             << aux->peso << "kg" << endl;
        aux = aux->ant;
    }
}

void mostrarCantidad() {
    cout << "Total de paquetes: " << contador << endl;
}

int main() {
    int op, id;
    string nombre;
    float peso;

    do {
        cout << "-- MENU ---" << endl;
        cout << "1. Insertar inicio" << endl;
        cout << "2. Insertar final" << endl;
        cout << "3. Mostrar adelante" << endl;
        cout << "4. Mostrar atras" << endl;
        cout << "5. Cantidad" << endl;
        cout << "0. Salir" << endl;
        cout << "Opcion: ";
        cin >> op;

        switch (op) {
            case 1:
                cin >> id >> nombre >> peso;
                insertarInicio(id, nombre, peso);
                break;
            case 2:
                cin >> id >> nombre >> peso;
                insertarFinal(id, nombre, peso);
                break;
            case 3:
                mostrarAdelante();
                break;
            case 4:
                mostrarAtras();
                break;
            case 5:
                mostrarCantidad();
                break;
        }
    } while (op != 0);

    return 0;
}
