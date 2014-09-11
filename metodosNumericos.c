/**
 * Universidad Nacional Autónoma de México
 * Matemáticas Aplicadas y Computación
 * Métodos Númericos I
 */
// Declaracion de bibliotecas
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <polinomios.h>

//Pre-definición de funciones
void biseccion(int opcion);
void falsaPosicion(int opcion);
void secante(int opcion);
int secante2();
int secante3();
int secante4();
void menuEcuaciones();

// Valores constantes
#define SALIR 0
#define BISECCION 1
#define FALSA_POSICION 2
#define NEWTON_RAPSON 3
#define SECANTE 4
#define DEFINE_POLINOMIO 5


/**
 * Metodo principal del paquete de 17 métodos implementando las ecuaciones:
 * 
 * 1. Sen(2x)(x^2+2x-15)
 * 2. Sen^2(x)
 * 3. e^x(x^2-16)
 * 4. sin(x)cos(x)
 * 
 * La quinta función será la evaluación de un polinomio de grado n definido 
 * por la siguiente estructura:
 * 
 * 5. P(x) = aoX^0 + a1X^1 + a2X^2 + anX^n
 * 
 * @return 0 
 */
int main(){
    
    int opcion;
    do{
        printf("Matematicas Aplicadas y Computacion\n");
        printf("Metodos Numericos I\n\n");
        printf("Tema: Solucion Numerica de Ecuaciones\n");
        printf("Seleccione uno de estos metodos\n");
        printf("1) Biseccion\n");
        printf("2) Falsa posocion\n");
        printf("3) Newton Rapson\n");
        printf("4) Secante\n");
        printf("0) Salir del Programa\n");
        scanf("%d",&opcion);
        
        switch(opcion){
            case BISECCION:
                printf("Método de Bisección:\n");
                menuEcuaciones();
                scanf("%d",&opcion);
                biseccion(opcion);
                break;
            case FALSA_POSICION:
                printf("Método de Falsa Posición\n");
                menuEcuaciones();
                scanf("%d",&opcion);
                falsaPosicion(opcion);
                break;
            case NEWTON_RAPSON:
                printf("Método de Newton Rapson\n");
                menuEcuaciones();
                scanf("%d",&opcion);
                break;
            case SECANTE:
                printf("Método de la Secante\n");
                menuEcuaciones();
                scanf("%d",&opcion);
                secante(opcion);
                break;
        }

    }while(opcion!=SALIR);
   
    
    return 0;
}

