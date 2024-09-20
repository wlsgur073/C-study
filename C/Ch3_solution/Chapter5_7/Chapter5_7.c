#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main()
{
	int hours=0, minutes=0, seconds=0;

	while (seconds >= 0)
	{
		printf("Input seconds : ");
		scanf("%d", &seconds);

		minutes = seconds / 60;
		seconds %= 60;

		hours = minutes / 60;
		minutes %= 60;

		if (seconds < 0)
			return;

		printf("%d hours, %d minutes, %d seconds\n", hours, minutes, seconds);

	}

	return 0;
}