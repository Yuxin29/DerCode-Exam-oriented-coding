#include <unistd.h>

static int	ft_atoi(char *s)
{
	int nbr;
	int	i;

	nbr = 0;
	i = 0;
	while (s[i])
	{
		nbr = nbr * 10 + (s[i] - '0');
		i++;
	}
	return (nbr);
}

static void	ft_itoa(int nbr)
{
	char c;
	
	c = (nbr % 10) + '0';
	if (nbr >= 10)	
		ft_itoa(nbr / 10);
	write(1, &c, 1);
}

int main(int argc, char **argv)
{
	if (argc == 2)
	{
		int	n;
		int	count;
		int length;
		char c;
		int sec;

		if (!argv[1][0])
		{
			write(1, "\n", 1);
    		return (0);
		}
		n = ft_atoi(argv[1]);
		count = 1;
		length = 0;
		while (argv[1][length])
			length++;
		while (count <= 9)
		{
			c = count + '0';
			sec = count * n;
			write(1, &c, 1);
			write(1, " x ", 3);
			write(1, argv[1], length);
			write(1, " = ", 3);
			ft_itoa(sec);
			write(1, "\n", 1);
			count++;
		}
		return (0);
	}
	else
	{
		write(1, "\n", 1);
		return (0);
	}
}
