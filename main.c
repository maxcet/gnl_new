#include "get_next_line.h"

int main()
{
    int fd;
    char *line;


    fd = open ("text.txt", O_RDONLY);
	line = get_next_line(fd);
	  printf("%s", line);
	    printf("%s\n", "potom vizov v cikle");
    while((line = get_next_line(fd)) != NULL)
   {
       printf("%s", line);
       free(line);
   }
    printf("%s\n", "Стандартный ввод:");
   while((line = get_next_line(0)) != NULL)
    {
		printf("%s", line);
		free(line);
	}
    return (0);
}