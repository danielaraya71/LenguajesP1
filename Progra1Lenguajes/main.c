/*
 Archivo: main.c
 Autores: Daniel Araya y Maria Jose Placido*/

//Librerias a utilizar
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*ESTRUCTURAS*/

//Estructura de empleado
typedef struct nodoEmp{
    int codigoEmpleado;
    char nombre[50];
    char apellido[50];
    char departamento[50];
    int codigoProyecto;
    struct nodoEmp* sig;
}Empleado;

Empleado *cabezaEmp=NULL;

//Estructura de proyectos
typedef struct nodoPro{
    int codigoProyecto;
    char nombre[50];
    int anioInicio;
    int anioFin;
    struct nodoPro* sig;
}Proyecto;

Proyecto *cabezaPro=NULL;

//Estructura de las actividades
typedef struct nodoAct{
    int codigoActividad;
    char descripcion[50];
    int avance;
    int codigoProyecto;
    struct nodoAct* sig;
}Actividad;

Actividad *cabezaAct= NULL;

//Se utilizan estos contadores para establecer los codigos respectivos
int cantidadEmp=0;
int cantidadPro=0;
int cantidadAct=0;


/*
 Metodo para registrar un nuevo empleado
 Entradas: no tiene entradas
 Salidas: no tiene salidas
 Objetivo: agregar a nodo a estructura empleado*/
void agregarEmpleado(){
    Empleado* nuevo=(Empleado*)malloc(sizeof(nuevo));
    printf("\n  Digite el nombre del empleado\n");
    scanf("%s",&nuevo->nombre);
    printf("\n  Digite el apellido del empleado\n");
    scanf("%s",&nuevo->apellido);
    printf("\n  Digite el departamento del departamento\n");
    scanf("%s",&nuevo->departamento);

    nuevo->codigoEmpleado=cantidadEmp;
    nuevo->codigoProyecto=0;
    printf("\n  Codigo de empleado es: %d\n",nuevo->codigoEmpleado);

    if(cabezaEmp==NULL){
        cabezaEmp=nuevo;
        cabezaEmp->sig=NULL;
    }
    else{
        nuevo->sig=cabezaEmp;
        cabezaEmp=nuevo;
    }
    cantidadEmp++;
    printf("\n  Empleado agregado con exito\n");
}

/*
Metodo para registrar la informacion de un proyecto en un nodo
Enrradas: nombre de proyecto, anio de inicio, anio de fin
Salidas: no tiene salidas
Objetivo: agregar un nuevo nodo en la estructura proyecto*/

void registrarProyecto(char nombreProyecto[50],int anioInicio, int anioFin){
	Proyecto *nodoProyecto=(Proyecto*)malloc(sizeof(Proyecto));
	strcpy(nodoProyecto->nombre,nombreProyecto);
	nodoProyecto->anioInicio=anioInicio;
	nodoProyecto->anioFin=anioFin;
	nodoProyecto->codigoProyecto=cantidadPro;
    if(cabezaPro==NULL){
        cabezaPro=nodoProyecto;
        cabezaPro->sig=NULL;
    }
    else{
        nodoProyecto->sig=cabezaPro;
        cabezaPro=nodoProyecto;
    }
    printf("\n  Proyecto agregado con exito\n");
    cantidadPro++;
    printf("\n  El codigo del proyecto es: %d\n",cabezaPro->codigoProyecto);
    printf("    El anio inicio es %d\n",cabezaPro->anioInicio);
    printf("    El anio fin es %d\n",cabezaPro->anioFin);

    printf("Cantidad proyectos: %d\n",cantidadPro);

}

/*
 Metodo para registrar un nuevo proyecto
 Entradas: no tiene entradas
 Salidas: no tiene salidas
 Objetivo: agregar un nuevo nodo a la estructura proyecto*/
