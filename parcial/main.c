#include <stdio.h>
#include <stdlib.h>
#include "lib.h"
#define OCUPADO 0
#define LIBRE 1
#define TAMPROP 20
#define TAMAUT 20

int main()
{
    ePropietario listaPropietario[TAMPROP];
    eProp_init(listaPropietario,TAMPROP);
    eAuto listaAutos[TAMAUT];
    eAuto_init(listaAutos,TAMAUT);
    int aux=0;
    int opcion=0;
    while(opcion!=9)
    {
        printf("\n    MENU\n1-ALTA DE PROPIETARIO\n2-MODIFICAR PROPIETARIO\n3-BAJA PROPIETARIO\n4-MOSTRAR LISTADO DE PROPIETARIOS\n5-INGRESO AUTOMOVIL\n6-MOSTRAR LISTADO AUTOMOVILES\n7-EGRESAR AUTOMOVIL\n");
        fflush(stdin);
        scanf("%d",&opcion);
        switch(opcion)
        {
        case 1:
            system("cls");
            aux=ePropietario_alta(listaPropietario,TAMPROP);
            if(aux==-2)
            {
                printf("\nNo hay lugar libre para realizar esta operacion, por favor contacte a su administrador de sistemas.\n");
            }
            system("cls");
            break;
        case 2:
            eProp_modificacion(listaPropietario,TAMPROP);
             break;
        case 3:
            eProp_baja(listaPropietario,TAMPROP,listaAutos,TAMAUT);
             break;
        case 4:
            eProp_mostrarListado(listaPropietario,TAMPROP);
            system("pause");
            break;
        case 5:
            eAuto_alta(listaAutos,TAMAUT,listaPropietario,TAMPROP);
            break;
        case 6:
            eAuto_mostrarListado(listaAutos,TAMAUT,listaPropietario,TAMPROP);
            break;
        case 7:
            eAuto_baja(listaAutos,TAMAUT,listaPropietario,TAMPROP);
            break;

        }

    }
}