void biseccion(int opcion)
{
    int *ptPolinomio, grado;
    int n;
    float li,ls,e,d,a,z,ex=2.7182818284;
    float fa,fb,pm,fx;
    
    if(opcion==DEFINE_POLINOMIO){
        printf("Define el grado del polinomio:\n");
        scanf("%d", &grado);
        ptPolinomio = definePolinomio(grado);
        leePolinomio(ptPolinomio, grado);
    }
    
    printf("Ingresa el Limite inferior : \n");
    scanf("%f",&li);
    printf("Ingresa el Limite Superior : \n");
    scanf("%f",&ls);
    printf("Ingresa el Error de tolerancia : \n");
    scanf("%f",&e);
    pm=(li+ls)/2;
    
    switch(opcion)
    {
        case 1:
            fa=seno(li);
            fb=seno(ls);
            fx=seno(pm);
            break;
             
        case 2:
            fa=senoCuadrado(li);
            fb=senoCuadrado(ls);
            fx=senoCuadrado(pm);
            break;
             
        case 3:
            fa=exponente(li);
            fb=exponente(ls);
            fx=exponente(pm);
            break;
             
        case 4:
            fa=senoCoseno(li);
            fb=senoCoseno(ls);
            fx=senoCoseno(pm);
            break;
            
        case 5:
            fa=evaluaPolinomio(li, ptPolinomio, grado);
            fb=evaluaPolinomio(ls, ptPolinomio, grado);
            fx=evaluaPolinomio(pm, ptPolinomio, grado);
            break;
            
    }
    
    a=(ls-li);
    if(a<0){
        d=(-1*a);
    }else{
        d=a;
    }
    
    if (d<e){
        z=0 ;
    }else{
        z=1;
    }
    
    n=0;
    printf("\nI LI\tLS\tf(LI)\tf(LS)\tPM\tf(PM)\tf(LI)*f(PM)\t\"|LS-LI|<Error\"\n");
    printf("0 %.2f\t%.2f\t%.2f\t%.2f\t%.2f\t%.2f\t%f\tFalso\n",li,ls,fa,fb,pm,fx,fa*fx);
    while(z)
    {
    n=n+1;
    if ((fa*fx)>0){
                   li=pm;
                   }
    if ((fa*fx)<0){
                   ls=pm;
                   }
    pm=(li+ls)/2;
    
    switch(opcion)
    {
        case 1:
            fa=seno(li);
            fb=seno(ls);
            fx=seno(pm);
            break;
             
        case 2:
            fa=senoCuadrado(li);
            fb=senoCuadrado(ls);
            fx=senoCuadrado(pm);
            break;
             
        case 3:
            fa=exponente(li);
            fb=exponente(ls);
            fx=exponente(pm);
            break;
             
        case 4:
            fa=senoCoseno(li);
            fb=senoCoseno(ls);
            fx=senoCoseno(pm);
            break;
            
        case 5:
            fa=evaluaPolinomio(li, ptPolinomio, grado);
            fb=evaluaPolinomio(ls, ptPolinomio, grado);
            fx=evaluaPolinomio(pm, ptPolinomio, grado);
            break;
    }
    
    a=(ls-li);
    if(a<0){
    d=(-1*a);
}
else d=a;
    if (d<e)
    {
                z=0 ;
                 }
    else
    z=1;
     if (z==0){
               printf("%d %.2f\t%.2f\t%.2f\t%.2f\t%.2f\t%.2f\t%f\tDetener\n",n,
                       li,ls,fa,fb,pm,fx,fa*fx);
               }
               else
    printf("%d %.2f\t%.2f\t%.2f\t%.2f\t%.2f\t%.2f\t%f\tFalso\n",n,li,ls,fa,fb,
             pm,fx,fa*fx);
    }
    printf("\nLa raiz es : %.9f \n\n",pm);
    free(ptPolinomio);

}

