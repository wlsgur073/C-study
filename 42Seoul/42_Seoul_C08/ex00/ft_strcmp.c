#include "ft.h"

int ft_strcmp(char* s1, char* s2)
{
	if (s1 == NULL)
		return 0;

	while (*s1 == *s2 && *s1)
	{
		s1++;
		s2++;
	}

	return (*s1 - *s2);
}