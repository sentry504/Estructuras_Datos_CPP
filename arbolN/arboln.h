#include <iostream>
using namespace std;
 
class arboln;

class nodoAN{
	private:
		string dato;
		string ruta;
		int nhijos;
		nodoAN *izq, *der;
		nodoAN();
		friend class arboln;
};

class arboln{
	nodoAN *raiz;
	int nnodos;
	void _agregar(string,string,string[], nodoAN* &, int, int);
	void _preord(nodoAN *,int);
	void _buscar(string, nodoAN *, int);
	void _borrar(string, nodoAN *, nodoAN *, int);
	void _posord(nodoAN *, int);
	public:
		arboln();
		void agregar(string,string);
		void preorden();
		void buscar(string);
		void borrar(string);
		void posorden();
};