void falsaPosicion(int opcion)
{
    int *ptPolinomio, grado;
    int n;
    float li,ls,e,d,z,ex=2.7182818284;
    float fa,fb,fp,fx;

    if(opcion==DEFINE_POLINOMIO){
        printf("Define el grado del polinomio:\n");
        scanf("%d", &grado);
        ptPolinomio = definePolinomio(grado);
        leePolinomio(ptPolinomio, grado);
    }
    
    printf("Ingresa el Limite inferior : \n");
    scanf("%f",&li);
    printf("Ingresa el Limite Superior : \n");
    scanf("%f",&ls);
    printf("Ingresa el Error de tolerancia : \n");
    scanf("%f",&e);
    switch(opcion)
    {
             case 1:
                 fa=seno(li);
                 fb=seno(ls);
                 fp=((ls*fa-li*fb)/(fa-fb));
                 fx=seno(fp);
             break;
             
             case 2:
                 fa=senoCuadrado(li);
                 fb=senoCuadrado(ls);
                 fp=((ls*fa-li*fb)/(fa-fb));
                 fx=senoCuadrado(fp);
             break;
             
             case 3:
                 fa=(pow(ex,li)*(pow(li,2)-16));
                 fb=(pow(ex,ls)*(pow(ls,2)-16));
                 fp=((ls*fa-li*fb)/(fa-fb));
                 fx=(pow(ex,fp)*(pow(fp,2)-16));
             break;
             
             case 4:
                 fa=senoCoseno(li);
                 fb=senoCoseno(ls);
                 fp=((ls*fa-li*fb)/(fa-fb));
                 fx=senoCoseno(fp);
             break;
             
             case 5:
                 fa=evaluaPolinomio(li, ptPolinomio, grado);
                 fb=evaluaPolinomio(ls, ptPolinomio, grado);
                 fp=((ls*fa-li*fb)/(fa-fb));
                 fx=evaluaPolinomio(fp, ptPolinomio, grado);
             break;
    }
    
    if(fx<0){
    d=(-1*fx);
    }else{
        d=fx;
    }
    
    if (d<e)
    {
                z=0 ;
                 }
    else
    z=1;
    n=0;
    printf("\nI LI\tLS\tf(LI)\tf(LS)\tFP\tf(FP)\tf(LI)*f(FP)\t\"|f(FP)|<Error\"\n");
    printf("0 %.2f\t%.2f\t%.2f\t%.2f\t%.2f\t%.2f\t%f         \tFalso\n",li,ls,fa,fb,fp,fx,fa*fx);
    while(z)
    {
    n=n+1;
    if ((fa*fx)>0){
                   li=fp;
                   }
    if ((fa*fx)<0){
                   ls=fp;
                   }
    
    switch(opcion)
    {
             case 1:
                 fa=seno(li);
                 fb=seno(ls);
                 fp=((ls*fa-li*fb)/(fa-fb));
                 fx=seno(fp);
             break;
             
             case 2:
                 fa=senoCuadrado(li);
                 fb=senoCuadrado(ls);
                 fp=((ls*fa-li*fb)/(fa-fb));
                 fx=senoCuadrado(fp);
             break;
             
             case 3:
                 fa=(pow(ex,li)*(pow(li,2)-16));
                 fb=(pow(ex,ls)*(pow(ls,2)-16));
                 fp=((ls*fa-li*fb)/(fa-fb));
                 fx=(pow(ex,fp)*(pow(fp,2)-16));
             break;
             
             case 4:
                 fa=senoCoseno(li);
                 fb=senoCoseno(ls);
                 fp=((ls*fa-li*fb)/(fa-fb));
                 fx=senoCoseno(fp);
             break;
             
             case 5:
                 fa=evaluaPolinomio(li, ptPolinomio, grado);
                 fb=evaluaPolinomio(ls, ptPolinomio, grado);
                 fp=((ls*fa-li*fb)/(fa-fb));
                 fx=evaluaPolinomio(fp, ptPolinomio, grado);
             break;
    }
    if(fx<0){
    d=(-1*fx);
}
else d=fx;
    if (d<e)
    {
                z=0 ;
                 }
    else
    z=1;
     if (z==0){
               printf("%d %.2f\t%.2f\t%.2f\t%.2f\t%.2f\t%.2f\t%f         \tDetener\n",n,li,ls,fa,fb,fp,fx,fa*fx);
               }
               else
    printf("%d %.2f\t%.2f\t%.2f\t%.2f\t%.2f\t%.2f\t%f         \tFalso\n",n,li,ls,fa,fb,fp,fx,fa*fx);
    }

    printf("\nLa raiz es : %.9f \n\n",fp);
    free(ptPolinomio);
}

