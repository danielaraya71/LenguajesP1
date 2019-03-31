
#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{
    int codigoEmpleado;
    char nombre[];
    char apellido[];
    char departamento[];
    int codigoProyecto;
    nodo *sig;
}empleado;
empleado *cabezaEmp=NULL;

typedef struct nodo{
    int codigoProyecto;
    char nombre[];
    int anioInicio;
    int anioFin;
    nodo *sig;
}proyecto;
proyecto *cabezaPro=NULL;

typedef struct nodo{
    int codigoActividad;
    char descripcion[];
    int avance;
    int codigoProyecto;
    nodo*sig;
}actividad;
actividad *cabezaAct= NULL;

void agregarEmpleado(){
    
}

void agregarProyecto(){
    
}

void agregarActividad(){
    
}
void agregar(){
    int opcionAgregar;
    printf("\nSelecciones alguna de las opciones\n");
    printf("1 para agregar un empleado\n2 para agregar un proyecto\n3 para agregar una actividad\n");
    scanf("%d",&opcionAgregar);
    switch(opcionAgregar){
        //Si elige la opcion 1, se agrega un numero, y ademas se suma 1 a variable longitud para tener control del tamano de la pila
        case 1: agregarEmpleado();
                break;
        //Si elige la opcion 2, se elimina el numero en tope y se le resta 1 a variable longitud
        case 2: agregarProyecto();
                break;
        case 3: agregarActividad();
                break;
        default: printf("Utilice solo las opciones validas\n");
    }
}

void modificarActividad(){
    
}

void consultarProyecto(){
    
}

void consultarEmpleado(){
    
}

int main() {
    int opcion,estado=1;
    //El menu se repetira infinitas veces hasta que el usuario digite la opcion para salir
    while(estado==1){
        //Se le pide al usuario que digite una de las opciones
        printf("\nSelecciones alguna de las opciones\n");
        printf("1 para agregar\n2 para eliminar\n3 para tamanio\n4 para imprimir\n5 para consultar valor en top\n6 para salir\n");
        scanf("%d",&opcion);
        switch(opcion){
                //Si elige la opcion 1, se agrega un numero, y ademas se suma 1 a variable longitud para tener control del tamano de la pila
                case 1: agregar();
                        break;
                //Si elige la opcion 2, se elimina el numero en tope y se le resta 1 a variable longitud
                case 2: modificarActividad();
                        break;
                case 3: consultarProyecto();
                        break;
                case 4: consultarEmpleado();
                        break;
                case 5:	estado=0;
                        break;
                default: printf("Utilice solo las opciones validas\n");
            }

    }
    printf("Ejecucion terminada\n");
    return 0;
}






