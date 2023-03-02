#include<stdio.h>

struct No {
    int value;
    No *next;

};

//lista é uma estrtura de dados dinâmica do tipo sequencial
struct Lista {
    No *head, *tail;
    int n;
    //Criar método construtor que apontará a cabeça e a cauda para NULL
    Lista() {
        head = tail = NULL;
    }

    bool vazia() {
        return (head == NULL);
    }

    void inserirInicio(int v) {
        No *novo = new No();
        novo -> value = v;
        if(vazia()) {
            novo->next = NULL;
            head = novo;
            tail = novo;
        } else {
            novo -> next = head;
            head = novo;
        }
    }

    void inserirFinal(int v) {
        No *novo = new No();
        novo -> value = v;
        if(vazia()) {
            novo -> next = NULL;
            head = novo;
            tail = novo;
        } else {
            novo -> next = NULL;
            tail -> next = novo;
            tail = novo;
        }
    }

    int tamanho(){
        int t = 0;
        No *aux = head;
        while(aux != NULL) {
            t++;
            aux = aux -> next;
        }
        return t;
    }

    void removerInicio() {
        if (!vazia()) {
            if (tamanho() == 1) {
                No *aux = head;
                head = NULL;
                tail = NULL;
                delete(aux);
            } else {
                No *aux = head;
                head = head -> next;
                delete(aux);
            }
            n--;
        }
    }

    void removerFinal() {
        if (!vazia()) {
            if (tamanho() == 1) {
                No *aux = head;
                head = NULL;
                tail = NULL;
                delete(aux);
            } else {
                No *penultimo = head;
                while (penultimo -> next != tail) {
                    penultimo = penultimo -> next;
                }
                delete(tail);
                tail = penultimo;
                tail -> next;
                tail -> next = NULL;
            }
            n--;
        }
    }

    void imprimir() {

        /*for(No *aux = head; aux != NULL; aux = aux -> next){
            printf("%d\n", aux -> value);
        }
        */

        No *aux = head;
        while (aux != NULL){
            printf("%d\n", aux -> value);
            aux = aux -> next;
        }
    }

};


int main() {

    Lista l;
    l.inserirInicio(1);
    l.inserirInicio(3);
    l.inserirInicio(5);
    l.inserirInicio(7);
    l.inserirInicio(9);

    l.inserirFinal(0);
    l.inserirFinal(2);
    l.inserirFinal(4);
    l.inserirFinal(6);
    l.inserirFinal(8);

    l.removerInicio();
    l.removerInicio();

    l.removerFinal();
    l.removerFinal();

    l.imprimir();


    return 0;
}