void secante(int opcion){
    
    float equis,fx,error,fprim;
    int suma,resta,divi,final;
    char interaccion[12]="Interaccion";
    char xn0[12]="xn-1";
    char xn[12]="xn";
    char fxn[12]="f(xn)";
    char fxn2[12]="f(xn-1)";
    char xn1[12]=" xn+1";
    char error2[15]="f{xn+1}<error";
    
    printf("Introdusca el valor de x\n");
    scanf("%f",&equis);
    printf("Introdusca el numero maximo del error\n");
    scanf("%f",&error);
    printf("Introdusca el numero de interacciones\n");
    scanf("%d",&suma);
    final=suma;
    float tabla[suma+2][7];
    
        switch(opcion)
    {
        case 1:
            if(seno(equis) == 0){
                printf("Se indetermina el Metodo con ese valor\n");
            }else{
                fx = seno(equis);
                printf("f(x): %f\n",fx);
                fx=fabs(fx);
                if(fx<error || fx==0){
                    printf("Se detiene el metodo porque se encontro raiz o se "
                            "paso el error\n");
                    printf("La Raiz o Aproximaxion de la Raiz es: %f\n",equis);
                }else{
                    
                    printf("%s    %s      %s     %s    %s     %s    %s\n",
                            interaccion,xn,xn0,fxn,fxn2,xn1,error2);

                    for(resta=0;resta<suma+1;resta++)
                    tabla[resta][0]=resta;
                    for(resta=0;resta<suma+1;resta++)
                    {
                        tabla[resta][1]=equis;
                        tabla[resta][2]=equis-1;
                        tabla[resta][3]=sin(2*equis)*(pow(equis,2)+2*equis-15);
                        tabla[resta][4]=sin(2*tabla[resta][2])*
                                        (pow(tabla[resta][2],2)+
                                         2*tabla[resta][2]-15);
                        
                        tabla[resta][5]=tabla[resta][1]-((tabla[resta][3]*
                                        (tabla[resta][2]-tabla[resta][1]))/
                                        (tabla[resta][4]-tabla[resta][3]));

                        equis=tabla[resta][5];
                        tabla[resta][6]=fabs(sin(2*equis)*
                                        (pow(equis,2)+2*equis-15));
                    }



                 for(resta=0;resta<suma+1;resta++){
                     for(divi=0;divi<7;divi++)
                         printf(" %9.3f",tabla[resta][divi]);
                     printf(" \n");
                 }
                 printf("Interacciones Terminadas\n\n");
                 if(fabs(tabla[final][6])<error)
                 printf("El limite del error se ha alcanzado,\nLa Raiz aprox es: %f\n",
                         tabla[final][5]);
                 else
                 printf("El limite del error todabia no se ha alcanzado,\nHasta ahora la "
                         "Raiz aproximada es: %f\n",tabla[final][5]);
                }
            }
          
            break;
             
        case 2:
            secante2();
            break;
             
        case 3:
            secante3();
           
            break;
             
        case 4:
            secante4();
            break;
            
        case 5:
            printf("En construccion..!\n");
            break;
    }
        
}

