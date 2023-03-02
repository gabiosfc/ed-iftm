#include <stdio.h>
#include <string.h>

struct Produto {
    char nome[100];
    int qtd;
    double valorUnit, valorTotal;

    Produto() {
        strcpy(nome, "");
        qtd = 0;
        valorUnit = 0;
        valorTotal = 0;
    }

    void ler() {
        scanf("%s %d %lf", nome, &qtd, &valorUnit);
        calcularValorTotal();
    }

    void imprimir() {
        printf("%s %d x %.2lf = %.2lf\n", nome, qtd, valorUnit, valorTotal);
    }

    void calcularValorTotal() {
        valorTotal = qtd * valorUnit;
    }
};

struct Venda {
    char nomeCliente[100];
    Produto itens[10];
    int qtdItens;
    double valorTotal;

    Venda() {
        strcpy(nomeCliente, "");
        qtdItens = 0;
        valorTotal = 0;
    }

    void ler() {
        scanf("%s %d", nomeCliente, &qtdItens);
        for(int i = 0; i < qtdItens; i++){
            itens[i].ler();
        }
        calcularValorTotal();
    }

    void imprimir() {
        printf("%s R$%.2lf\n", nomeCliente, valorTotal);
        for(int i = 0; i < qtdItens; i++){
            itens[i].imprimir();
        }
    }

    void calcularValorTotal() {
        valorTotal = 0;
        for(int i = 0; i < qtdItens; i++){
            valorTotal += itens[i].valorTotal;
        }
    }
};

int main() {
    Venda v;
    v.ler();
    v.imprimir();
    return 0;
}

