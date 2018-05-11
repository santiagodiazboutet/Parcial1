#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lib.h"
#define OCUPADO 0
#define LIBRE 1
#define ALPHA_ROMEO	150
#define FERRARI 	175
#define AUDI	    200
#define OTROS	    250


int eProp_init( ePropietario listado[],int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && listado != NULL)
    {
        retorno = 0;
        for(i=0; i<limite; i++)
        {
            listado[i].estado= LIBRE;
            listado[i].id= 0;

        }
            strcpy(listado[0].nombre,"Juan");

            strcpy(listado[0].tarjeta,"111-111");
            strcpy(listado[0].direccion,"mitre");
            listado[0].estado=OCUPADO;
            listado[0].id=1;
            strcpy(listado[1].nombre,"Luis");
            strcpy(listado[1].tarjeta,"222-222");
            strcpy(listado[1].direccion,"urquiza");
            listado[1].estado=OCUPADO;
            listado[1].id=2;
            strcpy(listado[2].nombre,"Maria");
            strcpy(listado[2].tarjeta,"333-333");
            strcpy(listado[2].direccion,"belgrano");
            listado[2].estado=OCUPADO;
            listado[2].id=3;
            strcpy(listado[3].nombre,"Jose");
            strcpy(listado[3].tarjeta,"444-444");
            strcpy(listado[3].direccion,"alsina");
            listado[3].estado=OCUPADO;
            listado[3].id=4;
    }
    return retorno;
}

