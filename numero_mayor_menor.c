#include <stdio.h>
void main(void)
{
	int numero; 

	printf("Introduce un numero: ");
	scanf("%d", &numero);

	if(numero==5){
		printf("El numero es igual a 5\n");
	}else if(numero>=5){
		printf("El numero introducido es mayor a 5\n");
	}else{
		printf("El numero introducido es menor que 5\n");
	}

}