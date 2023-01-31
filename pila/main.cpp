#include <iostream>
#include "metodos.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	pila Pila;
	Pila.push(2);
	Pila.push(4);
	Pila.push(6);
	Pila.push(7);
	Pila.push(8);
	Pila.push(4); Pila.rollu(); Pila.push(4); Pila.rollu();
	
	cout<<"\n";
	Pila.show();
}
