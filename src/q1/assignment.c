#include <stdio.h>

int main(int arg, char* argc[])
{
    //declaing different variable types
    int integer1;
    int* integerPointer;
    long longInteger;
    double* doublePointer;
    char** characterDPointer;
    
    //finding the different byte sizes using sizeof
    printf("Size of int: %ldß bytes\n",sizeof(integer1));
    printf("Size of int*: %ld bytes\n",sizeof(integerPointer));
    printf("Size of long: %ld bytes\n",sizeof(longInteger));
    printf("Size of double*: %ld bytes\n",sizeof(doublePointer));
    printf("Size of char**: %ld bytes\n",sizeof(characterDPointer));
}
