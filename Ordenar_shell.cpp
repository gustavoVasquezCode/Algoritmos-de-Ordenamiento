#include <iostream>
#include <stdlib.h>
#include <time.h>

// prototitpos de funciones
void generar_numeros(int arreglo[], int numero_elementos);
void shell(int arreglo[], int numero_elementos);
void imprimir_numeros(int arreglo[], int numero_elementos);

int main(void) {
	int cantidad = 0;
	
	std::cout << "Ingrese el numero de elementos del array: ";
	std::cin >> cantidad;
	int array[cantidad];
	
	generar_numeros(array, cantidad);
	std::cout << "\nElementos sin ordenar: " << std::endl;
	imprimir_numeros(array, cantidad);
	shell(array, cantidad);
	std::cout << "\n\nElementos ordenado: " << std::endl;
	imprimir_numeros(array, cantidad);
	
	
	system("pause > NULL");
	return EXIT_SUCCESS;
}

void shell(int arreglo[], int numero_elementos) {
	int i;
	int j;
	int k;
	int salto = numero_elementos / 2;
	float auxiliar;
	while (salto > 0) { // ordenación de salto listas
		for (i = salto; i < numero_elementos; i++){
 			j = i - salto;
			while(j >= 0) {
 				k = j + salto;
 				if (arreglo[j] <= arreglo[k]) // elementos contiguos de la lista
 					j = -1;
 				else {
 					auxiliar = arreglo[j];
 					arreglo[j] = arreglo[k];
 					arreglo[k] = auxiliar;
 					j = j - salto;
 				}
 			}
 		}
		salto = salto / 2;
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
