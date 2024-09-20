#include <stdio.h>

unsigned int ft_strlen(const char* str)
{
	unsigned int i;
	i = 0;
	while (str[i])
		i++;
	return (i);
}

unsigned int	ft_strlcat(char* dest, char* src, unsigned int size)
{
	unsigned int i;
	unsigned int j;

	i = 0;
	j = 0;
	if (size == 0)
		return ft_strlen(src);
	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0' && j + 1 < size)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	if (size != 0)
		dest[i] = '\0';
	return i;
}

int main()
{
	char a[10] = "ABCDE";
	char b[] = "HELL";
	printf("me : %d\n", ft_strlcat(a, b, 0));
	return 0;
}