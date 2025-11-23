#include <stdio.h>
#include <stdlib.h> 
#include "agenda.h" 

#define NOMBRE_ARCHIVO "contactos.csv"

void limpiar_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main() {
    Agenda mi_agenda;
    int opcion;
    int indice_encontrado;
    char nombre_buscado[30];
    char telefono_buscado[15];
    
   
    iniciar_agenda(&mi_agenda);
    cargar_contactos(NOMBRE_ARCHIVO, &mi_agenda);

    do {
        // Opciones 
        printf("\n");
        printf("         AGENDA C         \n");
        printf("\n");
        printf("1. Agregar Contacto\n");
        printf("2. Imprimir Agenda Completa\n");
        printf("3. Buscar Contacto por Nombre\n");
        printf("4. Buscar Contacto por Telefono\n");
        printf("5. Ordenar por Nombre (Ascendente)\n");
        printf("6. Ordenar por Nombre (Descendente)\n");
        printf("0. Salir y Guardar Cambios\n");
        printf("Seleccione una opción: ");
        
        
        if (scanf("%d", &opcion) != 1) {
            printf("\n Entrada inválida. Intente de nuevo.\n");
            limpiar_buffer();
            continue;
        }
        limpiar_buffer(); 
        
      
        switch (opcion) {
            case 1:
                
                Contacto temp_c; 
                agregar_contacto(&mi_agenda, temp_c); 
                break;
                
            case 2:
                
                imprimir_agenda(mi_agenda);
                break;
                
            case 3:
                printf("\nIngrese el nombre a buscar: ");
                scanf("%29s", nombre_buscado);
                indice_encontrado = buscar_contacto(&mi_agenda, nombre_buscado);
                if (indice_encontrado != -1) {
                    printf("\n Contacto encontrado:\n");
                    mostrar_contacto(mi_agenda.contactos[indice_encontrado]);
                } else {
                    printf("\n Contacto con nombre no encontrado.\n");
                }
                break;

            case 4:
                printf("\nIngrese el teléfono a buscar: ");
                scanf("%14s", telefono_buscado);
                indice_encontrado = buscar_contacto_x_telefono(&mi_agenda, telefono_buscado);
                if (indice_encontrado != -1) {
                    printf("\n Contacto encontrado:\n");
                    mostrar_contacto(mi_agenda.contactos[indice_encontrado]);
                } else {
                    printf("\n Contacto con teléfono  no encontrado.\n");
                }
                break;
                
            case 5:
                ordenar_contactos(&mi_agenda);
                printf("\n Agenda ordenada de forma ascendente.\n");
                break;

            case 6:
                ordenar_contactos_inv(&mi_agenda);
                printf("\n Agenda ordenada de forma descendente.\n");
                break;
                
            case 0:
                printf("\nGuardando la agenda...");
                guardar_contactos(NOMBRE_ARCHIVO, mi_agenda);
                printf("\nSaliendo...\n");
                break;

            default:
                printf("\n Opción no válida. Intente de nuevo.\n");
                break;
        }
    } while (opcion != 0);

    return 0;
}