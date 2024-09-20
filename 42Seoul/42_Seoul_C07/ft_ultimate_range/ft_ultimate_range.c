#include <stdio.h>
#include <stdlib.h>
/*
	a - > *ptr = &a -> **ptrptr = &ptr.
	main�� arr�� �ּҸ� **range�� �޾Ƽ�
	*range�� &arr�� ����.
*/

int ft_ultimate_range(int** range, int min, int max)
{
	int i;
	int* tmp;

	if (min >= max) // NULL����Ʈ�� �߻��� 0�� ��ȯ�Ǵ� �Ѵ� ����
	{
		*range = NULL;
		return 0;
	}

	*range = (int*)malloc((max - min) * sizeof(int));
	// main�� arr�� ����� �־��ִ� �Ͱ� ���� �ǹ�.
	// ���� if������ *arr�� NULL�� ��, �����̴� -1�� ��ȯ��.
	if (!*range)
	{
		*range = 0; // ���� �����Ⱚ�� �ڿ� ���� �� ������ ���½�����.
		return -1;
	}

	i = 0;
	tmp = *range;			// *range�� &arr�� �޾Ұ� �ּҸ� �ٲ� �� ���⿡ tmp���� �޾���
	while (min + i < max)
	{
		tmp[i] = min + i;	// min��ü�� 1���� �þ min.
		i++;
	}
	return (max - min);
}

int main()
{
	int* arr;
	int max = 15;
	int min = 5;

	printf("%d", ft_ultimate_range(&arr, min, max));

	return 0;
}