void agregarProyecto(){
    //Se verifica que existan al menos 2 empleados registrados
    if(cantidadEmp>=2){

        //Se solicitan datos del proyecto
        char nombreProyecto[50];
        printf("\n  Ingrese el nombre del proyecto\n");
        scanf("%s",&nombreProyecto);

        int anioInicio;
        printf("\n  Ingrese el anio de inicio del proyecto\n");
        scanf("%d",&anioInicio);

        int anioFin;
        printf("\n  Ingrese el anio de fin del proyecto\n");
        scanf("%d",&anioFin);

        //Se verifica que el anio de inicio sea menor que el anio de fin
        if(anioInicio<anioFin){
            int cantEmpleados=0;
            int verificador=0;
            while(verificador==0){
            	Empleado *nodoEmpleado=(Empleado*)malloc(sizeof(Empleado));
                Empleado *auxEmpleado= cabezaEmp;
                int encontrado=0;
                char nombreEmpleado[50];
                printf("\n  Ingrese el nombre del empleado\n");
                scanf("%s",&nombreEmpleado);
                while(auxEmpleado != NULL){

                    if(strcmp(auxEmpleado->nombre,nombreEmpleado)==0){
                        encontrado++;
                        strcpy(nodoEmpleado->nombre,auxEmpleado->nombre);
                        strcpy(nodoEmpleado->apellido,auxEmpleado->apellido);
                        strcpy(nodoEmpleado->departamento,auxEmpleado->departamento);
                        nodoEmpleado->codigoEmpleado=auxEmpleado->codigoEmpleado;
                        nodoEmpleado->codigoProyecto=cantidadPro;
                        cantEmpleados++;

                        if(cabezaEmp==NULL){
                            cabezaEmp=nodoEmpleado;
                            cabezaEmp->sig=NULL;
                        }
                        else{
                            nodoEmpleado->sig=cabezaEmp;
                            cabezaEmp=nodoEmpleado;
                        }
                        printf("\n  Empleado agregado con exito\n");
                    }
                    auxEmpleado=auxEmpleado->sig;
                }
                if(encontrado==0){
                    printf("\n  No se encontro el empleado\n");
                }
                printf("\n  Digite 0 si desea ingresar mas empleados\n");
                scanf("%d",&verificador);
            }
			if(cantEmpleados>=2){
				registrarProyecto(nombreProyecto,anioInicio,anioFin);
			}
			else{
				printf("El proyecto debe de tener 2 o mas empleados\n");
			}
		}
		else{
			printf("Anio de inicio no puede ser menor que anio fin\n");
		}
	}
	else{
		printf("No existe la cantidad necesaria de empleados\n");
	}
}

/*
Metodo que registra los datos de una actividad en un nodo actividad
Entradas: codigo de proyecto y descripcion de actividad
Salidas: no tiene salidas
Objetivo: agregar un nodo en la estructura actividad
*/
void registrarActividad(int codigoProyecto, char descripcion[50]){
    Actividad *nodoActividad=(Actividad*)malloc(sizeof(Actividad));
	nodoActividad->avance=0;
    int actividadesProyecto=1;
    Actividad *auxAct= cabezaAct;
    while(auxAct != NULL){
   		if(auxAct->codigoProyecto==nodoActividad->codigoProyecto){
        	actividadesProyecto++;
        }
            auxAct=auxAct->sig;
    }
    nodoActividad->codigoActividad=actividadesProyecto;

    if(cabezaAct==NULL){
        cabezaAct=nodoActividad;
        cabezaAct->sig=NULL;
    }
    else{
        nodoActividad->sig=cabezaAct;
        cabezaAct=nodoActividad;
    }
    printf("\n  Actividad agregada con exito\n");
    printf("\n  El codigo de la actividad es: %d\n",cabezaAct->codigoActividad);
    cantidadAct++;
}

/*
 Metodo para registrar una actividad en un proyecto
 Entradas: no tiene entradas
 Salidas: no tiene salidas
 Objetivo: agregar un nodo en la estructura actividad
 */
void agregarActividad(){
    if(cantidadPro>0){

    	int codigoProyecto;
        printf("\n  Digite el codigo del proyecto al que pertenece la actividad\n");
        scanf("%d",&codigoProyecto);

        char descripcion[50];
        printf("\n  Digite el nombre o descripcion de la actividad\n");
        scanf("%s",&descripcion);

        registrarActividad(codigoProyecto,descripcion);
    }
    else{
  		printf("No existe la cantidad necesaria de proyectos \n");
	}
}


/*
 Metodo para visualizar menu de registrar empleados, proyectos o registros
 Entradas: no tiene entradas
 Salidas: no tiene salidas
 Objetivo: mostrar un menu secundario en caso de escoger la opcion de agregar
 */
void agregar(){
    int opcionAgregar;
    printf("\nSelecciones alguna de las opciones\n");
    printf("1 para agregar un empleado\n2 para agregar un proyecto\n3 para agregar una actividad\n");
    scanf("%d",&opcionAgregar);
    switch(opcionAgregar){
        case 1: agregarEmpleado();
                break;
        case 2: agregarProyecto();
                break;
        case 3: agregarActividad();
                break;
        default: printf("Utilice solo las opciones validas\n");
    }
}

/*
Metodo para modificar el nodo de una activdad
Entradas: nodo cabeza de estructura actividad
Salidas: no tiene salidas
Objetivo: actualizar el avance de un nodo actividad*/
void modificarActividadAux(Actividad *cabezaAct,int codigoPro,int codigoAct){
    Actividad *auxAct=(Actividad*)malloc(sizeof(Actividad));
    auxAct=cabezaAct;
    while(auxAct != NULL){
        if(auxAct->codigoProyecto==codigoPro){
            if(auxAct->codigoActividad==codigoAct){
                printf("Digite el avance que lleva la actividad\n");
                scanf("%d",&auxAct->avance);
                printf("Avance actualizado con exito\n");
            }
        }
        auxAct=auxAct->sig;
    }
}
/*
 Metodo para modificar una actividad
 Entradas: no tiene entradas
 Salidas: no tiene salidas
 Objetivo: solicitar los datos para encontrar un nodo actividad
 */
