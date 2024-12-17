#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

void main(void){
    pid_t pid;
    int valor;

    pid = fork();
    int pipefd[2];
    pipe(pipe)


    if(pid == -1) {
        //No se hizo bien el fork
        printf("Hubo un problema con el fork");

    }else if(pid == 0){
        //Estamos en el proceso 2
        printf("Soy el proceso 2, mi PID es: %d y el pid de mi padre es:%d\n",  getpid(), getppid());

        close[pipefd[1]];
        valor=5;
        read(pipefd[0],valor, sizeof(valor));

        pid = fork();
        
        if(pid==-1){
            printf("Hubo un problema con el fork");
        }else if(pid==0){
            //Este es el proceso 5
            printf("Soy el proceso 5, mi PID es: %d y el pid de mi padre es:%d\n", getpid(), getppid());

            close[pipefd[0]];
            valor=1;
            read(pipefd[1],valor, sizeof(valor));

        }else{
            //Este es el proceso 2
            
            close[pipefd[0]];
            valor=5;
            read(pipefd[1],valor, sizeof(valor));

            pid=fork();

            if(pid==-1){
                printf("Hubo un problema con el fork");
            }else if(pid==0){
                //Estamos en el proceso 6
                printf("Soy el proceso 6,mi PID es: %d y el pid de mi padre es:%d\n",  getpid(), getppid());
            }else{
                //Estamos en el proceso 2
                pid=fork();

                if(pid==-1){
                    printf("Hubo un problema con el fork");
                }else if(pid==0){
                    //Estamos en el proceso 7
                    printf("Soy el proceso 7, mi PID es: %d y el pid de mi padre es:%d\n",  getpid(), getppid());
                }else{
                    //Proceso 2
                }

            }

        }

    }else{
        //Estamos en el proceso 1
        printf("Soy el proceso 1, mi PID es: %d y el pid de mi padre es:%d\n",  getpid(), getppid());

        close[pipefd[0]];
        valor=5;
        read(pipefd[1],valor, sizeof(valor));

        pid=fork();

        if(pid==-1){
            printf("Hubo un problema con el fork");
        }else if(pid==0){
            //Proceso 3
            printf("Soy el proceso 3, mi PID es: %d y el pid de mi padre es:%d\n",  getpid(), getppid());
            close[pipefd[0]];
            valor=7;
            read(pipefd[1],valor, sizeof(valor));
        }else{
            //Proceso 1

            pid = fork();

            if(pid==-1){
                //Error
                printf("Hubo un problema con el fork");
            }else if(pid==0){
                //Proceso 4
                printf("Soy el proceso 4, mi PID es: %d y el pid de mi padre es:%d\n",  getpid(), getppid());
                close[pipefd[0]];
                valor=3;
                read(pipefd[1],valor, sizeof(valor));
                pid=fork();

                if(pid==-1){
                    //Error
                    printf("Hubo un error con el fork");
                }else if (pid==0){
                    //Proceso 8
                    close[pipefd[0]];
                    valor=3;
                    read(pipefd[1],valor, sizeof(valor));
                    printf("Soy el proceso 8, mi PID es: %d y el pid de mi padre es:%d\n",  getpid(), getppid());

                    pid=fork();

                    if(pid==-1){
                        //Error
                        printf("Hubo un problema con el fork");
                    }else if(pid==0){
                        //Proceso 9
                        printf("Soy el proceso 9, mi PID es: %d y el pid de mi padre es:%d\n",  getpid(), getppid());
                        close[pipefd[0]];
                        valor=9;
                        read(pipefd[1],valor, sizeof(valor));
                    }else{
                        //Proceso 4
                    }

                }else{
                    //Proceso 4
                }

            }else{
                //Proceso 1
            }
        }
    }
    while(wait(NULL)!=-1);

    printf("El proceso %d ha terminado\n ", getpid());
}