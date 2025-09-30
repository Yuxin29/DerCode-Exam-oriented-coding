#include <stdarg.h>
#include <unistd.h>

static int ft_putstr(char *str)
{
    if (!str)
        return (write(1, "(null)", 6));
    int i = 0;
    while (str[i])
    {
        if (write(1, &str[i], 1) == -1)
            return (-1);
        i++;
    }
    return i;
}

static int ft_putdec(int n)
{
    int count = 0;
    int ret;
    if (n == -2147483648)
        return (write(1, "-2147483648", 11));
    if (n < 0)
    {
        if (write(1, "-", 1) == -1)
            return (-1);
        n = -n;
        count = 1;
    }
    if (n / 10 > 0)
    {
        ret = ft_putdec(n / 10);
        if (ret == -1)
            return (-1);
        count += ret;
    }
    char c = (n % 10) + '0';
    if (write(1, &c, 1) == -1)
        return (-1);
    count += 1;
    return (count);
}

static int ft_puthex(int n)
{
    int count = 0;
    int ret;
    if (n / 16 > 0)
    {
        ret = ft_putdec(n / 16);
        if (ret == -1)
            return (-1);
        count += ret;
    }
    char c = "0123456789abcdef"[n % 16];
    if (write(1, &c, 1) == -1)
        return (-1);
    count += 1;
    return (count);

}

int ft_printf(char *str, ...)
{
    int count = 0;
    int i = 0;
    int ret;
    va_list args;
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
                ret = ft_puthex(va_arg(args, int));
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
    return count;
}

#include <stdio.h>

int main(void)
{
    printf("%s\n", "test_printf");
    ft_printf("%s\n", "test_ft_printf");
    printf("%d\n", 123);
    ft_printf("%d\n", 123);
    printf("%x\n", 123);
    ft_printf("%x\n", 123);
    return 0;
}