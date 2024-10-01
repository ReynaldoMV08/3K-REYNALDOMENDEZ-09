// 3K-REYNALDOMENDEZ-09.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>

using namespace std;

struct nodo {
    int dato;
    nodo* siguiente;
};

void agregarNodo(nodo*& cabeza, int valor) {
    nodo* nuevoNodo = new nodo;
    nuevoNodo->dato = valor;
    nuevoNodo->siguiente = nullptr;

    if (cabeza == nullptr) {
        cabeza = nuevoNodo;
    }
    else {
        nodo* actual = cabeza;
        while (actual->siguiente != nullptr) {
            actual = actual->siguiente;
        }
        actual->siguiente = nuevoNodo;
    }
}

void imprimirLista(nodo* cabeza) {  // Cambiado a imprimirLista
    nodo* actual = cabeza;
    while (actual != nullptr) {
        cout << actual->dato << " ";
        actual = actual->siguiente;
    }
    cout << endl;
}

void borrarLista(nodo*& cabeza) {
    while (cabeza != nullptr) {
        nodo* siguiente = cabeza->siguiente;
        delete cabeza;
        cabeza = siguiente;
        cout << "elemento borrado ";
    }
}

int main() {
    nodo* cabeza = nullptr;
    int tamanolista;  // Cambiado a tamanolista
    cout << "ingrese la cantidad de elementos que desea agregar a la lista: ";
    cin >> tamanolista;

    if (tamanolista <= 0) {
        cout << "cantidad de elementos no valida" << endl;
        return 1;
    }

    for (int i = 0; i < tamanolista; i++) {
        int valor;
        cout << "ingrese dato " << i + 1 << ": ";
        cin >> valor;
        agregarNodo(cabeza, valor);
    }

    cout << "imprimiendo lista de numeros" << endl;
    imprimirLista(cabeza);

    borrarLista(cabeza);

    return 0;
}