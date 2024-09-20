#include <stdio.h>

unsigned char* g_hex;

void ft_putchar(char c)
{
	write(1, &c, 1);
}

void print_str(unsigned char* str, unsigned int len)
{
	unsigned int i;

	i = 0;
	while (i < 16 && i + 1 < len)
	{
		if (str[i] >= 32 && str[i] <= 126)
			ft_putchar(str[i]);
		else
			ft_putchar('.');
		i++;
	}
}

void print_hex(unsigned char* str, unsigned int len)
{
	unsigned int i;

	i = 0;
	while (i < 16 && i + 1 < len) // && str[i] 마지막 낮은 사이즈를 처리해주지 못하고 있음. size < 16일때 뒤가 쓰레기값으로 나옴
	{
		if (i % 2 == 0)
			ft_putchar(' ');
		ft_putchar(g_hex[(int)str[i] / 16]);
		ft_putchar(g_hex[(int)str[i] % 16]);
		i++;
	}
	while (i < 16)
	{
		if (i % 2 == 0)
			ft_putchar(' ');
		write(1, "  ", 2);
		i++;
	}
}

void print_addr(long long addr, int count)
{
	if (count == 16)
		return;
	print_addr(addr >> 4, count + 1); // 재귀를 쓰려면 long long인자 필요
	ft_putchar(g_hex[addr % 16]);
	// long long 64비트로 표현되는 것이 더 작은 크기의 자료형으로
	// 변환되며 이는 오버플로우가 나는 것을 방지하기 위함이다.
	// 16자리씩 출력하려고 하니 ul 64비트니까 4비트씩 쪼개서 16번 반복문 돈다.
}

void* ft_print_memory(void* addr, unsigned int size)
{
	unsigned int i;
	unsigned int len;
	unsigned char* ptr;

	g_hex = "0123456789abcdef";
	i = 0;
	len = size; // 복사한 이유 
	ptr = (unsigned char*)addr;
	if (size <= 0)
		return ;
	while (i < (size / 16) + 1)
	{
		print_addr((long long)ptr, 0);
		ft_putchar(':');
		print_hex(ptr, len);
		ft_putchar(' ');
		print_str(ptr, len);
		ft_putchar('\n');
		i++;
		ptr += 16;
		len -= 16; // size - 16한 값을 len에 계속 대입시켜, 마지막 16이 아닌 사이즈를 구할 수 있다.
	}
	return (addr);
}

int main()
{
	char test[] = "Shoot for the moon. even if you miss, you'll land among the stars. testfile";
	//Bonjour les amin
	ft_print_memory(test, sizeof(test));
	return 0;
}