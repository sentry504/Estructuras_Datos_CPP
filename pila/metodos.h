#include "clases.h"
#include <math.h>

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
    pick();
    if(n>=nnodos){
    	n=nnodos-1;
	}
	nodo *tmp=tope;
	nodo *tmp2=tmp->sig;
	for (int i=0; i<n; i++){
		tmp=tmp2;
		tmp2=tmp2->sig;
	}
	cout<<nnodos;
	tmp->sig=tmp2->sig;
	delete tmp2;
}

void pila::rolld(){
	double n = top();
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
