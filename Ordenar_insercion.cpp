#include <iostream>
#include <stdlib.h>
#include <time.h>

// prototitpos de funciones
void generar_numeros(int arreglo[], int numero_elementos);
void insersion(int arreglo[], int numero_elementos);
void imprimir_numeros(int arreglo[], int numero_elementos);

int main(void) {
	int cantidad = 0;
	
	std::cout << "Ingrese el numero de elementos del array: ";
	std::cin >> cantidad;
	int array[cantidad];
	
	generar_numeros(array, cantidad);
	std::cout << "\nElementos sin ordenar: " << std::endl;
	imprimir_numeros(array, cantidad);
	insersion(array, cantidad);
	std::cout << "\n\nElementos ordenado: " << std::endl;
	imprimir_numeros(array, cantidad);
	
	
	system("pause > NULL");
	return EXIT_SUCCESS;
}


void insersion(int arreglo[], int numero_elementos) {
	int i,j;
 	bool encontrado;
 	float auxiliar;
 	for (i = 1; i < numero_elementos; i++) {
 		auxiliar = arreglo[i];
 		j = i - 1;
 		encontrado = false;
		while (( j >= 0 ) && ! encontrado)
			if (arreglo[j] > auxiliar) { // se mueve dato hacia la derecha para la insercion
 				arreglo[j + 1] = arreglo[j];
 				j--;
 			}
			else
 				encontrado = true;
 			arreglo[j + 1] = auxiliar;
 	}
}


void generar_numeros(int arreglo[], int numero_elementos) {
	int i;
	srand(time(NULL));
	for(i = 0; i < numero_elementos; i++) {
		arreglo[i] =  1 + rand() % (101 - 1);
	}
}

void imprimir_numeros(int arreglo[], int numero_elementos) {
	int i;
	std::cout << "[ ";
	for (i = 0; i < numero_elementos; i++) {
		if (i < numero_elementos - 1) {
			std::cout << arreglo[i] << ", ";
		}
		else {
			std::cout << arreglo[i];
		}
	}
	std::cout << " ]" << std::endl;
}
