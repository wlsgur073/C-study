#include <unistd.h>

void ft_putstr(char *ptr)
{
	int size;

	size = 0;
	while(ptr[size])
	{
		write(1, &ptr[size], 1);
		size++;
	}
}


int main(void)
{
	char str[10] = "";
	ft_putstr(str);
}
