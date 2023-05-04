#include<stdio.h>

struct No {

    int valor;
    No *anterior, *proximo;

    No () {
        anterior = NULL;
        proximo = NULL;
    }

    No (int _valor) {
        valor = _valor;
        anterior = NULL;
        proximo = NULL;
    }
};

struct ListaDE {

    No *cabeca, *cauda;
    int n;

    ListaDE () {
        cabeca = NULL;
        cauda = NULL;
        n = 0;
    }

    bool vazia() {
        return cabeca == NULL;
    }

    void inserirInicio(int valor) {
        No *novo = new No(valor);
        if (vazia()) {
            cabeca = novo;
            cauda = novo;
        } else {
            novo->proximo = cabeca;
            cabeca->anterior = novo;
            cabeca = novo;
        }
        n++;
    }

    void inserirFinal(int valor) {
        No *novo = new No(valor);
        if (vazia()) {
            cabeca = novo;
            cauda = novo;
        } else {
            novo->anterior = cauda;
            cauda->proximo = novo;
            cauda = novo;
        }
        n++;
    }

    void inserirApos(int valor, int x) {
        if (tamanho() == x) {
            inserirFinal(valor);
        } else if (tamanho() > x) {
            No *aux1 = cabeca;
            for (int i = 0; i < x - 1; i++) {
                aux1 = aux1->proximo;
            }
            /*while (aux1->valor != x && aux1 != NULL) {
                aux1 = aux1->proximo;
            }
            if (aux1 == NULL) {
                // Não existe no vetor;
            }*/
            No *aux2 = aux1->proximo;
            No *novo = new No(valor);
            novo->proximo = aux2;
            novo->anterior = aux1;
            aux1->proximo = novo;
            aux2->anterior = novo;
            n++;
        } else {
            printf("X maior que o tamanho da lista.");
        }
    }

    int tamanho() {
        return n;
    }

    void imprimir() {
        No *aux = cabeca;
        while (aux != NULL) {
            printf("%d -> ", aux->valor);
            aux = aux->proximo;
        }
        printf("\n");
    }

    void imprimirReverso() {
        No *aux = cauda;
        while (aux != NULL) {
            printf("%d -> ", aux->valor);
            aux = aux->anterior;
        }
        printf("\n");
    }

    void removerInicio() {
        if (!vazia()) {
            if (tamanho() == 1) {
                delete(cabeca);
                cabeca = NULL;
                cauda = NULL;
            } else {
                No *aux = cabeca;
                cabeca = cabeca->proximo;
                cabeca->anterior = NULL;
                delete(aux);
            }
            n--;
        }
    }

    void removerFinal() {
        if (!vazia()) {
            if (tamanho() == 1) {
                delete(cabeca);
                cabeca = NULL;
                cauda = NULL;
            } else {
                No *aux = cauda;
                cauda = cauda->anterior;
                cauda->proximo = NULL;
                delete(aux);
            }
            n--;
        }
    }

};

int main() {

    ListaDE l;
    l.inserirInicio(1);
    l.inserirInicio(2);
    l.inserirInicio(3);
    l.inserirFinal(5);
    l.inserirFinal(6);
    l.inserirFinal(7);

    l.imprimir();
    l.imprimirReverso();

    l.removerInicio();
    l.removerFinal();

    l.imprimir();

    l.removerInicio();
    l.removerFinal();

    l.imprimirReverso();

    return 0;
}