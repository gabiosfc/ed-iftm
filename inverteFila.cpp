#include <stdio.h>

struct No {
    int valor;
    No* prox;
};

struct Pilha {
    No* topo;
    int n;

    Pilha() {
        topo = NULL;
        n = 0;
    }

    bool vazia() {
        return (topo == NULL);
    }

    void inserir(int v) {
        No* novo = new No();
        novo->valor = v;
        if (vazia()) {
            novo->prox = NULL;
            topo = novo;
        } else {
            novo->prox = topo;
            topo = novo;
        }
        n++;
    }

    int tamanho() {
        return n;
    }

    void remover() {
        if (!vazia()) {
            if (tamanho() == 1) {
                No* aux = topo;
                topo = NULL;
                delete (aux);
            } else {
                No* aux = topo;
                topo = topo->prox;
                delete (aux);
            }
            n--;
        }
    }

    int topoPilha() {
        if (vazia()) {
            return NULL;
        }
        return topo->valor;
    }

    void imprimir() {
        No* atual = topo;
        while (atual != NULL) {
            printf("%d ", atual->valor);
            atual = atual->prox;
        }
        printf("\n");
    }
};

struct Fila {
    No* inicio;
    No* fim;

    Fila() {
        inicio = NULL;
        fim = NULL;
    }

    bool vazia() {
        return (inicio == NULL);
    }

    void inserir(int v) {
        No* novo = new No();
        novo->valor = v;
        novo->prox = NULL;

        if (vazia()) {
            inicio = novo;
            fim = novo;
        } else {
            fim->prox = novo;
            fim = novo;
        }
    }

    void remover() {
        if (!vazia()) {
            No* temp = inicio;
            inicio = inicio->prox;
            delete temp;

            if (inicio == NULL) {
                fim = NULL;
            }
        }
    }

    void imprimir() {
        No* atual = inicio;
        while (atual != NULL) {
            printf("%d ", atual->valor);
            atual = atual->prox;
        }
        printf("\n");
    }
};

void inverterOrdem(Fila& fila) {
    Pilha pilha;

    while (fila.inicio != NULL) {
        No* temp = fila.inicio;
        fila.inicio = fila.inicio->prox;
        temp->prox = NULL;

        pilha.inserir(temp->valor);
        delete temp;
    }

    while (!pilha.vazia()) {
        No* temp = new No();
        temp->valor = pilha.topoPilha();
        temp->prox = NULL;

        if (fila.inicio == NULL) {
            fila.inicio = temp;
            fila.fim = temp;
        } else {
            fila.fim->prox = temp;
            fila.fim = temp;
        }

        pilha.remover();
    }
}

int main() {
    Fila f;

    f.inserir(1);
    f.inserir(5);
    f.inserir(21);
    f.inserir(7);
    f.inserir(8);
    
    f.imprimir();
    
    inverterOrdem(f);

    f.imprimir();

    return 0;
}
