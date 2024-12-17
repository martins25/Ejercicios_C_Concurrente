#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>



//Este metodo se encarga de gestionar las señales en el proceso hijo (ping)
void ping (int signal){
    system("echo PING >> resultado.txt");
}

//Este metodo se encarga de gestionar las señales en el proceso del 2º hijo (pong)
void pong (int signal){
    system("echo PONG  >> resultado.txt");
}


void main(void){
    //Definimo las varibales

    int fd1[2];


    char pidPing[10], pidPong[10], buffer[10];

    //Creamos los pipes
    pipe (fd1);

    
    int pid_hijo,pid_hijo2 ;

    //Creamos el proceso hijo y guardamos en una variable el PID
    pid_hijo = fork();

    switch (pid_hijo){
        case -1:
            printf("Hubo un problema con la creacion del fork");
            exit(0);
            break;
        case 0:
            //Soy el proceso 1 (ping)
            signal (SIGUSR1, ping);

            read(fd1[0], buffer, sizeof(buffer));


            for(int i =0;10>i;i++){
                kill(atoi(buffer),SIGUSR1);
                snprintf(pidPing, 10, "%d", getpid());
                write(fd1[1],pidPing,sizeof(buffer));
                pause();
            }           
            break;

        default:
            //Soy el proceso 2 (pong)
            pid_hijo2=fork();

            switch (pid_hijo2){
            case -1:
                printf("Hubo un problema con la creacion del fork");
                break;

            case 0:
                
                signal (SIGUSR1, pong);
                snprintf(pidPong, 10, "%d", getpid());
                write(fd1[1],pidPong,sizeof(buffer));

                for(int i =0;10>i;i++){
                    read(fd1[0], buffer, sizeof(buffer));  
                    kill(atoi(buffer),SIGUSR1);  
                    pause();
                }
                break;
                        
            default:
                break;
            }
                    
        break;
    }
}