#include "get_next_line.h"
#include <fcntl.h>

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

size_t	ft_strlen_n(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len] != '\n')
		len++;
	return (len);
}

char	*ft_strchr(const char *s, int c)
{
	char	*ptr;
	char	sym;

	ptr = (char *) s;
	sym = (char) c;
	while (*ptr && !(*ptr == sym))
		ptr++;
	if (*ptr == sym)
		return (ptr);
	else
		return (NULL);
}

char	*ft_get_line(char *tail)
{
	char *line;

	if (tail == NULL)
		return (NULL);
	line = (char *)malloc(ft_strlen_n(tail) + 1);
	if (line == NULL)
		return (NULL);
	ft_strlcpy(line, tail, ft_strlen_n(tail) + 1);
	if (ft_strlen(tail) == ft_strlen_n(tail))
		{	
			*tail = 0;
			return(line);
		}
	ft_strlcpy(tail, tail + ft_strlen_n(tail) + 1, ft_strlen(tail) + 1);
	return (line);
	
}

char		*get_next_line(int fd)
{
	static char 	*tail;
	char			*buffer;
	char			*line;
	int				reader;
	
	write(1, "tut\n", 4);
	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	write(1, "tut2\n", 5);
	buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return(NULL);
	reader = 1;
	write(1, "tut3\n", 5);
	while (reader != 0 || ft_strchr(tail, '\n') == NULL)
		{
			reader = read(fd, buffer, BUFFER_SIZE);
			if (reader == -1)
			{
				free(buffer);
				return(NULL);
			}
			write(1, "tut4\n", 5);
			buffer[reader] = '\0';
			write(1, "tut77\n", 10);
			tail = ft_strjoin(tail, buffer);
			write(1, "tut8\n", 10);
			free(buffer); 
			if (tail == NULL)
				return (NULL);
		}
	write(1, "tut5", 4);
	line = ft_get_line(tail);
	write(1, "tut6", 4);
	if (line == NULL)
		return (NULL);
	return(line);
}

int main(void)
{
	char *line;
	int fd;
	int check; 

	check = 1;
	fd = open ("text.txt", O_RDONLY);
	line = get_next_line(fd);
	printf("%s\n", line);

}
