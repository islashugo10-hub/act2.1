/*
 * Actividad 2.1 - Listas ligadas simples
 * Integrantes:
 * Jaime Hugo Islas Trujillo - A01821293
 * Francisco Xavier Olivos Barranco - A01820288
 *
 * Programa que maneja una lista ligada simple de enteros (puede tener
 * repetidos) con un menu ciclado. El menu no se muestra, solo se lee la
 * opcion que escribe el usuario.
 *
 * Opciones: 1 Inserta al inicio    2 Inserta al final  3 Elimina al inicio    4 Elimina al final  5 Imprime              0 Salir
 */


#include <iostream>
using namespace std;

// Cada nodo guarda un entero y la direccion del nodo que sigue.
struct Nodo {
    int dato;
    Nodo* siguiente;
};

/*
 * Inserta_al_inicio

 * Descripcion:   Mete un elemento nuevo al principio de la lista.

 * Entrada:       Doble apuntador a la cabeza y el elemento a insertar.

 * Salida:        Estructura de datos valida con el elemento insertado.

 * Precondicion:  Estructura de datos valida.

 * Postcondicion: Estructura modificada, el nodo nuevo queda como cabeza.

 * Complejidad:   Tiempo O(1) y espacio O(1), solo se crea un nodo y se cambian dos apuntadores sin importar el tamano de la lista.


 */
void Inserta_al_inicio(Nodo** cabeza, int valor) {
    Nodo* nuevo = new Nodo{valor, *cabeza};  // el nuevo apunta a la cabeza actual
    *cabeza = nuevo;                         // y ahora el nuevo es la cabeza
}

/*
 * Inserta_al_final
 * Descripcion:   Mete un elemento nuevo al final de la lista.
 * 
 * Entrada:       Doble apuntador a la cabeza y el elemento a insertar.
 * 
 * Salida:        Estructura de datos valida con el elemento insertado.
 * 
 * Precondicion:  Estructura de datos valida.
 * 
 * Postcondicion: Estructura modificada, el nodo nuevo queda como ultimo.
 * 
 * Complejidad:   Tiempo O(n) porque hay que recorrer los n nodos para llegar al final. Espacio O(1).
 *                
 */
void Inserta_al_final(Nodo** cabeza, int valor) {
    Nodo* nuevo = new Nodo{valor, nullptr};

    // Avanzamos de apuntador en apuntador hasta encontrar uno que valga
    // nullptr. Ahi es donde va el nodo nuevo (tambien sirve si la lista
    // esta vacia).
    while (*cabeza != nullptr) {
        cabeza = &((*cabeza)->siguiente);
    }
    *cabeza = nuevo;
}

/*
 * Elimina_al_inicio
 * Descripcion:   Borra el primer elemento de la lista. Si la lista esta vacia escribe ERROR.
 *                
 * Entrada:       Doble apuntador a la cabeza, valido.
 * 
 * Salida:        Estructura de datos valida.
 * 
 * Precondicion:  Estructura de datos valida.
 * 
 * Postcondicion: Estructura de datos valida, la cabeza pasa a ser el segundo nodo (o nullptr si solo habia uno).
 *                
 * Complejidad:   Tiempo O(1) y espacio O(1).
 */
void Elimina_al_inicio(Nodo** cabeza) {
    if (*cabeza == nullptr) {
        cout << "ERROR" << endl;
        return;
    }

    Nodo* borrar = *cabeza;         // guardamos el nodo para no perderlo
    *cabeza = borrar->siguiente;    // la cabeza se recorre al siguiente
    delete borrar;                  // y liberamos el que sacamos
}

/*
 * Elimina_al_final
 * Descripcion:   Borra el ultimo elemento de la lista. Si la lista esta  vacia escribe ERROR.
 *               
 * Entrada:       Doble apuntador a la cabeza, valido.
 * 
 * Salida:        Estructura de datos valida.
 * 
 * Precondicion:  Estructura de datos valida.
 * 
 * Postcondicion: Estructura de datos valida, el penultimo nodo (o la cabeza si solo habia uno) queda apuntando a nullptr.
 *              
 * Complejidad:   Tiempo O(n) porque se recorre la lista hasta el ultimo nodo. Espacio O(1).
 *                
 */
void Elimina_al_final(Nodo** cabeza) {
    if (*cabeza == nullptr) {
        cout << "ERROR" << endl;
        return;
    }

    // Nos paramos en el apuntador que senala al ultimo nodo.
    while ((*cabeza)->siguiente != nullptr) {
        cabeza = &((*cabeza)->siguiente);
    }
    delete *cabeza;
    *cabeza = nullptr;   // ese apuntador ahora marca el nuevo final
}

/*
 * Imprime
 * Descripcion:   Muestra los elementos de la lista, uno por linea.
 * 
 * Entrada:       Apuntador a la cabeza, valido.
 * 
 * Salida:        Los elementos en pantalla y la estructura de datos valida.
 * 
 * Precondicion:  Estructura de datos valida.
 * 
 * Postcondicion: Estructura de datos valida, sin cambios.
 * 
 * Complejidad:   Tiempo O(n) porque se visita cada nodo una vez. Espacio O(1).
 * 
 */
void Imprime(Nodo* cabeza) {
    for (Nodo* actual = cabeza; actual != nullptr; actual = actual->siguiente) {
        cout << actual->dato << endl;
    }
}

/*
 * Libera
 * Descripcion:   Libera todos los nodos de la lista antes de terminar el programa, para no dejar memoria sin liberar.
 *                
 * Entrada:       Doble apuntador a la cabeza, valido.
 * 
 * Salida:        Lista vacia (cabeza en nullptr).
 * 
 * Precondicion:  Estructura de datos valida.
 * 
 * Postcondicion: No queda ningun nodo en memoria dinamica.
 * 
 * Complejidad:   Tiempo O(n) y espacio O(1).
 * 
 */
void Libera(Nodo** cabeza) {
    while (*cabeza != nullptr) {
        Elimina_al_inicio(cabeza);
    }
}

int main() {
    Nodo* cabeza = nullptr;   // lista vacia al empezar
    int opcion, valor;

    // El menu no se imprime. Se repite hasta que llegue un 0.
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
                break;   // cualquier otra opcion se ignora
        }
    }

    Libera(&cabeza);
    return 0;
}