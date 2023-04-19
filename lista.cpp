// Online C++ compiler to run C++ program online
#include<stdio.h>
#include <time.h>
#include <unistd.h>

using namespace std;

struct No {
    int valor;
    time_t timestamp;
    No *prox;
};

struct Lista {
    No *cabeca, *cauda;
    int n;
    int ttl;

    Lista(int _ttl) {
        cabeca = cauda = NULL;
        n = 0;
        ttl = _ttl;
    }

    bool vazia() {
        return (cabeca == NULL);
    }
    
    int tamanho() { 
        return n;
    }

    void inserirInicio(int v) { 
        time_t horaAtual = time(NULL);
        No *novo = new No();
        novo->valor = v;
        novo->timestamp = horaAtual;
        novo->prox = NULL;
        if (vazia()) {
            cabeca = novo;
            cauda = novo;
        } else {
            novo->prox = cabeca;
            cabeca = novo;
        }
        n++;
    }

    void inserirFinal(int v) {
        time_t horaAtual = time(NULL);
        No *novo = new No();
        novo->valor = v;
        novo->timestamp = horaAtual;
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
        limpar();

        No *aux = cabeca;
        while (aux != NULL) {
            printf("%d\n", aux->valor);
        
            aux = aux->prox;
        }
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

    
    
    void limpar(){
        time_t horaAtual = time(NULL);
        while(!vazia() && (horaAtual - cabeca -> timestamp) > ttl){
            removerInicio();
        }
    }
    

};
                    

int main() {


    Lista l(1);
    l.inserirFinal(5);
    l.inserirFinal(10);
    l.inserirFinal(5);
    sleep(3);
    l.inserirFinal(6);
    l.inserirFinal(8);
    l.inserirFinal(5);
    l.inserirFinal(7);
    l.inserirFinal(5);
    l.inserirFinal(5);



    l.imprimir();

    
    printf("\nTamanho da lista: %d\n", l.tamanho());


    return 0;
}
