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
	int	i;
	char	c;

	i = 0;
	if (!str)
		return (write(1, "(null)", 1));
	while (str[i])
	{
		c = str[i];
		if (write(1, &c, 1) == -1)
			return (-1);
		i++;
	}
	return (i);
}

static int ft_putdec(int n)
{
	int 	count;
	int	rest;
	char	c;

	count = 0;
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
	c = (n % 10) + '0';
	if (write(1, &c, 1) == -1)
		return (-1);
	count++;
	return (count);
}

static int ft_puthex(unsigned int n)
{
	int	count;
	int	rest;
	char 	c;
	
	count = 0;
	if (n >= 16)
	{	
		rest = ft_puthex(n / 16);
		if (rest == -1)
			return (-1);
		count += rest;
	}
	c = "0123456789abcdef"[n % 16];
	if (write(1, &c, 1) == -1)
		return (-1);
	count++;
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list args;
	int	count;
	int	ret;
	int	i;
	
	var_start(args, str);
	count = 0;
	i = 0;
	if (!str)
		return (-1);
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1])
		{
			i++;
			if (str[i] == 's')
				ret = return(ft_putstr(va_arg(args, char *)));
			else if (str[i] = 'd')
				ret = return(ft_putdec(va_arg(args, int)));
			else if (str[i] = 'x')
				ret = return(ft_puthex(va_arg(args, unsigned int)));
			else
				ret = write(1, &str[i], 1);
		}
		else
			ret = write(1, &str[i], 1);
		if (ret == -1)
			return (-1);
		count += ret;
		i++;
	}
	va_end(args);
	return (count);
}

int main(void)
{
	printf("Hello %s\n", "atoto");
	ft_printf("Hello %s\n", "atoto");
	printf("Hello %d\n", 24534);
	ft_printf("Hello %d\n", 24534);
	printf("Hello %d\n", -24534);
	ft_printf("Hello %d\n", -24534);
	printf("Hello %x\n", 16);
	ft_printf("Hello %x\n", 16);
	return (0);
}
