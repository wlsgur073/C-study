#include <stdio.h>
#include <stdlib.h>

/*
	ex. strs = {'string', 'string', 'string'}, sep = &일 경우
	-> "string&string&string" // strjoin(strs, sep)
	delimiter - 구분 문자로 구분함.

	strs = { "hello", "world", "42" };
	sep = ",";
	"hello,world,42"
	* tmp = 'h';
	*(tmp + 1) = 'e';
*/

int ft_strlen(char* str)
{
	int i;

	if (!str)
		return 0;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char* ft_strcpy(char* dest, char* src)
{
	// 기존의 strcpy방식을 이용하면 dest 첫 번째 주소에서 계속
	// 교체가 되기에, 인자에 ++된 주소에서 시작하겠금 만들어줘야 한다.

	while (*src)
	{
		*dest = *src;
		src++;
		dest++;
	}
	return dest;
}

char *ft_strjoin(int size, char** strs, char* sep)
{
	int i;
	int buf_len;
	char* tmp;
	char* res;

	i = 0;
	buf_len = 0;
	while (i < size)
	{
		buf_len += ft_strlen(strs[i++]);
	}
	buf_len += ft_strlen(sep) * size - 1;
	// malloc은 += 연산자를 사용할 수 없기에, 하나의 int 변수에 저장해,
	// 해당 포인터에 malloc으로 버퍼의 길이를 정해준다.

	if(!(res = (char*)malloc(buf_len * sizeof(char))))
		return 0;
	tmp = res;
	//tmp = ft_strcpy(res, strs[0]);

	/*
		res에 strs[0] 주소를 넣고 tmp에게 알리고,
		사본인 tmp을 수정하고 res를 반환한다.
		만약 strs[0]을 res에 넣지않으면, res은 공간만 있고 원소가 없어서
		나중에 
	*/
	
	i = 0;
	while (i < size - 1)
	{
		tmp = ft_strcpy(tmp, strs[i++]);
		tmp = ft_strcpy(tmp, sep);
	}
	tmp = ft_strcpy(tmp, strs[i++]);

	*tmp = '\0';

	return res;
}

int main()
{
	char *a[] = { "hello", "world" ,"hooo" }; // -> hello&sdf&sdf
	char b[] = ", ";
	printf("%s", ft_strjoin(3, &a[0], b));
	
	//char dst[100] = "hello";
	//printf("%s", ft_strcat(dst, "world"));

	return 0;
}

/*
	char* a[] = { "hello", " " ," " };
	*랑 []를 같이 쓰면 문자열을 원소로 넣을 수 있다.
	printf("%p\n", a[0]); // 해당 원소의 첫번째 주소
	printf("%p\n", &*a[0]); // a[0]의 첫번째 원소의 &주소
*/