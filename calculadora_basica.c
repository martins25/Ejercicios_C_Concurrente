#include <stdio.h>
#include <stdbool.h>

float suma(float num1, float num2);
float resta(float num1, float num2);
float multiplicar(float num1, float num2);
float dividir(float num1, float num2);
void limpiar();
int menu();


int OPC1=1, OPC2=2,OPC3=3, OPC4=4, OPC5=5, CLS=45;
float  num1, num2;
bool salir=true;

void main(void){
	do{
		printf("\nIntroduzca el primer numero: \t");
		scanf("%f", &num1);
		printf("Introduzca el segundo numero: \t");
		scanf("%f", &num2);

		limpiar();	
		float resultado=0;
		
		switch(menu()){			
			case 1:
				resultado = suma(num1, num2);
				break;
			
			case 2:
				resultado=resta(num1, num2);
				break;

			case 3:
				resultado=multiplicar(num1, num2);
				break;
			
			case 4:
				resultado=dividir(num1, num2);
				break;
			case 5:
				salir=false;
				break;

			default:
				printf("El valor no esta disponible\n");
		}

		printf("El resultado de la operacion es: %f",resultado);

	}while(salir);



}

int menu(){
	int opc;

	limpiar();
	printf("Eliga una opcion:\n");
	printf("=================\n");
	printf("%d. Suma\n",OPC1);
	printf("%d. Resta\n",OPC2);
	printf("%d. Multiplicacion\n",OPC3);
	printf("%d. Division\n",OPC4);
	printf("%d. Salir\n",OPC5);
	scanf("%d", &opc);

	return opc;
}

void limpiar(){
	for(int i=0; i<CLS;i++){
		printf("\n");
	}
}

float suma(float num1, float num2){
	return num1+num2;
}

float resta(float num1, float num2){
	return num1-num2;
}

float multiplicar(float num1, float num2){
	return num1*num2;
}

float dividir(float num1, float num2){
	return num1/num2;
}