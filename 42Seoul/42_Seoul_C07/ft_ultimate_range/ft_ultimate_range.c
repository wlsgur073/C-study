#include <stdio.h>
#include <stdlib.h>
/*
	a - > *ptr = &a -> **ptrptr = &ptr.
	main의 arr의 주소를 **range가 받아서
	*range는 &arr를 뜻함.
*/

int ft_ultimate_range(int** range, int min, int max)
{
	int i;
	int* tmp;

	if (min >= max) // NULL포인트가 발생해 0이 반환되니 둘다 넣음
	{
		*range = NULL;
		return 0;
	}

	*range = (int*)malloc((max - min) * sizeof(int));
	// main의 arr에 사이즈를 넣어주는 것과 같은 의미.
	// 다음 if문에서 *arr가 NULL일 때, 오류이니 -1를 반환함.
	if (!*range)
	{
		*range = 0; // 남은 쓰레기값이 뒤에 있을 수 있으니 리셋시켜줌.
		return -1;
	}

	i = 0;
	tmp = *range;			// *range는 &arr를 받았고 주소를 바꿀 수 없기에 tmp으로 받아줌
	while (min + i < max)
	{
		tmp[i] = min + i;	// min자체와 1개씩 늘어난 min.
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