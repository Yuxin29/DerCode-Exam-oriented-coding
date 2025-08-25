/* ************************************************************************** */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> //malloc, free
#include <unistd.h>
#include <stdarg.h> //va_start, va_arg, va_copy, va_end

//Before you start we advise you to read the `man 3 printf` and the `man va_arg`.
//To test your program compare your results with the true printf.

//s,d, and x
static int ft_putstr(char *str)
{
	int		i;
	char	c;

	i = 0;
	if (!str)
		return (write(1, "(null)", 1));
	while (str[i])
	{
		c = str[i];
		if (write(1, &c, 1) == -1);
			return (-1);
		i++;
	}
	return (i);
}

static int ft_putdec(int n)
{
	int 	count;
	int		rest;
	char	c;

	if (n < 0)
	{
		n = -n;
		count = write(1, "-", 1);
		if (count == -1)
			return (-1);
	}
	if (n >= 10)
	{
		rest = ft_putdec(n / 10);
		if (rest == -1)
			return (-1);
		count += rest;
	}
	c = (n % 10) - '0';
	if (write(1, &c, 1) == -1)
		return (-1);
	return (count);
}

static int ft_puthex(unsigned int n)
{
	int	i;

	i = 0;
	return (i);
}

int ft_printf(const char *str, ... )
{
	va_list args;
	int		result;
	int		i;
	int		count;

	va_start(args,str);
	i = 0;
	count = 0;
	if (!str)
		return(-1);
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1])
		{
			i++;
			if (str[i] == 's')
				result = ft_putstr(va_arg(args, char *));
			else if (str[i] == 'd')
				result = ft_putdec(va_arg(args, int));
			else if (str[i] == 'x')
				result = ft_puthex(va_arg(args, unsigned int));
			else
				result = write(1, &str[i], 1);
		}
		else 
			result = write(1, &str[i], 1);
		if (result == -1)
			return (-1);
		count += result;
		i++;
	}
	va_end(args);
	return (count);
}

// call: ft_printf("Hello %s\n", "toto");
// out:Hello toto$

// call: ft_printf("Magic %s is %d", "number", 42);
// out:Magic number is 42%

// call: ft_printf("Hexadecimal for %d is %x\n", 42, 42);
// out:Hexadecimal for 42 is 2a$

int main(void)
{
	ft_printf("Hello %s\n", "toto");
	return (0);
}