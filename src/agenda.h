#ifndef __AGENDA_H__
#define __AGENDA_H__

#define MAX_CONTACTOS 100

enum TipoTelefono {CASA, MOVIL, OFICINA, OTRO};
enum Mes{ENERO, FEBERO, MARZO, ABRIL, MAYO, JUNIO, JULIO, SEPTIEMBRE, OCTUBRE, NOVIEMBRE, DICIEMBRE};

struct Persona{
    char nombre[30];
    char apellido [30];// apellido
    int mes_de_nacimiento [30];// mes de nacimiento
    int dia_de_nacimiento [30];// dia de nacimiento
    char tipo_contacto [10];// tipo contacto
    char telefono [15];// numero de telefono
    char tipo_de_numero [10];// tipo de numero
};

typedef struct Persona Contacto;

typedef struct Agenda{
    Contacto contactos[MAX_CONTACTOS];
    int num_contactos; //Lleva la cuenta de cuantos contactos están en la agenda
} Agenda;


void iniciar_agenda(Agenda *agenda);
void agregar_contacto(Agenda *agenda, Contacto c);
void imprimir_agenda(Agenda agenda);
int buscar_contacto(Agenda *agenda, char *nombre);
int buscar_contacto_x_telefono(Agenda *agenda, char telefono[]);
void ordenar_contactos(Agenda *agenda);
void ordenar_contactos_inv(Agenda *agenda);
void mostrar_contacto(Contacto);
void leer_contacto(Contacto *c);
void cargar_contactos(char *filename, Agenda *agenda);
void guardar_contactos(char *filename, Agenda agenda);

#endif // __AGENDA_H_