//------------------------
//  · Programa: MEMsym.c
//  · Autores: Jesús León y Mario
//  · Fecha: 23/11/2025
//------------------------

// 1 · Definicion de librerias, valores y estructuras
  // 1.1 · Librerias
  #include <stdio.h>
  #include <stdlib.h>
  #include <string.h>

  // 1.2 · Valores
  #define DIRECCION "accesos_memoria.txt"
  #define ARCHIVOSALIDA "CONTENTS_CACHE.bin"

  // 1.3 · Estructuras
  typedef struct {
    unsigned char ETQ;
    unsigned char Data[TAM_LINEA];
  } T_CACHE_LINE;
  
// 2 · Prototipos de funciones a desarollar
  void LimpiarCACHE(T_CACHE_LINE tbl[NUM_FILAS]);
  void VolcarCACHE(T_CACHE_LINE *tbl);
  void ParsearDireccion(unsigned int addr, int *ETQ, int *palabra, int *linea, int *bloque);

void TratarFallo(T_CACHE_LINE *tbl, char *MRAM, int ETQ,
int linea, int bloque);

// 3 · Función principal main
int main (int argc, char* argv[]){

  // 3.1 · Variables del programa
  char T_CACHE_LINE[8];
  int globaltime = 0;
  int numfallos = 0;

}

// 4 · Desarollo de funciones
// 4.1 · Función para...