int secante2()
{
    float equis,fx,error,fprim;
    int suma,resta,divi,final,retro;
    char interaccion[12]="Interaccion";
    char xn0[12]="xn-1";
    char xn[12]="xn";
    char fxn[12]="f(xn)";
    char fxn2[12]="f(xn-1)";
    char xn1[12]=" xn+1";
    char error2[15]="f{xn+1}<error";
   do
   {
    printf("Introdusca el valor de x\n");
    scanf("%f",&equis);
    printf("Introdusca el numero maximo del error\n");
    scanf("%f",&error);
    printf("Introdusca el numero de interacciones\n");
    scanf("%d",&suma);
    final=suma;
    float tabla[suma+2][7];
    
    if(sin(equis-1)*sin(equis-1)-sin(equis)*sin(equis)==0)
    printf("Se indetermina el Metodo con ese valor\n\n");
    else
    {
    fx=sin(2*equis)*(pow(equis,2)+2*equis-15);
    printf("f(x): %f\n",fx);
    fx=fabs(fx);
    if(fx<error || fx==0)
    {
        printf("Se detiene el metodo porque se encontro raiz o se paso el error\n");
        printf("La Raiz o Aproximaxion de la Raiz es: %f\n\n",equis);
    }
    else
    {
        printf("%s    %s      %s     %s    %s     %s    %s\n",interaccion,xn,xn0,fxn,fxn2,xn1,error2);

       for(resta=0;resta<suma+1;resta++)
       tabla[resta][0]=resta;
       for(resta=0;resta<suma+1;resta++)
       {



       tabla[resta][1]=equis;
       tabla[resta][2]=equis-1;
       tabla[resta][3]=sin(equis)*sin(equis);
       tabla[resta][4]=sin(equis-1)*sin(equis-1);
       tabla[resta][5]=tabla[resta][1]-((tabla[resta][3]*(tabla[resta][2]-tabla[resta][1]))/(tabla[resta][4]-tabla[resta][3]));
       equis=tabla[resta][5];
       tabla[resta][6]=fabs(sin(2*equis)*(pow(equis,2)+2*equis-15));
       }



    for(resta=0;resta<suma+1;resta++)
        {
           for(divi=0;divi<7;divi++)
           printf(" %9.3f",tabla[resta][divi]);
           printf(" \n");
        }
    printf("Interacciones Terminadas\n\n");
    if(fabs(tabla[final][6])<error)
    printf("El limite del error se ha alcanzado,\nLa Raiz aprox es: %f\n",tabla[final][5]);
    else
    printf("El limite del error todabia no se ha alcanzado,\nHasta ahora la Raiz aproximada es: %f\n",tabla[final][5]);
    }
    }// termina metodo
    
    printf("Preciona 1 para volver a intentar o \n0 para regresar al menu principal\n");
    scanf("%d",&retro);
   }while(retro!=0);

    getchar();

}
// METODO DE LA SECANTE TERCERA FUNCION..............//

int secante3()
{
    float equis,fx,error,fprim;
    int suma,resta,divi,final,retro;
    char interaccion[12]="Interaccion";
    char xn0[12]="xn-1";
    char xn[12]="xn";
    char fxn[12]="f(xn)";
    char fxn2[12]="f(xn-1)";
    char xn1[12]=" xn+1";
    char error2[15]="f{xn+1}<error";
   do
   {
    printf("Introdusca el valor de x\n");
    scanf("%f",&equis);
    printf("Introdusca el numero maximo del error\n");
    scanf("%f",&error);
    printf("Introdusca el numero de interacciones\n");
    scanf("%d",&suma);
    final=suma;
    float tabla[suma+2][7];
    if(((exp(equis-1)*(pow(equis-1,2)-16))-(exp(equis)*(pow(equis,2)-16)))==0)
    printf("Se indetermina el Metodo con ese valor\n\n");
    else
    {
    fx=sin(2*equis)*(pow(equis,2)+2*equis-15);
    printf("f(x): %f\n",fx);
    fx=fabs(fx);
    if(fx<error || fx==0)
    {
        printf("Se detiene el metodo porque se encontro raiz o se paso el error\n");
        printf("La Raiz o Aproximaxion de la Raiz es: %f\n\n",equis);
    }
    else
    {
        printf("%s    %s      %s     %s    %s     %s    %s\n",interaccion,xn,xn0,fxn,fxn2,xn1,error2);

       for(resta=0;resta<suma+1;resta++)
       tabla[resta][0]=resta;
       for(resta=0;resta<suma+1;resta++)
       {



       tabla[resta][1]=equis;
       tabla[resta][2]=equis-1;
       tabla[resta][3]=exp(equis)*(pow(equis,2)-16);
       tabla[resta][4]=exp(equis-1)*(pow(equis-1,2)-16);
       tabla[resta][5]=tabla[resta][1]-((tabla[resta][3]*(tabla[resta][2]-tabla[resta][1]))/(tabla[resta][4]-tabla[resta][3]));
       equis=tabla[resta][5];
       tabla[resta][6]=fabs(sin(2*equis)*(pow(equis,2)+2*equis-15));
       }



    for(resta=0;resta<suma+1;resta++)
        {
           for(divi=0;divi<7;divi++)
           printf(" %9.3f",tabla[resta][divi]);
           printf(" \n");
        }
    printf("Interacciones Terminadas\n\n");
    if(fabs(tabla[final][6])<error)
    printf("El limite del error se ha alcanzado,\nLa Raiz aprox es: %f\n",tabla[final][5]);
    else
    printf("El limite del error todabia no se ha alcanzado,\nHasta ahora la Raiz aproximada es: %f\n",tabla[final][5]);
    }
    }
    printf("Preciona 1 para volver a intentar o \n0 para regresar al menu principal\n");
    scanf("%d",&retro);
   }while(retro!=0);

    getchar();

}

