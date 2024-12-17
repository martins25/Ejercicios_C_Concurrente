#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

void main(void){
    int tamano;

    printf("Introduce el tamaño de la matriz:\t");
    scanf("%d", &tamano);

    int matriz[tamano][tamano], matriz2[tamano][tamano], resultado[tamano][tamano];

    for(int i=0; i<tamano;i++){
        for(int j=0; j<tamano;j++){
            matriz[i][j]= rand() % 10;
            matriz2[i][j]= rand() % 10;
        }
    }

    for (int  i = 0; i < tamano; i++){
        for (int j = 0; j < tamano; j++){
            resultado[i][j] =0;
            for (int k = 0; k < tamano; k++){
                resultado[i][j]+= matriz[i][k]*matriz2[k][j];
            }
        }
    }

    for (int i = 0; i < tamano; i++){
            printf("\n");
        for (int j = 0; j < tamano; j++){
            printf("%d\t", matriz[i][j]);            
        }
    }
    printf("\n\n");


    for (int i = 0; i < tamano; i++){
            printf("\n");
        for (int j = 0; j < tamano; j++){
            printf("%d\t", matriz2[i][j]);            
        }
    }
    printf("\n\n");


    for (int i = 0; i < tamano; i++){
            printf("\n");
        for (int j = 0; j < tamano; j++){
            printf("%d\t", resultado[i][j]);            
        }
    }
    printf("\n\n");

}