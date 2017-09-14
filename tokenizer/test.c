#include "mytoc.h"
#include<stdio.h>
int main(){
  char *str;
  printf("Type the string: ");
  //sets str to the user input... pretty sure its causing the random numbers on the side of the words
  scanf("%m[^\n]", &str);
  //by default the delimiter is a space
  char delim = ' ';
  //calling the mytoc funtion and setting list to the list of words returned
  char ** list = mytoc(str, delim);
  char *p;
  //go through the list of words and print them out
  for(int i = 0; i < numberOfWords(str, delim); i++){
    int pcount = 0;
    printf("$ ");
    for(p = list[i]; *p; ++p){
      printf("%c", list[i][pcount]);
      pcount++;
    }
    printf("\n");
  }

  printf("\n");
  
}
