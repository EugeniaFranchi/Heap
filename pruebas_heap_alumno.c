#include "heap.h"
#include "testing.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char* valor1= "a";
char* valor2= "b";
char* valor3= "c";
char* valor4= "d";
char* valor5= "e";
void* arreglo1[5] = {"e","d","c","b","a"};
void* arreglo2[5] = {"a","e","c","b","d"};
void* arreglo3[11] = {"f","e","g","a","h","c","i","b","j","k","d"};
void* arreglo4[5] = {"e","a","c","b","d"};

int comparar_strings(const void *dato1, const void *dato2){
	char* string1 = (char*) dato1;
	char* string2 = (char*) dato2;
	return strcmp(string1, string2);
}

int comparar_numeros(const void *dato1, const void *dato2){
	int* int1 = (int*) dato1;
	int* int2 = (int*) dato2;
	return *int1 - *int2;
}

void pruebas_heap_vacio(){
	heap_t* heap = heap_crear(comparar_strings);
	print_test("Creo un heap", heap);
	print_test("Tiene 0 elementos", heap_cantidad(heap) == 0);
	print_test("Esta vacio", heap_esta_vacio(heap) == true);
	print_test("No se puede desencolar", heap_desencolar(heap) == NULL);
	heap_destruir(heap, NULL);
	print_test("Destruyo el heap", true);
}

void pruebas_heap_crear_arreglo(){
	/*Con arreglo vacio*/
	heap_t* heap = heap_crear_arr(arreglo1, 0, comparar_strings);
	print_test("Creo un heap desde arreglo", heap);
	print_test("Tiene 0 elementos", heap_cantidad(heap) == 0);
	print_test("Esta vacio", heap_esta_vacio(heap) == true);
	heap_destruir(heap, NULL);
	print_test("Destruyo el heap", true);
	
	/*Con arreglo de elementos ordenados*/
	heap = heap_crear_arr(arreglo1, 5, comparar_strings);
	print_test("Creo un heap desde arreglo", heap);
	print_test("Tiene 5 elementos", heap_cantidad(heap) == 5);
	print_test("No esta vacio", heap_esta_vacio(heap) == false);
	heap_destruir(heap, NULL);
	print_test("Destruyo el heap", true);
	
	/*Con arreglo de elementos desordenados*/
	heap = heap_crear_arr(arreglo1, 5, comparar_strings);
	print_test("Creo un heap desde arreglo", heap);
	print_test("Tiene 5 elementos", heap_cantidad(heap) == 5);
	print_test("No esta vacio", heap_esta_vacio(heap) == false);
	heap_destruir(heap, NULL);
	print_test("Destruyo el heap", true);
}

void pruebas_heap_arr_desencolar(){
	/*Con arreglo vacio*/
	heap_t* heap = heap_crear_arr(arreglo1, 0, comparar_strings);
	print_test("No se puede desencolar", heap_desencolar(heap) == NULL);
	heap_destruir(heap, NULL);
	
	/*Con arreglo de elementos ordenados*/
	heap = heap_crear_arr(arreglo1, 5, comparar_strings);
	print_test("Desencolo valor5",heap_desencolar(heap) == valor5);
	print_test("Tiene 4 elementos",heap_cantidad(heap) == 4);
	print_test("Desencolo valor4",heap_desencolar(heap) == valor4);
	print_test("Tiene 3 elementos",heap_cantidad(heap) == 3);
	print_test("Desencolo valor3",heap_desencolar(heap) == valor3);
	print_test("Tiene 2 elementos",heap_cantidad(heap) == 2);
	print_test("Desencolo valor2",heap_desencolar(heap) == valor2);
	print_test("Tiene 1 elemento",heap_cantidad(heap) == 1);
	print_test("Desencolo valor1",heap_desencolar(heap) == valor1);
	print_test("No puedo desencolar",heap_desencolar(heap) == NULL);
	print_test("Tiene 0 elementos",heap_cantidad(heap) == 0);
	heap_destruir(heap, NULL);
	
	/*Con arreglo de elementos desordenados*/
	heap = heap_crear_arr(arreglo2, 5, comparar_strings);
	print_test("Desencolo valor5",heap_desencolar(heap) == valor5);
	print_test("Tiene 4 elementos",heap_cantidad(heap) == 4);
	print_test("Desencolo valor4",heap_desencolar(heap) == valor4);
	print_test("Tiene 3 elementos",heap_cantidad(heap) == 3);
	print_test("Desencolo valor3",heap_desencolar(heap) == valor3);
	print_test("Tiene 2 elementos",heap_cantidad(heap) == 2);
	print_test("Desencolo valor2",heap_desencolar(heap) == valor2);
	print_test("Tiene 1 elemento",heap_cantidad(heap) == 1);
	print_test("Desencolo valor1",heap_desencolar(heap) == valor1);
	print_test("No puedo desencolar",heap_desencolar(heap) == NULL);
	print_test("Tiene 0 elementos",heap_cantidad(heap) == 0);
	heap_destruir(heap, NULL);
}

