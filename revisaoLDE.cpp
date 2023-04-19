// Online C++ compiler to run C++ program online
#include<stdio.h>
#include <time.h>

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
        limpar();
        No *aux = cabeca;
        while (aux != NULL) {
            printf("%d\n", aux->valor);
            aux = aux->prox;
        }
    }

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
    
    void timestamp() {
        struct tm *p;
        time_t seconds;
    
        time(&seconds);
        p = localtime(&seconds);

        printf("\nData: %d/%d/%d\n", p->tm_mday, p->tm_mon + 1, p->tm_year + 1900);
        printf("Hora: %d:%d:%d\n", p->tm_hour, p->tm_min, p->tm_sec);
        
        /*time_t mytime;
        mytime = time(NULL);
        printf(ctime(&mytime));*/

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
    l.inserirFinal(6);
    l.inserirFinal(8);
    l.inserirFinal(5);
    l.inserirFinal(7);
    l.inserirFinal(5);
    l.inserirFinal(5);



    l.imprimir();

    
    printf("\nTamanho da lista: %d\n", l.tamanho());
    
    l.timestamp();

    return 0;
}