void modificarActividad(Actividad *cabezaAct){
    if(cantidadAct>0){
        int codigoPro,codigoAct;
        printf("Digite el codigo del proyecto al que desea acceder\n");
        scanf("%d",&codigoPro);
        printf("Digite el codigo de la activdad que desea modificar\n");
        scanf("%d",&codigoAct);
        modificarActividadAux(cabezaAct,codigoPro,codigoAct);
    }
}

/*
 Metodo que consulta todos los empleados de un proyecto
 Entradas: el codigo del proyecto
 Salidas: no tiene salidas
 Objetivo: mostrar en pantalla la lista de empleados de un proyecto
 */
void consultarEmpleadoPro(int codigoProyecto){
    Empleado *auxEmp = (Empleado*)malloc(sizeof(Empleado));
    auxEmp=cabezaEmp;
    while(auxEmp != NULL){
        if(auxEmp->codigoProyecto==codigoProyecto){
            printf("\nEl nombre del empleado es: %s\n",auxEmp->nombre);
            printf("El apellido del empleado es: %s\n",auxEmp->apellido);
            printf("El departamento del empleado es: %s\n",auxEmp->departamento);
        }
        auxEmp=auxEmp->sig;
    }
}

/*
 Metodo para consultar la lista de actividades de un proyecto
 Entradas: el codigo del proyecto
 Salidas: no tiene salidas
 Objetivo: Mostrar en pantalla la lista de actividades de un proyecto
 */
void consultarActividadPro(int codigoProyecto){
    Actividad *auxAct= (Actividad*)malloc(sizeof(Actividad));
    auxAct=cabezaAct;
    while(auxAct != NULL){
        if(auxAct->codigoProyecto==codigoProyecto){
            printf("\nEl codigo de la actividad es: %d\n",auxAct->codigoActividad);
            printf("La descripcion de la actividad es: %s\n",auxAct->descripcion);
            printf("El avance de la actividad es: %d\n",auxAct->avance);
        }
        auxAct=auxAct->sig;
    }
}

/*
 Metodo para consultar los datos de un proyecto en especifico
 Entradas: no tiene entradas
 Salidas: no tiene salidas
 Objetivo: mostrar en pantalla los datos de un proyecto
 */
void consultarProyecto(){
    if(cantidadPro>0){
        int buscaProyecto;
        printf("Indique el codigo del proyecto que desea consultar\n");
        scanf("%d",&buscaProyecto);
        Proyecto *auxPro=(Proyecto*)malloc(sizeof(Proyecto));
        auxPro=cabezaPro;
        while(auxPro != NULL){
            if(auxPro->codigoProyecto==buscaProyecto){
                printf("El nombre del proyecto: %s\n",auxPro->nombre);
                printf("El codigo del proyecto es: %d\n",auxPro->codigoProyecto);
                printf("El anio de inicio del proyecto es: %d\n",auxPro->anioInicio);
                printf("El anio de fin del proyecto es: %d\n",auxPro->anioFin);
            }
            auxPro=auxPro->sig;
        }
        consultarEmpleadoPro(buscaProyecto);
        consultarActividadPro(buscaProyecto);
    }
    else{
        printf("No existen proyectos por el momento\n");
    }
}

/*
 Metodo para consultar la informacion de un empleado
 Entradas: no tiene entradas
 Salidas: no tiene salidas
 Objetivo: mostrar en pantalla los datos de un empleado
 */
void consultarEmpleado(){
    if(cantidadEmp>0){
        Empleado *auxEmp=(Empleado*)malloc(sizeof(Empleado));
		auxEmp=cabezaEmp;
        int codigoEmpleado;
        printf("Indique el codigo de empleado que desea consultar\n");
        scanf("%d",&codigoEmpleado);
        while(auxEmp != NULL){
            if(auxEmp->codigoEmpleado==codigoEmpleado){
                printf("\nNombre de empleado: %s\n",auxEmp->nombre);
                printf("Apellido de empleado: %s\n",auxEmp->apellido);
                printf("Departamento de empleado: %s\n",auxEmp->departamento);
                printf("Codigo del proyecto: %d\n",auxEmp->codigoProyecto);
            }
            auxEmp=auxEmp->sig;
        }
    }
    else{
        printf("No existen empleados para consultar\n");
    }
}


/*
 Metodo main para inicializar el programa
 Entradas: no tiene entradas
 Salidas: no tiene salidas
 Objetivo: ejecutar el programa
 */
int main() {
    int opcion,estado=1;
    while(estado==1){
        printf("\nSelecciones alguna de las opciones\n");
        printf("1 para agregar\n2 para modificar actividad\n3 para consultar proyecto\n4 para consultar empleado\n5 para salir\n");
        scanf("%d",&opcion);
        switch(opcion){
            case 1: agregar();
                    break;
            case 2: modificarActividad(cabezaAct);
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