void pruebas_heap_encolar_cantidad(){

	char* puntero1;
	char* puntero2;
	char* puntero3;
	char* puntero4;
	char* puntero5;
	char* puntero6;
	char* puntero7;
	char* puntero8;
	char* puntero9;
	char* puntero10;
	
	puntero1 = "a";
	puntero2 = "b";
	puntero3 = "c";
	puntero4 = "d";
	puntero5 = "e";
	puntero6 = "f";
	puntero7 = "g";
	puntero8 = "h";
	puntero9 = "i";
	puntero10= "j";
	
	
	/*Un elemento*/
	heap_t* heap = heap_crear(comparar_strings);
	print_test("Encolo valor1",heap_encolar(heap, valor1));
	print_test("Tiene 1 elemento",heap_cantidad(heap) == 1);
	heap_destruir(heap, NULL);

	/*Varios elementos ordenados y repetido*/
	heap = heap_crear(comparar_strings);
	print_test("Encolo valor1",heap_encolar(heap, puntero1));
	print_test("Tiene 1 elemento",heap_cantidad(heap) == 1);
	print_test("Encolo valor2",heap_encolar(heap, puntero2));
	print_test("Tiene 2 elementos",heap_cantidad(heap) == 2);
	print_test("Encolo valor3",heap_encolar(heap, puntero3));
	print_test("Tiene 3 elementos",heap_cantidad(heap) == 3);
	print_test("Encolo valor4",heap_encolar(heap, puntero4));
	print_test("Tiene 4 elementos",heap_cantidad(heap) == 4);
	print_test("Encolo valor5",heap_encolar(heap, puntero5));
	print_test("Tiene 5 elementos",heap_cantidad(heap) == 5);
	print_test("Encolo valor6",heap_encolar(heap, puntero6));
	print_test("Tiene 6 elementos",heap_cantidad(heap) == 6);
	print_test("Encolo valor7",heap_encolar(heap, puntero7));
	print_test("Tiene 7 elementos",heap_cantidad(heap) == 7);
	print_test("Encolo valor8",heap_encolar(heap, puntero8));
	print_test("Tiene 8 elementos",heap_cantidad(heap) == 8);
	print_test("Encolo valor9",heap_encolar(heap, puntero9));
	print_test("Tiene 9 elementos",heap_cantidad(heap) == 9);
	print_test("Encolo valor10",heap_encolar(heap, puntero10));
	print_test("Tiene 10 elementos",heap_cantidad(heap) == 10);
	heap_destruir(heap, NULL);

	printf("\n");

	/*Varios elementos desordenados*/
	heap = heap_crear(comparar_strings);
	print_test("Encolo valor5",heap_encolar(heap, valor5));
	print_test("Tiene 1 elemento",heap_cantidad(heap) == 1);
	print_test("Encolo valor2",heap_encolar(heap, valor2));
	print_test("Tiene 2 elementos",heap_cantidad(heap) == 2);
	print_test("Encolo valor1",heap_encolar(heap, valor1));
	print_test("Tiene 3 elementos",heap_cantidad(heap) == 3);
	print_test("Encolo valor4",heap_encolar(heap, valor4));
	print_test("Tiene 4 elementos",heap_cantidad(heap) == 4);
	print_test("Encolo valor3",heap_encolar(heap, valor3));
	print_test("Tiene 5 elementos",heap_cantidad(heap) == 5);
	heap_destruir(heap, NULL);
}

