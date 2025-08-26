/* ************************************************************************** */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#include <stdlib.h>	// malloc, free
#include <unistd.h>	// read

# define BUFFER_SIZE 42

// ssize_t	read(int fd, void *buf, size_t count);
char    *get_next_line(int fd);

#endif
