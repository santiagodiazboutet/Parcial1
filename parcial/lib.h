#ifndef LIB_H_INCLUDED
#define LIB_H_INCLUDED


typedef struct {
   int id;
   char nombre[50];
   char direccion[50];
   char tarjeta[50];
   int estado;
}ePropietario;
typedef struct {
   int id;
   char patente[8];
   char direccion[50];
   int marca;
   int idProp;
   int estado;
}eAuto;

int eProp_init(ePropietario[],int limite);
int ePropietario_alta(ePropietario  listado[],int limite);
int ePropietario_siguienteId(ePropietario listado[],int limite);
int ePropietario_buscarLugarLibre(ePropietario listado[],int limite);
void eProp_mostrarUno(ePropietario parametro);
void eProp_mostrarNombre(ePropietario parametro);
int eProp_mostrarListado(ePropietario[] ,int limite);
int eProp_modificacion(ePropietario listado[] ,int limite);
int eProp_buscarPorId(ePropietario listado[] ,int limite, int id);
int eProp_baja(ePropietario listado[] ,int limite,eAuto [],int);

int eAuto_init(eAuto[],int limite);
int eAuto_alta(eAuto listado[],int limite, ePropietario[],int);
int eAuto_siguienteId(eAuto listado[],int limite);
int eAuto_buscarLugarLibre(eAuto listado[],int limite);
void eAuto_mostrarUno(eAuto parametro);
void eAuto_mostrarMarca(eAuto parametro);
int eAuto_mostrarListado(eAuto[] ,int, ePropietario [], int);
float eAuto_mostrarMarcayPrecio(eAuto parametro);
int devolverHorasEstadia();
int eAuto_baja(eAuto listado[] ,int limite,ePropietario propietario[], int limiteProp);
int eAuto_buscarPorId(eAuto listado[],int limite,int id);
int eAuto_buscarPorIdProp(eAuto listado,int limite,int id);
#endif // LIB_H_INCLUDED
