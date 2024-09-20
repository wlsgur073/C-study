#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void display(char cr, int lines, int width);

int main()
{
	char c;
	int rows, cols;

	while ((c = getchar()) != '\n')
	{
		scanf("%d %d", &rows, &cols);

		//while (getchar() != '\n') continue;

		display(c, rows, cols);
	}
	return 0;
}

void display(char cr, int lines, int width)
{
	int i, j;

	for (int i = 0; i < lines; ++i)
	{
		for (int j = 0; j < width; ++j)
			printf("%c", cr);
		printf("\n");
	}
}