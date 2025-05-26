#include <unistd.h>

static int ft_isspace(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	return (0);
}

static int ft_countwords(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
	 	while (str[i] && ft_isspace(str[i]))
			i++;
		while (str[i] && !ft_isspace(str[i]))
            i++;
		count++;
		i++;
	}
	return (count);
}

int	main(int argc, char **argv)
{
	int	i;
	int 	j;
	int	count;

	if (argc != 2)
	{
		write(1, "\n", 1);
		return(0);
	}
	i = 0;
	j = 0;
	count = ft_countwords(argv[1]);
	while (ft_isspace(argv[1][i]))
            i++;
	while (argv[1][i] && j < count)
	{
		while (argv[1][i] && !ft_isspace(argv[1][i]))
		{
			write(1, &argv[1][i], 1);
			i++;
		}
		if (argv[1][i] && j < count - 1)
		{
			write(1, " ", 1);
			j++;
		}
		while (argv[1][i] && ft_isspace(argv[1][i]))
            i++;
	}
	write(1, "\n", 1);
	return (0);
}
