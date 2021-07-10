#include "get_next_line.h"

int main()
{
    int fd;
    char *line;


    fd = open ("text.txt", O_RDONLY);
    printf("%s", "line");

    while((line = get_next_line(fd)) != NULL)
   {     
       printf("%s", line);
       free(line);
   }

    return (0);
}