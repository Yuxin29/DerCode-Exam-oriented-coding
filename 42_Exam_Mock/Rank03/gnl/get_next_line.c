/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h> 	//for open in main
#include <stdio.h>	//for printf in main

static size_t ft_strlen(char *s)
{
    size_t i;

    i = 0;
    if (!s)
        return (i);
    while (s[i])
        i++;
    return (i);
}

static char *ft_strchr(char *s, char c)
{
    if (!s)
        return (NULL);
    while (*s)
    {
        if (*s == c)
            return ((char *)s);
        s++;
    }
    if (c == '\0')
        return ((char *)s);
    return (NULL);
}

static char *ft_strjoin(char *s1, char *s2)
{
    size_t     len1;
    size_t     len2;
    size_t     i;
    char    *joined;
    
    i = 0;
    len1 = ft_strlen(s1);
    len2 = ft_strlen(s2);
    joined = malloc(len1 + len2 + 1);
    if (!joined)
        return (NULL);
    while (i < len1)
    {
        joined[i] = s1[i];
        i++;
    }
    i = 0;
    while (i < len2)
    {
        joined[len1 + i] = s2[i];
        i++;
    }
    joined[len1 + len2] = '\0';
    free (s1);
    return (joined);
}

static char *extract_and_update(char **stash)
{
	int	i;
	int	j;
	char	*line;
	char	*new_stash;
	
	i = 0;
	j = 0;
	while ((*stash)[i] && (*stash)[i] != '\n')
		i++;
	if ((*stash)[i] == '\n')
		i++;
	line = malloc(i + 1);
	if (!line)
		return (NULL);
	while (j < i)
	{
		line[j] = (*stash)[j];
		j++;
	}
	line[j] = '\0';
	if (!(*stash)[i])
	{
		free(*stash);
		*stash = NULL;
		return (line);
	}
	new_stash = malloc(ft_strlen(*stash) - i + 1);
	if (!new_stash)
		return (NULL);
	j = 0;
	while ((*stash)[i])
	{
		new_stash[j] = (*stash)[i];
		j++;
		i++;
	}
	new_stash[j] = '\0';
	free (*stash);
	*stash = new_stash;
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		buf[BUFFER_SIZE + 1];
	int		n;
	
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	n = 1;
	while (!ft_strchr(stash, '\n') && n > 0)
	{
		n = read(fd, buf, BUFFER_SIZE);
		if (n < 0)
		{
			if (*stash)
				free (stash);
			stash = NULL;
			return (NULL);
		}
		buf[n] = '\0';
		if (n > 0)
			stash = ft_strjoin(stash, buf);
	}
	if (n == 0)
		return (NULL);
	return(extract_and_update(&stash));
}


int	main(int argc, char **argv)
{
	int	fd;
	char *line;
	fd = open(argv[1], O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}
	return (0); 
}
