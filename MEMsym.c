//------------------------
//  · Programa: MEMsym.c
//  · Autores: Jesús León y Mario
//  · Fecha: 23/11/2025
//------------------------



/* --- Comentario para desarrollar todos los conceptos que contiene el ejercicio y lo que hay que hacer en él. ---

  1 · Explicación del funcionamiento de una caché con nuestros datos:
  
	· La CPU necesita direcciones que contiene la RAM, la CPU puede hacer el proceso de ir a 
	recoger estas direcciones, pero es un procedimiento que lleva bastante tiempo.
	
    · Por ello, existe nuestra caché, que es el intermediario entre estos dos para optimizar el tiempo de recogida de datos. 
	Comprueba si lo que ha pedido la CPU almacenada en bloques/líneas lo tiene la RAM o no.  
    Si lo que ha pedido la CPU está, es un HIT. Entonces la CPU lee el dato directo de la caché. 
    Y si no está, estamos ante un MISS. Y la caché copia el bloque completo de la RAM a la línea correspondiente y actualiza la etiqueta entregando el dato a la CPU. 


  2 · Datos e interpretación de ellos del PDF de la práctica:
  
	Nombre del sistema: MEGATRONIX
	Cache de correspondencia directa: ETQ / Lin / Pal
	Dirección de 12 bits: Etiqueta: 5 / Línea: 3 / Palabra: 4

	La caché tiene 8 líneas (2^3), lo definiremos como NUM_FILAS = 8
	Y utiliza 16 bytes (2^4) por cada línea, se define como TAM_LINEA = 16

	Cuando se inicia la caché está esta vacía con valores por defecto,
	por ello la etiqueta tiene un valor por defecto y la línea también:
	ETQ_DEFAULT = 0xFF
	DATOS_DEFAULT = 0x23

	La RAM binaria que tiene una memoria total de 4096 bytes (2^11) 
	Se debe leer en el archivo "CONTENTS_RAM.bin" que contiene direcciones (en hexadecimal, EJ: A70) que contiene la ram.
	para la simulación de esta memoria caché.
  
	El archivo accesos_memoria.txt son las direcciones que la CPU pide a la RAM. 

	Si es un MISS, se incrementa numfallos por 1, se suma 20 a globaltime, se carga el bloque y los mensajes.
	Si es HIT, se muestra el dato leído.

	Finalmente, tras cada acceso que la CPU hace de la memoria caché se va a:
		· Hacer un sleep de 1 segundo, sleep(1).
		· Mostrar por pantalla los resultados finales: 
			-Los accesos 	
			-Los fallos
			-Tiempo medio
			-Texto leido.
			(Formato del PDF: Accesos totales: %d; fallos: %d; Tiempo medio: %.2f\nTexto leído: %s)
		· Escribir/Volcar los 16 bytes de cada línea (8 líneas * 16 bytes = 128 bytes) en el archivo CONTENTS_CACHE.bin 
			(byte 0 de ese fichero es el byte 0 de la línea 0 de la caché y el byte 128, es el byte 15 de la línea 15)
  
 -------------------------------------------------------------------------------------------------------------------*/

// 1 · Definicion de librerias, valores y estructuras
  // 1.1 · Librerias
  #include <stdio.h>
  #include <stdlib.h>
  #include <string.h>

  // 1.2 · Valores
  #define DIRECCIONESCPU "accesos_memoria.txt"
  #define ARCHIVOSALIDA  "CONTENTS_CACHE.bin"
  #define DIRECCIONESRAM "CONTENTS_RAM.bin"
  
  #define NUM_FILAS 8
  #define TAM_LINEA 16        
  #define RAM_SIZE 4096       

  // 1.3 · Estructuras
  typedef struct {
    unsigned char ETQ;
    unsigned char Data[TAM_LINEA];
  } T_CACHE_LINE;
  
  // 1.4 · Variables globales (Asumo que se pueden utilizar, el año pasado no se podia)
  int globaltime = 0;
  int numfallos  = 0;
  
  char RAM[RAM_SIZE];
  
// 2 · Prototipos de funciones a desarollar
	void LimpiarCACHE(T_CACHE_LINE tbl[NUM_FILAS]); // 1Mario
	void VolcarCACHE(T_CACHE_LINE *tbl); // 2Jesús
	void ParsearDireccion(unsigned int addr, int *ETQ, int *palabra, int *linea, int *bloque); // 3Mario
	void TratarFallo(T_CACHE_LINE *tbl, char *MRAM, int ETQ, int linea, int bloque); // 4Jesús

// 3 · Función principal main
int main (int argc, char* argv[]){

  // 3.1 · Variables del main
  char T_CACHE_LINE[NUM_FILAS]; // 8 filas, 8 elementos.


}

// 4 · Desarollo de funciones
	// 4.1 · Función para...
		void LimpiarCACHE(T_CACHE_LINE tbl[NUM_FILAS]){
			
		}
		
	// 4.2 · (Jesús)Función cuyo proposito es enseñar el estado actual de la caché cuando se la llame.
	
		/*
		* Consistiendo en mostrar el contenido del array de estrcuturas T_CACHE_LINE.
		* Nos piden tambien: "Los datos se imprimen de izquierda a derecha de mayor a menor peso. Esto
		* significa que el byte situado más a la izquierda es el byte 15 de la línea y el
		* situado a la derecha el byte 0." 
		*/
	
		//· T_CACHE_LINE *tbl - Puntero al primer elemento del array de estructuras T_CACHE_LINE
		void VolcarCACHE(T_CACHE_LINE *tbl){
			printf("Estado actual de la cache:\n");
			
			// Para mostrar el contenido del array de estructuras hacemos un bucle for que analice todas sus lineas.
			// Como aqui no nos dicen el orden empezamos desde la linea 0 incrementando el valor hasta 7.
			for (int i = 0; i < NUM_FILAS; ++i) {
				printf("Linea %d | ETQ:%02X | Datos: ", i, tbl[i].ETQ);
				
				 // Nos piden imprimir los datos de mayor a menor peso: byte 15 (may,izq)  hasta 0 (men,der).
				 // De esta forma empezamos por el numero 15 que es 16 (Tlin) -1 y vamos decrementando su valor hasta llegar a 0.
				for (int j = TAM_LINEA - 1; j >= 0; --j) {
					printf("%02X ", tbl[i].Data[j]);
				}
				printf("\n"); // Salto de liena cada linea para que se vea limpio.
			}
			print("Fin del estado actual de la cache\n")


	// 4.3 · Función para...
		void ParsearDireccion(unsigned int addr, int *ETQ, int *palabra, int *linea, int *bloque){
			
		}

	// 4.4 · (Jesús)Función que se llama cuando se produce un MISS en la cache-
	
		/*
		* Un miss es un fallo de acceso de la cache a un bloque de memoria de la RAM, ahora el porceso se hace de CPU a RAM.
		*
		*
		*/
	
	
		//· T_CACHE_LINE *tbl - Puntero al primer elemento del array de estructuras T_CACHE_LINE
		//· char *RAM - Puntero a la memoria RAM
		//· int ETQ - etiqueta de la cache
		//· int linea - linea de la cache
		//· int bloque - bloque de la ram
		void TratarFallo(T_CACHE_LINE *tbl, char *RAM, int ETQ, int linea, int bloque){
			
			
		}
