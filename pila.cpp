#include <iostream>
#include <math.h>
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
    void duppila();
};

nodo::nodo(){
    dato=0;
    sig=NULL;
}



//---- metodos de pila-------------

pila::pila(){
    tope=NULL;
    nnodos=0;
}

void pila::push(double _dato){
    nodo *nuevo=new nodo;
    nuevo->dato=_dato;
    nuevo->sig=tope;
    tope=nuevo;
    nnodos++;
}

double pila::top(){
    return ((nnodos>0)?tope->dato:0);
}

void pila::drop(){
    if(tope!=NULL){
        nodo *tmp=tope;
        tope=tope->sig;
        delete tmp;
        nnodos--;
    }
}

double pila::pop(){
    double _dato=top();
    drop();
    return _dato;
}

void pila::show(){
    if(tope==NULL)
        cout<<"pila vacia";
    else
        for(nodo *tmp=tope;tmp!=NULL;tmp=tmp->sig)
            cout<<tmp->dato<<((tmp->sig)?", ":"");
    cout<<endl;
}

void pila::swap(){
    if(nnodos>=2){
        nodo *tmp=tope->sig;
        tope->sig=tmp->sig;
        tmp->sig=tope;
        tope=tmp;
    }
}

void pila::dup(){
    if(tope){
        push(top());
    }
}

void pila::pick(){
    if(tope){
        double pos=pop();
        if(nnodos>=pos+1){
            nodo *tmp = tope;
            for(int i=0;i<pos;i++)
                tmp=tmp->sig;
            push(tmp->dato);
        }
    }
}

void pila::dupn(){
    if(tope){
        double n = pop();
        if(n>nnodos)
            n=nnodos;
        for(int x=n;x>0;x--){
            push(n-1); pick();
        }          
    }
}
void pila::rollu(){
	double n = top();
    if((n+1)>=nnodos){
    	n=nnodos-2;
    	drop();push(n);
	}
	pick();
	nodo *tmp=tope;
	nodo *tmp2=tmp->sig;
	for (int i=0; i<n; i++){
		tmp=tmp2;
		tmp2=tmp2->sig;
	}
	tmp->sig=tmp2->sig;
	delete tmp2;
}

void pila::rolld(){
	double n = pop();
	if(n>=nnodos){
    	n=nnodos-1;
	}
	nodo *tmp=tope;
	nodo *tmp2=tmp;
	tope=tope->sig;
	for (int i=0; i<n; i++){
		tmp2=tmp2->sig;
	}
	tmp->sig=tmp2->sig;
	tmp2->sig=tmp;
}

void pila::dropn(){
	if(tope){
		double n = pop();
		if(n>nnodos)
            n=nnodos;
        for(;n>0;n--)
            drop();
    	}
}

void pila::depth(){
	push(nnodos);
}

void pila::clear(){
	depth();
	dropn();
}

void pila::add(){
	if(nnodos>=2){
		push(pop()+pop());
	}
}

void pila::sub(){
	if(nnodos>=2){
		swap();
		push(pop()-pop());
	}
}

void pila::mult(){
	if(nnodos>=2){
		push(pop()*pop());
	}
}

void pila::divi(){
	if(nnodos>=2){
		swap();
		push(pop()/pop());
	}
}

void pila::pot(){
	if(nnodos>=2){
		push(pow(pop(),pop()));
	}
}

void pila::duppila(){
	pila Pila2;
	if(tope==NULL)
        cout<<"pila vacia";
    else
        for(nodo *tmp=tope;tmp!=NULL;tmp=tmp->sig)
            Pila2.push(tmp->dato);
	Pila2.show();
}

int main() {
	pila Pila;
	Pila.push(2);
	Pila.push(4);
	Pila.push(6);
	Pila.push(8);
	Pila.push(10);
	Pila.show();
	
}
