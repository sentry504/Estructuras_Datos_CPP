#include <iostream>
using namespace std;

class listaD;
class nodoD{
    private:
        int dato;
        nodoD *sig;
        nodoD *ant;
        nodoD();
friend listaD;
};

nodoD::nodoD(){
    dato=0;
    ant=sig=NULL;
}
//-------------------------------

class listaD{
    private:
        nodoD *inic;
        nodoD *ult;
        int nnodos;
    public:
        listaD();
        ~listaD();
        void inlifo(int);
        void infifo(int);
        void inpos(int,int);
        void show();
        void showr();
        void borrar();
        void limpiar();
        void inord(int);
        int buscar(int);
};

listaD::listaD(){
    inic=ult=NULL;
    nnodos=0;
}

listaD::~listaD(){
	limpiar();
}

void listaD::inlifo(int _dato){
    nodoD *nuevo=new nodoD;
    nuevo->dato=_dato;
    nuevo->sig=inic;
    inic=nuevo;
    if(ult==NULL)
        ult=nuevo;
    if(nnodos>0)
        nuevo->sig->ant=nuevo;

    nnodos++;
}

void listaD::infifo(int _dato){
    nodoD *nuevo=new nodoD;
    nuevo->dato=_dato;
    if(inic==NULL){
        ult=inic=nuevo;
    }
    else{
    	ult->sig=nuevo;
    	nuevo->ant=ult;
        ult=nuevo;
    }

    nnodos++;
}

void listaD::inpos(int pos, int _dato){
    nodoD *nuevo=new nodoD;
    nuevo->dato=_dato;
    if(pos==0){
        nuevo->sig=inic;
        inic=nuevo;
    }
    if(pos<0){
    	nodoD *tmp=ult;
        for(;pos<0;tmp=tmp->ant)
            pos++;
        
        nuevo->sig=tmp->sig;
        tmp->sig->ant=nuevo;
        nuevo->ant=tmp;
        tmp->sig=nuevo;
	}
    if((pos>0)&&(nnodos>=pos)){
        nodoD *tmp=inic;
        for(;pos>1;tmp=tmp->sig)
            pos--;
        
        nuevo->sig=tmp->sig;
        tmp->sig->ant=nuevo;
        nuevo->ant=tmp;
        tmp->sig=nuevo;
    }
    if(nnodos<pos){
		ult->sig=nuevo;
		nuevo->ant=ult;
        ult=nuevo;
    }
}

void listaD::inord(int _dato){
	nodoD *nuevo=new nodoD;
    nuevo->dato=_dato;
    nodoD *tmp=inic;
    nodoD *tmp2;
	
	if(inic==NULL){
        ult=inic=nuevo;
    }
    else{
    	//Corregirlo para que se cambie el nodo y no el dato
    	//Ordenamiento burbuja forma descendente, solamente cambiando el valor dato de los apuntadores
    	for (int i = 0; i < nnodos - 1; i++){
			nodoD *actual=inic;
			nodoD *siguiente=actual->sig;
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
		
		//Fase de insercion del nodo en la posicion correspondiente
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
			if(!tmp->sig){
				ult->sig=nuevo;
    			nuevo->ant=ult;
        		ult=nuevo;
			}else{
				nuevo->sig=tmp->sig;
	        	tmp->sig->ant=nuevo;
	    	    nuevo->ant=tmp;
	        	tmp->sig=nuevo;
			}
		}
	}
    nnodos++;
}

void listaD::borrar(){
    if(inic!=NULL){
        if(nnodos==1){
            delete inic;
            inic=ult=NULL;
        }
        else{
                nodoD *tmp=inic;
                inic=tmp->sig;
                inic->ant=NULL;
                delete tmp;
        }
		nnodos--;
    }
}

void listaD::limpiar(){
	while(nnodos>0){
		borrar();
	}
}

int listaD::buscar(int _dato){
	int pos=-1;
	nodoD *tmp=inic;
	for(int i=0; i<nnodos; i++){
		if(tmp->dato==_dato){
			pos=i;
			break;
		}
		tmp=tmp->sig;
	}
	return pos;
}

void listaD::show(){
    if(inic==NULL)
        cout<<"lista vacia";
    else
        for(nodoD *tmp=inic;tmp!=NULL;tmp=tmp->sig)
            cout<<tmp->dato<<((tmp->sig)?",":"");
    cout<<endl;
}

void listaD::showr(){
    if(inic==NULL)
        cout<<"lista vacia";
    else
        for(nodoD *tmp=ult;tmp!=NULL;tmp=tmp->ant)
            cout<<tmp->dato<<((tmp->ant)?",":"");
    cout<<endl;
}

//---------------------------------

int main(){
    listaD ld1;
    ld1.infifo(5);
	ld1.infifo(3);
    ld1.infifo(8);
    ld1.infifo(9);
    ld1.show();
    ld1.inord(7);
    ld1.show();
    return 0;
}