int ePropietario_buscarLugarLibre(ePropietario listado[],int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && listado != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(listado[i].estado == LIBRE)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

int ePropietario_siguienteId(ePropietario listado[],int limite)
{
    int retorno = 0;
    int i;
    if(limite > 0 && listado != NULL)
    {
        for(i=0; i<limite; i++)
        {
            if(listado[i].estado == OCUPADO)
            {
                    if(listado[i].id>retorno)
                    {
                         retorno=listado[i].id;
                    }

            }
        }
    }

    return retorno+1;
}
int ePropietario_alta(ePropietario  listado[],int limite)
{
    int retorno = -1;
    char nombre[20];
    char tarjeta[20];
    char direccion[20];
    int id;
    int indice;
    if(limite > 0 && listado != NULL)
    {
        retorno = -2;
        indice = ePropietario_buscarLugarLibre(listado,limite);
        if(indice >= 0)
        {
                id = ePropietario_siguienteId(listado,limite);
                retorno = 0;
                system("cls");
                printf("\nIngrese el nombre del propietario.\n");
                fflush(stdin);
                gets(nombre);
                printf("\nIngrese la direccion.\n");
                fflush(stdin);
                gets(direccion);
                printf("\nIngrese la tarjeta de credito.\n");
                fflush(stdin);
                gets(tarjeta);
                strcpy(listado[indice].nombre, nombre);
                strcpy(listado[indice].direccion, direccion);
                strcpy(listado[indice].tarjeta, tarjeta);
                listado[indice].id = id;
                listado[indice].estado = OCUPADO;

        }
    }
    return retorno;
}

int eProp_modificacion(ePropietario listado[] ,int limite)
{   int id;
    int i;
    int opcion=1;
    int aux=0;
    char aux1[20];
    while(opcion!=5)
    {
        eProp_mostrarListado(listado,limite);
        printf("\nIngrese id del componente a modificar. Ingrese 0 para salir:\n");
        scanf("%d",&id);
        if(id==0)
        {
            break;
        }
        i=eProp_buscarPorId(listado,limite,id);
        if(i==-2||i==-3)
        {
            printf("\nEl numero ingresado no pertenece a un Id en funcionamiento");
        }
        else
        {
            while(opcion!=4)
            {
                printf("\nEl usuario a modificar es: %s,Nro. Tarjeta:%s. Direccion:%s.",listado[i].nombre,listado[i].tarjeta, listado[i].direccion);
                printf("\nIngrese el nuevo numero de tarjeta.\n");
                fflush(stdin);
                gets(aux1);
                printf("El nuevo numero de tarjeta es:%s. Esta seguro de que desea modificarlo?\n1-SI\n2-NO",aux);
                scanf("%d",&aux);
                if(aux==1)
                {
                strcpy(listado[i].tarjeta, aux1);
                opcion=4;
                }
                else if(aux==2)
                {
                     printf("Desea ingresar otro numero?\n1-SI\n2-SALIR");
                     scanf("%d",&aux);
                     if(aux==1)
                     {
                        system("cls");
                     }
                     else if(aux==2)
                     {
                         opcion=4;
                     }
                    else
                {
                     printf("Por favor, Ingrese una opcion valida");
                }
                }else
                {
                     printf("Por favor, Ingrese una opcion valida");
                }


            }
        }
    }
    return i;
}

int eProp_baja(ePropietario listado[] ,int limite,eAuto autos[],int limiteAuto)
{   int id;
    int i;
    int j;
    int opcion=1;
    int aux=0;
    int aux2=0;
    float precio;
    float total;
    while(opcion!=0)
    {
        eProp_mostrarListado(listado,limite);
        printf("\nIngrese id del componente a modificar\n");
        scanf("%d",&id);
        i=eProp_buscarPorId(listado,limite,id);
        if(i==-2||i==-3)
        {
            printf("\nEl numero ingresado no pertenece a un Id en funcionamiento\n");
        }
        else
        {   while (opcion!=0)
            {

            printf("Esta seguro que desea dar de baja a %s.\n1-SI 2-NO",listado[i].nombre);
            scanf("%d",&aux);
            if(aux ==1)
                {
                    listado[i].estado=LIBRE;
                    opcion=0;
                    for(j=0;j<limiteAuto;j++)
                    {
                        aux2=eAuto_buscarPorIdProp(autos[j],limiteAuto,listado[i].id);
                        precio=0;
                        if (aux2!=-1)
                        {
                        eAuto_mostrarUno(autos[aux2]);
                        precio=eAuto_mostrarMarcayPrecio(autos[aux2]);
                        total=total+precio;
                        }

                    }
                    printf("El Propietario debe: $%.2f",total);

                }
            else if(aux==2)
            {
                opcion=0;
            }
            else
                {
                printf("Por favor ingrese una opcion valida");
            }
            }
        }
    }
    return i;
}


void eProp_mostrarUno(ePropietario parametro)
{
     printf("%s id: %d- Nro Tarjeta:%s -Domicilio: %s \n",parametro.nombre,parametro.id,parametro.tarjeta,parametro.direccion);

}
void eProp_mostrarNombre(ePropietario parametro)
{
     printf("-Propietario:%s \n",parametro.nombre);

}
int eProp_mostrarListado(ePropietario listado[],int limite)
{
    int retorno = -1;
    int i;

    if(limite > 0 && listado != NULL)
    {
        retorno = 0;
        for(i=0; i<limite; i++)
        {
            if(listado[i].estado==OCUPADO)
            {

                eProp_mostrarUno(listado[i]);
            }
        }
    }
    return retorno;
}

int eProp_buscarPorId(ePropietario listado[] ,int limite, int id)
{
    int retorno = -1;
    int i;
    if(limite > 0 && listado != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(listado[i].estado == OCUPADO && listado[i].id == id)
            {
                retorno = i;

                break;
            }
        }
    }
    return retorno;
}
int eAuto_init( eAuto listado[],int limite)
{
    int retorno = -1;
    int i;
    int id[]= {1,2,3,4,5,6,7,8,9,10};
    char patente[][20]= {"AAA","CCC","DDD","BBB","ZZZ","III","HHH","EEE","FFF","GGG"};
    int marca[]= {1,3,3,2,2,3,3,4,3,1};
    int propietario[]= {2,1,2,1,3,3,4,1,4,3};

    if(limite > 0 && listado != NULL)
    {
        retorno = 0;
        for(i=0; i<limite; i++)
        {
            listado[i].estado= LIBRE;
            listado[i].id= 0;

        }

        for (i=0;i<10;i++)
        {
            strcpy(listado[i].patente,patente[i]);
            listado[i].marca=marca[i];
            listado[i].idProp=propietario[i];
            listado[i].id=id[i];
            listado[i].estado=OCUPADO;
        }


    }
    return retorno;
}

