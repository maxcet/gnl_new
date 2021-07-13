#include "get_next_line.h"

char 	*get_next_line(int fd)
{
	static char	*save_line;
	char		*buffer;
	char		*line;
	int			rd;

	rd = 1;
	if (read(fd, 0, 0) < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (buffer == NULL)
		return (NULL);
	while (rd != 0 && ft_strchr(save_line, '\n') == NULL)
	{
		rd = read(fd, buffer, BUFFER_SIZE);
		if (rd == -1)
			return (ft_get_free(&buffer));
		buffer[rd] = 0;
		save_line = ft_strjoin(save_line, buffer);
	}
	free(buffer);
	line = ft_get_line(save_line);
	if (ft_strlen(save_line) == 0)
		return (ft_get_free(&save_line));
	ft_get_saveline(&save_line, line);
	return (line);
}

char	*ft_get_line(char *save_line)
{
	char		*ptr;
	char		*line;

	ptr = ft_strchr(save_line, '\n');
	if (ptr == NULL && *save_line != 0)
		line = ft_strdup(save_line);
	else if (ptr != NULL)
		line = ft_substr(save_line, 0, (ptr - save_line) + 1);
	else
		return (NULL);
	return (line);
}

char	*ft_strdup(const char *s1)
{
	int		len;
	char	*str;

	len = ft_strlen(s1);
	str = (char *)malloc(len + 1);
	if (str == NULL)
		return (NULL);
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

int	ft_get_saveline(char **save_line, char *line)
{
	char	*temprary_str;

	temprary_str = ft_strdup(*save_line + (ft_strlen(line)));
	free(*save_line);
	*save_line = temprary_str;
	if (*save_line == NULL)
		return (0);
	return (1);
}
