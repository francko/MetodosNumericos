/**
 * Universidad Nacional Autónoma de México
 * Matemáticas Aplicadas y Computación
 * Métodos Númericos I
 * 
 */

/**
 * Biblioteca definida para los cuatro polinomios definidos de manera estatica
 * y uno quinto de grado n definido por el usuario.
 * 
 * 1. Sen(2x)(x^2+2x-15)
 * 2. Sen^2(x)
 * 3. e^x(x^2-16)
 * 4. sin(x)cos(x)
 * 
 * El quinto polinomio su estructura se define como:
 * 
 * 5. P(x) = aoX^0 + a1X^1 + a2X^2 + anX^n
 * 
 */

// Incoporación de bibliotecas
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * Funcion que evalua el polinomio:
 * 
 * Sen(2x)(x^2+2x-15)
 * 
 * @param x
 * @return solucion
 */
float seno(float x){
    
    float solucion = 0;
    
    solucion = sin(2*x)*(pow(x,2)+2*x-15)-sin(2*(x-1))*(pow((x-1),2)+2*(x-1)-15);
    if(solucion==0)
        return 1;
    
    return solucion;
}

/**
 * Función que evalua la derivada del polinomio
 * 
 * Sen(2x)(x^2+2x-15)
 * 
 * @param x
 * @return solucion
 */
float derivaSeno(float x){
    float solucion = 0;
    
    solucion = sin(2*x)*(pow(x,2)+2*x-15);
    
    return solucion;
}


/**
 * Funcion que evalua el polinomio:
 * 
 * Sen^2(x)
 * 
 * @param x
 * @return solucion
 */
float senoCuadrado(float x){
    float solucion = 0;
    
    solucion = sin(x-1)*sin(x-1)-sin(x)*sin(x);
    
    return solucion;
}

/**
 * Funcion que deriva el polinomio:
 * 
 * Sen^2(x)
 * 
 * @param x
 * @return solucion
 */

float derivaSenoCuadraro(float x){
    float solucion = 0;
    
    solucion = sin(2*x)*(pow(x,2)+2*x-15);
    
    return solucion;
}

/**
 * Función que evalua el polinomio:
 * 
 * e^x(x^2-16)
 * 
 * @param x
 * @return solucion
 */
float exponente(float x){
    float solucion = 0;
    
    solucion = (exp(x-1)*(pow(x-1,2)-16))-(exp(x)*(pow(x,2)-16));
    
    return solucion;
}

/**
 * Función que evalua el polinomio:
 * 
 * sin(x)cos(x)
 * 
 * @param x
 * @return solucion
 */
float senoCoseno(float x){
    float solucion = 0;
    
    solucion = (sin(x)*cos(x))-(sin(x)*cos(x));
    
    return solucion;
}

/**
 * Funcion que deriva el polinomio:
 * 
 * sin(x)cos(x)
 * 
 * @param x
 * @return 
 */
float derivaSenoCoseno(float x){
    float solucion = 0;
    
    solucion = sin(2*x)*(pow(x,2)+2*x-15);
    
    return solucion;
}

/**
 * Define la estructura de un polinomio de grado n con la siguiente estructura:
 * 
 * P(x) = aoX^0 + a1X^1 + a2X^2 + anX^n
 * 
 * @param grado
 * @return *ptEcuacion 
 */
int  *definePolinomio(int grado){
    
    int *ptPolinomio;
  
    ptPolinomio = calloc(grado, sizeof(int *));
    
    return ptPolinomio;
}

/**
 * Asigna los valores para el polinomio creado
 *  
 * @param ptPolinomio
 * @param grado
 */
void leePolinomio(int *ptPolinomio, int grado){
    
    int i;
    for(i=grado; i>=0; i--){
        printf("Define el coeficiente para X^%d\n", i);
        scanf("%d",&ptPolinomio[i]);
    }
}

/**
 * Función que evalua el valor del polinomio p(x)
 * 
 * @param x
 * @param ptPolinomio
 * @param grado
 * @return solucion
 */
int evaluaPolinomio(int x, int *ptPolinomio, int grado){
    
    int i, solucion = 0;
    
    for(i=grado; i>=0; i--){
        solucion +=ptPolinomio[i] * pow(x,i); 
    }
    
    return solucion;
}
/**
 * Deriva el polinomio definido por el usuario
 * 
 * @param x
 * @param ptPolinomio
 * @param grado
 * @return 
 */
int derivaPolinomio(int x, int *ptPolinomio, int grado){
    
    int i, solucion = 0;
    
    for(i=grado; i>=0; i--){
        
        if(i!=0)
            solucion +=i * ptPolinomio[i] * pow(x,i-1);
        if(i==0)
            solucion +=ptPolinomio[i];
    }
    
    return solucion;
}