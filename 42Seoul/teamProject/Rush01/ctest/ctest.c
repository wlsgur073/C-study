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
	while (i < 16 && i + 1 < len) // && str[i] ������ ���� ����� ó�������� ���ϰ� ����. size < 16�϶� �ڰ� �����Ⱚ���� ����
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
	print_addr(addr >> 4, count + 1); // ��͸� ������ long long���� �ʿ�
	ft_putchar(g_hex[addr % 16]);
	// long long 64��Ʈ�� ǥ���Ǵ� ���� �� ���� ũ���� �ڷ�������
	// ��ȯ�Ǹ� �̴� �����÷ο찡 ���� ���� �����ϱ� �����̴�.
	// 16�ڸ��� ����Ϸ��� �ϴ� ul 64��Ʈ�ϱ� 4��Ʈ�� �ɰ��� 16�� �ݺ��� ����.
}

void* ft_print_memory(void* addr, unsigned int size)
{
	unsigned int i;
	unsigned int len;
	unsigned char* ptr;

	g_hex = "0123456789abcdef";
	i = 0;
	len = size; // ������ ���� 
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
		len -= 16; // size - 16�� ���� len�� ��� ���Խ���, ������ 16�� �ƴ� ����� ���� �� �ִ�.
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