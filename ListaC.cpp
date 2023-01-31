#include <iostream>
#include <cmath>
using namespace std;

class listaC;
class nodo{
    private:
        int dato;
        nodo *sig;
        nodo();
friend listaC;
};

nodo::nodo(){
    dato=0;
    sig=NULL;
}

class listaC{
private:    
    nodo *act;
    int nnodos;
public:
    listaC();
    void insertar(int);
    void inpos(int,int);
    void buscar(int);
    void borrar();
    void show();
    int count(int);
    void inord(int);
    void clear();
    ~listaC();
};

listaC::listaC(){
    act=NULL;
    nnodos=0;
}

listaC::~listaC(){
	clear();
}

void listaC::insertar(int _dato){
    nodo *nuevo=new nodo;
    nuevo->dato=_dato;

if(!act){
    act=nuevo;
    nuevo->sig=nuevo;
}
else{
    nuevo->sig=act->sig;
    act->sig=nuevo;
    act=nuevo;
}
nnodos++;

}

int listaC::count(int _dato){
	int contador=0;
	nodo *tmp=act;
	for(int i=0; i<nnodos; i++){
		if(tmp->dato==_dato){
			contador=contador+1;
		}
		tmp=tmp->sig;
	}
	return contador;	
}

void listaC::buscar(int _dato){
	int pos=-1;
	nodo *tmp=act;
	for(int i=0; i<nnodos; i++){
		if(tmp->dato==_dato){
			break;
		}
		tmp=tmp->sig;
	}
	act=tmp;
}

void listaC::inord(int _dato){
	nodo *nuevo=new nodo;
    nuevo->dato=_dato;
	nodo *tmp=act;
	nodo *tmp2;
	
	for (int i = 0; i < nnodos - 1; i++){
		nodo *actual=act;
		nodo *siguiente=actual->sig;
		int tmp;
		for (int j = i + 1; j < nnodos; j++){
	   		if(actual->dato > siguiente->dato){
	      		tmp=actual->dato;
	       		actual->dato=siguiente->dato;
	       		siguiente->dato=tmp;
	   			actual=actual->sig;
    			siguiente=siguiente->sig;
	      	}
	      	else{
	   			actual=actual->sig;
	   			siguiente=siguiente->sig;	
			}
	    }
	}
	
	tmp=act;
	tmp2=tmp->sig;	
	
    if(act->dato>_dato){
   		nuevo->sig=act;
        act=nuevo;
	}else{
		for(int i=0; i<nnodos; i++){
			if(tmp->dato<=_dato){
				tmp2=tmp->sig;
				if(tmp2->dato<=_dato){
					tmp=tmp->sig;
				}
			}else{
				break;
			}
		}
		nuevo->sig=tmp->sig;
	    tmp->sig=nuevo;
	}
		
    nnodos++;
}

void listaC::borrar(){
    if(act){
        if(nnodos==1){
            delete act;
            act=NULL;
        }
        else{
                nodo *tmp=act;
                act=tmp->sig;
                delete tmp;
        }
		nnodos--;
    }
}

void listaC::clear(){
	while(nnodos>0){
		borrar();
	}
}

void listaC::show(){
    if(!act)
        cout<<"lista vacia";
    else
        for(int n=0;n<nnodos;n++){
            cout<<act->dato<<((n==nnodos-1)?"":",");
            act=act->sig;
        }

    cout<<endl;
}

void listaC::inpos(int _dato, int pos){
    if(pos<0){
    	int x=nnodos+pos;
    	for(;x>0;x--){
	    	act=act->sig;
		}
	}else{
		for(int x=(pos%nnodos)-1;x>0;x--){
	    	act=act->sig;
		}
	}
    insertar(_dato);
}

//---------------------------
int main(){
    listaC lc1;
    lc1.insertar(3);
    lc1.insertar(5);
    lc1.insertar(2);
    lc1.insertar(5);
    lc1.insertar(0);
    lc1.insertar(5);
    lc1.insertar(11);
    lc1.insertar(20);
    lc1.insertar(12);
    lc1.insertar(4);
    cout<<"\nContador: "<<lc1.count(5)<< "\n";
    lc1.inpos(15,-1);
    lc1.inord(-2);
    lc1.show();
    lc1.borrar();
    lc1.show();
    lc1.buscar(20);
    lc1.show();
    lc1.clear();
    lc1.show();
    //lc1.inpos(8,18);
    //lc1.show();
}
