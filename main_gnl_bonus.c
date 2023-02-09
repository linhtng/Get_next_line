#include <stdio.h>
#include <fcntl.h>
#include "get_next_line_bonus.h"

int     main(void)
 {
  //char  *line;
  int   fd1;
  int   fd2;
  int   fd3;

fd1 = open("test", O_RDONLY);

  
fd2 = open("test2", O_RDONLY);

  
  //fd3
  fd3 = open("test3", O_RDONLY);



printf("%s",get_next_line(fd1));
printf("%s",get_next_line(fd2));
printf("%s",get_next_line(fd1));
printf("%s",get_next_line(fd3));
printf("%s",get_next_line(fd2));
printf("%s",get_next_line(fd3));

if (close(fd1) == -1)
    return (-1);
if (close(fd2) == -1)
    return (-1);
if (close(fd3) == -1)
return (-1);
  return (0);
 }