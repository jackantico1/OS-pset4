#include <stdio.h>
#include <string.h>
#define MAX_SUB_COMMANDS 5 
#define MAX_ARGS 10

struct SubCommand{
  char *line;
  char *argv[MAX_ARGS];
};

struct Command {
  struct SubCommand sub_commands[MAX_SUB_COMMANDS];
  int num_sub_commands;
  char *stdin_redirect; 
  char *stdout_redirect; 
  int background;
};

void ReadRedirectsAndBackground(struct Command *command);
void PrintCommand(struct Command *command);

int main() {

  char s[200];
  //char s[30] = "a b c | d e f g";

  
  printf("Enter a string: ");
  fgets(s, sizeof s, stdin);

	
  struct Command command;
  ReadCommand(s, &command);
  PrintCommand(&command);


	return 0;

}