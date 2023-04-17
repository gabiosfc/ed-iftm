// Online C++ compiler to run C++ program online
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

    int tamanho() { 
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

    void removerN(int x) {
        for (int i = 0; i < x; i++) {
            removerFinal();
        }
    }

    void removerSegundo() {
        if (tamanho() == 2) {
            removerFinal();
        } else if (tamanho() > 2) {
            No *aux = cabeca->prox;
            cabeca->prox = aux->prox;
            delete(aux);
            n--;
        }
    }

    void inserirTamanho() {
        inserirFinal(tamanho());
    }

    void inserirN(int x) {
        for (int i = 1; i <= x; i++) {
            inserirFinal(i);
        }
    }

    void inserirPenultima(int x) {
        if (tamanho() > 1) {
            No *penultimo = cabeca;
            while (penultimo->prox != cauda) {
                penultimo = penultimo->prox;
            }
            No *novo = new No();
            novo->valor = x;
            novo->prox = cauda;
            penultimo->prox = novo;
        }
    }
    
    bool encontrarElemento(int x) {
        No *aux = cabeca;
        while (aux != NULL) {
            if(aux -> valor == x) {
                return true;
            }
            aux = aux->prox;
        }
        return false;
    }
    
    void removerOcorrencia(int x){
        while (!vazia() && cabeca -> valor == x) {
            removerInicio();
        }  
        while (!vazia() && cauda -> valor == x){
            removerFinal();
        } 
        No *aux = cabeca;
        No *anterior = aux;
        while (!vazia() && aux != NULL) {
            if(aux -> valor == x) {
                No *aux2 = aux;
                anterior -> prox = aux -> prox;
                anterior = anterior;
                aux = aux->prox;
                delete(aux2);
                n--;
            } else {
                anterior = aux;
                aux = aux->prox;
            }
        }
    }
    
    void inserirElementoInexistente(int x){
        if(encontrarElemento(x) == false){
            inserirFinal(x);
        }
    }

};
                    

int main() {

    Lista l;
    l.inserirFinal(5);
    l.inserirFinal(10);
    l.inserirFinal(5);
    l.inserirFinal(6);
    l.inserirFinal(8);
    l.inserirFinal(5);
    l.inserirFinal(7);
    l.inserirFinal(5);
    l.inserirFinal(5);
    l.inserirFinal(5);
    l.inserirFinal(5);


    l.imprimir();
    
    //1. Criar um método capaz de retornar se um determinado elemento existe na lista (true ou false).
    printf("\nExercício 1\n");
    printf("Elemento existe na lista? %s\n", l.encontrarElemento(5) ? "true" : "false");
    
    //2. Criar um método capaz de, se caso um determinado elemento exista na lista, remover todas as ocorrências esse elemento.
    printf("\nExercício 2\n");
    l.removerOcorrencia(5);
    l.imprimir();
    
    //3. Criar um método capaz de inserir um elemento no final da lista apenas se o mesmo não existir. Se o mesmo já estiver presente, seu método não deve fazer nada.
    printf("\nExercício 3\n");
    l.inserirElementoInexistente(10);
    l.inserirElementoInexistente(22);
    l.imprimir();
    
    printf("\nTamanho da lista: %d\n", l.tamanho());

    return 0;
}
