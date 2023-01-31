#include <iostream>
#include <sstream>
#include "arboln.h"
using namespace std;

nodoAN::nodoAN(){
	dato="";
	ruta="";
	izq=der=NULL;
}

arboln::arboln(){
	raiz=NULL;
	nnodos=0;
}

void arboln::agregar(string ruta,string folder){
	string lectura; 
	string cadena=ruta;
    stringstream input1(cadena); 
    int n=0;
    while (getline(input1, lectura, '/'))
    {
        n++;
    };
    stringstream input2(cadena); 
    string folders[n];
    n=0;
    while (getline(input2, lectura, '/'))
    {
        folders[n]=lectura;
        n++;
    };
    
   	_agregar(ruta,folder,folders,raiz,0,n);
}
void arboln::_agregar(string ruta,string folder,string folders[],nodoAN *&raiztmp,int i,int registro){
	if (!raiztmp){
		raiztmp= new nodoAN;
		raiztmp->ruta=ruta;
		raiztmp->dato=folder;
		nnodos++;
	}
	else{
		if(folders[0]=="C:"){
			if (folders[i]==raiztmp->dato){
				_agregar(ruta,folder,folders,raiztmp->izq, i+1,registro);
			}else{
				_agregar(ruta,folder,folders,raiztmp->der,i,registro);
			}
		}
	}
}

void arboln::preorden(){
	_preord(raiz);
}

void arboln::_preord(nodoAN *raiztmp){
	if (raiztmp){
		cout<< raiztmp->ruta<<raiztmp->dato<<"\n";
		if(raiztmp->der){
			_preord(raiztmp->der);
		}
		if(raiztmp->izq){
			_preord(raiztmp->izq);
		}
	}
}

void arboln::posorden(){
	_posord(raiz);
}

void arboln::_posord(nodoAN *raiztmp){
	if (raiztmp){
		if(raiztmp->der){
			_posord(raiztmp->der);
		}
		if(raiztmp->izq){
			_posord(raiztmp->izq);
		}
		cout<<raiztmp->ruta<<raiztmp->dato<<"\n";
	}
}

void arboln::mostrar(string dir){
	cout<<" Ruta '"<< dir<<"'\n";
	_mostrar(dir,raiz);
}

void arboln::_mostrar(string dir,nodoAN *raiztmp){
	if (raiztmp){
		if(dir==raiztmp->ruta.substr(0,dir.size())){
			cout<< raiztmp->ruta<<raiztmp->dato<<"\n";
		}
		if(raiztmp->der){
			_mostrar(dir,raiztmp->der);
		}
		if(raiztmp->izq){
			_mostrar(dir,raiztmp->izq);
		}
	}
}

void arboln::buscar(string dir){
	_buscar(dir,raiz,true);
}

void arboln::_buscar(string _dir, nodoAN *raiztmp,bool boleano){
	if (raiztmp){
		if(boleano && _dir==raiztmp->dato){
			cout<<" folder '"<< raiztmp->dato<<"'\n";
			cout<<" Encontrado en '"<< raiztmp->ruta<<raiztmp->dato<<"'\n";
			boleano=false;
		}
		if(raiztmp->der){
			_buscar(_dir,raiztmp->der,boleano);
		}
		if(raiztmp->izq){
			_buscar(_dir,raiztmp->izq,boleano);
		}
	}
}

void arboln::borrar(string dir){
	cout<<" registros de '"<< dir<<"'\n";
	_borrar(dir,raiz,raiz);
}
void arboln::_borrar(string _dir, nodoAN *temp, nodoAN *raiztmp){
	if(raiztmp){
		if(_dir==raiztmp->ruta.substr(0,_dir.size())){
			cout<< raiztmp->ruta<<raiztmp->dato <<"\n";
			if(raiztmp->der){
				temp->izq=raiztmp->der;
				delete raiztmp;
				raiztmp=temp;
			}else{
				temp->izq=raiztmp->izq;
				delete raiztmp;
				raiztmp=temp;
			}
		}
		if(raiztmp->der){
			_borrar(_dir,raiztmp,raiztmp->der);
		}
		if(raiztmp->izq){
			_borrar(_dir,raiztmp,raiztmp->izq);
		}
	}
}
