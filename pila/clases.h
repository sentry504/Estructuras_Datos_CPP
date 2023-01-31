#include <iostream>
using namespace std;

class pila;
class nodo{
    private:
        double dato;
        nodo *sig;
        nodo();
friend pila;
};

class pila{
private:
    nodo *tope;
    int nnodos;
public:
    pila();
    //~pila();
    //---------M. Basicos ------------
    void push(double=0); //pone datos en la pila
    double top();       //retorna el valor tope
    void drop();        //borra el nodo en el tope
    double pop();       //borra el nodo tope retornando su valor
    //---------M. de manejo ----------
    void show();        //muestra los datos de la pila
    void swap();        //intercambia los dos nodos en el tope
    void dup();         //duplica el nodo en el tope de la pila
    void pick();//*     //recibe pos del tope de la pila y hace una copia del nodo en esa posicion
    void dupn();//*     //duplica n nodos en el tope
    void dropn();		//borra n nodos en el tope de la pila
    void rollu();//*    //permite subir un nodo al tope
    void rolld();//*    //permite bajar el nodo tope a la pos x
    void depth();       //pone en el tope la cantidad de nodos
    void clear();       //limpia la pila
    //---------M. de operacion -------
    void add();//*      //suma los nodos en el tope
    void sub();//*      //resta
    void mult();//*     //multiplica
    void divi();//*     //divide
    void pot();//*      //potencia B^E
};
