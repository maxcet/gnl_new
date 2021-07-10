#include "get_next_line.h"

char 	*get_next_line(int fd)
{
	static char	*tail;
	char		*buffer;
	char		*line;
	int			rd;

	line = NULL;
	rd = 1;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (buffer == NULL)
		return (NULL);
	while (rd != 0 && ft_strchr(tail, '\n') == NULL)
	{
		rd = read(fd, buffer, BUFFER_SIZE);
		if (rd < 0)
			return (NULL);
		buffer[rd] = '\0';
		tail = ft_strjoin(tail, buffer);
	}
	if (rd == 0)
		return(NULL);
	line = ft_get_line(tail);
	ft_get_tail(&tail, line);
	return (line);
}

char	*ft_get_line(char *tail)
{
	char	*ptr;
	char	*line;

	ptr = ft_strchr(tail, '\n');
	line = ft_substr(tail, 0, ptr - tail);
	line = ft_strjoin(line, (const char *)"\n");
	return(line);
}

char	*ft_strdup(const char *s1)
{
	int		len;
	char	*str;

	len = ft_strlen(s1);
	str = (char *)malloc(len + 1);
	if (str == 0)
		return (0);
	len = 0;
	while (s1[len] != 0)
	{
		str[len] = s1[len];
		len++;
	}
	str[len] = '\0';
	return (str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	index;
	char	*str;

	if (s == 0 || start + len > ft_strlen(s))
		return (NULL);
	str = (char *)malloc(sizeof(char) * len + 1);
	if (str == NULL)
		return (NULL);
	index = 0;
	while (index < len)
	{
		str[index] = s[start];
		index++;
		start++;
	}
	str[index] = '\0';
	return (str);
}

int		ft_get_tail(char **tail, char *line)
{
	char	*temp;

	temp = ft_strdup(*tail + (ft_strlen(line)));
	free(*tail);
	*tail = temp;
	if (*tail == NULL)
		return (0);
	return (1);
}
