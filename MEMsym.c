//------------------------
//  · Programa: MEMsym.c
//  · Autores: Jesús León y Mario
//  · Fecha: 23/11/2025
//------------------------


/* --- Comentario para desarrollar todos los conceptos que contiene el ejercicio y lo que hay que hacer en el. ---

  1 · Explicacion del funcionamiento de una cache con nuestros datos:
  
	· La CPU necesita direcciones que contiene la RAM, la CPU puede hacer el proceso de ir a 
	recoger estas direcciones pero es un porcedimiento que lleva bastante tiempo.
	
    · Por ello, existe nuestra cache que es el intermedieario entre estos dos para optimizar el tiempo de recogida de datos. 
	Comprueba si lo que ha pedido la CPU almacenado en bloques/lineas lo tiene la RAM o no.  
    Si lo que ha pedido la CPU esta, es un HIT. Entonces la CPU lee el dato directo de la cache. 
    Y si no esta, estamos ante un MISS. Y la cache copia el bloque completo de la RAM a la linea correspondiente y actualiza la etiqueta entregando el dato a la CPU. 

  2 · Datos e interpretacion de ellos del PDF de la practica:
  
	Nombre del sistema: MEGATRONIX
	Cache de correspondencia directa: ETQ / Lin / Pal
	Dirección de 12 bits: Etiqueta: 5 / Línea: 3 / Palabra: 4

	La cache tiene 8 líneas (2^3), lo definiremos como NUM_FILAS = 8
	Y utiliza 16 bytes (2^4) por cada linea, se define como TAM_LINEA = 16

	Cuando se inicia la cache esta esta vacia con valores por defecto,
	por ello la etiqueta tiene un valor por defecto y la linea tambien:
	ETQ_DEFAULT = 0xFF
	DATOS_DEFAULT = 0x23

	La RAM binaria que tiene una memoria total de 4096 bytes (2^11) 
	Se debe leer en el archivo "CONTENTS_RAM.bin" que contiene direcciones (en hexadecimal, EJ: A70) que contiene la ram.
	para la simulacion de esta memoria cache.
  
	El archivo accesos_memoria.txt son las direcciones que la CPU pide a la RAM. 

	Si es un MISS, se incrementa numfallos por 1, se suma 20 a globaltime, se carga el bloque y los mensajes.
	Si es HIT, se muestra el dato leido.

	Finalmnete, tras cada acceso que la CPU hace de la memoria cache se va a:
		· Hacer un sleep de 1 segundo, sleep(1).
		· Mostrar por pantalla los resultados finales: 
			-Los accesos 	
			-Los fallos
			-Tiempo medio
			-Texto leido.
			(Formato del PDF: Accesos totales: %d; fallos: %d; Timepo medio: %.2f\nTexto leído: %s)
		· Escribir/Volcar los 16 bytes de cada linea (8 lineas * 16 bytes = 128 bytes) en el archivo CONTENTS_CACHE.bin 
			(byte 0 de ese fichero es el byte 0 de la línea 0 de la caché y el byte 128, es el byte 15 de la línea 15)
  
 -------------------------------------------------------------------------------------------------------------------*/ 

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

