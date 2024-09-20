#include <stdio.h>
#include <stdlib.h>

#define INT_MIN     (-2147483647 - 1)
#define INT_MAX       2147483647

/*
	1. range함수란, 설정된 최소값 인자에서부터
	   최대값 인자 사이의 모든 값을 리턴한다.
	2. 최소값이 최대값보다 크거나 같으면 NULL포인터를 반환한다.
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
		arr[i++] = min++; // min자체와 1개씩 늘어난 min.
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