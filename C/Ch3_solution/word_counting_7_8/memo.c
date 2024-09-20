#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

#define STOP '.'

int main()
{
	int count = 0, lines = 0, words = 0;
	char input;
	bool word_flag = false;
	bool line_flag = false;

	printf("Enter text : \n");

	while ((input = getchar()) != STOP)
	{
		if (isalpha(input))
			count++;

		if (isalpha(input) && !word_flag)
		{
			words++;
			word_flag = true;
		}
		else if (isspace(input))
			word_flag = false;

		if (!isspace(input) && !line_flag)
		{
			lines++;
			line_flag = true;
		}
		else if (input == '\n')
			line_flag = false;
	}
	printf("count = %d, Words = %d, Lines = %d", count, words, lines);


	return 0;
}