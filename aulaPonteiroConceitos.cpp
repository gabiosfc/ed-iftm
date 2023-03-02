#include<stdio.h>

int main(){

    //endere�o de mem�ria da vari�vel: &
    //ponteiro: *

    int a;
    scanf("%d", &a);
    printf("%d\n", a);

    //vari�vel inteiro do tipo ponteiro que recebe o endere�o de mem�ria da vari�vel 'a'
    int *p = &a;
    //ex: a : endere�o 100 : valor 3
    //ex: p : endere�o 101 : valor 100

    //imprime o endere�o de mem�ria da vari�vel a
    printf("%d\n", p);

    //imprime o valor que est� no endere�o de mem�ria do ponteiro, no caso � o valor de a
    printf("%d\n", *p);

    return 0;

}
