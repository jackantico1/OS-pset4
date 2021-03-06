#include <stdio.h>
#include <string.h>
#define MAX_SUB_COMMANDS 5 
#define MAX_ARGS 10

struct SubCommand{
  char *line; // this is the "a | b c > output.txt < input.txt &" or no?
  char *argv[MAX_ARGS];
};

struct Command {
  struct SubCommand sub_commands[MAX_SUB_COMMANDS];
  int num_sub_commands;
  char *stdin_redirect; 
  char *stdout_redirect; 
  int background;
};

//Is it okay if it doesn't use the reverse methodology
void ReadRedirectsAndBackground(struct Command *command);

void PrintCommand(struct Command *command);

void ReadRedirectsAndBackground(struct Command *command) {

}

int main() {

  //char s[200];

  // printf("Enter a string: ");
  // fgets(s, sizeof s, stdin);
  char c;

  char s[40] = "a | b c > output.txt < input.txt &";

  struct Command command;
  ReadRedirectsAndBackground(&command);

  int i;
  int counterBackward = 1;
  int counterForward = 1;
  int stdinStart = 0;
  int stdinEnd = 0;
  int stdoutStart = 0;
  int stdoutEnd = 0;
  char background[5] = "no";

  int len = sizeof(s)/sizeof(s[0]);
  for (i = 0; i < len; i++) {

    c = s[i];

    if (s[i] == '.') {
      while (s[i - counterBackward] != ' ') {
        counterBackward++;
      }

      while (s[i + counterForward] != ' ') {
        counterForward++;
      }

      if (stdinStart == 0) {
        stdinStart = i - counterBackward + 1;
        stdinEnd = counterForward + i - 1;
      } else {
        stdoutStart = i - counterBackward + 1;
        stdoutEnd = counterForward + i - 1;
      }

      counterBackward = 0;
      counterForward = 0;
    }

    //Does this way work? -> I think yes
    if (s[i - 1] == '&' && s[i] == '\0') {
      background[0] = 'y';
      background[1] = 'e';
      background[2] = 's';
    }

  }

  int lenS1 = stdinEnd - stdinStart + 1;
  char s1[lenS1];
  int j;
  for (j = 0; j < lenS1; j++) {
    s1[j] = s[stdinStart + j];
  }

  int lenS2 = stdoutEnd - stdoutStart + 1;
  char s2[lenS2];
  int k;
  for (k = 0; k < lenS2; k++) {
    s2[k] = s[stdoutStart + k];
  }

  printf("Redirect stdin: %s \n", s1);
  printf("Redirect stdout: %s \n", s2);
  printf("Background: %s \n", background);
	
  // struct Command command;
  // ReadCommand(s, &command);
  // PrintCommand(&command);


	return 0;

}