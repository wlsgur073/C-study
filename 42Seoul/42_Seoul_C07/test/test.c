#include <stdio.h>

char* hex;

void	print_str(char* ptr)
{
	int i;

	i = 0;
	while (ptr[i] && i < 16)
	{
		if (ptr[i] > 32 && ptr[i] < 126)
			write(1, &ptr[i], 1);
		else
			write(1, ".", 1);
		i++;
	}
}

void	print_hex(char* ptr, unsigned len)
{
	unsigned int i;

	i = 0;
	while (i < 16 && i < len)
	{
		if (i % 2 == 0)
			write(1, " ", 1);
		write(1, &hex[ptr[i] / 16], 1);
		write(1, &hex[ptr[i] % 16], 1);
		i++;
	}
	// if (ptr[i++] == 0)
	// 	write(1, "00", 2);
	while (i < 16)
	{
		if (i % 2 == 0)
			write(1, " ", 1);
		write(1, "  ", 2);
		i++;
	}

}

void	print_add(long long addr, int count)
{
	if (count == 16)
		return;
	print_add(addr >> 4, count + 1);
	write(1, &hex[addr % 16], 1);
}

void* ft_print_memory(void* addr, unsigned int size)
{
	unsigned int i;
	unsigned int len;
	char* ptr;

	i = 0;
	len = size;
	ptr = (char*)addr;
	hex = "0123456789abcdef";
	while (*ptr && i < size / 16 + 1)
	{
		print_add((long long)ptr, 0);
		write(1, ":", 1);
		print_hex(ptr, len);
		write(1, " ", 1);
		print_str(ptr);
		write(1, "\n", 1);
		ptr += 16;
		len -= 16;
		i++;
	}
	return (addr);
}

int		main()
{
	char a[] = "\x42\x6f\x6e\x6a\x6f\x75\x72\x20\x6c\x65\x73\x20\x61\x6d\x69\x6e\x63\x68\x65\x73\x09\x0a\x09\x63\x20\x20\x65\x73\x74\x20\x66\x6f\x75\x09\x74\x6f\x75\x74\x09\x63\x65\x20\x71\x75\x20\x6f\x6e\x20\x70\x65\x75\x74\x20\x66\x61\x69\x72\x65\x20\x61\x76\x65\x63\x09\x0a\x09\x70\x72\x69\x6e\x74\x5f\x6d\x65\x6d\x6f\x72\x79\x0a\x0a\x0a\x09\x6c\x6f\x6c\x2e\x6c\x6f\x6c\x0a\x20\x00";
	char b[] = "everthing is fine. there is huge wall block to me make cannot see anything. but it's okay my firend. i'm gonna fly again.";
	ft_print_memory(b, sizeof(b));
	return 0;
}