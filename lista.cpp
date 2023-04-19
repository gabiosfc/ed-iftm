#include<stdio.h>

struct No {
    int valor;
    No *prox;
};

struct Lista {
    No *cabeca, *cauda;
    int n;

    Lista() {
        cabeca = cauda = NULL;
        n = 0;
    }

    bool vazia() {
        return (cabeca == NULL);
    }

    void inserirInicio(int v) { 
        No *novo = new No();
        novo->valor = v;
        if (vazia()) {
            novo->prox = NULL;
            cabeca = novo;
            cauda = novo;
        } else {
            novo->prox = cabeca;
            cabeca = novo;
        }
        n++;
    }

    void inserirFinal(int v) {
        No *novo = new No();
        novo->valor = v;
        if (vazia()) {
            novo->prox = NULL;
            cabeca = novo;
            cauda = novo;
        } else {
            novo->prox = NULL;
            cauda->prox = novo;
            cauda = novo;
        }
        n++;
    }

    void imprimir() {
        No *aux = cabeca;
        while (aux != NULL) {
            printf("%d\n", aux->valor);
            aux = aux->prox;
        }
    }


    int tamanho() { // O(1)
        return n;
    }

    void removerInicio() { 
        if (!vazia()) {
            if (tamanho() == 1) {
                No *aux = cabeca;
                cabeca = NULL;
                cauda = NULL;
                delete(aux);
            } else {
                No *aux = cabeca;
                cabeca = cabeca->prox;
                delete(aux);
            }
            n--;
        }
    }

    void removerFinal() { 
        if (!vazia()) {
            if (tamanho() == 1) {
                No *aux = cabeca;
                cabeca = NULL;
                cauda = NULL;
                delete(aux);
            } else {
                No *penultimo = cabeca;
                while (penultimo->prox != cauda) {
                    penultimo = penultimo->prox;
                }
                delete(cauda);
                cauda = penultimo;
                cauda->prox = NULL;
            }
            n--;
        }
    }

    //exercicio 1
    void reduzirLista(int v) {
        if (v < tamanho()) {
            for (int i = 0; i < tamanho(); i++) {
                removerFinal();
            }
        } else {
            for (int i = 0; i < v; i++) {
                removerFinal();
            }
        }
    }

    //exercicio 2 
    void removerSegundoElemento(){
        if (!vazia()) {
            if (tamanho() >= 1) {
                No *aux = cabeca->prox;
                No *aux2 = aux->prox;
                delete(aux);
            } 
            n--;
        }
    }


    //exercicio 3
    void inserirTamanhoFinal() {
        int v = tamanho();
        inserirFinal(v);
    }

    //exercico 4
    void inserirNCrescente(int v) {
        int aux = 1;
        for (int i = 0; i < v; i++){
            inserirFinal(aux);
            aux++;
        }
    }

    //exercicio 5 
   void inserirPenultimo(int v) {
        No *novo = new No();
        novo->valor = v;
        if (tamanho() >= 1) {
            No *aux = cauda;
            cauda = novo;
            cauda -> prox = aux;
        }
        n++;
    }

};
    

int main() {

    Lista l;
    l.inserirInicio(5);
    l.inserirInicio(7);
    l.inserirInicio(10);
    l.inserirFinal(8);
    l.inserirFinal(2);
    l.inserirFinal(3);
    l.removerInicio();
    l.removerInicio();
    l.removerInicio();
    l.imprimir();

    l.reduzirLista(30);
    l.imprimir();
    l.removerSegundoElemento();
    l.imprimir();
    l.inserirTamanhoFinal();
    l.imprimir();
    l.inserirNCrescente(27);
    l.imprimir();
    l.inserirPenultimo(20);
    l.imprimir();


    printf("\nTamanho da lista: %d\n", l.tamanho());


    return 0;
}
