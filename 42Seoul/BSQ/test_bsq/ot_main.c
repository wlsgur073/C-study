#include <stdio.h>

void	sort_int_tab(int* tab, unsigned int size)
{
	unsigned int i;
	unsigned int j;
	int min;
	int temp;

	i = 0;
	if (size == 0)
		return;
	while (i < size - 1)
	{
		j = i;
		min = tab[i];
		while (j < size)
		{
			if (min > tab[j])
			{
				temp = tab[j];
				tab[j] = min;
				min = temp;
			}
			j++;
		}
		tab[i] = min;
		i++;
	}
}

int main()
{
	int a[] = { 1, 2, 6, 4, 5, 5, 8 };
	sort_int_tab(a, 7);
}