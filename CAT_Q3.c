/*
Name:Graham wafula 
Reg No:PA106/G/28759/25
*/
#include <stdio.h>
int main() {
    FILE *f1, *f2;
    int i, n, sum = 0, count = 0;
    float avg;

    f1 = fopen("input.txt", "w");
    if (f1 == NULL) {
        printf("Error\n");
        return 0;
    }

    printf("Enter 10 numbers:\n");
    for (i = 0; i < 10; i++) {
        scanf("%d", &n);
        fprintf(f1, "%d\n", n);
    }
    fclose(f1);

    f1 = fopen("input.txt", "r");
    f2 = fopen("output.txt", "w");
    if (f1 == NULL || f2 == NULL) {
        printf("Error\n");
        return 0;
    }

    while (fscanf(f1, "%d", &n) == 1) {
        sum = sum + n;
        count++;
    }

    avg = (float)sum / count;

    fprintf(f2, "Sum = %d\n", sum);
    fprintf(f2, "Average = %.2f\n", avg);

    fclose(f1);
    fclose(f2);

    printf("\ninput.txt:\n");
    f1 = fopen("input.txt", "r");
    while ((n = fgetc(f1)) != EOF)
        putchar(n);
    fclose(f1);

    printf("\noutput.txt:\n");
    f2 = fopen("output.txt", "r");
    while ((n = fgetc(f2)) != EOF)
        putchar(n);
    fclose(f2);

    return 0;
}
