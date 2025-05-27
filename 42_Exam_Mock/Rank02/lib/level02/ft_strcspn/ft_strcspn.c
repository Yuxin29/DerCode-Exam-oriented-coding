#include <stdlib.h>
#include <string.h>
#include <stdio.h>

static int	ft_belong(char c, const char *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

size_t	ft_strcspn(const char *s, const char *reject)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (ft_belong(s[i], reject))
			return (i);
		i++;
	}
	return (i);
}

int	main(void)
{
	size_t	re1;
	size_t	re2;

	re1 = strcspn("asbcedf", "efd");
	re2 = ft_strcspn("asbcedf", "efd");
	printf("%zu\n", re1);
	printf("%zu\n", re2);
	return (0);
}
