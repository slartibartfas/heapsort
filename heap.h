#include "tree.h"

#include <stdio.h>

// repariert einen Heap wenn er bis auf die Wurzel passt
void siftDown(int *tree, int start, int end){
  int root
/*Der Elternkonten, der gerade ueberprueft und dann evntl. mit einem Kind getauscht werden soll */,
  child /*Das Kind von root, das gerade ueberprueft wird */,
  swap /*Das Kind, mit dem root getauscht werden soll */;

  root=start;
//Am Anfang ist root gleich start, wenn root mit einem Kind getauscht wurde, wird root zu diesem Kind, welches dann wiederum ueberprueft wird


//solange root noch einen Nachfolger hat
  while (leftof(root)<=end){
    child=leftof(root);
    swap=root;
//swap wird gleich root gesetzt. Wenn es am Ende der Schleife immer noch root ist, bestand kein Bedarf etwas zu tauschen und die Methode ist fertig 

    if (*(tree+swap)<*(tree+child))
      /*Wenn das linke Kind groesser als swap (also root) ist, wird swap auf das Kind geaendert*/
      	swap=child;


    child=rightof(root);
//Das gleiche mit dem rechten Kind, wenn es NOCH GROESSER ist
    if(child<=end
/*Wenn der rechte Knoten existiert*/
	 && *(tree+swap)<*(tree+child))
      	swap=child;
    
  //vertausche root und swap wenn verschieden

    if (swap!=root)
      	swapf (tree, root, swap);
//wenn kein kind kleiner als root ist, ist die funktion fertig      
    else return;
          //macht mit dem Kind das ausgetauscht wurde weiter und tauscht es weiter, falls es kleine Kinder hat
       root=swap;
  }

}


void heapify(int * tree, int length){
  int start=parentof(length-1);

  // fange beim letzten elternknoten an

  while (start >= 0){

    siftDown(tree, start, length-1);
    //gehe einen Knoten zurueck
    start--;
  }
  return;
  
}
