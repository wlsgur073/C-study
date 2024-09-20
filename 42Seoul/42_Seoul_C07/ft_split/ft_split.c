#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

/*
	split함수란, 문자열을 다른 문자열로 나누는 함수이다.
	문자열 charset의 각 문자는 str문자열을 구분하기 위한 구분자로 사용.
	이 함수는 배열의 각 항에 두 개의 구분자로 둘러싸인 문자열의 주소가 포함되어
	있는 배열을 반환합니다. 배열의 마지막에는 0에 해당하는 값을 넣어 배열의 끝임을
	표시해야 한다.
	배열에 빈 문자열은 없습니다. 이를 감안해 결혼을 도출해 보자.
	인자로 주어진 문자열은 수정할 수 없다.
	
	ex.) str = "거봉 수박 포도 복숭아 망고 딸기 배 참외"
		 ft_split(str)
	<결과물>
	-> {'거봉', '수박', '포도', '복숭아', '망고', '딸기', '배', '참외'}
	문자열의 각각의 단어를 분리시키는 것이다.
*/

/*
* 함수가 이중 포인터인 이유는 main에서 2차원 배열로 표현할 수 있기 때문이다.
* "1원소", "2원소", "3원소"로 받게 되면, [row][col]으로 표현했을 때,
* [0][0]은 "1원소", [0][1]은 "2원소"
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
	static 포인터 변수를 최초 호출하면 NULL을 가지고 있는다.

char * my_token(char* str)
{
	static char* sp; // static을 선언해서 sp함수를 반환해도 다시 부를 때 해당 값을 유지하고 있는다.
	char * tp;
	char * rp;

	if(sp == NULL)
		sp = str; // sp는 str의 첫 주소를 기억하고 있을 것이다.
	// 처음 sp를 호출할 떄는 null로 str의 첫 주소를 보지만,
	// 다음 호출할 때도 str의 첫 주소로 초기화하면 안되니 다음 값을 유지시켜야 해서 if문을 쓴다.

	if(*sp == '\0') // sp가 계속 str를 읽다가 마지막 \0를 만나면 return NULL
		return NULL;

	tp = sp; // tp로 다음 null혹은, 해당 특수문자까지 주소를 나아간다.
	while((*tp != '\0') && (*tp != ' '))
	{
		tp++;
	}
	if(*tp != '\0')
	{
		*tp = '\0'; // 정지 지점에 null을 넣어주고, 한 칸 앞으로 나간다.
		tp++; // 해당 문자열의 첫 주소를 가리키게 된다.
	}
	rp = sp; // tp를 sp에 알리기 전에, rp로 sp의 첫 주소를 기억시켜준다.
	sp = tp; // tp를 sp로 넣어 다음 단계의 문자열 첫 주소를 sp에 알려준다.

	return rp;
*/