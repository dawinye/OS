#include <stdio.h>
#include <string.h>
#define MAX_SUB_COMMANDS 5
#define MAX_ARGS 10



struct SubCommand
{
 char *line;
 char *argv[MAX_ARGS];
};

struct Command
{
 struct SubCommand sub_commands[MAX_SUB_COMMANDS]; 
 int num_sub_commands;
}; 
//headers
void print_args(char **argv);
void ReadArgs(char *in, char **argv, int size);
void ReadCommand(char *line, struct Command *command);
void PrintCommand(struct Command *command);

int main() {
    //char array to store the entered string
  char s[200];

  struct Command command;
  printf("enter a string: ");
  //put the string into s
  fgets(s, sizeof(s), stdin);
  //making it null terminated
  int len = strlen(s);
  s[len-1]='\0';
  
  ReadCommand(s, &command);

  PrintCommand(&command);
  //print_args(argv);
  // struct Command *command;
  // char *line = "this is the | worst | thing";
  // ReadCommand(line,command);

  return 0;
}

void print_args(char **argv) {
  int i = 0;
  while (argv[i] != NULL){
    printf("argv[%d] ='%s'\n", i, argv[i]);
    i++;
  }
}
void ReadArgs(char *in, char **argv, int size) {
  int i;
  int count = 0;
  char *token;
  
  token = strtok(in, " ");
  for (i = 0; i < size - 1; i++){
    if (token == NULL){
      break;
    }
    token[strcspn(token,"\n")] = '\0';
    char *pointer = strdup(token);
    argv[i] = pointer;
    token = strtok(NULL, " ");
    count += 1;
  }
  // while(token!=NULL && count<size){
  //   argv[count]=strdup(token);
  //   token=strtok(NULL," ");
  //   count+=1;
  // }
  argv[count] = NULL;

}

void ReadCommand(char *line, struct Command *command)
{
  //struct SubCommand subcommand;
  char *token;
  token = strtok(line, "|");
  int count=0;
  while (token != NULL && count<MAX_SUB_COMMANDS)
  {
    command->sub_commands[count].line = strdup(token);
    token = strtok(NULL, "|");
    count++;
  }
  command->num_sub_commands=count;
  int j=0;
  for (j=0;j<command->num_sub_commands;j+=1){
    ReadArgs(command->sub_commands[j].line, command->sub_commands[j].argv, MAX_ARGS);
  }
  
}
void PrintCommand(struct Command *command)
{
  int i = 0;
  for (i; i < command->num_sub_commands; i++)
    {
      print_args(command->sub_commands[i].argv);
    }
}