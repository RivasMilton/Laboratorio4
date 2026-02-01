bool buscarPorId(int id) {

    Nodo* aux = head; // Iniciamos desde el primer nodo

    while (aux != NULL) { // Recorremos la lista
        if (aux->id == id) { // Si encuentra el id, returna verdadero
            return true;
        }

        // Avanzamos al siguiente nodo
        aux = aux->sig;
    }

    return false; //else returna falso
}
