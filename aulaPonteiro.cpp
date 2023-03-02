#include<stdio.h>

struct No {
    //Criado um nó no qual vai receber uma variável e o ponteiro vai apontar para o próximo espaço de memória para armazenar a próxima variável recebida
    //Estrutura importante para listas
    int x;
    No *proximo;
};

struct Data {
    int dia, mes, ano, idade;
};

//Passagem de parametro por valor
//Isto é uma cópia da struct é criada na memória
void imprimir(Data d){
    printf("Por valor: %02d/%02d/%04d\n", d.dia, d.mes, d.ano);
}

//Passagem de parametro por referencia
//Isto é usamos a mesma posição de memória da struct na função principal
//A função chama por ponteiro de data
void imprimir(Data *d){
    printf("Por referencia: %02d/%02d/%04d\n", d->dia, d->mes, d->ano);
}

int main(){

    Data d;
    d.dia = 10;
    d.mes = 12;
    d.ano = 1993;

    imprimir(d);
    //passar o endereço como parametro através do &
    imprimir(&d);

    return 0;

}
