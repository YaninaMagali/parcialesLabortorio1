#ifndef PEDIRDATOS_H_INCLUDED
#define PEDIRDATOS_H_INCLUDED
int pedirEntero(char mensaje[]);
void obtenerCadena(char msj[], char mensajeError[], char cadena[], int TAMANIO_CADENA);
int validarSiEsChar(char cadena[]);
char obtenerUnCaracter(char mensaje[]);
char remmplazarSaltoPorEspacio(char string[]);
int confirmarAccionUsuario(void);
float pedirNumeroFlotante(char mensaje[]);
int generarId(int ultimoId);
void formatearNombrePropio(char cadena[]);
float calcularPromedio(float valorUno, float ValorDos);

#endif // PEDIRDATOS_H_INCLUDED