void pruebas_heap_desencolar_cantidad(){
	/*Un elemento*/
	heap_t* heap = heap_crear(comparar_strings);
	print_test("Encolo valor1",heap_encolar(heap, valor1));
	print_test("Desencolo valor1",heap_desencolar(heap) == valor1);
	print_test("No puedo desencolar",heap_desencolar(heap) == NULL);
	print_test("Tiene 0 elementos",heap_cantidad(heap) == 0);
	heap_destruir(heap, NULL);
	
	/*Varios elementos ordenados y repetido*/
	heap = heap_crear(comparar_strings);
	print_test("Encolo valor1",heap_encolar(heap, valor1));
	print_test("Encolo valor2",heap_encolar(heap, valor2));
	print_test("Encolo valor3",heap_encolar(heap, valor3));
	print_test("Encolo valor1",heap_encolar(heap, valor1));
	print_test("Encolo valor4",heap_encolar(heap, valor4));
	print_test("Encolo valor5",heap_encolar(heap, valor5));
	print_test("Tiene 6 elementos",heap_cantidad(heap) == 6);
	print_test("Desencolo valor5",heap_desencolar(heap) == valor5);
	print_test("Tiene 5 elementos",heap_cantidad(heap) == 5);
	print_test("Desencolo valor4",heap_desencolar(heap) == valor4);
	print_test("Tiene 4 elementos",heap_cantidad(heap) == 4);
	print_test("Desencolo valor3",heap_desencolar(heap) == valor3);
	print_test("Tiene 3 elementos",heap_cantidad(heap) == 3);
	print_test("Desencolo valor2",heap_desencolar(heap) == valor2);
	print_test("Tiene 2 elemento",heap_cantidad(heap) == 2);
	print_test("Desencolo valor1",heap_desencolar(heap) == valor1);
	print_test("Tiene 1 elemento",heap_cantidad(heap) == 1);
	print_test("Desencolo valor1",heap_desencolar(heap) == valor1);
	print_test("No puedo desencolar",heap_desencolar(heap) == NULL);
	print_test("Tiene 0 elementos",heap_cantidad(heap) == 0);
	heap_destruir(heap, NULL);
	
	/*Varios elementos desordenados*/
	heap = heap_crear(comparar_strings);
	print_test("Encolo valor5",heap_encolar(heap, valor5));
	print_test("Encolo valor2",heap_encolar(heap, valor2));
	print_test("Encolo valor1",heap_encolar(heap, valor1));
	print_test("Encolo valor4",heap_encolar(heap, valor4));
	print_test("Encolo valor3",heap_encolar(heap, valor3));
	print_test("Tiene 5 elementos",heap_cantidad(heap) == 5);
	print_test("Desencolo valor5",heap_desencolar(heap) == valor5);
	print_test("Tiene 4 elementos",heap_cantidad(heap) == 4);
	print_test("Desencolo valor4",heap_desencolar(heap) == valor4);
	print_test("Tiene 3 elementos",heap_cantidad(heap) == 3);
	print_test("Desencolo valor3",heap_desencolar(heap) == valor3);
	print_test("Tiene 2 elementos",heap_cantidad(heap) == 2);
	print_test("Desencolo valor2",heap_desencolar(heap) == valor2);
	print_test("Tiene 1 elemento",heap_cantidad(heap) == 1);
	print_test("Desencolo valor1",heap_desencolar(heap) == valor1);
	print_test("No puedo desencolar",heap_desencolar(heap) == NULL);
	print_test("Tiene 0 elementos",heap_cantidad(heap) == 0);
	heap_destruir(heap, NULL);
}

