//Librerias a utilizar
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct nodoEmp{
    int codigoEmpleado;
    char nombre[50];
    char apellido[50];
    char departamento[50];
    int codigoProyecto;
    struct nodoEmp* sig;
}Empleado;
Empleado *cabezaEmp=NULL;

//Estructura donde se guardan temporalmente los datos de proyectos
typedef struct nodoPro{
    int codigoProyecto;
    char nombre[50];
    int anioInicio;
    int anioFin;
    Empleado nodoEmpleado;
    struct nodoPro* sig;
}Proyecto;
Proyecto *cabezaPro=NULL;

//Estructura donde se guardan temporalmente los datos de actividades
typedef struct nodoAct{
    int codigoActividad;
    char descripcion[50];
    int avance;
    int codigoProyecto;
    struct nodoAct* sig;
}Actividad;
Actividad *cabezaAct= NULL;

int cantidadEmp=0;
int cantidadPro=0;
int cantidadAct=0;

void agregarEmpleado(){
    
    //SE CREA NUEVO NODO TIPO EMPLEADO Y SE LE AGREGAN SUS DATOS
    Empleado* nuevo=(Empleado*)malloc(sizeof(nuevo));
    printf("Digite su nombre\n");
    scanf("%s",&nuevo->nombre);
    printf("Digite su apellido\n");
    scanf("%s",&nuevo->apellido);
    printf("Digite su departamento\n");
    scanf("%s",&nuevo->departamento);
    
    //ESTOS LOS PUSE NADA MAS PARA PROBAR
    nuevo->codigoEmpleado=cantidadEmp;
    nuevo->codigoProyecto=NULL;
    
    //Si la pila esta vacia se agrega en el tope y si no, se coloca encima del que sea el tope
    if(cabezaEmp==NULL){
        cabezaEmp=nuevo;
        cabezaEmp->sig=NULL;
    }
    else{
        nuevo->sig=cabezaEmp;
        cabezaEmp=nuevo;
    }
    cantidadEmp++;
    printf("\nEmpleado agregado con exito\n");
}

void imprimir(){
    
}

void agregarProyecto(){
    //Se verifica que existan al menos 2 empleados registrados
    if(cantidadEmp>=2){
    //Se crear un nuevo nodo para el proyecto y para el empleado, y se introducen los datos del proyecto, exceptuando la lista de empleados y actividades
        Proyecto *proyecto=(Proyecto*)malloc(sizeof(proyecto));
        Empleado *nodoEmpleado=(Empleado*)malloc(sizeof(nodoEmpleado));
        printf("Ingrese el nombre del proyecto\n");
        scanf("%s",&proyecto->nombre);
        int anioInicio, anioFin;
        printf("Ingrese el anio de inicio del proyecto\n");
        scanf("%s",&anioInicio);
        printf("Ingrese el anio de fin del proyecto\n");
        scanf("%s",&anioFin);
        if(anioInicio<anioFin){
            proyecto->codigoProyecto=cantidadPro;
            int verificador=0, cantEmpleados=0;
            //El nodo auxiliar sirve para recorrer la lista global de empleados
            Empleado *auxEmpleado= cabezaEmp;
            while(verificador==0){
                char nombre[50]; 
                printf("Ingrese el nombre del empleado\n");
                scanf("%s",&nombre);
                while(auxEmpleado != NULL){
            //Se busca el nombre del empleado con el nodo auxiliar
                    if(strcmp(auxEmpleado->nombre,nombre)==0){
                        strcpy(nodoEmpleado->nombre,auxEmpleado->nombre);
                        strcpy(nodoEmpleado->apellido,auxEmpleado->apellido);
                        strcpy(nodoEmpleado->departamento,auxEmpleado->departamento);
                        nodoEmpleado->codigoEmpleado=auxEmpleado->codigoEmpleado;
                        nodoEmpleado->codigoProyecto=proyecto->codigoProyecto;
                        cantEmpleados++;
                        
                        if(cabezaEmp==NULL){
                            cabezaEmp=nodoEmpleado;
                            cabezaEmp->sig=NULL;
                        }
                        else{
                            cabezaEmp->sig=cabezaEmp;
                            cabezaEmp=nodoEmpleado;
                        }
                        
                        printf("Empleado agregado con exito\n");
                       
                    }
                    auxEmpleado=auxEmpleado->sig;
                }
                printf("Presione 0 si desea ingresar mas empleados\n");
                scanf("%i",&verificador);
            }
            if(cantEmpleados>=2){
                if(cabezaPro==NULL){
                    cabezaPro=proyecto;
                    cabezaPro->sig=NULL;
                }
                else{
                    cabezaPro->sig=cabezaPro;
                    cabezaPro=proyecto;
                }
            }
        }
    }
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






