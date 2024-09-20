#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

/*
	split�Լ���, ���ڿ��� �ٸ� ���ڿ��� ������ �Լ��̴�.
	���ڿ� charset�� �� ���ڴ� str���ڿ��� �����ϱ� ���� �����ڷ� ���.
	�� �Լ��� �迭�� �� �׿� �� ���� �����ڷ� �ѷ����� ���ڿ��� �ּҰ� ���ԵǾ�
	�ִ� �迭�� ��ȯ�մϴ�. �迭�� ���������� 0�� �ش��ϴ� ���� �־� �迭�� ������
	ǥ���ؾ� �Ѵ�.
	�迭�� �� ���ڿ��� �����ϴ�. �̸� ������ ��ȥ�� ������ ����.
	���ڷ� �־��� ���ڿ��� ������ �� ����.
	
	ex.) str = "�ź� ���� ���� ������ ���� ���� �� ����"
		 ft_split(str)
	<�����>
	-> {'�ź�', '����', '����', '������', '����', '����', '��', '����'}
	���ڿ��� ������ �ܾ �и���Ű�� ���̴�.
*/

/*
* �Լ��� ���� �������� ������ main���� 2���� �迭�� ǥ���� �� �ֱ� �����̴�.
* "1����", "2����", "3����"�� �ް� �Ǹ�, [row][col]���� ǥ������ ��,
* [0][0]�� "1����", [0][1]�� "2����"
*/

char* ft_strcpy(char* dest, char* src)
{
	while (*src)
	{
		*dest = *src;
		src++;
		dest++;
	}
	return dest;
}

char** ft_split(char* str, char* charset)
{
	static char* sp;
	char* tp;
	char* rp;

	if(sp == NULL)
		sp = str;

	if(*sp == '\0')
		return NULL;

	tp = sp;
	while ((*tp != *charset) && (*tp != '\0'))
	{
		tp++;
	}
	if (*tp != '\0')
	{
		*tp = '\0';
		tp++;
	}

	rp = sp;
	sp = tp;
	return rp;
}

int main()
{
	char a[] = "hello world! there";
	char b[] = " ";
	char **test;
	test = ft_split(a, b);
	/*while (test = ft_split(a, b))
	{
		printf("%s\n", test);
	}*/
	printf("%s", test[0]);

	/*char *maybe;
	maybe = strtok(a, b);
	while (maybe != NULL)
	{
		printf("%s\n", maybe);
		maybe = strtok(NULL, b);
	}*/

	return 0;
}

/*
	static ������ ������ ���� ȣ���ϸ� NULL�� ������ �ִ´�.

char * my_token(char* str)
{
	static char* sp; // static�� �����ؼ� sp�Լ��� ��ȯ�ص� �ٽ� �θ� �� �ش� ���� �����ϰ� �ִ´�.
	char * tp;
	char * rp;

	if(sp == NULL)
		sp = str; // sp�� str�� ù �ּҸ� ����ϰ� ���� ���̴�.
	// ó�� sp�� ȣ���� ���� null�� str�� ù �ּҸ� ������,
	// ���� ȣ���� ���� str�� ù �ּҷ� �ʱ�ȭ�ϸ� �ȵǴ� ���� ���� �������Ѿ� �ؼ� if���� ����.

	if(*sp == '\0') // sp�� ��� str�� �дٰ� ������ \0�� ������ return NULL
		return NULL;

	tp = sp; // tp�� ���� nullȤ��, �ش� Ư�����ڱ��� �ּҸ� ���ư���.
	while((*tp != '\0') && (*tp != ' '))
	{
		tp++;
	}
	if(*tp != '\0')
	{
		*tp = '\0'; // ���� ������ null�� �־��ְ�, �� ĭ ������ ������.
		tp++; // �ش� ���ڿ��� ù �ּҸ� ����Ű�� �ȴ�.
	}
	rp = sp; // tp�� sp�� �˸��� ����, rp�� sp�� ù �ּҸ� �������ش�.
	sp = tp; // tp�� sp�� �־� ���� �ܰ��� ���ڿ� ù �ּҸ� sp�� �˷��ش�.

	return rp;
*/