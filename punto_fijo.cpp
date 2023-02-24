#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cmath>
#include <math.h>
#include <conio.h>
#include <iomanip>

/*
Autor: Yelsyn Hernandez
Fecha: 22-02-2023
Descrip0cion: Aproxima una raiz de una funcion utilizando el metodo del punto fijo

*/
using namespace std;

float f(float x){
	//inciso 1
    //return pow(x,4) - (3 * pow(x,2)) - 3;

    //Inciso 2:
    float valor1 = x * x * x;
    float valor2 = 4 * pow(x,2);
    return valor1 + valor2 -10;
}

float g(float x){
	//inciso 1, transformacion 1
	//return pow(x,4) - (3 * pow(x,2)) - 3 + x; //No converge
	//Inciso 1, transformacion 2
	//return pow(( (3 * pow(x,2)) + 3 ),1/4); //Converge
	//Inciso 1, transformacion 3
	//return pow( (-pow(x,4)+3)/-3 ,1/2);

	//inciso 2, tranformación 1
	//return pow(x,3)+ (4 * pow(x,2)) + x -10; no converge
	//inciso 2, transformacion 2
	float valor = 10 - pow(x,3);

	return pow( (10 - pow(x,3) / 4)  ,1/2);
}

//Funcion que imprime la separacion entre columnas para mejorar el formato
void imprimir(int n,char c){
    for(int i = 0; i < n; i++){
    	printf("%c",c);
    }
}

void validar_negativo(float n){
	if(n < 0){
		imprimir(4,32);
	}
	else{
		imprimir(5, 32);
	}
}

int main(){
    float p0 = 0;
    float tp0 = 0;
    float TOL = 0;
    float error_abs = 0;
    float error_rel = 0;
    float p = 0;
    float FP = 0;
    int exp = 0;
    int IT = 0;
    int i = 1;
    bool exito = false;

    printf("M%ctodos num%cricos, Secci%cn A\n",130,130,162);
    printf("Yelsyn Hern%cndez\n", 160);
    printf("Carnet: 9490-17-969\n");

    printf("Ingrese p0: ");
    scanf("%f",&p0);

    printf("Ingrese tolerancia: 10^");
    scanf("%i",&exp);
    printf("Cantidad de iteraciones: ");
    scanf("%i",&IT);

    TOL = pow(10,exp);

    printf("\nCalculando con p0=%.1f, tolerancia 10^%i y %i iteraciones\n\n",p0,exp,IT);

    //Division
    imprimir(120,205);
    printf("\n");

    printf("i");
    imprimir(16, 32);
	printf("p0");
	imprimir(18, 32);
	printf("p [g(p0)]");
	imprimir(16, 32);
	printf("f(p)");
	imprimir(16, 32);
	printf("Error ABS");
	imprimir(16,32);
	printf("Error Rel\n");

    while (i <= IT){
        p = g(p0);
        FP = f(p);

        error_abs = abs( (p-p0)/p );
        error_rel = abs( p - p0);

        printf("%i", i);
        if(i < 10){
        	imprimir(5,32);
        }
        else{
        	imprimir(4,32);
        }

		validar_negativo(p0);
        printf("%.15f",p0);

        validar_negativo(p);
        printf("%.15f",p);

        validar_negativo(FP);
        printf("%.15f",FP);

        validar_negativo(error_abs);
        printf("%.15f",error_abs);

        validar_negativo(error_rel);
        printf("%.15f\n",error_rel);

        if( error_abs < TOL) {
            exito = true;
            printf("\nLa ra%cz se aproxima en el punto p0 = %.15f \n",161,p0);
            printf("y g(p)= %.15f",p);
            break;
        }
        i++;

        p0 = p;
    }

    if(!exito){
        printf("\nEl m%ctodo fracas%c despu%cs de \"%i\" intentos",130,162,130,IT);
    }

    getch();

    return 0;
}
