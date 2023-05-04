#include<stdio.h>
#include<sys/time.h>
#include <unistd.h>

struct No {

    int valor;
    long int timestamp;
    No *anterior, *proximo;

    No () {
        anterior = NULL;
        proximo = NULL;
    }

    No (int _valor) {
        valor = _valor;
        anterior = NULL;
        proximo = NULL;
        timestamp = time(NULL);
    }
};

struct ListaDE {

    No *cabeca, *cauda;
    int n;
    int duracao; // segundos

    ListaDE (int _duracao) {
        cabeca = NULL;
        cauda = NULL;
        n = 0;
        duracao = _duracao;
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

    int tamanho() {
        return n;
    }

    void imprimir() {
        removerExpirados();
        No *aux = cabeca;
        while (aux != NULL) {
            printf("%d -> ", aux->valor);
            aux = aux->proximo;
        }
        printf("\n");
    }

    void imprimirReverso() {
        removerExpirados();
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

    void removerExpirados() {
        No *aux = cabeca;
        while (aux != NULL) {
            long int timestamp = time(NULL) - duracao;
            if (aux->timestamp < timestamp) {
                if (aux == cabeca) {
                    aux = aux->proximo;
                    removerInicio();
                } else if (aux == cauda) {
                    aux = aux->proximo;
                    removerFinal();
                } else {
                    No *anterior = aux->anterior;
                    No *proximo = aux->proximo;
                    anterior->proximo = proximo;
                    proximo->anterior = anterior;
                    delete(aux);
                    aux = proximo;
                    n--;
                }
            } else {
                aux = aux->proximo;
            }
        }
    }

};

int main() {

    ListaDE l(10);

    l.inserirInicio(1);
    l.inserirInicio(2);
    l.inserirInicio(3);

    l.imprimir();
    sleep(5);

    l.inserirInicio(4);
    l.inserirFinal(5);

    l.imprimir();
    sleep(10);

    l.inserirFinal(6);
    l.inserirFinal(7);

    l.imprimir();

    return 0;
}
