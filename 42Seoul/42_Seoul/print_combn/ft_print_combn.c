#include <stdio.h>
void rec(char buf[], int num, int len, int max)
{
	int i;

	if (num == 10)
		return;
	if (len == max) {
		//printf("n번째임\n");
		buf[len - 1] = num + '0';
		write(1, buf, len);
		if (buf[0] != 10 - max + '0')
			write(1, ", ", 2);
		//write(1, " ", 1);
		return;
	}
	else {
		i = num;
		while (i < 10) 
		{
			buf[len - 1] = '0' + num;
			i++;
			rec(buf, i, len + 1, max);		//max는 n이므로 항상 고정값

		}
	}
	//-------------------
}
void ft_print_combn(int n)
{
	int start_num;
	char buf[9];
	start_num = 0;
	while (start_num <= 10 - n)
	{
		buf[0] = '0' + start_num;
		rec(buf, start_num++, 1, n); //문자열, 시작 번호, 길이, 최대 갯수

	}
}
int main()
{
	ft_print_combn(4);

}