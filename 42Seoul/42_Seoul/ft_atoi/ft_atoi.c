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
* 문자열을 int 정수로 바꿔주는 함수 (atoi)
1. int로 표현할 수 없는 범위인 값일 경우에는 미정의 동작이 발생.
2. white space를 무시한다.
3. +또는 -기호로 시작할 수 있다. -만 기호가 표시됨.
4. 10진수 기반으로 분석한다.
5. 숫자들이 온 다음에, 그렇지 않는 문자들이 오면 무시한다.
6. 공백 문자만 들어있거나, 빈 문자열일 경우 0이 리턴된다.
*/