#include <iostream>
#include "listadoble.h"

using namespace std;

int main( ) {
	listadoble<int> enteros;
	
	enteros.pushfront(1);
	enteros.pushfront(2);
	enteros.pushfront(3);
	
	enteros << 4 << 5 << 6;

    int *ptr_01 = enteros.find(0);
    if (ptr_01 == nullptr) {
        enteros << 0;
    }

    cout << "Tamaño: " << enteros.size() << endl << endl << "Lista:" << endl;

    enteros.print();      
	
}
