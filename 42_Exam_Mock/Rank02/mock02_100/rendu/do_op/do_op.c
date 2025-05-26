#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

//int atoi(const char *nptr);

int	main(int argc, char **argv)
{
	int	n1;
	int n2;
	int re;

	if (argc != 4)
	{	
		write(1, "\n", 1);
		return (0);
	}
	n1 = atoi(argv[1]);
	n2 = atoi(argv[3]);
	if (argv[2][0] == '+')
		re = n1 + n2;
	if (argv[2][0] == '-')
        re = n1 - n2;
	if (argv[2][0] == '*')
        re = n1 * n2;
	if (argv[2][0] == '/')
        re = n1 / n2;
	printf("%i\n", re);
	return (0);
}
