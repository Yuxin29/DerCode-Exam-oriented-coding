#include <unistd.h>
/*
if (c == ' ' || c == '\f' || c == '\n' || c == '\r' || c == '\t' || c == '\v')
*/
static int	ft_isspace(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		int	i;

		if (!argv[1][0])
		{
			write(1, "\n", 1);
			return (0);
		}
		i = 0;
		while (argv[1][i])
			i++;
		i--;
		while (ft_isspace(argv[1][i]))
			i--;
		while (!ft_isspace(argv[1][i]) && i > 0)
			i--;
		i++;
		while (!ft_isspace(argv[1][i]) && argv[1][i])
        {
			write(1, &argv[1][i], 1);
			i++;
		}
		write(1, "\n", 1);
		return (0);
	}
	write(1, "\n", 1);
	return (0);
}
