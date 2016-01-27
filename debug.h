#include <stdio.h>

const int  debugout = 0;

void debug(char str[]){
  if (debugout!=0){
    printf(str);
    printf("\n");
  }
  
}
