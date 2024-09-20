#include <stdio.h>
#include <stdlib.h>

int checker(char c, char* charset)
{
	int i;

	i = 0;
	if (c == '\0')
		return 1;
	while (charset[i])
	{
		if (c == charset[i])
			return 1;
		i++;
	}
	return 0;
}

int count_words(char* str, char* charset)
{
	int count;

	count = 0;
	while (*str)
	{
		while (checker(*str, *charset))
			str++;
		if (*str == '\0')
			break;
		while (!checker(*str, *charset) && *str != '\0')
			str++;
		count++;
	}
	return count;
}

char* ft_strdup(char* str)
{
	int i;
	char* ret;

	i = 0;
	if (!str)
		return NULL;
	while (str[i])
		i++;
	if (!(ret = (char*)malloc((i + 1) * sizeof(char))))
		return NULL;
	i = 0;
	while (str[i])
	{
		ret[i] = str[i];
		i++;
	}
	ret[i] = '\0';
	return ret;
}

char** ft_split(char* str, char* charset)
{
	char** ret;
	int i;
	int count;

	count = count_words(*str, *charset);
	if (!(ret = malloc((count + 1) * sizeof(char*))))
		return NULL;
	i = 0;
	while (*str)
	{
		while (checker(*str, *charset))
			str++;
		if (*str == '\0')
			break;
		while (!checker(*str, *charset) && *str != '\0')
			str++;
		ret[i] = ft_strdup(*str);
		i++;
	}
	ret[i] = 0;
	return ret;
}

int main()
{
	char a[] = "  hello world yes!";
	char b[] = " ";
	char** test = ft_split(a, b);
	int i = 0;
	while (test[i])
	{
		printf("%s ", test[i]);
		i++;
	}

	return 0;
}