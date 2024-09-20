#include <stdio.h>
#include <stdlib.h>

#define INT_MIN     (-2147483647 - 1)
#define INT_MAX       2147483647

/*
	1. range�Լ���, ������ �ּҰ� ���ڿ�������
	   �ִ밪 ���� ������ ��� ���� �����Ѵ�.
	2. �ּҰ��� �ִ밪���� ũ�ų� ������ NULL�����͸� ��ȯ�Ѵ�.
*/

int* ft_range(int min, int max)
{
	int i;
	int* arr;

	if (min >= max)
		return NULL;

	arr = (int*)malloc((max - min) * sizeof(int));
	if (!arr)
		return NULL;
	i = 0;
	while (min < max)
	{
		arr[i++] = min++; // min��ü�� 1���� �þ min.
	}
	return arr;
}

int main()
{
	int* a;
	int min = 2;
	int max = 4;
	a = ft_range(min, max);
	for(int i = 0; min < max; ++min)
	{
		printf("%d ", a[i++]);
	}
	free(a);

	return 0;
}