#include <stdio.h>
#include <stdlib.h>

/*
	1. strdup �Լ���, malloc�� ȣ���Ͽ� src�� ������ ��,
	   ����� ���ο� ���ڿ��� ���� �����͸� ��ȯ�ϴ� �Լ��̴�.
	2. ��ȯ�� �����ʹ� free() �Լ��� �̿��Ͽ� ������ �����Ѵ�.
	3. ���ο� ���ڿ� ������ ������ ���, NULL�����͸� ��ȯ�Ѵ�.
*/

// malloc(�ش� string�� null�� ������ ������)

char* ft_strdup(char* src)
{
	int i;
	char* dest;
	
	if (!src)
		return NULL;
	i = 0;
	while (src[i])	//	null�� ������ src�� size�� ���Ѵ�.
		i++;

	//dest = (char*)malloc((i + 1) * sizeof(char));
	if (!(dest = (char*)malloc((i + 1) * sizeof(char))))
		return (NULL);
	// ()�� �켱���ǿ� ���ؼ� dest�� ����� �־��� ��,
	// �ش� ����� NULL�� ���, NULL�� �����ϰ� �Ѵ�.

	i = 0;
	while (src[i])
	{
		dest[i] = src[i]; // src���ڿ��� dest�� �����Ѵ�.
		i++;
	}
	dest[i] = '\0';

	return dest; // �ش� src�� �纻�� ���ڿ��� ��ȯ�Ѵ�.
}

int main()
{
	char a[] = "hello";
	char* tmp = ft_strdup(a);
	printf("%s", tmp);
	free(tmp);

	return 0;
}