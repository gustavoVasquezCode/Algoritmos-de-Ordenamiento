#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Declaramos nuestros prototipos de funciones
void generar_numeros(int arreglo[], int numero_elementos);
void ordenar_numeros(int arreglo[], int numero_elementos);
void imprimir_numeros(int arreglo[], int numero_elementos);

int main(void) {
	int cantidad = 0;
	
	printf("Ingrese el numero de elementos del array: ");
	scanf("%d", &cantidad);
	int array[cantidad];
	
	generar_numeros(array, cantidad);
	printf("\nNumeros sin ordenar: \n");
	imprimir_numeros(array, cantidad);
	ordenar_numeros(array, cantidad);
	printf("\n\n\nNumeros ordenados: \n");
	imprimir_numeros(array, cantidad);
	
	printf("\n\n\n");
	system("pause > 0");
	return EXIT_SUCCESS;
}

void generar_numeros(int arreglo[], int numero_elementos) {
	int i;
	srand(time(NULL));
	for (i = 0; i < numero_elementos; i++) {
		arreglo[i] = 1 + rand() % (301 - 1);
	}
}

void ordenar_numeros(int arreglo[], int numero_elementos) {
	int i;
	int j;
	int auxiliar;
	for (i = 0; i < (numero_elementos - 1); i++) {
		for (j = 0; j < (numero_elementos - i - 1); j++) {
			if (arreglo[j] > arreglo[j + 1]) {
				auxiliar = arreglo[j];
				arreglo[j] = arreglo[j + 1];
				arreglo[j + 1] = auxiliar;
			}
		}
	}
}

void imprimir_numeros(int arreglo[], int numero_elementos) {
	int i;
	printf("[ ");
	for (i = 0; i < numero_elementos; i++) {
		if (i < numero_elementos - 1) {
			printf("%d, ", arreglo[i]);
		}
		else {
			printf("%d", arreglo[i]);
		}
	}
	printf(" ]");
}
