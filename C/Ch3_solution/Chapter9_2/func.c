#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define WIDTH 40
#define NAME "Jin-Hyeok Kim"
#define ADDRESS "Deajeon, Korea"

void print_multiple_chars(char c, int n_stars, bool endl)
{
	for (int i = 0; i < n_stars; ++i)
		putchar(c);
	if (endl)
		printf("\n");
}

void print_centered_str(char str[])
{
	int n_blanks = 0;

	n_blanks = (WIDTH - strlen(str)) / 2;
	print_multiple_chars(' ', n_blanks, 0);
	printf("%s\n", str);
}

int main()
{

	print_multiple_chars('*', WIDTH, true);
	//printf("\n");

	print_centered_str(NAME);
	print_centered_str(ADDRESS);

	print_multiple_chars('*', WIDTH, false);

	return 0;
}