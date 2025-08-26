/* ************************************************************************** */

#include <stdio.h> //printf
#include <unistd.h> //write
#include <stdarg.h> //va_start, va_arg, va_copy, va_end

static int ft_putstr(char *str)
{
	int	i;
	
	i = 0;
	if (!str)
		return (write(1, "(null)", 6));
	while(str[i])
	{
		if (write(1, &str[i], 1) == -1)
			return (-1);
		i++;
	}
	return (i);
}

static int	ft_putdec(int	n)
{
	int	count;
	int	ret;
	char	c;
	count = 0;
	if (n == -2147483648)
		return (write(1, "-2147483648", 11));
	if (n < 0)
	{
		if (write(1, "-", 1) == -1)
			return (-1);
		count = 1;
		n = -n;
	}
	if (n / 10 > 0)
	{
		ret = ft_putdec(n / 10);
		if (ret == -1)
			return (-1);
		count += ret;
	}
	c = (n % 10) + '0';
	ret = write(1, &c, 1);
	if (ret == -1)
		return (-1);
	count += ret;
	return (count);
}

static int	ft_puthex(unsigned int	n)
{
	int	count;
	int	ret;
	char	c;
	
	count = 0;
	if (n / 16 > 0)
	{
		ret = ft_puthex(n / 16);
		if (ret == -1)
			return (-1);
		count += ret;
	}
	c = "0123456789abcdef"[n % 16];
	ret = write(1, &c, 1);
	if (ret == -1)
		return (-1);
	count += ret;
	return (count);
}

int	ft_printf(char *str, ...)
{
	va_list args;
	int	count;
	int	i;
	int	ret;
	
	count = 0;
	i = 0;
	va_start(args, str);
	if (!str || !*str)
		return (-1);
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1])
		{
			i++;
			if (str[i] == 's')
				ret = ft_putstr(va_arg(args, char *));
			else if (str[i] == 'd')
				ret = ft_putdec(va_arg(args, int));
			else if (str[i] == 'x')
				ret = ft_puthex(va_arg(args, unsigned int));
			else
				ret = write(1, &str[i], 1);
		}
		else
			ret = write(1, &str[i], 1);
		if (ret == -1)
			return (-1);
		i++;
		count += ret;
	}
	va_end(args);
	return (count);
}

int	main(void)
{
	ft_printf("%s\n", "te");
	printf("%s\n", "te");
	ft_printf("%d\n", -223);
	printf("%d\n", -223);
	ft_printf("%x\n", 2223);
	printf("%x\n", 2223);
	return (0);
}
