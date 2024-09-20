#include <stdio.h>

char is_space(char c)
{
	if (c == '\n' || c == '\t' || c == ' '||
		c == '\f' || c == '\v' || c == '\r')
		return (c);
	return NULL;
}

int is_num(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int ft_atoi(char* str)
{
	int i;
	int r;

	i = 1;
	r = 0;

	if (*str == NULL)
		return (0);
	while (is_space(*str))
	{
		str++;
	}
	while (*str == '-')
	{
		i *= -1;
		str++;
	}
	while (is_num(*str))
	{
	 	r = r * 10 + *str - '0';
		str++;
	}
	return (r * i);
}

int main()
{
	printf("%d\n", ft_atoi("  -123 -- a"));

	return 0;
}

/*
* ���ڿ��� int ������ �ٲ��ִ� �Լ� (atoi)
1. int�� ǥ���� �� ���� ������ ���� ��쿡�� ������ ������ �߻�.
2. white space�� �����Ѵ�.
3. +�Ǵ� -��ȣ�� ������ �� �ִ�. -�� ��ȣ�� ǥ�õ�.
4. 10���� ������� �м��Ѵ�.
5. ���ڵ��� �� ������, �׷��� �ʴ� ���ڵ��� ���� �����Ѵ�.
6. ���� ���ڸ� ����ְų�, �� ���ڿ��� ��� 0�� ���ϵȴ�.
*/