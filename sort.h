#include "heap.h"

#include <stdio.h>

void sort(int * tree, int length){
  int end=length-1;


  heapify(tree, length);
  
  while (end >0){
    //Da die Wurzel am groessten ist kann sie an letzte Stelle gerueckt werden
    swapf(tree, 0, end);
    //und end ist eins weiter vorne
    end--;

    //Da der neue Baum bis auf die Wurzel passt, kann siftdown angewandt werden
    siftDown(tree, 0, end);
  }
  return;
}
