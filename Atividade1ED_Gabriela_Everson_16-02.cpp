//Atividade 1 - Estrutura de Dados
//Alunos:
//Everson Esteves da Silva
//Gabriela de Oliveira Silva Fernandes Correia


#include <stdio.h>
#include <string.h>
#include <time.h>
#include <iostream>
#include <ctime>
using namespace std;

struct Data {

    int calcularIdade() {
        int diaNascimento, mesNascimento, anoNascimento;
        printf("Digite a data de nascimento (dd/mm/aaaa):\n");
        scanf("%d/%d/%d", &diaNascimento, &mesNascimento, &anoNascimento);

        time_t t = time(NULL);
        tm* timePtr = localtime(&t);
        int anoAtual = timePtr->tm_year + 1900;
        int mesAtual = timePtr->tm_mon + 1;
        int diaAtual = timePtr->tm_mday;

        int diasIdade = (anoAtual - anoNascimento) * 365
               + (mesAtual - mesNascimento) * 30
               + (diaAtual - diaNascimento);

        int idade = diasIdade / 365;

        return idade;
    }

};

struct Cliente {
    char nome[100], sexo[1];
    int idade;
    Data dataNascimento;

    Cliente() {
        strcpy(nome, "");
        strcpy(sexo, "");
        idade = 0;
    }

    void ler() {
        printf("Digite o nome:\n");
        scanf("%s", nome);
        printf("Digite o sexo (F ou M):\n");
        scanf("%s", sexo);
        idade = dataNascimento.calcularIdade();
    }

    void imprimir() {
        printf("\nNome: %s\nIdade: %d anos\nSexo: %s\n\n", nome, idade, sexo);
    }
};

int opcao() {

    int menu;

    printf("\n---------------Menu---------------\n\n");
    printf("Digite o numero da opcao desejada:\n\n");
    printf("1. Cadastrar clientes\n");
    printf("2. Listar clientes\n");
    printf("3. Sair\n\n");

    scanf("%d", &menu);

    return menu;
}

int main() {
    int i = 0;
    Cliente lista[50];

    while(1 == 1){

        int menu = opcao();

        if(menu == 1){
            lista[i].ler();
            i++;

        } else if (menu == 2) {

            for(int j = 0; j < i; j++){
                printf("\nCliente %d:\n", j+1);
                lista[j].imprimir();
            }

        } else if (menu == 3){
            break;

        } else {
            printf("\n>>> Digite um valor valido! <<<\n\n");
            opcao();
        }
    };

    return 0;
}


