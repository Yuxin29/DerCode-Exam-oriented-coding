#include <stdio.h>
#include <stdlib.h>

//  int atoi(const char *nptr);

static int  check_prime(int nbr)
{
    int i;

    i = 2;
    while (i < nbr)
    {
        if (nbr % i == 0)
            return (1);
        i++;
    }
    return (0);
}

static void print_prime(int nbr)
{
    int i;
    if (check_prime(nbr) == 0)
    {
        printf("%i\n", nbr);
        return ;
    }
    i = 2;
    while (i <= nbr)
    {
        while (nbr % i == 0)
        {
            printf("%i", i);
            if (i < nbr)
            	printf("%c", '*');
            nbr /= i;
        }
        i++;
    }
    printf("\n");
    return ;
}

int main(int argc, char **argv)
{
    int nbr;

    if (argc != 2)
    {
        printf("\n");
        return (0);
    }
    nbr = atoi(argv[1]);
    print_prime(nbr);
    return (0);
}

