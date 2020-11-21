#ifndef PARTICIPANTES_H_INCLUDED
#define PARTICIPANTES_H_INCLUDED
typedef struct
{
int numeroConcursante;
int anioNacimiento;
char nombre[50];
char dni[13];
char fechaPresentacion[15];
char temaPresentacion [30];
int puntajePrimeraRonda;
int puntajeSegundaRonda;
float promedio;
}eParticipante;

eParticipante* new();
eParticipante* newParameters(char* AuxnumeroConcursante, char* AuxanioNacimiento, char* Auxnombre, char* Auxdni, char*  AuxfechaPresentacion, char*  AuxtemaPresentacion,char* AuxpuntajePrimeraRonda);
int generarNumeroRandom();

int loadFromText(char* path, LinkedList* pArrayList);
int ListarParticipantes(LinkedList* pArrayList);

int getNombre(eParticipante* this, char* nombre);
int getDNI(eParticipante* this, char* dni);
int getFechaPresentacion(eParticipante* this, char* fecha);
int getTemaPresentacion(eParticipante* this, char* tema);
int getnumeroConcursante(eParticipante* this,int* numero);
int getAnioNacimiento(eParticipante* this,int* anio);
int getPuntajeUno(eParticipante* this,int* puntos);
int getPuntajeDos(eParticipante* this,int* puntos);
int getPromedio(eParticipante* this,float* promedio);

int setNumeroConcursante(eParticipante* this, char* numero);
int setAnioNacimiento(eParticipante* this, char* anio);
int setNombre(eParticipante* this, char* nombre);
int setDNI(eParticipante* this, char* dni);
int setFechaPresentacion(eParticipante* this, char* fecha);
int setTemaPresentacion(eParticipante* this, char* tema);
int setPuntajePrimeraRonda(eParticipante* this, char* puntos);
int setPuntajeSegundaRonda(eParticipante* this, int puntos);
int setPromedio(eParticipante* this, float promedio);

int asignarSegundoPuntajeRandom(void* pParticipante);
int generarNumeroRandom();
int calcularPromedio(void* pParticipante);


#endif // PARTICIPANTES_H_INCLUDED
