#include "get_next_line.h"


char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dest;
	int		len;


	len = ft_strlen(s1) + ft_strlen(s2);

	dest = ft_strnew(len);
	if (dest == NULL)
		return (NULL);
	if (s1 != NULL)
		ft_strlcpy(dest, s1, len + 1);
	if (s2 != NULL)
		ft_strlcpy(dest + ft_strlen(s1), s2, len - ft_strlen(s1) + 1);
	return (dest);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	index;

	index = 0;
	if (!src)
		return (0);
	if (size > 0)
	{
		while (src[index] && index < (size - 1))
		{
			dst[index] = src[index];
			index++;
		}
		dst[index] = 0;
	}
	index = ft_strlen(src);
	return (index);
}

char	*ft_strnew(size_t size)
{
	char	*str;
	char	*ptr;
	str = (char *)malloc(sizeof(char) * (size + 1));
	if (str)
		{
			ptr = str;
			while (size--) 
				*ptr++ = '\0';
		}
	return (str);
}
