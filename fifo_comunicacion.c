#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>


void main(void){
    
    int result = system("ls | grep FIFO");

    if(result == 0){
        system("rm FIFO");   
    }


    //Creacion de pid
    pid_t pid;

    //Escritura de FIFO
    int fp;
    char pr2[] = "5", pr3[] = "7",pr4[] = "3", pr5[] = "1", pr6[] = "8", pr7[] = "2", pr8[] = "3", pr9[] = "9";


    //Lectura de FIFO
    int bytesLeidos;
    char buffer[5] = "";

    //Creamos el FIFO con una tuberia
    if(mknod("FIFO", S_IFIFO | 0666, 0)==-1){
        printf("HA OCURRIDO UN ERROR...\n");
        exit(-1);
    }

    //Creamos el primer hijo
    pid = fork();


   if(pid == -1) {
        //No se hizo bien el fork
        printf("Hubo un problema con el fork");

    }else if(pid == 0){
        //Estamos en el proceso 2

        pid = fork();

        if(pid==-1){
            printf("Hubo un problema con el fork");
        }else if(pid==0){
            //Este es el proceso 5
            write(fp, pr5, strlen(pr5));

        }else{
            //Este es el proceso 2
            pid=fork();

            if(pid==-1){
                printf("Hubo un problema con el fork");
            }else if(pid==0){
                //Estamos en el proceso 6
                write(fp, pr6, strlen(pr6));
            }else{
                //Estamos en el proceso 2
                pid=fork();

                if(pid==-1){
                    printf("Hubo un problema con el fork");
                }else if(pid==0){
                    //Estamos en el proceso 7
                    write(fp, pr7, strlen(pr7));
                }else{
                    //Proceso 2
                    write(fp, pr2, strlen(pr2));
                }

            }

        }

    }else{        
        //Estamos en el proceso 1

        pid=fork();

        if(pid==-1){
            printf("Hubo un problema con el fork");
        }else if(pid==0){
            //Proceso 3
            write(fp, pr3, strlen(pr3));
        }else{
            //Proceso 1
           pid = fork();

            if(pid==-1){
                //Error
                printf("Hubo un problema con el fork");
            }else if(pid==0){
                //Proceso 4
                pid=fork();

                if(pid==-1){
                    //Error
                    printf("Hubo un error con el fork");
                }else if (pid==0){
                    //Proceso 8
                    write(fp, pr8, strlen(pr8));

                    pid=fork();

                    if(pid==-1){
                        //Error
                        printf("Hubo un problema con el fork");
                    }else if(pid==0){
                        //Proceso 9
                        write(fp, pr9, strlen(pr9));
                    }else{
                        //Proceso 4
                    }

                }else{
                    //Proceso 4
                    write(fp, pr4, strlen(pr4));
                }

            }else{
                //Proceso 1
                printf("Hola?");

                 
                int total;
                fp = open ("FIFO", 1);

                if (fp == -1){
                    printf("ERROR AL ABRIR EL FICHERO...");
                    exit(-1);
                } 
                
                printf("Hola entro");
                
                while(1){
                    printf("toy dentro");
                    fp = open("FIFO", 0);
 
                    
                    if(read(fp, buffer, sizeof(buffer))!=0){
                        total += atoi(buffer);
                        printf("entre");
                    }
/*
                    if(total == bandera){
                        
                        exit(0);
                    }   
  */                  printf("Total: %d",total);                 
                }
            }

        }
    }

    close(fp);
    while(wait(NULL)!=-1);
}