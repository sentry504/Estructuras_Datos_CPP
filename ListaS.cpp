#include <iostream>
using namespace std;

class listaS;
class nodo{
    private:
        int dato;
        nodo *sig;
        nodo();
friend listaS;
};

nodo::nodo(){
    dato=0;
    sig=NULL;
}
//-------------------------------

class listaS{
    private:
        nodo *inic;
        nodo *ult;
        int nnodos;
    public:
        listaS();
		~listaS();
        void inlifo(int);
        void infifo(int);
        void inpos(int,int);
        void show();
        void borrar();
        void limpiar();
        void inord(int);
        int buscar(int);
        void unique();
};

listaS::listaS(){
    inic=ult=NULL;
    nnodos=0;
}

listaS::~listaS(){
	limpiar();
}

void listaS::unique()
{
	nodo *actual=inic;
		for (int i = 0; i < nnodos - 1; i++){
			int tmp=actual->dato;
			nodo *siguiente=actual->sig;
		    for (int j = i + 1; j < nnodos; j++){
	      		if(tmp!=siguiente->dato){
	      			actual=actual->sig;
	       			siguiente=siguiente->sig;
	      		}
	      		else{
	      			cout<< "dato: "<<actual->dato;
	      			if(siguiente->sig!=NULL){
	      				actual=siguiente;
	      				delete siguiente;
	      				siguiente=actual->sig;
					}else{
						delete siguiente;
						ult=actual;
					}
				}
			}
			actual=actual->sig;
		}	
}
void listaS::inlifo(int _dato){
    nodo *nuevo=new nodo;
    nuevo->dato=_dato;
    nuevo->sig=inic;
    inic=nuevo;
    if(ult==NULL)
        ult=nuevo;
    nnodos++;
}

void listaS::show(){
	if (inic==NULL)
		cout<<"lista vacia";
    for(nodo *tmp=inic;tmp!=NULL;tmp=tmp->sig)
        cout<<tmp->dato<<((tmp->sig)?",":"");
    cout<<endl;
}

void listaS::infifo(int _dato){
    nodo *nuevo=new nodo;
    nuevo->dato=_dato;
    if(inic==NULL){
        ult=inic=nuevo;
    }
    else{
        ult->sig=nuevo;
        ult=nuevo;
    }

    nnodos++;
}

void listaS::inpos(int pos, int _dato){
    nodo *nuevo=new nodo;
    nuevo->dato=_dato;
    if(pos==0){
        nuevo->sig=inic;
        inic=nuevo;
    }
    if(pos<0){
    	nodo *tmp=inic;
    	int posNew=nnodos+pos;
        for(;posNew>1;tmp=tmp->sig)
            posNew--;
        
        nuevo->sig=tmp->sig;
        tmp->sig=nuevo;
	}
    if((pos>0)&&(nnodos>=pos)){
        nodo *tmp=inic;
        for(;pos>1;tmp=tmp->sig)
            pos--;
        
        nuevo->sig=tmp->sig;
        tmp->sig=nuevo;
    }
    if(nnodos<pos){
        ult->sig=nuevo;
        ult=nuevo;
    }
}

void listaS::inord(int _dato){
	nodo *nuevo=new nodo;
    nuevo->dato=_dato;
	nodo *tmp=inic;
	nodo *tmp2;
	
	if(inic==NULL){
        ult=inic=nuevo;
    }
    else{
    	//Ordenamiento burbuja forma descendente, solamente cambiando el valor dato de los apuntadores
    	for (int i = 0; i < nnodos - 1; i++){
			nodo *actual=inic;
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
		
		tmp=inic;
		tmp2=tmp->sig;	
		
    	if(inic->dato>_dato){
    		nuevo->sig=inic;
        	inic=nuevo;
		}else{
			for(int i=0; i<nnodos; i++){
				if(tmp->dato<=_dato){
					if(tmp->sig!=NULL){
						tmp2=tmp->sig;
						if(tmp2->dato<=_dato){
							tmp=tmp->sig;
						}
					}
				}else{
					break;
				}
			}
			nuevo->sig=tmp->sig;
		    tmp->sig=nuevo;
		}
	}
    nnodos++;
}

void listaS::borrar(){
    if(inic!=NULL){
        if(nnodos==1){
            delete inic;
            inic=ult=NULL;
        }
        else{
                nodo *tmp=inic;
                inic=tmp->sig;
                delete tmp;
        }
		nnodos--;
    }
}

void listaS::limpiar(){
	while(nnodos>0){
		borrar();
	}
}

int listaS::buscar(int _dato){
	int pos=-1;
	nodo *tmp=inic;
	for(int i=0; i<nnodos; i++){
		if(tmp->dato==_dato){
			pos=i;
			break;
		}
		tmp=tmp->sig;
	}
	return pos;
}
//-------------------------------
int main(){
    listaS l1;
    l1.infifo(5);
    l1.infifo(3);
    l1.infifo(5);
    l1.show();
    l1.unique();
    l1.inord(-2);
    l1.inord(20);
    l1.inord(7);
    l1.show();
    l1.limpiar();
    l1.show();
   
}
