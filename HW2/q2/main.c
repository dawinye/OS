#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
int main() {
  //Create the pipe
  int fds[2];
  pipe(fds);

  //Fork 
  pid_t childpid1 = fork();
  
  

  if (childpid1 == 0) 
  {
      close(fds[0]);
      close(1);
      dup(fds[1]);

      char *argv[3];
      argv[0] = "ls";
      argv[1] = "-l";
      argv[2] = NULL;
      execvp(argv[0],argv);
    
  } 
  else 
  {
    pid_t childpid2 = fork();

    if (childpid2 == 0) 
    {
      close(fds[1]);

      close(0);
      dup(fds[0]);

      char *argv[2];
      argv[0] = "wc";
      argv[1] = NULL;
      execvp(argv[0],argv);
    }
    else{
      close(fds[0]);
      close(fds[1]);
      int finish1 = wait(NULL);
      printf("Process %d finished\n", finish1);
      int finish2 = wait(NULL);
      printf("Process %d finished\n", finish2);
    }
    return 0;
  }
  
}
