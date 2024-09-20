#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define BASE1  12000000.0
#define BASE2  46000000.0
#define BASE3  88000000.0
#define BASE4 150000000.0
#define BASE5 300000000.0
#define BASE6 500000000.0

#define RATE1 (6.0 / 100.0)
#define RATE2 (15.0 / 100.0)
#define RATE3 (24.0 / 100.0)
#define RATE4 (35.0 / 100.0)
#define RATE5 (38.0 / 100.0)
#define RATE6 (40.0 / 100.0)

#define BASIC_DEDUCTION 1500000.0

int main()
{
	double income = 0.0;
	double tax = 0.0;

	scanf("%lf", &income);

	income -= BASIC_DEDUCTION;

	if (income <= BASE1)
	{
		tax = income * RATE1;
	}
	else if (income <= BASE2)
	{
		tax = BASE1 * RATE1 + (income - BASE1) * RATE2;
	}
	else if (income <= BASE3)
	{
		tax = BASE1 * RATE1 + (BASE2 - BASE1) * RATE2 + (income - BASE2) * RATE3;
	}
	
	printf("Tax is = %f\n", tax);
	printf("Your income after tax deduction = %f", income - tax);

	return 0;
}