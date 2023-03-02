#include<stdio.h>

struct No {
    //Criado um n� no qual vai receber uma vari�vel e o ponteiro vai apontar para o pr�ximo espa�o de mem�ria para armazenar a pr�xima vari�vel recebida
    //Estrutura importante para listas
    int x;
    No *proximo;
};

struct Data {
    int dia, mes, ano, idade;
};

//Passagem de parametro por valor
//Isto � uma c�pia da struct � criada na mem�ria
void imprimir(Data d){
    printf("Por valor: %02d/%02d/%04d\n", d.dia, d.mes, d.ano);
}

//Passagem de parametro por referencia
//Isto � usamos a mesma posi��o de mem�ria da struct na fun��o principal
//A fun��o chama por ponteiro de data
void imprimir(Data *d){
    printf("Por referencia: %02d/%02d/%04d\n", d->dia, d->mes, d->ano);
}

int main(){

    Data d;
    d.dia = 10;
    d.mes = 12;
    d.ano = 1993;

    imprimir(d);
    //passar o endere�o como parametro atrav�s do &
    imprimir(&d);

    return 0;

}
