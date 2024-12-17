#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

void main(void){
    pid_t pid;
    int valor = 10;
    char[] error = "Hubo un error inesperado al crear el fork";

    pid = fork();

    if(pid == -1){
        printf("%s\n", error);

    }else if(pid == 0){
        //Estamos en el "hijo"
        pid = fork();
        
        if(pid == -1){
            printf("%s\n", error);
        }else if(pid == 0){
            //Estamos en el nieto
            valor-2;
            printf("El valor del nieto es: %d\n", valor);
        }else{
            //Estamos en el hijo (padre del nieto)
            valor-2;
            printf("El valor del hijo es: %d\n", valor);
        }
    }else{
        //Estamos en el padre
        valor-2;
        printf("El valor del padre es: %d\n", valor);
    }
}