// METODO DE LA SECANTE CUARTA FUNCION .................//

int secante4()
{
    float equis,fx,error,fprim;
    int suma,resta,divi,final,retro;
    char interaccion[12]="Interaccion";
    char xn0[12]="xn-1";
    char xn[12]="xn";
    char fxn[12]="f(xn)";
    char fxn2[12]="f(xn-1)";
    char xn1[12]=" xn+1";
    char error2[15]="f{xn+1}<error";
   do
   {
    printf("Introdusca el valor de x\n");
    scanf("%f",&equis);
    printf("Introdusca el numero maximo del error\n");
    scanf("%f",&error);
    printf("Introdusca el numero de interacciones\n");
    scanf("%d",&suma);
    final=suma;
    float tabla[suma+2][7];
    if(((sin(equis)*cos(equis))-(sin(equis)*cos(equis)))==0)
    printf("Se indetermina el Metodo con ese valor\n\n");
    else
    {
    fx=sin(2*equis)*(pow(equis,2)+2*equis-15);
    printf("f(x): %f\n",fx);
    fx=fabs(fx);
    if(fx<error || fx==0)
    {
        printf("Se detiene el metodo porque se encontro raiz o se paso el error\n");
        printf("La Raiz o Aproximaxion de la Raiz es: %f\n\n",equis);
    }
    else
    {
        printf("%s    %s      %s     %s    %s     %s    %s\n",interaccion,xn,xn0,fxn,fxn2,xn1,error2);

       for(resta=0;resta<suma+1;resta++)
       tabla[resta][0]=resta;
       for(resta=0;resta<suma+1;resta++)
       {



       tabla[resta][1]=equis;
       tabla[resta][2]=equis-1;
       tabla[resta][3]=sin(equis)*cos(equis);
       tabla[resta][4]=sin(equis-1)*cos(equis-1);
       tabla[resta][5]=tabla[resta][1]-((tabla[resta][3]*(tabla[resta][2]-tabla[resta][1]))/(tabla[resta][4]-tabla[resta][3]));
       equis=tabla[resta][5];
       tabla[resta][6]=fabs(sin(2*equis)*(pow(equis,2)+2*equis-15));
       }



    for(resta=0;resta<suma+1;resta++)
        {
           for(divi=0;divi<7;divi++)
           printf(" %9.3f",tabla[resta][divi]);
           printf(" \n");
        }
    printf("Interacciones Terminadas\n\n");
    if(fabs(tabla[final][6])<error)
    printf("El limite del error se ha alcanzado,\nLa Raiz aprox es: %f\n",tabla[final][5]);
    else
    printf("El limite del error todabia no se ha alcanzado,\nHasta ahora la Raiz aproximada es: %f\n",tabla[final][5]);
    }
    }
    printf("Preciona 1 para volver a intentar o \n0 para regresar al menu principal\n");
    scanf("%d",&retro);
   }while(retro!=0);

    getchar();

}

void menuEcuaciones(){
    
    printf("Seleccione un de las ecuaciones\n");
    printf("1) f(x)=Sen(2x)(x^2+2x-15)\n");
    printf("2) f(x)=sen^2(x)\n");
    printf("3) f(x)=e^x(x^2-16)\n");
    printf("4) f(x)=Sen(x)Cos(x)\n");
    printf("5) P(x) = aoX^0 + a1X^1 + a2X^2 + anX^n\n");
}

