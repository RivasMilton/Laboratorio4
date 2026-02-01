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

Nodo* buscarPorId(int id) {
    Nodo* aux = head;
    while (aux != NULL) {
        if (aux->id == id)
            return aux;
        aux = aux->sig;
    }
    return NULL;
}

void insertarInicio(int id, string nombre, float peso) {

    if (buscarPorId(id) != NULL) {
        cout << "ID repetido\n";
        return;
    }

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

    if (buscarPorId(id) != NULL) {
        cout << "ID repetido\n";
        return;
    }

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
        cout << "Lista vacia\n";
        return;
    }

    Nodo* aux = head;
    while (aux != NULL) {
        cout << "[" << aux->id << "] "
             << aux->nombre << " - "
             << aux->peso << "kg\n";
        aux = aux->sig;
    }
}

void mostrarAtras() {
    if (tail == NULL) {
        cout << "Lista vacia\n";
        return;
    }

    Nodo* aux = tail;
    while (aux != NULL) {
        cout << "[" << aux->id << "] "
             << aux->nombre << " - "
             << aux->peso << "kg\n";
        aux = aux->ant;
    }
}

void eliminarPorId(int id) {

    if (head == NULL) {
        cout << "Lista vacia\n";
        return;
    }

    Nodo* aux = head;

    while (aux != NULL) {
        if (aux->id == id) {

            if (head == tail) {
                head = tail = NULL;
            }
            else if (aux == head) {
                head = head->sig;
                head->ant = NULL;
            }
            else if (aux == tail) {
                tail = tail->ant;
                tail->sig = NULL;
            }
            else {
                aux->ant->sig = aux->sig;
                aux->sig->ant = aux->ant;
            }

            delete aux;
            contador--;
            cout << "Eliminado\n";
            return;
        }
        aux = aux->sig;
    }

    cout << "No existe\n";
}

void liberarLista() {
    Nodo* aux = head;
    while (aux != NULL) {
        Nodo* borrar = aux;
        aux = aux->sig;
        delete borrar;
    }
    head = tail = NULL;
    contador = 0;
}

int main() {
    int op, id;
    string nombre;
    float peso;

    do {
        cout << "\n--- MENU ---\n";
        cout << "1. Insertar inicio\n";
        cout << "2. Insertar final\n";
        cout << "3. Mostrar adelante\n";
        cout << "4. Mostrar atras\n";
        cout << "5. Cantidad\n";
        cout << "6. Buscar por ID\n";
        cout << "7. Eliminar por ID\n";
        cout << "0. Salir\n";
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
                cout << "Total: " << contador << endl;
                break;

            case 6:
                cin >> id;
                if (buscarPorId(id))
                    cout << "Existe\n";
                else
                    cout << "No existe\n";
                break;

            case 7:
                cin >> id;
                eliminarPorId(id);
                break;
        }

    } while (op != 0);

    liberarLista();
    return 0;
}
