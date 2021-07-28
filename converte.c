#include "converte.h"
 
int cria_codigo(int n, char DDD[size])
{
    char centena = ' ', dezena = ' ', unidade = ' ', cent, dez, uni;
    char resultado[size];
    int tamanho;
    float x, atualiza;
    x=n;
    ///inicializa o vetor resultado com espaços
 
    for(int i=0; i<size; i++)
    {
        if(i==size-1){
           ///tava preenchento todo o vetor com espaços vazios
           ///esse if impede que a ultima posicao seja preenchida, nao consegui pensar em nd mais eficiente
        }
        else
        {
            resultado[i] = ' ';
        }
    }
 
    if(x==0){
        centena = '0';
        dezena = '0';
        unidade = '0';
    }
    else
    {
 
        ///verificando se o numero possui a casa das centenas
        if(x/100>=9)
        {
            centena = '9';
            x=x-900;
        }
        if( x/100>=8)
        {
            centena ='8';
            x=x-800;
        }
 
        if( x/100>=7)
        {
            centena ='7';
            x=x-700;
        }
 
        if( x/100>=6)
        {
            centena ='6';
            x=x-600;
        }
 
        if( x/100>=5)
        {
            centena ='5';
            x=x-500;
        }
 
        if( x/100>=4)
        {
            centena ='4';
            x=x-400;
        }
 
        if( x/100>=3)
        {
            centena ='3';
            x=x-300;
        }
 
        if( x/100>=2)
        {
            centena ='2';
            x=x-200;
        }
 
        if(x/100>=1)
        {
            centena ='1';
            x=x-100;
        }
        if(x/100<1)
        {
            cent = '0';
        }
 
        ///verificando se o numero possui a casa das dezenas
        if(x/10>=9)
        {
            dezena = '9';
            x=x-90;
        }
        if(x/10>=8)
        {
            dezena = '8';
            x=x-80;
        }
        if(x/10>=7)
        {
            dezena = '7';
            x=x-70;
        }
        if(x/10>=6)
        {
            dezena = '6';
            x=x-60;
        }
        if(x/10>=5)
        {
            dezena = '5';
            x=x-50;
        }
        if(x/10>=4)
        {
            dezena = '4';
            x=x-40;
        }
        if(x/10>=3)
        {
            dezena = '3';
            x=x-30;
        }
        if(x/10>=2)
        {
            dezena = '2';
            x=x-20;
        }
        if(x/10>=1)
        {
            dezena = '1';
            x=x-10;
        }
        if(x/10<1)
        {
            dez = '0';
        }
 
 
        ///verificando a casa das unidades
        if(x==9)
        {
            unidade = '9';
        }
        if(x==8)
        {
            unidade = '8';
        }
        if(x==7)
        {
            unidade = '7';
        }
        if(x==6)
        {
            unidade = '6';
        }
        if(x==5)
        {
            unidade = '5';
        }
        if(x==4)
        {
            unidade = '4';
        }
        if(x==3)
        {
            unidade = '3';
        }
        if(x==2)
        {
            unidade = '2';
        }
        if(x==1)
        {
            unidade = '1';
        }
        if(x==0)
        {
            uni = '0';
        }
    }
 
     for(int i=0; i<tamanho; i++)
    {
        if(i==0)
        {
            if(centena== ' ')
            {
                resultado[i]=cent;
                DDD[i]=resultado[i];
            }
            else
            {
                resultado[i]=centena;
                DDD[i]=resultado[i];
            }
        }
        if(i==1)
        {
            if(dezena== ' ')
            {
                resultado[i]=dez;
                DDD[i]=resultado[i];
            }
            else
            {
                resultado[i]=dezena;
                DDD[i]=resultado[i];
            }
        }
        if(i==2)
        {
            if(unidade== ' ')
            {
                resultado[i]=uni;
                DDD[i]=resultado[i];
            }
            else
            {
                resultado[i]=unidade;
                DDD[i]=resultado[i];
            }
        }
    }
}
