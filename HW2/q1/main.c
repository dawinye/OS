#include <stdio.h>
#include <string.h>
void print_args(int number, char **argv);
int get_args(char *in, char **argv, int max_args);
int main() {
  char s[200];
  char *argv[10];
  int argc;

  printf("enter a string: ");
  fgets(s, sizeof(s), stdin);
  
  argc = get_args(s, argv, 10);
  
  print_args(argc,argv);

  return 0;
}

void print_args(int number, char **argv) {
  int i;
  for (i = 0; i < number; i++) {
    printf("argv[%d] ='%s'\n", i, argv[i]);
    }
}

int get_args(char *in, char **argv, int max_args) {
  int i;
  int count = 0;
  char *token;
  
  token = strtok(in, " ");
  for (i = 0; i < max_args; i++){
    if (token == NULL){
      return count;
    }
    token[strcspn(token,"\n")] = '\0';
    char *pointer = strdup(token);
    argv[i] = pointer;
    token = strtok(NULL, " ");
    count += 1;
  }
  
  return count;
}
