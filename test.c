#include <stdio.h>
#include <string.h>

char str[7];

char* retStr(){
  strcpy(str,"cyber");
  return(str);
}

int cyber(int a){
  switch (a) {
    case 1:
    return 1;
    case 2:
    return 2;
    case 3:
    return 5;
    default:
    return 0;
  }
}

struct Node{
  int value;
  int count;
  char *next;
};



int aaa(){
  return 1;
}


int bbb(){
  return 2 * aaa() + 1;
}
void main(){
  char* aStr = retStr();
  printf("%s\n",aStr);
  printf("%d\n",cyber(3));
  char arr[8] = "cracker";
  char letters[16] = "isrveawhobpnutfg";
  int a;
  a = arr[0] & 0xf;
  printf("%c\n",letters[arr[0] & 0xf]);

  struct Node node1;
  struct Node node2;
  struct Node node3;
  struct Node node4;
  struct Node node5;
  struct Node node6;

  node6.value = 0x1b0;
  node6.count = 1;

  int c = bbb();
  printf("%d\n", c);

}
