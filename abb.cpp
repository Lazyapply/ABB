#include "abb.hpp"
#include <iostream>
#include <stdlib.h>

using namespace std;

void insertarNodo(ABB &arbol, int xdata){
    ABB nuevoNodo;
    //si no existe

        if(!arbol){
            nuevoNodo = new(nodo);
            nuevoNodo->dato = xdata;
            nuevoNodo->izq  = NULL;
            nuevoNodo->der  = NULL;
            arbol= nuevoNodo;
        }
        else if(buscarNodo(arbol, xdata) == false){
            if(xdata < arbol->dato){
                    insertarNodo(arbol->izq, xdata);
            }
            if(xdata > arbol->dato){
                    insertarNodo(arbol->der, xdata);
            }
        }
}
bool buscarNodo(ABB &arbol, int xdata){
    if(!arbol)
            return false;
    //si es mayor que busque en la izq
    else if(arbol->dato > xdata)
        buscarNodo(arbol->izq, xdata);
    //si es menor que busque en la der
    else if(arbol->dato < xdata)
        buscarNodo(arbol->der, xdata);
    else
        return true;

}
void imprimirArbol(ABB &arbol){
    if(arbol){
        imprimirArbol(arbol->izq);
        cout << arbol->dato << ", ";
        imprimirArbol(arbol->der);
    }
}
void eliminarNodo(ABB &arbol, int xdata){
    ABB padre = NULL;
    ABB actual;
    ABB nodo;
    int aux;

    //empezmos por el arbol padre
    actual = arbol;
    while(actual){
            //si el nodo raiz = nodo buscado
        if(xdata == actual->dato){
            //si es hoja
            if(!actual->izq && !actual->der){
                if(padre){
                    if(padre->der == actual)
                        padre->der = NULL;
                    else if(padre->izq == actual)
                        padre->izq = NULL;
                }
                else
                    arbol = NULL;

                actual = NULL;
            }
            else{
                //nodo raiz = actual
                padre = actual;
                //si tiene nodo a la derecha
                if(actual->der){
                    nodo = actual->der;
                    //buscamos el mas a la izquierda
                    while(nodo->izq){
                        padre = nodo;
                        nodo = nodo->izq;
                    }
                }
                else{
                    //Buscamos el mas a la derecha
                    nodo = actual->izq;
                    while(nodo->der){
                        padre = nodo;
                        nodo = nodo->der;
                    }
                }
                //intercambiamos los elementos entre nodo Raiz y nodo
                aux = actual->dato;
                actual->dato = nodo->dato;
                nodo->dato = aux;
                actual = nodo;
            }
        }
        else{
            padre = actual;
            //si el valor del nodo raiz > que el nodo, continuamos por el arbol izquierdo
            if(xdata > actual->dato)
                actual = actual->der;
            else if(xdata  < actual->dato)
                actual = actual->izq;
        }
    }
}
int numNodos(ABB &arbol, int &nodos){
    if(arbol){
        numNodos(arbol->izq, nodos);
        nodos++;
        numNodos(arbol->der, nodos);
    }
    return nodos;
}
void eliminarSubarbol(ABB &arbol,int &xdata){
    if(arbol->dato < xdata)
        eliminarSubarbol(arbol->der, xdata);
    else if(arbol->dato > xdata)
        eliminarSubarbol(arbol->izq, xdata);
    else if(arbol->dato == xdata)
        arbol = NULL;
}
void menu(){
    system("CLS");
    cout << "\n\tPractica 2 Arboles de Busqueda Binaria\n";
    cout << "\t--------------------------------------\n";
    cout << "\n\tOpciones disponibles: \n";
    cout << "\n\t\t1 - Insertar nodo\n";
    cout << "\t\t2 - Buscar nodo\n";
    cout << "\t\t3 - Imprimir arbol\n";
    cout << "\t\t4 - Eliminar nodo\n";
    cout << "\t\t5 - Numero de nodos\n";
    cout << "\t\t6 - Eliminar subarbol\n";
    cout << "\n\n\t\t0 - Salir";
}
