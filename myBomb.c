#include <stdio.h>
#include <signal.h>
#include <stdbool.h>
#include "stdlib.h"

char *input_strings[7][80];
FILE *infile;
int num_input_strings = 0;

typedef struct node{
  int value;
  int id;
  struct node *next;
};

struct node node6 = {0x1b0, 6, NULL};
struct node node5 = {0x0d4, 5, &node6};
struct node node4 = {0x3e5, 4, &node5};
struct node node3 = {0x12d, 3, &node4};
struct node node2 = {0x2d5, 2, &node3};
struct node node1 = {0x0fd, 1, &node2};

typedef struct n{
  int num;
  struct n *nodeA;
  struct n *nodeB;
};

struct n n48 = {0x3e9, NULL, NULL};
struct n n46 = {0x2f, NULL, NULL};
struct n n43 = {0x14, NULL, NULL};
struct n n42 = {0x7, NULL, NULL};
struct n n44 = {0x23, NULL, NULL};
struct n n47 = {0x63, NULL, NULL};
struct n n41 = {0x1, NULL, NULL};
struct n n45 = {0x28, NULL, NULL};
struct n n34 = {0x6b, &n47, &n48};
struct n n31 = {0x6, &n41, &n42};
struct n n33 = {0x2d, &n45, &n46};
struct n n32 = {0x16, &n43, &n44};
struct n n22 = {0x32, &n33, &n34};
struct n n21 = {0x8, &n31, &n32};
struct n n1 = {0x24, &n21, &n22};



void sig_handler(){
  printf("So you think you can stop the bomb with ctrl-c, do you?\n");
  sleep(3);
  printf("Well...");
  fflush(stdout);
  sleep(1);
  printf("OK. :-)\n");
  exit(16);
}

void initialize_bomb(){
  signal(2,sig_handler);
}

bool blank_line(char *line){
  if ((line[0] == NULL) || (((line[0] == '\n') || (line[0] == '\r')) && (line[1] == NULL))){
    return true;
  }else{
    return false;
  }
}

char * skip(FILE *input){
  char *result;
  do{
    if ((result = fgets(input_strings[num_input_strings], 80, input)) == NULL){
      return NULL;
    }
  } while (blank_line(input_strings[num_input_strings]));
  return input_strings[num_input_strings];
}

char* read_line(FILE *input){
  char *retLine;
  retLine = skip(input);
  num_input_strings++;
  return retLine;
}

void explode_bomb(){
  printf("\nBOOM!!!\n");
  printf("The bomb has blown up.\n");
  exit(8);
}

int string_length(char* str){
  int i=0;
  if (str[0] == NULL){
    return 0;
  }
  for (i = 0; str[i] != NULL; i++){}
  return(i-1);
}

bool strings_not_equal(char *line1, char *line2){
  if(string_length(line1) != string_length(line2)){
    return true;
  }
  for(int i=0; line1[i] != '\0'; i++){
    if (line1[i] != line2[i]){
      return true;
    }
  }
  return false;
}

int fun7(struct n *aNode, int num){
  if(aNode == NULL){
    return 0;
  }
  if(num >= aNode->num){
    if(num == aNode->num){
      return 0;
    }
    return 2 * fun7(aNode->nodeB, num) + 1;
  }
  return 2 * fun7(aNode->nodeA, num);
}

void secret_phase(){
  long a = __strtol_internal(read_line(infile),0,0xa,0);
  if(a - 1 > 1000){
    explode_bomb();
  }
  if(fun7(&n1, a) != 7){
    explode_bomb();
  }
  printf("Wow! You've defused the secret stage!\n");
  phase_defused();
}

void phase_defused(){
  if (num_input_strings == 6){
    int num;
    char word[80];
    if (sscanf(input_strings[3],"%d %s", &num ,word) == 2){
      if(!strings_not_equal(word, "austinpowers")){
        printf("Curses, you've found the secret phase!\n");
        printf("But finding it and solving it are quite different...\n");
        secret_phase();
      }
    }
    printf("Congratulations! You've defused the bomb!\n");
  }
}

void phase_1(char *line){
  if (strings_not_equal(line, "Public speaking is very easy.\n")){
    explode_bomb();
  }
}

