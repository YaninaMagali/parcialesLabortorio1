#ifndef GETDATABASE_H_INCLUDED
#define GETDATABASE_H_INCLUDED
int getString(char* pChar, int stringSize, char message[], char errorMessage[], int attempts);
int getInt(int* pNumber, char message[], char errorMessage[], int min, int max, int attempts);
int getNumber(char* pNumber, int pNumberSize, char message[], char errorMessage[], int attempts);
char remmplazarSaltoPorEspacio(char* string);
int getBase(char* string, int stringSize);
#endif // GETDATABASE_H_INCLUDED
