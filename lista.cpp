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
                cauda->prox = NULL;
            }
            n--;
        }
    }

    //exercicio 1
    void reduzirLista (int n) {
        int n;
        if (n < tamanho()) {
            for (int i = 0; i < tamanho(); i++) {
                removerFinal();
            }
        } else {
            for (int i = 0; i < n; i++) {
                removerFinal();
            }
        }
    }

    //exercicio 2 
    void removerSegundoElemento (){
        if (!vazia()) {
            if (tamanho() <= 1) {
                break;
            } else {
                No *aux = cabeca->prox;
                No *aux2 = aux->prox;
                delete(aux);
            }
            n--;
        }
    }

    //exercicio 3
    void inserirTamanhoFinal () {
        int v = tamanho();
        inserirFinal(v);
    }

    //exercico 4
    void inserirNCrescente (int n) {
        int n, aux = 1;
        for (int i = 0; i < n; i++){
            inserirFinal(aux);
            aux++;
        }
    }

    //exercicio 5 
   void inserirPenultimo () {
        No *novo = new No();
        novo->valor = v;
        if (tamanho() <= 1) {
            break;
        } else {
            No *aux = cauda;
            cauda = novo;
            cauda -> prox = aux;
        }
        n++;
    }
        
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



    return 0;
}