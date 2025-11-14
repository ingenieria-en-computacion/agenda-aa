#include <stdio.h>
#include <string.h> 
#include "agenda.h"

/**
 * Esta función se encarga de iniciar el número de contactos a cero
 */
void iniciar_agenda(Agenda *agenda){
    (*agenda).num_contactos = 0;
}



// Varible que lleva la cuenta de cuantos contactos hay en la agenda
int num_contactos;

/**
 * Esta función sirve para agregar un contacto nuevo en la agenda
 */
void agregar_contacto(Agenda *agenda, Contacto c){
    if ((*agenda).num_contactos < MAX_CONTACTOS){
        // con esto accederemos al arreglo de 'contactos'
        int indice = (*agenda).num_contactos;
        (*agenda).contactos[indice] = c;
        (*agenda).num_contactos++;
    }else{
        printf("Error fatal: La agenda esta llena\n");
    }
}


/**
 * Esta función sirve para buscar un contacto por nombre en la agenda y retorna la posición del contacto si exisite
 * En caso contrario retorna -1
 */
int buscar_contacto(Agenda *agenda, char *nombre){
    
    for (int i = 0; i < (*agenda).num_contactos; i++) {
        if (strcmp((*agenda).contactos[i].nombre, nombre) == 0){
            return i; //vamos a retornar la posicion
        }
    }
    return -1;
}


/**
 * Esta función  sirve para buscar un contacto por su número de telefono en la agenda
 */
int buscar_contacto_x_telefono(Agenda *agenda, char telefono[]){

}


/**
 * Esta función sirve para ordenar los contactos por nombres de forma ascendente
 */
void ordenar_contactos(Agenda *a){
    int i, j;
    Contacto temp;
    for(i = 0; i < a->num_contactos; i++){
        for(j=0; j < a->num_contactos-i-1; j++){
            if(strcmp(a->contactos[j].nombre, a->contactos[j+1].nombre)>0){
                temp = a->contactos[j];
                a->contactos[j] = a->contactos[j+1];
                a->contactos[j+1] = temp;
            }
        }
    }
}

/**
 * Esta función sirve para ordenar los contactos por nombres de forma descendente
 */
void ordenar_contactos_inv(Agenda *a){
    int i, j;
    Contacto temp;
    for(i = 0; i < a->num_contactos; i++){
        for(j=0; j < a->num_contactos-i-1; j++){
            //Completar basandose en la función anterior
        }
    }
}


/**
 * Función auxiliar para imprimir un contacto
 */
void mostrar_contacto(Contacto){

}


/**
 * Función auxiliar para leer un contacto
 */
void leer_contacto(Contacto *c){

}

/**
 * Función que imprime todos los contactos de la agenda en pantalla
 */
void imprimir_agenda(Agenda agenda){

}

/**
 * Función que sirve para cargar contactos escritos en un archivo a la agenda
 */
void cargar_contactos(char *filename, Agenda *agenda){

}


/**
 * Función que sirve para guardar todos los contactos de la agenda en un archivo
 */
void guardar_contactos(char *filename, Agenda agenda){

}