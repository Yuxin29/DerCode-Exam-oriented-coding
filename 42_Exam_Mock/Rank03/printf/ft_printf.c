/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuwu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 18:47:21 by yuwu              #+#    #+#             */
/*   Updated: 2025/08/25 18:53:12 by yuwu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> //malloc, free
#include <unistd.h>
//va_start, va_arg, va_copy, va_end

//s,d, and x

//Before you start we advise you to read the `man 3 printf` and the `man va_arg`.
//To test your program compare your results with the true printf.

static int ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if write(1, str[i], 1) = -1;
			return (-1);
		i++;
	}
	return (i);
}

static int ft_putdec(char *str)
{
	//
	return (i);
}

static int ft_puthex(char *str)
{
	//
	return (i);
}

int ft_printf(const char *, ... );
{


}


call: ft_printf("Hello %s\n", "toto");
out:Hello toto$

call: ft_printf("Magic %s is %d", "number", 42);
out:Magic number is 42%

call: ft_printf("Hexadecimal for %d is %x\n", 42, 42);
out:Hexadecimal for 42 is 2a$
