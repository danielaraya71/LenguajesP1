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
    char codigoProyecto[5];
    struct nodoAct* sig;
}Actividad;

Actividad *cabezaAct= NULL;

//Se utilizan estos contadores para establecer los codigos respectivos
int cantidadEmp=0;
int cantidadPro=1;
int cantidadAct=0;


/*
 Metodo para registrar un nuevo empleado
 Entradas: no tiene entradas
 Salidas: no tiene salidas
 Objetivo: agregar a nodo a estructura empleado*/
void agregarEmpleado(){
    Empleado* nuevo=(Empleado*)malloc(sizeof(nuevo));
    printf("Digite su nombre\n");
    scanf("%s",&nuevo->nombre);
    printf("Digite su apellido\n");
    scanf("%s",&nuevo->apellido);
    printf("Digite su departamento\n");
    scanf("%s",&nuevo->departamento);
    
    nuevo->codigoEmpleado=cantidadEmp;
    nuevo->codigoProyecto=0;
    printf("Codigo de empleado es: %d",nuevo->codigoEmpleado);
    
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
    Proyecto *nodo= cabezaPro;
    while(nodo != NULL){
        printf("%s\n",nodo->nombre);
        printf("%d\n",nodo->anioFin);
        nodo=nodo->sig;
    }
}

/*
 Metodo para registrar un nuevo proyecto
 Entradas: no tiene entradas
 Salidas: no tiene salidas
 Objetivo: agregar un nuevo nodo a la estructura proyecto*/
void agregarProyecto(){
    //Se verifica que existan al menos 2 empleados registrados
    if(cantidadEmp>=2){
    //Se crear un nuevo nodo para el proyecto y para el empleado, y se introducen los datos del proyecto, exceptuando la lista de empleados y actividades
        Proyecto *proyecto=(Proyecto*)malloc(sizeof(proyecto));
        Empleado *nodoEmpleado=(Empleado*)malloc(sizeof(nodoEmpleado));
        printf("Ingrese el nombre del proyecto\n");
        scanf("%s",&proyecto->nombre);
        proyecto->codigoProyecto=cantidadPro;
        printf("Ingrese el anio de inicio del proyecto\n");
        scanf("%d",&proyecto->anioInicio);
        printf("Ingrese el anio de fin del proyecto\n");
        scanf("%d",&proyecto->anioFin);
        if(proyecto->anioInicio<proyecto->anioFin){
            
            int cantEmpleados=0;
            int verificador=0;
            while(verificador==0){
                Empleado *auxEmpleado= cabezaEmp;
                char nombre[50]; 
                printf("Ingrese el nombre del empleado\n");
                scanf("%s",&nombre);
                while(auxEmpleado != NULL){
                    
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
                            nodoEmpleado->sig=cabezaEmp;
                            cabezaEmp=nodoEmpleado;
                        }
                        printf("Empleado agregado con exito\n");
                       
                    }
                    auxEmpleado=auxEmpleado->sig;
                }
                printf("Digite 0 si desea ingresar mas empleados\n");
                scanf("%d",&verificador);
            }
            if(cantEmpleados>=2){
                if(cabezaPro==NULL){
                    cabezaPro=proyecto;
                    cabezaPro->sig=NULL;
                }
                else{
                    proyecto->sig=cabezaPro;
                    cabezaPro=proyecto;
                }
                printf("Proyecto agregado con exito\n");
                cantidadPro++;
                printf("El ano inicio es %d\n",cabezaPro->anioInicio);
                printf("El codigo del proyecto es: %d\n",cabezaPro->codigoProyecto);
                printf("El ano inicio es %d\n",cabezaPro->anioInicio);
                printf("El ano fin es %d\n",cabezaPro->anioFin);
            }
            else{
                printf("El proyecto no cuenta con los suficientes empleados\n");
            }
        }
        else{
            printf("No es posible que fecha de inicio sea mayor a fecha de fin\n");
        }
    }
    else{
        printf("No es posible crear un proyecto, ya que no existen los suficientes empleados\n");
    }
}

/*
 Metodo para registrar una actividad en un proyecto
 Entradas: no tiene entradas
 Salidas: no tiene salidas
 Objetivo: agregar un nodo en la estructura actividad*/
