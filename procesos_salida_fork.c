#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

int main(void){
    pid_t pid;
    system("echo > salidaEjercicioTres.txt");
    
    pid=fork();
    
    if(pid == -1){
        printf("No se ha podido crear el proceso hijo...");
        exit(-1);
    }else if(pid==0){
        //Proceso hijo
        system("ls /run >> salidaEjercicioTres.txt");   
    }else{
        //Proceso padre
        system("ls /home/adrian/Escritorio >> salidaEjercicioTres.txt");
    }
}
