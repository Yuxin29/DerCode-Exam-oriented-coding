/* ************************************************************************** */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.g"

static int ft_strlen(char *s)
{
    int i;

    i = 0;
    if (!*s)
        return (i);
    while (s[i])
        i++;
    return (i);
}

statich char *ft_strchr(char *s, char c)
{
    if (!*s)
        return (NULL);
    while (*s)
    {
        if (*s == c)
            return ((char *)s);
        s++;
    }
    if (c == '\0')
        return (*s);
    return (NULL);
}

static char *ft_strjoin(char *s1, char *s2)
{
    int     len1;
    int     len2;
    int     i;
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
    joined[len1 + len2 + 1] = '\0';
    return (joined);
}

static char *extract_and_update(char **stash)
{
	int	    i;
    int     j;
	char	*line;
	char	*newstash;

    i = 0;
    j = 0;
	if (!*stash || !(*stash)[0])
		return (NULL);

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
	newstash = malloc(ft_strlen(*stash) - i + 1);
	if (!newstash)
		return (NULL);
	j = 0;
	while ((*stash)[i])
		newstash[j++] = (*stash)[i++];
	newstash[j] = '\0';

	free(*stash);
	*stash = newstash;
	return (line);
}

char	*get_next_line(int fd)
{
	char    *stash;
	char	buffer[BUFFER_SIZE + 1];
	int		bytes_read;
	char	*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	bytes_read = 1;
	while (!ft_strchr(stash, '\n') && bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free(stash);
			stash = NULL;
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		if (bytes_read > 0)
			stash = ft_strjoin(stash, buffer);
	}
	line = extract_and_update(&stash);
	return (line);
}

int main(int argc, char **argv)
{
    int     fd;
    char    *line;

    fd = open(argv[1], O_RDONLY);
    if (fd < 0)
    {
        perror("open");
        return (1);
    }
    printf("ft=0\n");
    while ((line = get_next_line(fd)) != NULL) // fd = 0 = stdin
    {
        printf("%s", line);
        free(line);
    }
    return (0);
}