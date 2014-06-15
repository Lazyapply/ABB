#include <iostream>
#include "abb.hpp"
#include <cstdlib>
#include <conio.h>
using namespace std;

int main()
{
    int opt = -1;
    int datoN=0;
    ABB nArbol = NULL;

    //Datos de demo
    int i=0;
    int d [28]={8, 2, 6, 5, 3, 9, 7, 15, 44, 51, 88, 19, 25, 33, 80, 20, 60, 50, 30, 90, 70, 150, 440, 510, 880, 190, 250, 330};
    for(i=0;i<28;i++)
        insertarNodo(nArbol, d[i]);


    while(opt != 0){
        switch (opt){

            case 1:
                system("CLS");
                cout << "\n\n\tIntroduce el valor del nuevo nodo: ";
                cin >> datoN;
                insertarNodo(nArbol, datoN);
                opt = -1;
            break;

            case 2:
                system("CLS");
                cout << "\n\n\tIntroduce el valor del nodo que buscas: ";
                cin >> datoN;
                system("CLS");
                if(buscarNodo(nArbol, datoN)){
                    cout << "\n\n\tEl nodo con valor < " << datoN << " > SI se encuentra en el arbol.\n";
                }
                else{
                    cout << "\n\n\tEl nodo con valor < " << datoN << " > NO se encuentra en el arbol.\n";
                }
                cout << "\tPulse una tecla para continuar...";
                getch();
                opt = -1;
            break;

            case 3:
                system("CLS");
                cout << "\n\tLos elementos del ABB son: ";
                cout << "\n\t";
                imprimirArbol(nArbol);
                cout << "\n\n\tPulse una tecla para continuar...";
                getch();
                opt = -1;
            break;

            case 4:
                system("CLS");
                cout << "\n\tIntroduzca el valor del nodo que quiere eliminar: ";
                cin >> datoN;
                    eliminarNodo(nArbol, datoN);
                cout << "\n\n\tPulse una tecla para continuar...";
                getch();
                opt = -1;
            break;

            case 5:
                int n;
                n=0;
                system("CLS");
                cout << "\n\tEl numero de nodos del arbol es: " << numNodos(nArbol, n);
                cout << "\n\n\tPulse una tecla para continuar...";
                getch();
                opt = -1;
            break;

            case 6:
                system("CLS");
                cout << "\n\tIntroduzca el valor del subarbol que quiere eliminar: ";
                cin >> datoN;
                    eliminarSubarbol(nArbol, datoN);
                cout << "\n\n\tPulse una tecla para continuar...";
                getch();
                opt = -1;
            break;

            default:
                menu();
                cout << "\n\n\tSeleccione una opcion: ";
                cin >> opt;
            break;
        }



    }
    return 0;
}
