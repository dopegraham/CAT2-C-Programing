#include <stdio.h>

int main() {
    float hrs, wage;
    float gross_pay, tax,net_pay;


    printf("Enter the hours worked in a week: ");
    scanf("%f", &hrs);
    printf("Enter the hourly wage: ");
    scanf("%f", &wage);

    if (hrs > 40) {
        gross_pay = 40 * wage + (hrs - 40) * wage * 1.5;
    } else {
        gross_pay = hrs * wage;
    }

    if (gross_pay <= 600) {
        tax = gross_pay * 0.15;
    } else {
        tax = 600 * 0.15 + (gross_pay - 600) * 0.20;
    }

    
    net_pay = gross_pay - tax;
    printf("Gross pay:%f\n",gross_pay);
    printf("Taxes:%f\n", tax);
    printf("Net pay:%f", net_pay);
	
	 return 0;
}