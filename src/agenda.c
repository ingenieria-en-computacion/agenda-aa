#include <stdio.h>
#include <string.h> 
#include "agenda.h"
#define NOMBRE_ARCHIVO "contactos.csv"

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

        leer_contacto(&c);

        int indice = (*agenda).num_contactos;
        (*agenda).contactos[indice] = c;
        (*agenda).num_contactos++; 
        printf("Contacto añadido \n");

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
    for (int i = 0; i < (*agenda).num_contactos; i++){
        if (strcmp((*agenda).contactos[i].telefono, telefono) == 0){
            return i; //contacto encontrado y vamos a retornar el indice
        }
    }
    return -1; //retorna -1 si no lo encontro
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
            if (strcmp(a->contactos[j].nombre, a->contactos[j+1].nombre) < 0){
                temp = a->contactos [j+1];
                a->contactos [j+1] = temp;
            }
        }
    }
}


/**
 * Función auxiliar para imprimir un contacto
 */
void mostrar_contacto(Contacto c){
    printf("  Nombre: %s %s\n", c.nombre, c.apellido);
    printf("  Fecha De Nacimiento: %d/%d\n", c.dia_de_nacimiento, c.mes_de_nacimiento);
     printf("  Tipo de Contacto: %s\n", c.tipo_contacto);
    printf("  Teléfono (%s): %s\n", c.tipo_de_numero, c.telefono);
}


/**
 * Función auxiliar para leer un contacto
 */
void leer_contacto(Contacto *c){
    printf("Ingrese los datos del contacto");

    printf("Nombre: ");
    scanf("%29s", c->nombre);
    
    printf("Apellido: ");
    scanf("%29s", c->apellido);
    
    printf("Tipo de Contacto (FAVORITO/NORMAL): ");
    scanf("%9s", c->tipo_contacto); 
    
    printf("Teléfono: ");
    scanf("%14s", c->telefono); 
    
    printf("Tipo de Teléfono (MOVIL/CASA): ");
    scanf("%9s", c->tipo_de_numero);

    printf("Día de Nacimiento (1-31): ");
    scanf("%d", &c->dia_de_nacimiento);

    printf("Mes de Nacimiento (1-12): ");
    scanf("%d", &c->mes_de_nacimiento);
}

/**
 * Función que imprime todos los contactos de la agenda en pantalla
 */
void imprimir_agenda(Agenda agenda){
    if (agenda.num_contactos == 0) {
        printf("\n La agenda está vacía no hay contactos para mostrar.\n");
        return;
    }
    printf("\n LISTA DE CONTACTOS (%d en total) \n", agenda.num_contactos);

    for (int i = 0; i < agenda.num_contactos; i++) {
        printf(" \n");
        printf("ID: %d\n", i + 1);
        
        mostrar_contacto(agenda.contactos[i]); 
    }
    printf("\n");
}

/**
 * Función que sirve para cargar contactos escritos en un archivo a la agenda
 */
void cargar_contactos(char *filename, Agenda *agenda){
    
    FILE *archivo = fopen(filename, "r");
     if (archivo == NULL) {
        printf("Advertencia: No se encontró el archivo '%s'. Iniciando agenda vacía.\n", filename);
        return;
    }

    int contactos_cargados = 0;
    Contacto nuevo;

    while (fscanf(archivo, "%29[^,],%29[^,],%d,%d,%9[^,],%14[^,],%9[^\n]\n", 
                  nuevo.nombre, 
                  nuevo.apellido, 
                  &nuevo.dia_de_nacimiento, 
                  &nuevo.mes_de_nacimiento, 
                  nuevo.tipo_contacto,     
                  nuevo.telefono, 
                  nuevo.tipo_de_numero) == 7) { 
        
        if (agenda->num_contactos < MAX_CONTACTOS) {
            int indice = agenda->num_contactos;
            agenda->contactos[indice] = nuevo;
            agenda->num_contactos++;
            contactos_cargados++;
        } else {
            break; 
        }
    }

    
    fclose(archivo);
    printf("%d contactos cargados desde '%s'.\n", contactos_cargados, filename);

}


/**
 * Función que sirve para guardar todos los contactos de la agenda en un archivo
 */
void guardar_contactos(char *filename, Agenda agenda){
    
    FILE *archivo = fopen(filename, "w");
    
    if (archivo == NULL) {
        printf("ERROR: No se pudo abrir o crear el archivo %s.\n", filename);
        return;
    }

    for (int i = 0; i < agenda.num_contactos; i++){
        Contacto c = agenda.contactos[i];
        
        fprintf(archivo, "%s,%s,%d,%d,%s,%s,%s\n", 
                c.nombre, 
                c.apellido, 
                c.dia_de_nacimiento, 
                c.mes_de_nacimiento, 
                c.tipo_contacto,     
                c.telefono, 
                c.tipo_de_numero);
    }

    fclose(archivo);
    printf("%d contactos guardados exitosamente en '%s'.\n", agenda.num_contactos, filename);
}