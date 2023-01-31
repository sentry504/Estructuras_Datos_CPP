#include <iostream>
using namespace std;
 
class arbolb;

class nodoAB{
	private:
		int dato;
		nodoAB *izq, *der;
		nodoAB();
		friend class arbolb;
};

class arbolb{
	nodoAB *raiz;
	int nnodos;
	void _insert(int, nodoAB* &);
	void _enord(nodoAB *);
	void _preord(nodoAB *);
	void _posord(nodoAB *);
	int _altura(nodoAB *);
	void _mostrarnivel(int, nodoAB *);
	int _mostrarhojas(int,int, nodoAB *);
	public:
		arbolb();
		void insertar(int);
		void enorden();
		void preorden();
		void posorden();
		int altura();
		void mostrarnivel(int);
		void mostrarniveles();
		void mostrarhojas();
};

nodoAB:: nodoAB(){
	dato=0;
	izq=der=NULL;
}

arbolb::arbolb(){
	raiz=NULL;
	nnodos=0;
}

void arbolb::insertar(int _dato){
	_insert(_dato,raiz);
}

void arbolb::_insert(int _dato,nodoAB *&raiztmp){
	if (!raiztmp){//raiztmp==NULL
		raiztmp= new nodoAB;
		raiztmp->dato=_dato;
		nnodos++;
	}
	else{
		if (_dato<raiztmp->dato){
			_insert(_dato,raiztmp->izq);
		}else{
			_insert(_dato,raiztmp->der);
		}
	}
}

void arbolb::enorden(){
	_enord(raiz);
}

void arbolb::_enord(nodoAB *raiztmp){
	if (raiztmp){
		if(raiztmp->izq){
			_enord(raiztmp->izq);
		}
		cout << raiztmp->dato << " ";
		
		if(raiztmp->der){
			_enord(raiztmp->der);
		}
	}
}

void arbolb::preorden(){
	_preord(raiz);
}

void arbolb::_preord(nodoAB *raiztmp){
	if (raiztmp){
		cout << raiztmp->dato << " ";
		
		if(raiztmp->izq){
			_preord(raiztmp->izq);
		}
		
		if(raiztmp->der){
			_preord(raiztmp->der);
		}
	}
}

void arbolb::posorden(){
	_posord(raiz);
}

void arbolb::_posord(nodoAB *raiztmp){
	if (raiztmp){
		if(raiztmp->izq){
			_posord(raiztmp->izq);
		}
		
		if(raiztmp->der){
			_posord(raiztmp->der);
		}
		cout << raiztmp->dato << " ";
	}
}

int arbolb::altura(){
	return _altura(raiz);
}

int arbolb::_altura(nodoAB *raiztmp){
	int altizq, altder;
	if (raiztmp){
		altizq=_altura(raiztmp->izq);
		altder=_altura(raiztmp->der);
		if(altizq>altder){
			return(altizq+1);
		}else{
			return(altder+1);
		}
	}else{
		return(0);
	}
}

void arbolb::mostrarnivel(int n){
	_mostrarnivel(n, raiz);
}

void arbolb::_mostrarnivel(int _nivel, nodoAB *raiztmp){	
	if(raiztmp){
		if(_nivel==0){
			cout<< raiztmp->dato << " ";
		}
		_mostrarnivel(_nivel-1, raiztmp->izq);
		_mostrarnivel(_nivel-1, raiztmp->der);
	}
}

void arbolb::mostrarniveles(){
	for (int i=0; i<altura();i++){
		cout << "Nivel "<< i << ": "; mostrarnivel(i); cout <<"\n";
	}
}

int arbolb::_mostrarhojas(int _nivel,int n, nodoAB *raiztmp){	
	if(raiztmp){
		if(_nivel==0){
			if(!raiztmp->izq){
				 return n++;
			}
		}
		_mostrarhojas(_nivel-1,n, raiztmp->izq);
		_mostrarhojas(_nivel-1,n, raiztmp->der);
	}
}

void arbolb::mostrarhojas(){
	for (int i=0; i<altura();i++){
		cout << "Hojas en el nivel "<< i << ": "<<_mostrarhojas(i,0,raiz); cout <<"\n";
	}
}
int main(){
	arbolb a1;
	a1.insertar(10);
	a1.insertar(5);
	a1.insertar(8);
	a1.insertar(12);
	a1.insertar(15);
	a1.insertar(10);
	a1.insertar(7);
	a1.insertar(2);
	a1.insertar(4);
	a1.insertar(14);
	cout << "Orden:\n";
	a1.enorden();
	cout << "\n\nPreOrden:\n";
	a1.preorden();
	cout << "\n\nPosOrden:\n";
	a1.posorden();
	cout << "\n\nAltura: " << a1.altura();
	cout << "\n\nNodos nivel 2: "; a1.mostrarnivel(2);
	cout <<"\n\n";
	a1.mostrarniveles();
	a1.mostrarhojas();
	return 0;
}
