void pruebas_heap_esta_vacio(){
	/*Un elemento*/
	heap_t* heap = heap_crear(comparar_strings);
	print_test("Encolo valor1",heap_encolar(heap, valor1));
	print_test("No esta vacio",heap_esta_vacio(heap) == false);
	print_test("Desencolo valor1",heap_desencolar(heap) == valor1);
	print_test("Esta vacio",heap_esta_vacio(heap) == true);
	heap_destruir(heap, NULL);
	
	/*Varios elementos ordenados*/
	heap = heap_crear(comparar_strings);
	print_test("Encolo valor1",heap_encolar(heap, valor1));
	print_test("Encolo valor2",heap_encolar(heap, valor2));
	print_test("Encolo valor3",heap_encolar(heap, valor3));
	print_test("Encolo valor4",heap_encolar(heap, valor4));
	print_test("Encolo valor5",heap_encolar(heap, valor5));
	print_test("No esta vacio",heap_esta_vacio(heap) == false);
	print_test("Desencolo valor5",heap_desencolar(heap) == valor5);
	print_test("No esta vacio",heap_esta_vacio(heap) == false);
	print_test("Desencolo valor4",heap_desencolar(heap) == valor4);
	print_test("No esta vacio",heap_esta_vacio(heap) == false);
	print_test("Desencolo valor3",heap_desencolar(heap) == valor3);
	print_test("No esta vacio",heap_esta_vacio(heap) == false);
	print_test("Desencolo valor2",heap_desencolar(heap) == valor2);
	print_test("No esta vacio",heap_esta_vacio(heap) == false);
	print_test("Desencolo valor1",heap_desencolar(heap) == valor1);
	print_test("Esta vacio",heap_esta_vacio(heap) == true);
	heap_destruir(heap, NULL);
	
	/*Varios elementos desordenados*/
	heap = heap_crear(comparar_strings);
	print_test("Encolo valor5",heap_encolar(heap, valor5));
	print_test("Encolo valor2",heap_encolar(heap, valor2));
	print_test("Encolo valor1",heap_encolar(heap, valor1));
	print_test("Encolo valor4",heap_encolar(heap, valor4));
	print_test("Encolo valor3",heap_encolar(heap, valor3));
	print_test("No esta vacio",heap_esta_vacio(heap) == false);
	print_test("Desencolo valor5",heap_desencolar(heap) == valor5);
	print_test("No esta vacio",heap_esta_vacio(heap) == false);
	print_test("Desencolo valor4",heap_desencolar(heap) == valor4);
	print_test("No esta vacio",heap_esta_vacio(heap) == false);
	print_test("Desencolo valor3",heap_desencolar(heap) == valor3);
	print_test("No esta vacio",heap_esta_vacio(heap) == false);
	print_test("Desencolo valor2",heap_desencolar(heap) == valor2);
	print_test("No esta vacio",heap_esta_vacio(heap) == false);
	print_test("Desencolo valor1",heap_desencolar(heap) == valor1);
	print_test("Esta vacio",heap_esta_vacio(heap) == true);
	heap_destruir(heap, NULL);
}

void pruebas_heap_ver_max_desencolar(){
	/*Un elemento*/
	heap_t* heap = heap_crear(comparar_strings);
	print_test("Encolo valor1",heap_encolar(heap, valor1));
	print_test("El valor maximo es valor1",heap_ver_max(heap) == valor1);
	print_test("Desencolo valor1",heap_desencolar(heap) == valor1);
	print_test("No hay valor maximo",heap_ver_max(heap) == NULL);
	heap_destruir(heap, NULL);
	
	/*Varios elementos ordenados*/
	heap = heap_crear(comparar_strings);
	print_test("Encolo valor1",heap_encolar(heap, valor1));
	print_test("Encolo valor2",heap_encolar(heap, valor2));
	print_test("Encolo valor3",heap_encolar(heap, valor3));
	print_test("Encolo valor4",heap_encolar(heap, valor4));
	print_test("Encolo valor5",heap_encolar(heap, valor5));
	print_test("El valor maximo es valor5",heap_ver_max(heap) == valor5);
	print_test("Desencolo valor5",heap_desencolar(heap) == valor5);
	print_test("El valor maximo es valor4",heap_ver_max(heap) == valor4);
	print_test("Desencolo valor4",heap_desencolar(heap) == valor4);
	print_test("El valor maximo es valor3",heap_ver_max(heap) == valor3);
	print_test("Desencolo valor3",heap_desencolar(heap) == valor3);
	print_test("El valor maximo es valor2",heap_ver_max(heap) == valor2);
	print_test("Desencolo valor2",heap_desencolar(heap) == valor2);
	print_test("El valor maximo es valor1",heap_ver_max(heap) == valor1);
	print_test("Desencolo valor1",heap_desencolar(heap) == valor1);
	print_test("No hay valor maximo",heap_ver_max(heap) == NULL);
	heap_destruir(heap, NULL);
	
	/*Varios elementos desordenados*/
	heap = heap_crear(comparar_strings);
	print_test("Encolo valor5",heap_encolar(heap, valor5));
	print_test("Encolo valor2",heap_encolar(heap, valor2));
	print_test("Encolo valor1",heap_encolar(heap, valor1));
	print_test("Encolo valor4",heap_encolar(heap, valor4));
	print_test("Encolo valor3",heap_encolar(heap, valor3));
	print_test("El valor maximo es valor5",heap_ver_max(heap) == valor5);
	print_test("Desencolo valor5",heap_desencolar(heap) == valor5);
	print_test("El valor maximo es valor4",heap_ver_max(heap) == valor4);
	print_test("Desencolo valor4",heap_desencolar(heap) == valor4);
	print_test("El valor maximo es valor3",heap_ver_max(heap) == valor3);
	print_test("Desencolo valor3",heap_desencolar(heap) == valor3);
	print_test("El valor maximo es valor2",heap_ver_max(heap) == valor2);
	print_test("Desencolo valor2",heap_desencolar(heap) == valor2);
	print_test("El valor maximo es valor1",heap_ver_max(heap) == valor1);
	print_test("Desencolo valor1",heap_desencolar(heap) == valor1);
	print_test("No hay valor maximo",heap_ver_max(heap) == NULL);
	heap_destruir(heap, NULL);
}

