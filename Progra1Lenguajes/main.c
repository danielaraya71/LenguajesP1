
#include <stdio.h>
#include <stdlib.h>

void agregarEmpleado(){
    
}

void agregarProyecto(){
    
}

void agregarActividad(){
    
}
void agregar(){
    
}


int main(int argc, char** argv) {
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
                                longitud++;
                                break;
                //Si elige la opcion 2, se elimina el numero en tope y se le resta 1 a variable longitud
                case 2: eliminar();
                        break;
                case 3: 
                        break;
                case 4: imprimir();
                        break;
                case 5: top();
                        break;
                case 6:	estado=0;
                        break;
                default: printf("Utilice solo las opciones validas\n");
            }

    }
    printf("Ejecucion terminada\n");
    return 0;
}






