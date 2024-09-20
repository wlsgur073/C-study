#include <stdio.h>
#include <stdlib.h>

int		how_many_chars(char* input)
{
	int		cnt;
	cnt = 0;
	while (input[cnt])
		cnt++;
	return (cnt);
}

void	strings_distribute(char** string_array, char* input, int mod)
{
	int		digit_of_string;
	int		i;
	int		j;
	
	i = 0;
	j = 0;
	digit_of_string = 1;
	while (input[j])
	{
		string_array[i][digit_of_string - 1] = input[j];
		if ((j + 1) % 3 == mod)
		{
			string_array[i][(digit_of_string)] = '\0';
			i++;
			digit_of_string = 1;
		}
		else
			digit_of_string++;
		j++;
	}
}

char** ft_seperate(char* input, int cnt)
{
	char** string_array;
	int		hmt;
	int		i;

	i = 0;
	hmt = cnt / 3 + 1;
	string_array = (char**)malloc(sizeof(char*) * hmt);
	while (i < hmt)
	{
		string_array[i] = (char*)malloc(sizeof(char) * (3 + 1));
		i++;
	}
	string_array[i] = '\0';
	strings_distribute(string_array, input, 0);

	return (string_array);
}

int main(int argc, char* argv[])
{
	char** string_array;
	int		i;
	int		j;
	int		cnt;
	int		hmt;

	argc = 2;
	argv[1] = "123456789";
	cnt = how_many_chars(argv[1]);
	hmt = cnt / 3 + 1;
	string_array = ft_seperate(argv[1], cnt);
	i = -1;
	j = hmt;
	while (++i < hmt)
	{
		write(1, string_array[i], 4);
		//printf("%s\n", string_array[i]);
	}
	return 0;
}