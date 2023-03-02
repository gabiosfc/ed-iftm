#include<stdio.h>

int main(){

    //endereço de memória da variável: &
    //ponteiro: *

    int a;
    scanf("%d", &a);
    printf("%d\n", a);

    //variável inteiro do tipo ponteiro que recebe o endereço de memória da variável 'a'
    int *p = &a;
    //ex: a : endereço 100 : valor 3
    //ex: p : endereço 101 : valor 100

    //imprime o endereço de memória da variável a
    printf("%d\n", p);

    //imprime o valor que está no endereço de memória do ponteiro, no caso é o valor de a
    printf("%d\n", *p);

    return 0;

}