void read_six_numbers(char *line, int *nums){
  if (sscanf(line, "%d %d %d %d %d %d", &nums[0], &nums[1], &nums[2], &nums[3], &nums[4], &nums[5]) <= 5){
    explode_bomb();
  }
}

void phase_2(char *line){
  int j = 1, numbers[6];
  read_six_numbers(line, numbers);
  for(int i=1; i<7; i++){
    j *= i;
    if (numbers[i-1] != j){
      explode_bomb();
    }
  }
}

void phase_3(char *line){
  int num1, num3;
  char bl, ch2;
  if (sscanf(line, "%d %c %d", &num1, &ch2, &num3) <= 2){
    explode_bomb();
  }
  switch (num1) {
    case 0:
    bl = 'q';
    if (num3 != 777){
      explode_bomb();
    }
    break;
    case 1:
    bl = 'b';
    if (num3 != 214){
      explode_bomb();
    }
    break;
    case 2:
    bl = 'b';
    if (num3 != 755){
      explode_bomb();
    }
    break;
    case 3:
    bl = 'k';
    if (num3 != 251){
      explode_bomb();
    }
    break;
    case 4:
    bl = 'o';
    if (num3 != 160){
      explode_bomb();
    }
    break;
    case 5:
    bl = 't';
    if (num3 != 485){
      explode_bomb();
    }
    break;
    case 6:
    bl = 'v';
    if (num3 != 780){
      explode_bomb();
    }
    break;
    case 7:
    bl = 'b';
    if (num3 != 524){
      explode_bomb();
    }
    break;
    default:
      explode_bomb();
  }
  if (bl != ch2){
    explode_bomb();
  }
}

int func4(int num){
  int retNum = 0;
  if (num > 1){
    return func4(num - 1) + func4(num - 2);
  }
  return 1;
}

void phase_4(char *line){
  int num;
  sscanf(line, "%d", &num);
  if (func4(num) != 55){
    explode_bomb();
  }
}

void phase_5(char *line){
  char letters[16] = "isrveawhobpnutfg";
  char constructWord[7];
  if (string_length(line) != 6){
    explode_bomb();
  }
  for(int i=0; i<6; i++){
    constructWord[i] = letters[line[i] & 0xf];
  }
  constructWord[6] = 0;
  if (strings_not_equal(constructWord, "giants")){
    explode_bomb();
  }
}

void phase_6(char *line){
  unsigned int numbers[6];
  read_six_numbers(line, numbers);
  for(int i=0; i<6; i++){
    if(numbers[i] - 1 > 5){
      explode_bomb();
    }
    for(int j=i+1; j<6; j++){
      if(numbers[i] == numbers[j]){
        explode_bomb();
      }
    }
  }
  struct node *allNodes[6];
  struct node *nodeX = &node1;
  for(int i=0; i<6; i++){
    nodeX = &node1;
    while(nodeX->id != numbers[i]){
      nodeX = nodeX->next;
    }
    allNodes[i] = nodeX;
  }
  for(int i=0; i<5; i++){
    allNodes[i]->next = allNodes[i+1];
  }
  allNodes[5]->next = NULL;

  for(int i=0; i<5; i++){
    if(allNodes[i]->value < allNodes[i]->next->value){
      explode_bomb();
    }
  }
}

void main(int argc, char** argv){
  if (argc == 1){
    infile = stdin;
  }else if (argc == 2){
    infile = fopen(argv[1],"r");
    if (infile == NULL){
      printf("%s: Error: Couldn't open %s\n",argv[0],argv[1]);
      exit(8);
    }
  }else{
    printf("Usage: %s [<input_file>]\n",argv[0]);
    exit(8);
  }
  initialize_bomb();
  printf("Welcome to my fiendish little bomb. You have 6 phases with\n");
  printf("which to blow yourself up. Have a nice day!\n");
  phase_1(read_line(infile));
  phase_defused();
  printf("Phase 1 defused. How about the next one?\n");
  phase_2(read_line(infile));
  phase_defused();
  printf("That's number 2.  Keep going!\n");
  phase_3(read_line(infile));
  phase_defused();
  printf("Halfway there!\n");
  phase_4(read_line(infile));
  phase_defused();
  printf("So you got that one.  Try this one.\n");
  phase_5(read_line(infile));
  phase_defused();
  printf("Good work!  On to the next...\n");
  phase_6(read_line(infile));
  phase_defused();
}
