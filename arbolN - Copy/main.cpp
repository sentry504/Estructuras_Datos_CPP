#include <iostream>
#include "arboln.h"
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	arboln a1;
	a1.agregar("","C:");
	a1.agregar("C:/","users");
	a1.agregar("C:/users/","Carlos");
	a1.agregar("C:/users/Carlos/","archivos");
	a1.agregar("C:/","documentos");
	a1.agregar("C:/","imagenes");
	a1.agregar("C:/users/","Angel");
	a1.agregar("C:/documentos/","doc1");
	a1.agregar("C:/imagenes/","img1");
	a1.agregar("C:/users/","Adriana");
	a1.agregar("k:/imagenes/","img4");
	a1.agregar("C:/users/Adriana/","archivos");
	a1.agregar("C:/users/Adriana/archivos/","archivo1");
	a1.agregar("C:/imagenes/","img2");
	a1.agregar("C:/imagenes/","img4");
	a1.agregar("C:/imagenes/","img3");
	a1.agregar("C:/documentos/","doc2");
	a1.agregar("C:/documentos/doc2/","A");
	
	cout << "\n--preorden:\n";
	a1.preorden();
	
	cout << "\n--Buscar";
	a1.buscar("Adriana");
	
	cout << "\n--Mostrar";
	a1.mostrar("C:/users");
	
	cout << "\n--Borrar";
	a1.borrar("C:/documentos/");
	
	cout << "\n--preorden:\n";
	a1.preorden();
	
	cout << "\n--posorden:\n";
	a1.posorden();
	return 0;
}
