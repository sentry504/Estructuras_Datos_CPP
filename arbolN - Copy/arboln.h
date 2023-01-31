#include <iostream>
using namespace std;
 
class arboln;

class nodoAN{
	private:
		string dato;
		string ruta;
		nodoAN *izq, *der;
		nodoAN();
		friend class arboln;
};

class arboln{
	nodoAN *raiz;
	int nnodos;
	void _agregar(string,string,string[], nodoAN* &, int, int);
	void _mostrar(string,nodoAN *);
	void _preord(nodoAN *);
	void _posord(nodoAN *);
	void _buscar(string, nodoAN *,bool);
	void _borrar(string, nodoAN *, nodoAN *);
	public:
		arboln();
		void agregar(string,string);
		void preorden();
		void mostrar(string);
		void posorden();
		void buscar(string);
		void borrar(string);
};
