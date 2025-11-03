#include <stdio.h>
#include <stdlib.h>

void writeInputFile();
void processNumbers();
void displayFiles();

int main() {
    writeInputFile();
    processNumbers();
    displayFiles();
    return 0;
}

// 1?? Function to write 10 integers into input.txt
void writeInputFile() {
    FILE *fp = fopen("input.txt", "w");
    if (fp == NULL) {
        printf("Error opening input.txt for writing!\n");
        exit(1);
    }

    int num,i;
    printf("Enter 10 integers:\n");
    for (int i = 0; i < 10; i++){
        scanf("%d", &num);
        fprintf(fp, "%d\n", num);
    }

    fclose(fp);
    printf("Numbers saved to input.txt successfully.\n\n");
}

// 2?? Function to read numbers, find sum and average, and write to output.txt
void processNumbers() {
    FILE *in = fopen("input.txt", "r");
    FILE *out = fopen("output.txt", "w");

    if (in == NULL || out == NULL) {
        printf("Error opening file(s)!\n");
        exit(1);
    }

    int num, sum = 0, count = 0;
    while (fscanf(in, "%d", &num) == 1) {
        sum += num;
        count++;
    }

    float avg = (count > 0) ? (float)sum / count : 0;
    fprintf(out, "Sum = %d\nAverage = %.2f\n", sum, avg);

    fclose(in);
    fclose(out);
    printf("Sum and average written to output.txt.\n\n");
}

// 3?? Function to display contents of both files
void displayFiles() {
    FILE *in = fopen("input.txt", "r");
    FILE *out = fopen("output.txt", "r");
    char ch;

    if (in == NULL || out == NULL) {
        printf("Error opening file(s) for display!\n");
        exit(1);
    }

    printf("---- Contents of input.txt ----\n");
    while ((ch = fgetc(in)) != EOF)
        putchar(ch);

    printf("\n---- Contents of output.txt ----\n");
    while ((ch = fgetc(out)) != EOF)
        putchar(ch);

    fclose(in);
    fclose(out);
}