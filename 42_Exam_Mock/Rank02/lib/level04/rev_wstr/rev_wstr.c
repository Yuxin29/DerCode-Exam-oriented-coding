#include <stdlib.h>
#include <unistd.h>

int	is_space(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	return (0);
}

int count_word(char *str)
{
	int	word_nbr;
	
	word_nbr = 0;
	while (*str)
	{
		if (is_space(*str))
			word_nbr++;
		str++;
	}
	word_nbr++;
	return (word_nbr);
}

int	main(int argc, char **argv)
{
	int i;
	int count;
	int word_nbr;
	int word_pt;
	
	if (argc != 2)
	{
		write (1, "\n", 1);
		return (0);
	}
	i = 0;
	count = 0;
	word_nbr = count_word(argv[1]);
	word_pt = 0;
	while (argv[1][i])
		i++;
	while (i >= 0)
	{
		while (!is_space(argv[1][i]))
			i--;
		i++;
		while (!is_space(argv[1][i+count]) && argv[1][i+count])
		{
			write(1, &argv[1][i + count], 1);
			count++;
		}
		if (word_pt < word_nbr)
			write(1, " ", 1);
		i--;
		if (is_space(argv[1][i]))
			i--;
		count = 0;
		word_pt++;
	}
	return (0);
}
