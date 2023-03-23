#include<stdio.h>

struct No {
    int valor;
    No *anterior, *proximo;
    No() {
        anterior = proximo = NULL;
    }
    No(int _valor) {
        valor = _valor;
        anterior = proximo = NULL;
    }
};

struct ListaCircular {
    No *cabeca, *cauda;
    int n;
    ListaCircular() {
        cabeca = cauda = NULL;
        n = 0;
    }
    bool vazia() {
        return cabeca == NULL;
    }
    int tamanho() {
        return n;
    }
    void inserirInicio(int valor) {
        No *novo = new No(valor);
        if (vazia()) {
            cabeca = cauda = novo;
            cabeca->proximo = cauda;
            cauda->anterior = cabeca;
        } else {
            novo->proximo = cabeca;
            novo->anterior = cauda;
            cauda->proximo = novo;
            cabeca->anterior = novo;
            cabeca = novo;
        }
        n++;
    }
    void inserirFinal(int valor) {
        No *novo = new No(valor);
        if (vazia()) {
            cabeca = cauda = novo;
            cabeca->proximo = cauda;
            cauda->anterior = cabeca;
        } else {
            novo->proximo = cabeca;
            novo->anterior = cauda;
            cauda->proximo = novo;
            cabeca->anterior = novo;
            cauda = novo;
        }
        n++;
    }
    void imprimir() {
        if (!vazia()) {
            No *aux = cabeca;
            do {
                printf("%d\n", aux->valor);
                aux = aux->proximo;
            } while (aux != cabeca);
        }
        printf("\n");
    }
    void removerInicio() {
        if (!vazia()) {
            if (tamanho() == 1) {
                delete(cabeca);
                cabeca = cauda = NULL;
            } else {
                No *aux = cabeca;
                cabeca = cabeca->proximo;
                cabeca->anterior = cauda;
                cauda->proximo = cabeca;
                delete(aux);
            }
            n--;
        }
    }
    void removerFinal() {
        if (!vazia()) {
            if (tamanho() == 1) {
                delete(cabeca);
                cabeca = cauda = NULL;
            } else {
                No *aux = cauda;
                cauda = cauda->anterior;
                cabeca->anterior = cauda;
                cauda->proximo = cabeca;
                delete(aux);
            }
            n--;
        }
    }



    void salto(int k) {
        if (!vazia()) {
            No *result = cabeca;

            do {
                No *aux = result;
                for(int i = 1; i < k; i++){
                    aux = aux->proximo;
                }
                result = aux->proximo;
                printf("Resultado: %d\n", result->valor);
                //delete(aux);
                n--;
            } while (tamanho() != 1);
            printf("Resultado: %d\n", result->valor);
        }
    }
};

int main() {
    int nc, n, k;

    scanf("%d", &nc);

    for(int i = 0; i < nc; i++){

        scanf("%d %d", &n, &k);

        ListaCircular lc;

        for(int i = 1; i <= n; i++){
            lc.inserirFinal(i);
        }
        lc.imprimir();

        lc.salto(k);


        //lc.imprimir();
    }

    return 0;
}
