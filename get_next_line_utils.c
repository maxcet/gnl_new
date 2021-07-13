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

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*dest;
	size_t	i;
	size_t	len1;
	size_t	len2;

	if (!s1 && !s2)
		return (NULL);
	i = 0;
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	dest = (char *)malloc(len1 + len2 + 1);
	if (!dest)
		return (NULL);
	i -= 1;
	while (++i < len1)
		dest[i] = s1[i];
	i -= 1;
	while (++i < len1 + len2)
		dest[i] = s2[i - len1];
	dest[i] = '\0';
	free((char *)s1);
	return (dest);
}

char	*ft_get_free(char **trash)
{
	free(*trash);
	*trash = NULL;
	return (NULL);
}
