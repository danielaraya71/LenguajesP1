//Librerias a utilizar
#include <stdio.h>
#include <stdlib.h>

//Estructura donde se guardan temporalmente los datos de empleados
typedef struct nodoEmp{
    int codigoEmpleado;
    int nombre[50];
    char apellido[50];
    char departamento[50];
    int codigoProyecto;
    struct nodoEmp* sig;
}empleado;
empleado *cabezaEmp=NULL;

//Estructura donde se guardan temporalmente los datos de proyectos
typedef struct nodoPro{
    int codigoProyecto;
    char nombre[50];
    int anioInicio;
    int anioFin;
    struct nodoPro* sig;
}proyecto;
proyecto *cabezaPro=NULL;

//Estructura donde se guardan temporalmente los datos de actividades
typedef struct nodoAct{
    int codigoActividad;
    char descripcion[50];
    int avance;
    int codigoProyecto;
    struct nodoAct* sig;
}actividad;
actividad *cabezaAct= NULL;

void agregarEmpleado(){
    //TODAVIA FALTA LO DE CODIGO EMPLEADO, ESTE SE DEBE DE GENERAR AUTOMATICAMENTE
    
    //SE CREA NUEVO NODO TIPO EMPLEADO Y SE LE AGREGAN SUS DATOS
    empleado* nuevo=(empleado*)malloc(sizeof(nuevo));
    printf("Digite su nombre\n");
    scanf("%s",&nuevo->nombre);
    printf("Digite su apellido\n");
    scanf("%s",&nuevo->apellido);
    printf("Digite su departamento\n");
    scanf("%s",&nuevo->departamento);
    
    //ESTOS LOS PUSE NADA MAS PARA PROBAR
    nuevo->codigoEmpleado=1;
    nuevo->codigoProyecto=1;
    
    //Si la pila esta vacia se agrega en el tope y si no, se coloca encima del que sea el tope
    if(cabezaEmp==NULL){
        cabezaEmp=nuevo;
        cabezaEmp->sig=NULL;
    }
    else{
        nuevo->sig=cabezaEmp;
        cabezaEmp=nuevo;
    }
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
        printf("1 para agregar\n2 para modificar actividad\n3 para consultar proyecto\n4 para consultar empleado\n5 para salir\n");
        scanf("%d",&opcion);
        switch(opcion){
            case 1: agregar();
                    break;
            case 2: modificarActividad();
                    break;
            case 3: consultarProyecto();
                    break;
            case 4: consultarEmpleado();
                    break;
            case 5: estado=0;
                    break;
            default: printf("Utilice solo las opciones validas\n");
        }
    }
    printf("Ejecucion terminada\n");
    return 0;
}






