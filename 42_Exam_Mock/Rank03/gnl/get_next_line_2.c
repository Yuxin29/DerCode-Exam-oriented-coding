#include <stdlib.h>
#include <unistd.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 10
#endif

//get line with a long, str, we have start and end index
char *get_line(char *str, int start, int end)
{
	char *ret = malloc((end - start + 1) * sizeof(char));
	if (!ret)
		return (NULL);
	for (int i = 0; i < end - start + 1; ++i)
		ret[i] = str[start + i];
	ret[end - start] = '\0';
	return (ret);
}

char *get_next_line(int fd)
{
	char buff[BUFFER_SIZE];
	static char cache[100000];
	static int	start = 0;
	static int	end = 0;
	while (1)
	{
		int bytes = read(fd, buff, BUFFER_SIZE);
		if (bytes > 0)
		{
			for (int i = 0; i < bytes; ++i)
				cache[end++] = buff[i];
			continue;	
		}
		else if (bytes < 0)
			return (0);
		else
			break;
	}
	if (start == end)
		return (0);
	for (int i = start; i < end; ++i)
	{
		if (cache[i] == '\n')
		{
			char *line = get_line(cache, start, i + 1);
			start = i + 1;
			return (line);
		}
	}
	char *line = get_line(cache, start, end);
	start = end;
	return (line);
}

#include <stdio.h>
#include <fcntl.h>

int	main(int ac, char **av)
{
	int fd = open(av[1], O_RDONLY);
	char	*line;
	line = get_next_line(fd);
	while (line)
	{
		printf("%s\n", line);
		free (line);
		line = get_next_line(fd);
	}
	close(fd);
	return (0);
}
