#include <io.h>
#include <stdio.h>
#include <stdlib.h>
/*
	최소값과 최대값 사이의 숫자를 출력하세요(최솟값 포함).
*/

int *ft_range(int min, int max)
{
	int i;
	int *temp;
	int *ret;

	if(min >= max)
		return 0;
	if(!(ret = (int *)malloc(sizeof(int) * max - min)))
		return NULL;
	temp = ret;
	i = 0;
	while(min < max)
	{
		ret[i] = min++;
		i++;
	}
	return (ret);
}
int main()
{
	int min = 1, max = 5, i = 0;
	int *arr;
	arr = ft_range(min, max);
	while(min < max)
	{
		printf("%d ", arr[i]);
		min++;
		i++;
	}
	return 0;
}
