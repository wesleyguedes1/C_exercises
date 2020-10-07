#include <stdio.h>
int main (void) {
    int visa = 0;
    int f_digit = 0;
    int sec_digit = 0;
    int master = 0;
    int amex = 0;
    long long int divider = 1;
    long long int number;
    long long int module = 10;
    printf("Number:");
    scanf("%lld", &number);
    int num_length = 0;
    int i = 0;
    long long int j = number;
    long long int sum1 = 0;
    long long int sum2 = 0;
    // loop pra pegar o "tamanho" do número
    for (j; j > 0;) {
        j/=10;
        num_length+=1;
    }
    printf("Tamanho do número: %d\n", num_length);
    //loop pra pegar cada dígito do número
    if (num_length > 12  && num_length < 17) {
        do {
            long long int result = ((number % module) / divider );
            if (i % 2 != 0) {
                if ((result * 2) > 9) {
                    sum1+= (result * 2) % 10;
                    sum1+= (result * 2) / 10;
                } else {
                    sum1+= result * 2;
                }
            } else {
                sum2+= result;
            }
            if (i == 13) {
                if (result == 7 || result == 40) {
                    amex+=1;
                }
            }
            if (i == 14) {
                if (result == 1 || result == 2 || result == 3 || result == 4 || result == 5) {
                    master+=1;
                }
            }
            module*=10;
            divider*=10;
            f_digit = result;
            i++;
        } while (i < num_length);
        printf("Valor de i: %d\n", i);
        //checar a quantidade de dígitos e os primeiros dígitos
        int check_sum = sum1 + sum2;
        int valid_card = check_sum % 10;
        //se a soma de sum1 e sum2 em módulo 10 (aka o útimo dígito do resultado) for igual a zero:
        if (valid_card == 0) {
            if (i == 15 && f_digit == 3) {
                amex+=1;
            } else if (i == 16 && f_digit == 5) {
                master+=1;
            } else if (i == 13 || i == 16){
                if (f_digit == 4) {
                    visa+=2;
                }
            }
            if (amex == 2) {
                printf("AMEX\n");
            } else if (master == 2) {
                printf("MASTERCARD\n");
            } else if (visa == 2) {
                printf("VISA\n");
            }
        } else {
            printf("INVALID\n");
        }
    } else {
        printf("INVALID\n");
    }
}