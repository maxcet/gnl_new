#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	char	*ptr;
	char	sym;

	if (s == NULL)
		return (NULL);
	ptr = (char *) s;
	sym = (char) c;
	while (*ptr && !(*ptr == sym))
		ptr++;
	if (*ptr == sym)
		return (ptr);
	else
		return (NULL);
}

size_t	ft_strlen(const char *s)
{
	size_t	len;

	if (s == NULL)
		return (0);
	len = 0;
	while (s[len] != 0)
		len++;
	return (len);
}

char	*ft_strcpy(char *dest, char const *src)
{
	char	*temprary_str;

	if (src == NULL)
		return (NULL);
	temprary_str = dest;
	while (*src != 0)
	{
		*temprary_str = *src;
		temprary_str++;
		src++;
	}
	*temprary_str = 0;
	return (dest);
}

char	*ft_strcat(char *dest, const char *src)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (dest[i] != 0)
		i++;
	j = 0;
	while (src[j] != 0)
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = 0;
	return (dest);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*dest;
	int		len;

	len = ft_strlen(s1) + ft_strlen(s2);
	if (s1 || s2)
	{
		dest = (char *)malloc(sizeof(char) * (len + 1));
		if (dest == NULL)
			return (NULL);
		ft_strcpy(dest, s1);
		ft_strcat(dest, s2);
		return (dest);
	}
	else
		return (NULL);
}
