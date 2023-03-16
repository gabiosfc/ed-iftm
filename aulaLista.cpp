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
    
    //1. Criar um método que recebe um número N e remove os N últimos elementos da lista. Caso o tamanho da lista seja menor que N, esvaziar a lista.
    void reduzirLista(int v) {
        for (int i = 0; i < v; i++) {
            removerFinal();
        }
    }

    //2. Crie um método que remove o segundo elemento da lista. Se a lista tiver tamanho <= 1, seu método não deve fazer nada. 
    void removerSegundoElemento(){
        if (!vazia()) {
            if (tamanho() == 2) {
                removerFinal();
            } else if (tamanho() > 2){
                No *aux = cabeca -> prox;
                cabeca -> prox = aux -> prox;
                delete(aux);
                n--;
            }
        }
    }

    //3. Crie um método que seja capaz de inserir no final da lista o tamanho atual da lista.
    void inserirTamanhoFinal() {
        inserirFinal(tamanho());
    }

    //4. Crie um método que receba um número N e insira na lista todos os números de 1 até N.
    void inserirNCrescente(int v) {
        int aux = 1;
        for (int i = 0; i < v; i++){
            inserirFinal(aux);
            aux++;
        }
    }

    //5.Crie um método que insere um elemento sempre na penúltima posição da lista. Se a lista tiver tamanho <= 1, seu método não deve fazer nada. 
   void inserirPenultimo(int v) {
        if (tamanho() > 1) {
            No *penultimo = cabeca;
            while(penultimo->prox !=cauda){
                penultimo = penultimo -> prox;
            }
            No *novo = new No();
            novo -> valor = v;
            novo -> prox = cauda;
            penultimo -> prox = novo;
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
    
    printf("Exercício 1\n");
    l.reduzirLista(3);
    l.imprimir();
    printf("Exercício 2\n"); 
    l.removerSegundoElemento();
    l.imprimir();
    printf("Exercício 3\n"); 
    l.inserirTamanhoFinal();
    l.imprimir();
    printf("Exercício 4\n"); 
    l.inserirNCrescente(12);
    l.imprimir();
    printf("Exercício 5\n"); 
    l.inserirPenultimo(20);
    l.imprimir();
    
 
    return 0;
}
