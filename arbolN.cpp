#include <iostream>
using namespace std;
 
class arboln;

class nodoAB{
	private:
		int dato;
		nodoAB *izq, *der;
		nodoAB();
		friend class arboln;
};

class arboln{
	nodoAB *raiz;
	int nnodos;
	void _agregar(int, nodoAB* &);
	void _preord(nodoAB *);
	void _posord(nodoAB *);
	int _altura(nodoAB *);
	void _mostrarnivel(int, nodoAB *);
	public:
		arboln();
		void agregar(int);
		void preorden();
		void posorden();
		int altura();
		void mostrarnivel(int);
		void mostrarniveles();
};

nodoAB:: nodoAB(){
	dato=0;
	izq=der=NULL;
}

arboln::arboln(){
	raiz=NULL;
	nnodos=0;
}

void arboln::agregar(int _dato){
	_insert(_dato,raiz);
}

//Modificar
void arboln::_insert(int _dato,nodoAB *&raiztmp){
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

void arboln::preorden(){
	_preord(raiz);
}

void arboln::_preord(nodoAB *raiztmp){
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

void arboln::posorden(){
	_posord(raiz);
}

void arboln::_posord(nodoAB *raiztmp){
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

int arboln::altura(){
	return _altura(raiz);
}

int arboln::_altura(nodoAB *raiztmp){
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

void arboln::mostrarnivel(int n){
	_mostrarnivel(n, raiz);
}

void arboln::_mostrarnivel(int _nivel, nodoAB *raiztmp){	
	if(raiztmp){
		if(_nivel==0){
			cout<< raiztmp->dato << ((raiztmp->izq||raiztmp->der)?"--":" ");
		}
		_mostrarnivel(_nivel-1, raiztmp->izq);
		_mostrarnivel(_nivel-1, raiztmp->der);
	}
}

void arboln::mostrarniveles(){
	for (int i=0; i<altura();i++){
		cout << "Nivel "<< i << ": "; mostrarnivel(i); cout <<"\n";
	}
}
int main(){
	arboln a1;
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
	cout << "\n\nPreOrden:\n";
	a1.preorden();
	cout << "\n\nPosOrden:\n";
	a1.posorden();
	cout << "\n\nAltura: " << a1.altura();
	cout << "\n\nNodos nivel 2: "; a1.mostrarnivel(2);
	cout <<"\n\n";
	a1.mostrarniveles();
	return 0;
}
