void pruebas_heap_volumen(){
	heap_t* heap = heap_crear(comparar_numeros);
	for (size_t i = 5000; i>0; i--){
		int* num = malloc(sizeof(int));
		if (!num){
			return;
		}
		*num = rand() %5000;
		heap_encolar(heap, num);
	}
	print_test("Encolo 5000 elementos", true);
	
	int prim = 5001;
	int* ant= &prim;
	int* act;
	for (size_t i = 5000; i>0; i--){
		act = (int*) heap_desencolar(heap);
		if (*ant < *act){
			break;
		}
		*ant = *act;
		free(act);
	}
	print_test("Desencolo 5000 elementos", true);
	print_test("No puedo desencolar",heap_desencolar(heap) == NULL);
	heap_destruir(heap, NULL);
}

void pruebas_heap_sort(){
	heap_sort(arreglo3, 11, comparar_strings);
	fprintf(stderr,"1: %s\n",(char*)arreglo3[0]);
	fprintf(stderr,"2: %s\n",(char*)arreglo3[1]);
	fprintf(stderr,"3: %s\n",(char*)arreglo3[2]);
	fprintf(stderr,"4: %s\n",(char*)arreglo3[3]);
	fprintf(stderr,"5: %s\n",(char*)arreglo3[4]);
	fprintf(stderr,"6: %s\n",(char*)arreglo3[5]);
	fprintf(stderr,"7: %s\n",(char*)arreglo3[6]);
	fprintf(stderr,"8: %s\n",(char*)arreglo3[7]);
	fprintf(stderr,"9: %s\n",(char*)arreglo3[8]);
	fprintf(stderr,"10: %s\n",(char*)arreglo3[9]);
	fprintf(stderr,"11: %s\n",(char*)arreglo3[10]);

    heap_sort(arreglo4, 5, comparar_strings);
    print_test("Ordena un arreglo desordenado",arreglo4[0] == valor1 && arreglo4[1] == valor2 && arreglo4[2] == valor3 && arreglo4[3] == valor4 && arreglo4[4] == valor5);
}

void pruebas_heap_alumno(){
	printf("\n--- PRUEBAS VACIO ---\n");
	pruebas_heap_vacio();
	printf("\n--- PRUEBAS CREAR/DESTRUIR ARREGLO ---\n");
	pruebas_heap_crear_arreglo();
	printf("\n--- PRUEBAS DESENCOLAR ARREGLO ---\n");
	pruebas_heap_arr_desencolar();
	printf("\n--- PRUEBAS ENCOLAR/CANTIDAD ---\n");
	pruebas_heap_encolar_cantidad();
	printf("\n--- PRUEBAS DESENCOLAR/CANTIDAD ---\n");
	pruebas_heap_desencolar_cantidad();
	printf("\n--- PRUEBAS ESTA VACIO ---\n");
	pruebas_heap_esta_vacio();
	printf("\n--- PRUEBAS VER MAX/DESENCOLAR ---\n");
	pruebas_heap_ver_max_desencolar();
	printf("\n--- PRUEBAS VOLUMEN ---\n");
	pruebas_heap_volumen();
	printf("\n--- PRUEBAS SORT ---\n");
	pruebas_heap_sort();
}

