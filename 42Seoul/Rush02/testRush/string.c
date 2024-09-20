void	ft_strcpy(char* dst, char* begin, char* end)
{
	while (begin <= end)
		*(dst++) = *(begin++);
	*dst = 0;
}

int		ft_strlen(char* str)
{
	int ret;

	ret = 0;
	while (str[ret])
		++ret;
	return (ret);
}

int		ft_is_equal(char* a, char* b)
{
	while (*a && *b && *a == *b)
	{
		++a;
		++b;
	}
	return (*a == *b);
}