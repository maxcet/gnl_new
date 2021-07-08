#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
# 	define BUFFER_SIZE 32
# endif


char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strcpy(char *dest, char const *src);
char	*ft_strcat(char *dest, const char *src);
char	*ft_strnew(size_t size);
char	*ft_strchr(const char *s, int c);


char	*get_next_line(int fd);

size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);

#endif