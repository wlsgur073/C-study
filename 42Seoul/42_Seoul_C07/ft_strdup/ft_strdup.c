#include <stdio.h>
#include <stdlib.h>

/*
	1. strdup 함수란, malloc을 호출하여 src를 복사한 후,
	   복사된 새로운 문자열에 대한 포인터를 반환하는 함수이다.
	2. 반환된 포인터는 free() 함수를 이용하여 영역을 해제한다.
	3. 새로운 문자열 생성에 실패할 경우, NULL포인터를 반환한다.
*/

// malloc(해당 string의 null을 제외한 사이즈)

char* ft_strdup(char* src)
{
	int i;
	char* dest;
	
	if (!src)
		return NULL;
	i = 0;
	while (src[i])	//	null을 제외한 src의 size를 구한다.
		i++;

	//dest = (char*)malloc((i + 1) * sizeof(char));
	if (!(dest = (char*)malloc((i + 1) * sizeof(char))))
		return (NULL);
	// ()의 우선순의에 의해서 dest에 사이즈를 넣어준 후,
	// 해당 사이즈가 NULL일 경우, NULL을 리턴하게 한다.

	i = 0;
	while (src[i])
	{
		dest[i] = src[i]; // src문자열을 dest에 복사한다.
		i++;
	}
	dest[i] = '\0';

	return dest; // 해당 src의 사본인 문자열을 반환한다.
}

int main()
{
	char a[] = "hello";
	char* tmp = ft_strdup(a);
	printf("%s", tmp);
	free(tmp);

	return 0;
}