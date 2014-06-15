typedef struct nodo{
    int dato;
    struct nodo *izq, *der;
}*ABB;

bool buscarNodo(ABB &arbol, int xdata);
void insertarNodo(ABB &arbol, int xdata);
void imprimirArbol(ABB &arbol);
void eliminarNodo(ABB &arbol, int xdata);
int numNodos(ABB &arbol, int &nodos);
void eliminarSubarbol(ABB &arbol,int &xdata);
void menu();
