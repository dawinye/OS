#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){
  int fds[2];
  pipe(fds);
  int fds1[2];
  pipe(fds1);
  int pid = fork();
  int i = 0;
  if (pid == 0)
  {
  // Child
    close(fds[0]);
    close(fds1[1]);
    char c;
    for (i; i < 5; i++)
    {
      read(fds1[0], &c, 1);
      printf("%d. Child\n", i + 1);
      fflush(stdout);
      if (i != 4)
      {
        write(fds[1], &c,  1);
      }
    }
    
  }
  else
  {
  // Parent
    close(fds[1]);
    close(fds1[0]);
    char c;
    for (i; i < 5; i++)
    {
      if (i != 0)
      {
        read(fds[0], &c, 1);
      }
      printf("%d. Parent\n", i + 1);
      fflush(stdout);
      write(fds1[1], &c,  1);
      
  }
  wait(NULL);
  }
} 