#include <unistd.h>
#include <stdlib.h>

static int ft_islower(char c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	return (0);
}
/*
static int ft_isupper(char c)
{
    if (c >= 'A' && c <= 'Z')
        return (1);
    return (0);
}*/

static int	count_word(char *str)
{
	int	count;

	count = 0;
	while (*str)
	{
		if (*str >= 'A' && *str <= 'Z')
			count++;
		str++;
	}
	return (count);
}

static void	write_lower(char c)
{
	c += 32;
	write(1, &c, 1);
	return ;
}

int	main(int argc, char **argv)
{
	int	i;
	int n;
	int count;
	char dash;

	if (argc != 2)
	{
		write(1, "\n", 1);
		return(0);
	}
	i = 0;
	n = 0;
	count = count_word(argv[1]);
	dash = '_';
	while (ft_islower(argv[1][i]) && argv[1][i])
	{
		write(1, &argv[1][i], 1);
		i++;
	}
	while (argv[1][i])
	{
		if (n < count)
		{
			write(1, &dash, 1);
			n++;
		}
		write_lower(argv[1][i]);
			i++;
		while (ft_islower(argv[1][i]) && argv[1][i])
    	{
        	write(1, &argv[1][i], 1);
        	i++;
    	}
	}
	return (0);
}
