#include "get_next_line.h"

int main()
{
    int fd;
    char *line;


    fd = open ("file", O_RDONLY);

 while((line = get_next_line(fd)) != NULL)
{
    printf("%s", line);
    free(line);
}
//printf("%s\n", "Стандартный ввод:");
//while((line = get_next_line(0)) != NULL)
//{
//	printf("%s", line);
//	free(line);
//}
    return (0);
}

//int main()
//{
//	char *line;
//	line = 0;
//	while ((line = get_next_line(0)) != NULL)
//	{
//		write(1, line, ft_strlen(line));
//		free(line);
//		line = 0;
//	}
//}