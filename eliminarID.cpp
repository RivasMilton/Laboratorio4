void eliminarPorId(int id) { 
    if (head == NULL) { //verificar para que no truene
        cout << "Lista vacia\n";
        return;
    }
    Nodo* aux = head; // iniciamos desde el primer nodo

    while (aux != NULL) { // Recorremos la lista
        if (aux->id == id) { 
            if (head == tail) {
                head = NULL; // La lista queda vacía pq no hay mas nodos
                tail = NULL;
            }
            
            else if (aux == head) { // eliminar solo si es el primer nodo
                head = head->sig;
                head->ant = NULL;
            }
        
            else if (aux == tail) { // eliminar solo si es el ultimo nodo
                tail = tail->ant;
                tail->sig = NULL;
            }
            
            else {                  // eliminar en medio de la lista
                aux->ant->sig = aux->sig;
                aux->sig->ant = aux->ant;
            }

            delete aux; 
            contador--;

            cout << "Paquete eliminado correctamente\n";
            return;
        }

        // Avanzamos al siguiente nodo
        aux = aux->sig;
    }

    // else para cuando no se encuentra el id xd
    cout << "ID no encontrado\n";
}
