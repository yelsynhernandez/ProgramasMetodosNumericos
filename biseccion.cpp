#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cmath>
#include <math.h>
#include <conio.h>

/*
Autor: Yelsyn Hernandez
Fecha: 16-02-2023
Descripcion: Aproxima una raiz de un intervalo [a,b] utilizando el metodo de biseccion

*/
using namespace std;

float f(float x){
    //Inciso a:
    //return x - pow(2,-x);

    //Inciso 2:
    //return pow(2.71828,x) - pow(x,2) + (3 * x) - 2;

    //Inciso 3:
    //return ((2 * x) * cos(x)) - pow(x+1,2);

    //Inciso 4:
    return (x * cos(x)) - (2 * pow(x,2)) + (3 * x);
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
    float a = 0;
    float b = 0;
    float p = 0;
    float TOL = 0;
    float FA = 0;
    float FP = 0;
    float error = 0;
    int exp = 0;
    int IT = 0;
    int i = 1;
    bool exito = false;

    printf("M%ctodos num%cricos, Secci%cn A\n",130,130,162);
    printf("Yelsyn Hern%cndez\n", 160);
    printf("Carnet: 9490-17-969\n");

    printf("Intervalo a: ");
    scanf("%f",&a);
    printf("Intervalo b: ");
    scanf("%f",&b);
    printf("Ingrese tolerancia: 10^");
    scanf("%i",&exp);
    printf("Cantidad de iteraciones: ");
    scanf("%i",&IT);

    TOL = pow(10,exp);

    printf("\nCalculando [%.1f,%.1f] con tolerancia 10^%i y %i iteraciones\n\n",a,b,exp,IT);

    //Division
    imprimir(120,205);
    printf("\n");

    FA = f(a);

    printf("i");
    imprimir(13, 32);
	printf("a");
	imprimir(21, 32);
	printf("b");
	imprimir(22, 32);
	printf("p");
	imprimir(19, 32);
	printf("f(p)");
	imprimir(17,32);
	printf("error\n");

    while (i <= IT){
        p = (a+b)/2;
        FP = f(p);

        error = abs( (b-a)/2 );

        printf("%i", i);
        if(i < 10){
        	imprimir(5,32);
        }
        else{
        	imprimir(4,32);
        }

        printf("%.15f", a);

		validar_negativo(p);
        printf("%.15f",b);

        validar_negativo(p);
        printf("%.15f",p);

        validar_negativo(FP);
        printf("%.15f",FP);

        validar_negativo(error);
        printf("%.15f\n", error);

        if( (FP == 0) || (error < TOL) ){
            exito = true;
            printf("\nLa ra%cz se aproxima en el punto p = %.15f \n",161,p);
            printf("y f(p)= %.15f",FP);
            break;
        }
        i++;

        if( (FA * FP) > 0 ){
            a = p;
            FA = FP;
        }
        else{
            b = p;
        }
    }

    if(!exito){
        printf("\nEl m%ctodo fracas%c despu%cs de \"%i\" intentos",130,162,130,IT);
    }

    getch();

    return 0;
}
