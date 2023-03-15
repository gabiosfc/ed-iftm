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

    bool vazia() { // O(1)
        return (cabeca == NULL);
    }

    void inserirInicio(int v) { // O(1)
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

    void inserirFinal(int v) { // O(1)
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

    void imprimir() { // O(n)
        /*for (No *aux = cabeca; aux != NULL; aux = aux->prox) */
        No *aux = cabeca;
        while (aux != NULL) {
            printf("%d\n", aux->valor);
            aux = aux->prox;
        }
    }

    /*int tamanho() { // O(n)
        int t = 0;
        No *aux = cabeca;
        while (aux != NULL) {
            t++;
            aux = aux->prox;
        }
        return t;
    }*/

    int tamanho() { // O(1)
        return n;
    }

    void removerInicio() { // O(1)
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

    void removerFinal() { // O(n)
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
                cauda->prox;
                cauda->prox = NULL;
            }
            n--;
        }
    }
    

    //exercicio 1
    void reduzirLista(int v) {
        if (v > tamanho()) {
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
            if (tamanho() > 1) {
                No *segundo = cabeca->prox;
                No *aux = segundo->prox;
                delete(segundo);
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
        if (tamanho() > 1) {
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
    l.inserirInicio(6);
    l.inserirInicio(22);
    l.inserirInicio(1);
    l.inserirFinal(8);
    l.inserirFinal(2);
    l.inserirFinal(3);

    l.imprimir();
    
    printf("Exercício 1\n"); //ok
    l.reduzirLista(3);
    l.imprimir();
    printf("Exercício 2\n"); //erro
    //l.removerSegundoElemento();
    l.imprimir();
    printf("Exercício 3\n"); //ok
    l.inserirTamanhoFinal();
    l.imprimir();
    printf("Exercício 4\n"); //ok
    l.inserirNCrescente(12);
    l.imprimir();
    printf("Exercício 5\n"); //erro
    l.inserirPenultimo(20);
    l.imprimir();
    
 
    return 0;
}

