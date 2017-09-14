#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include "mytoc.h"

//function that is used to tell me how many words are in a string while using the delimiter
int numberOfWords(char *str, char delim){
  int numOfWords = 0;
  int count = 0;
  char *p;
  for(p = str; *p; ++p){
    if(*p != '\0'){
      // printf("%c%", *p);
    }
    if(*p == delim){
      if(count != 0){
	numOfWords++;
	count = 0;
      }
    }
    else
      count++;
  }
  if(count != 0)
    numOfWords++;
  return numOfWords;
}

//tells me the number of characters in a string
int numberOfChar(char *word){
  char *p;
  int count = 0;
  for(p = word; *p; ++p)
    count++;
  return count;
}

//given a strin and a delimiter, it returns an array of strings with the appropriate memory allocated
char ** mytoc(char *str, char delim){
  
  int count = 0;
  //used to get the appropriate size for listOfWords
  int numOfWords = numberOfWords(str, delim);
  //temp pointer that is used to go through the given string
  char *p;
  char **listOfWords;
  int wordCounter = 0;
  //used as a key to keep track of where in the string we currently are when parsing the string
  int totalCount = 0;

  //allocating memory for listOfWords
  listOfWords = (char**) malloc(sizeof(char*) * numOfWords);

  //gets the length of the string
  int len = numberOfChar(str);
  printf("words: ");
  printf("%d\n", numOfWords);
  p = str;

  //used to make sure that a space isn't part of a word
  int charCounter = 0;
  
  for(int x = 0; x <= len; x++){

    //makes sure that a space isn't considered a word
    if(p[totalCount] == delim && charCounter == 0)
      count = 0;
    
    //adds a word to the list of words
    if(p[totalCount] == delim && count != 0){
      listOfWords[wordCounter] = (char*) malloc(sizeof(char)*count+1);
      for(int i = 0; i < count; i++){
	listOfWords[wordCounter][i] = p[totalCount - charCounter];
	charCounter--;
      }
      totalCount++;
      wordCounter++;
      count = 0;
      charCounter = 0;
   }
    //if it is at the end of the string and there is a word that hasn't been added
    else if(x == len && count != 0){
      listOfWords[wordCounter] = (char*) malloc(sizeof(char)*count+1);
      for(int i = 0; i < count; i++){
	listOfWords[wordCounter][i] = p[totalCount - charCounter];
	charCounter--;
      }
      
      totalCount++;
      wordCounter++;
      count = 0;
      charCounter = 0;
    }
    //if it hasn't hit a delimiter
    else if(p[totalCount] != delim){
      totalCount++;
      count++;
      charCounter++;
    }
    else{
      totalCount++;
      count++;
      
    }
  }
  return listOfWords;
}  
