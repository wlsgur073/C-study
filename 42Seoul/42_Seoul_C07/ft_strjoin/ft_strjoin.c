#include <stdio.h>
#include <stdlib.h>

/*
	ex. strs = {'string', 'string', 'string'}, sep = &�� ���
	-> "string&string&string" // strjoin(strs, sep)
	delimiter - ���� ���ڷ� ������.

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
	// ������ strcpy����� �̿��ϸ� dest ù ��° �ּҿ��� ���
	// ��ü�� �Ǳ⿡, ���ڿ� ++�� �ּҿ��� �����ϰڱ� �������� �Ѵ�.

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
	// malloc�� += �����ڸ� ����� �� ���⿡, �ϳ��� int ������ ������,
	// �ش� �����Ϳ� malloc���� ������ ���̸� �����ش�.

	if(!(res = (char*)malloc(buf_len * sizeof(char))))
		return 0;
	tmp = res;
	//tmp = ft_strcpy(res, strs[0]);

	/*
		res�� strs[0] �ּҸ� �ְ� tmp���� �˸���,
		�纻�� tmp�� �����ϰ� res�� ��ȯ�Ѵ�.
		���� strs[0]�� res�� ����������, res�� ������ �ְ� ���Ұ� ���
		���߿� 
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
	*�� []�� ���� ���� ���ڿ��� ���ҷ� ���� �� �ִ�.
	printf("%p\n", a[0]); // �ش� ������ ù��° �ּ�
	printf("%p\n", &*a[0]); // a[0]�� ù��° ������ &�ּ�
*/