
// * Actividad 2.1 - Listas ligadas simples


#include <iostream>
using namespace std;

// Nodo de la lista
struct Nodo {
    int dato;
    Nodo* siguiente;
};

/*
 * Inserta_al_inicio
 * Descripcion: se encarga de meter un elemento al inicio de la lista ligada.
 * Entrada: doble apuntador a la cabeza (Nodo) y el elemento a insertar.
 * Salida: lista valida con el elemento insertado.
 * Complejidad: O(1) en tiempo y espacio (solo se crea un nodo y se
 *              reasignan dos apuntadores).
 */
void Inserta_al_inicio(Nodo** cabeza, int valor) {
    Nodo* nuevo = new Nodo{valor, *cabeza};
    *cabeza = nuevo;
}

/*
 * Inserta_al_final
 * Descripcion: inserta un elemento al final de la lista ligada.
 * Entrada: doble apuntador a la cabeza (Nodo**) y el elemento a insertar.
 * Salida: lista valida con el elemento insertado.
 * Complejidad: O(n) en tiempo, donde n es el numero de nodos, porque
 *              hay que recorrer la lista hasta el ultimo nodo. O(1) en espacio.
 */
void Inserta_al_final(Nodo** cabeza, int valor) {
    Nodo* nuevo = new Nodo{valor, nullptr};
    while (*cabeza != nullptr) {
        cabeza = &((*cabeza)->siguiente);
    }
    *cabeza = nuevo;
}

/*
 * Elimina_al_inicio
 * Descripcion: elimina el elemento al inicio de la lista. Si la lista esta
 *              vacia, escribe la palabra ERROR.
 * Entrada: doble apuntador a la cabeza (Nodo**).
 * Salida: lista valida (sin el primer elemento).
 * Complejidad: O(1) en tiempo y espacio.
 */
void Elimina_al_inicio(Nodo** cabeza) {
    if (*cabeza == nullptr) {
        cout << "ERROR" << endl;
        return;
    }
    Nodo* borrar = *cabeza;
    *cabeza = borrar->siguiente;
    delete borrar;
}

/*
 * Elimina_al_final
 * Descripcion: elimina el elemento al final de la lista. Si la lista esta
 *              vacia, escribe la palabra ERROR.
 * Entrada: doble apuntador a la cabeza (Nodo**).
 * Salida: lista valida (sin el ultimo elemento).
 * Complejidad: O(n) en tiempo, porque se recorre la lista hasta el ultimo
 *              nodo. O(1) en espacio.
 */
void Elimina_al_final(Nodo** cabeza) {
    if (*cabeza == nullptr) {
        cout << "ERROR" << endl;
        return;
    }
    while ((*cabeza)->siguiente != nullptr) {
        cabeza = &((*cabeza)->siguiente);
    }
    delete *cabeza;
    *cabeza = nullptr;
}

/*
 * Imprime
 * Descripcion: imprime los elementos de la lista, uno por linea.
 * Entrada: apuntador a la cabeza (Nodo*).
 * Salida: los elementos en la salida estandar; la lista no se modifica.
 * Complejidad: O(n) en tiempo, O(1) en espacio.
 */
void Imprime(Nodo* cabeza) {
    for (Nodo* actual = cabeza; actual != nullptr; actual = actual->siguiente) {
        cout << actual->dato << endl;
    }
}

// Libera toda la memoria de la lista. Complejidad: O(n).
void Libera(Nodo** cabeza) {
    while (*cabeza != nullptr) {
        Elimina_al_inicio(cabeza);
    }
}

int main() {
    Nodo* cabeza = nullptr;
    int opcion, valor;

    // Menu ciclado: no se imprime, solo se espera la entrada del usuario.
    while (cin >> opcion && opcion != 0) {
        switch (opcion) {
            case 1:
                cin >> valor;
                Inserta_al_inicio(&cabeza, valor);
                break;
            case 2:
                cin >> valor;
                Inserta_al_final(&cabeza, valor);
                break;
            case 3:
                Elimina_al_inicio(&cabeza);
                break;
            case 4:
                Elimina_al_final(&cabeza);
                break;
            case 5:
                Imprime(cabeza);
                break;
            default:
                break;  // opcion invalida: se ignora
        }
    }

    Libera(&cabeza);
    return 0;
}
