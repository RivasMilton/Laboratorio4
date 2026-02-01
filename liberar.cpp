void liberarLista() {

    Nodo* aux = head; //iniciar desde el primer nodo

    while (aux != NULL) { //recorrer la lista
        Nodo* borrar = aux;
        aux = aux->sig; 
        delete borrar;  //borrar el nodo actual
    }

    head = NULL; //lo dejamos como el inicio
    tail = NULL; //lo dejamos como el final
    contador = 0; //reiniciamos el contador
}
