#include "rush02.h"

char* trim_left(char* str)
{
	while (*str && is_white_space(*str))
		++str;
	return (str);
}

void	trim_right(char* str)
{
	if (!*str)
		return;
	while (*str)
		++str;
	--str;
	while (is_white_space(*str))
		--str;
	*(++str) = 0;
}

char* trim_side(char* str)
{
	char* ret;
	char* begin;
	char* end;

	if (!*str)
		return (0);
	begin = str;
	while (*begin && is_white_space(*begin))
		++begin;
	end = begin;
	while (*end)
		++end;
	--end;
	while (is_white_space(*end))
		--end;
	ret = (char*)malloc(end - begin + 2);
	ft_strcpy(ret, begin, end);
	return (ret);
}

/*
** remove white-space of the side of the string argument
*/

char* trim_allocated_str(char* str)
{
	char* ret;

	ret = trim_side(str);
	free(str);
	return (ret);
}