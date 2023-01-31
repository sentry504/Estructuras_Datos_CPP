#include <iostream>
#include <sstream>
#include "arboln.h"
using namespace std;

nodoAN::nodoAN(){
	dato="";
	ruta="";
	nhijos=0;
	izq=der=NULL;
}

arboln::arboln(){
	raiz=NULL;
	nnodos=0;
}

void arboln::agregar(string _dir,string _folder){
	string lectura; 
	string cadena=_dir;
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
    
   	_agregar(_dir,_folder,folders,raiz,0,n);
}
void arboln::_agregar(string _dir,string _folder,string _folders[],nodoAN *&raiztmp,int i,int registro){
	if (!raiztmp){
		raiztmp= new nodoAN;
		raiztmp->ruta=_dir;
		raiztmp->dato=_folder;
		raiztmp->nhijos++;
		nnodos++;
	}
	else{
		if(_folders[0]=="C:"){
			if (_folders[i]==raiztmp->dato){
				_agregar(_dir,_folder,_folders,raiztmp->izq, i+1,registro);
			}else{
				_agregar(_dir,_folder,_folders,raiztmp->der,i,registro);
			}
		}else{
			cout<<"Proyecto estructura datos error: Ruta de acceso no permitida!\n";
		}
	}
}

void arboln::preorden(){
	_preord(raiz,0);
}

void arboln::_preord(nodoAN *raiztmp,int n){
	if (raiztmp){
		cout<<n<<"|"<< raiztmp->ruta<<raiztmp->dato<<"\n";
		if(raiztmp->der){
			cout<<", der";
			_preord(raiztmp->der,n+1);
		}
		if(raiztmp->izq){
			cout<<", izq";
			_preord(raiztmp->izq,n+1);
		}
	}
}

void arboln::posorden(){
	_posord(raiz,0);
}

void arboln::_posord(nodoAN *raiztmp, int n){
	if (raiztmp){
		if(raiztmp->der){
			cout<<"der, ";
			_posord(raiztmp->der,n+1);
		}
		if(raiztmp->izq){
			cout<<"izq, ";
			_posord(raiztmp->izq,n+1);
		}
		cout<<n<<"|"<<raiztmp->ruta<<raiztmp->dato<<"\n";
	}
}

void arboln::buscar(string dir){
	cout << "\n--Buscar: "<<dir<<"\n";
	_buscar(dir,raiz,0);
}

void arboln::_buscar(string _dir, nodoAN *raiztmp,int n){
	if (raiztmp){
		if(_dir==raiztmp->ruta.substr(0,_dir.size())){
			cout<<n<<"|"<< raiztmp->ruta<<raiztmp->dato <<"\n";
		}
		if(raiztmp->der){
			_buscar(_dir,raiztmp->der,n+1);
		}
		if(raiztmp->izq){
			_buscar(_dir,raiztmp->izq,n+1);
		}
	}
}

void arboln::borrar(string dir){
	cout << "\n--Nodos a eliminar de: "<<dir<<"\n";
	_borrar(dir,raiz,raiz,0);
}
void arboln::_borrar(string _dir, nodoAN *temp, nodoAN *raiztmp,int n){
	if(raiztmp){
		if(_dir==raiztmp->ruta.substr(0,_dir.size())){
			cout<<n<<"|raiztmp--"<< raiztmp->ruta<<raiztmp->dato <<"\n";
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
			_borrar(_dir,raiztmp,raiztmp->der,n+1);
		}
		if(raiztmp->izq){
			_borrar(_dir,raiztmp,raiztmp->izq,n+1);
		}
	}
}