void agregarActividad(){
    if(cantidadPro>0){
        Actividad *nodoAct=(Actividad*)malloc(sizeof(nodoAct));
        printf("Digite el codigo del proyecto al que pertenece la actividad\n");
        scanf("%s",&nodoAct->codigoProyecto);
        printf("Digite el nombre o descripcion de la actividad\n");
        scanf("%s",&nodoAct->descripcion);
        nodoAct->avance=0;
        int actividadesProyecto=1;
        Actividad *auxAct= cabezaAct;
        while(auxAct != NULL){
            if(auxAct->codigoProyecto==nodoAct->codigoProyecto){
                actividadesProyecto++;
            }
            auxAct=auxAct->sig;
        }
        nodoAct->codigoActividad=actividadesProyecto;
        
        if(cabezaAct==NULL){
            cabezaAct=nodoAct;
            cabezaAct->sig=NULL;
        }
        else{
            nodoAct->sig=cabezaAct;
            cabezaAct=nodoAct;
        }
        printf("Actividad agregada con exito\n");
        printf("El codigo de la actividad es: %d\n",cabezaAct->codigoActividad);
        cantidadAct++;
    }
    else{
        printf("No existen proyectos por el momento\n");
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
 Metodo para modificar una actividad
 Entradas: no tiene entradas
 Salidas: no tiene salidas
 Objetivo: modificar el atributo avance en un nodo de la estructura actividad
 */
void modificarActividad(){
    if(cantidadAct>0){
        char codigoPro[5],codigoAct[5];
        printf("Digite el codigo del proyecto al que desea acceder\n");
        scanf("%s",&codigoPro);
        printf("Digite el codigo de la activdad que desea modificar\n");
        scanf("%s",&codigoAct);
        Actividad *auxAct=(Actividad*)malloc(sizeof(Actividad));
        auxAct=cabezaAct;
        while(auxAct != NULL){
            if(strcmp(auxAct->codigoProyecto,codigoPro)){
                if(strcmp(auxAct->codigoActividad,codigoAct)){
                    printf("Digite el avance que lleva la actividad\n");
                    scanf("%s",&auxAct->avance);
                    printf("Avance actualizado con exito\n");
                }
            }
            auxAct=auxAct->sig;
        }
    }
}

/*
 Metodo que consulta todos los empleados de un proyecto
 Entradas: el codigo del proyecto
 Salidas: no tiene salidas
 Objetivo: mostrar en pantalla la lista de empleados de un proyecto
 */
void consultarEmpleadoPro(int codigoProyecto){
    Empleado *auxEmp=cabezaEmp;
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
    Actividad *auxAct=cabezaAct;
    while(auxAct != NULL){
        if(auxAct->codigoProyecto==codigoProyecto){
            printf("\nEl codigo de la actividad es: %d\n",auxAct->codigoActividad);
            printf("La descripcion de la actividad es: %s\n",auxAct->descripcion);
            printf("El avance de la actividad es: %%d\n",auxAct->avance);
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
        Proyecto *auxPro=cabezaPro;
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
        Empleado *auxEmp=cabezaEmp;
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

void cargarDatos(){
    int contador=0;
    int leerArch,i;
    char temp[200];
    char cambioLinea;
    
    FILE *f;
    f=fopen("empleados.txt","r");
    if(f==NULL){
        printf("No se pudo abrir el archivo\n");
        exit(1);
    }
    while(!feof(f)){
        fgets(temp,200,f);
        contador++;
    }
    
    rewind(f);
    
    Empleado *nodoEmp=(Empleado*)malloc(contador*sizeof(Empleado));
    
    printf("hola");
    for(leerArch=0;!feof(f);leerArch++){
        cambioLinea="";
        for(i=0;cambioLinea!=",";i++){
            cambioLinea=fgetc(f);
            if(cambioLinea!=","){
                temp[i]=cambioLinea;
            }
        }
        strcpy(nodoEmp->nombre,temp);
        
        for(i=0;cambioLinea!=",";i++){
            cambioLinea=fgetc(f);
            if(cambioLinea!=","){
                temp[i]=cambioLinea;
            }
        }
        strcpy(nodoEmp->apellido,temp);
    }
}

/*
 Metodo main para inicializar el programa
 Entradas: no tiene entradas
 Salidas: no tiene salidas
 Objetivo: ejecutar el programa
 */
int main() {
    cargarDatos();
    int opcion,estado=1;
    while(estado==1){
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








