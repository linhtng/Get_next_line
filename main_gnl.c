#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int     main(void)
 {
  char  *line;
  int   fd1;

  //fd1
  if ((fd1 = open("test", O_RDONLY)) == -1)
    printf("error opening");
  line = NULL;
  while ((line = get_next_line(fd1)) != NULL)
   {
     printf("%s", line);
     free(line);
   }
  if (!(line))
    printf("there is nothing else to read, or an error occurred");
  if (close(fd1) == -1)
    return (-1);
/*   system("export MallocStackLogging=1");     
  system("leaks a.out"); */
  return (0);
 }
