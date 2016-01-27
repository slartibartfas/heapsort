
#include "sort.h"


#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int check (int  * tree, int length);

int main (){
  // Groesse des Baumes / des Arrays
  const int length=2000000;
  int tree [length];
  long long int start_time, end_time, elapsed;
  struct timeval gettime_now;
  FILE *timelog;
  
  
  // Fuellen mit Zufallszahlen
  srand(time(0)); //Uhrzeit als Basis fuer Zufallszahlen
  
  for (int i=0; i<length; i++){
    tree [i] = rand();
  }
  printf("Erzeugte Array mit Zufallszahlen\n");
  
  //Laufzeitmessung
  gettimeofday(&gettime_now, NULL);
  start_time=gettime_now.tv_usec+1000000*gettime_now.tv_sec;
  //sortieren
  sort(tree, length);

  gettimeofday(&gettime_now, NULL);
  end_time=gettime_now.tv_usec+1000000*gettime_now.tv_sec;

  //schreibe Zeit in logfile
  timelog = fopen("timelog", "a+");
  
  elapsed = (end_time - start_time);
  printf("Benoetigte %d us\n", elapsed);
  fprintf(timelog, "%d\n", elapsed);

  fclose(timelog);
 
  //u\"eberpru\"fe die Sortierreihenfolge 
  if (check(tree, length)==0){
    printf("Reihenfolge stimmt!\n");
    return 0;
  }
  else
    printf("Falsch Sortiert\n");
  return 1;
}


int check (int * tree, int  length){
  for (int i = 0; i < length-1; i++){
    if (*(tree+i)>*(tree+i+1)){
      return 1;
          
    }
      
  }
  return 0;
  
}




