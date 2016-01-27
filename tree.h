#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "debug.h"

int leftof(int i){
  return i*2+1;
}

int rightof(int i){
  return i*2+2;
}
 
int parentof(int i){
  // floor(i) = abrunden(i) 
  return floor((i-1)/2);
}

void swapf (int *tree, int a, int b){
  int tmp;

  tmp=*(tree+a);
  *(tree+a)=*(tree+b);
  *(tree+b)=tmp;
  return;
}

 
