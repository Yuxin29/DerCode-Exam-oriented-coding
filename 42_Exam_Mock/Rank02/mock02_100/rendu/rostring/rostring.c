#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

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

static char *ft_firstword(char *str)
{
	char	*first;
	int		leng;

	leng = 0;
	while (*str && ft_isspace(*str))
		str++;
	while(str[leng] && !ft_isspace(str[leng]))
		leng++;
	first = malloc(sizeof(char) * (leng + 1));
	if (!first)
		return (NULL);
	leng = 0;
	while(str[leng] && !ft_isspace(str[leng]))
	{
		first[leng] = str[leng];
		leng++;
	}
	first[leng] = '\0';
	return (first);
}

int	main(int argc, char **argv)
{
	int	i;
	int 	j;
	int	count;
	char *first;

	if (argc < 2)
	{
		write(1, "\n", 1);
		return(0);
	}
	i = 0;
	if (argc > 2)
	{
		while (argv[1][i])
		{
			write(1, &argv[1][i], 1);
			i++;
		}
		write(1, "\n", 1);
		return (0);
	}
	j = 0;
	count = ft_countwords(argv[1]) - 1;
	first = ft_firstword(argv[1]);
	if (!first)
	{
        write(1, "\n", 1);
        return(0);
    }
	while (ft_isspace(argv[1][i]))
            i++;
	while (!ft_isspace(argv[1][i]))
            i++;
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
	if (j > 0)
		write(1, " ", 1);
	while (*first)
	{
			write(1, &(*first), 1);
			first++;
	}
	write(1, "\n", 1);
	return (0);
}
