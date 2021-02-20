#include <stdio.h>
int main(void) {
    int number = 0;
    int quantNum = 0;
    int somaNum = 0;
    int pares = 0;
    int maior = 0;
    printf("Digite um número: ");
    scanf("%d", &number);
    if (number <= 0) {
        printf("O número informado é menor ou igual à 0. Por favor tente novamente\n");
    }
    while (number > 0) {
        if (number%2==0){
            pares+=1;
        }
        if (number > maior) {
            maior = number;
        }
        quantNum+=1;
        somaNum+= number;
        printf("Digite um número: ");
        scanf("%d", &number);

    }
    float media;
    media = somaNum / quantNum;
    printf("Maior número: %d\n", maior);
    printf("Quantidade de pares: %d\n", pares);
    printf("Média: %f\n", media);
}