int eAuto_buscarLugarLibre(eAuto listado[],int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && listado != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(listado[i].estado == LIBRE)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

int eAuto_siguienteId(eAuto listado[],int limite)
{
    int retorno = 0;
    int i;
    if(limite > 0 && listado != NULL)
    {
        for(i=0; i<limite; i++)
        {
            if(listado[i].estado == OCUPADO)
            {
                    if(listado[i].id>retorno)
                    {
                         retorno=listado[i].id;
                    }

            }
        }
    }

    return retorno+1;
}
int eAuto_alta(eAuto  listado[],int limite, ePropietario propietario[],int limiteProp)
{
    int retorno = -1;
    char patente[20];
    int marca;
    int idProp;
    int id;
    int indice;
    int j=-1;
    if(limite > 0 && listado != NULL)
    {
       while(j<0){

        eProp_mostrarListado(propietario,limiteProp);
        printf ("\nIngrese el id del propietario del auto.\n");
        scanf("%d",&idProp);
        j=eProp_buscarPorId(propietario,limiteProp,idProp);
        if(j<0)
        {
            printf("Por favor ingrese un id de propietario valido");
        }else
        {

        retorno = -2;
        indice = eAuto_buscarLugarLibre(listado,limite);
        if(indice >= 0)
        {
                listado[indice].idProp=idProp;
                id = eAuto_siguienteId(listado,limite);
                retorno = 0;
                system("cls");
                printf("\nIngrese el numero de patente.\n");
                fflush(stdin);
                gets(patente);
                printf("\nIngrese la marca del auto.\n1-ALPHA ROMEO\n2-FERRARI\n3-AUDI\n4.OTRO\n");
                scanf("%d",&marca);
                strcpy(listado[indice].patente, patente);
                listado[indice].marca=marca;
                listado[indice].id = id;
                listado[indice].estado = OCUPADO;
        }
        }
       }
       }


    return retorno;
}
int eAuto_buscarPorId(eAuto listado[] ,int limite, int id)
{
    int retorno = -1;
    int i;
    if(limite > 0 && listado != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(listado[i].estado == OCUPADO && listado[i].id == id)
            {
                retorno = i;

                break;
            }
        }
    }
    return retorno;
}
int eAuto_buscarPorIdProp(eAuto listado ,int limite, int id)
{
    int retorno = -1;
    int i;
         if(listado.estado == OCUPADO && listado.idProp == id)
            {
                retorno = i;
            }

    return retorno;
}

int eAuto_mostrarListado(eAuto listado[],int limite,ePropietario propietario[],int limiteProp)
{
    int retorno = -1;
    int i;
    int j;
    if(limite > 0 && listado != NULL)
    {
        retorno = 0;
        for(i=0; i<limite; i++)
        {
            if(listado[i].estado==OCUPADO)
            {
                j=eProp_buscarPorId(propietario,limiteProp,listado[i].idProp);
                eAuto_mostrarUno(listado[i]);
                eAuto_mostrarMarca(listado[i]);
                eProp_mostrarNombre(propietario[j]);


            }
        }
    }
    return retorno;
}
void eAuto_mostrarUno(eAuto parametro)
{
     printf("\n id:%d -Patente:%s ",parametro.id,parametro.patente);

}
void eAuto_mostrarMarca(eAuto parametro)
{
    if (parametro.marca==1)
    {
        printf("-marca: %s ","ALPHA ROMEO");
    }
     else if(parametro.marca==2)
     {
         printf("-marca: %s ","FERRARI");
     }else if(parametro.marca==3)
     {
         printf("-marca: %s ","AUDI");
     }
     else
     {
         printf("-marca: OTRO ");
     }

}
int eAuto_baja(eAuto listado[] ,int limite,ePropietario propietario[], int limiteProp)
{   int id;
    int i;
    int j;
    int opcion=1;
    int aux=0;
    while(opcion!=0)
    {
        eAuto_mostrarListado(listado,limite,propietario,limiteProp);
        printf("\nIngrese id del componente a egresar\n");
        scanf("%d",&id);
        i=eAuto_buscarPorId(listado,limite,id);
        if(i==-2||i==-3)
        {
            printf("\nEl numero ingresado no pertenece a un Id en funcionamiento\n");
        }
        else
        {   while (opcion!=0)
            {

            printf("Esta seguro que desea dar de egresar a auto patente %s.\n1-SI 2-NO",listado[i].patente);
            scanf("%d",&aux);
            if(aux ==1)
                {

                    listado[i].estado=LIBRE;
                    opcion=0;
                    j=eProp_buscarPorId(propietario,limiteProp,listado[i].idProp);
                    eProp_mostrarNombre(propietario[j]);
                    eAuto_mostrarUno(listado[i]);
                    eAuto_mostrarMarcayPrecio(listado[i]);
                    system("pause");

                }
            else if(opcion==0)
            {
                opcion=0;
            }
            else
                {
                printf("Por favor ingrese una opcion valida");
            }
            }
        }
    }
    return i;
}
float eAuto_mostrarMarcayPrecio(eAuto parametro)
{   float precio;
    int horas=devolverHorasEstadia();
    if (parametro.marca==1)
    {   precio=(float)horas*ALPHA_ROMEO;
        printf("-marca: %s- precio: %.2f\n","ALPHA ROMEO",precio);
    }
     else if(parametro.marca==2)
     {     precio=(float)horas*FERRARI;
         printf("-marca: %s- precio: $%.2f\n","FERRARI",precio);
     }else if(parametro.marca==3)
     {
         precio=(float)horas*AUDI;
         printf("-marca: %s- precio: $%.2f\n","AUDI",precio);
     }
     else
     {   precio=(float)horas*OTROS;
         printf("-marca: OTRO- precio: $%.2f\n",precio);
     }
return precio;
}



int devolverHorasEstadia()
{
    int horas;

    srand(time(NULL));

    horas = (rand()%24)+1;

    return horas ;

}
