#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <time.h> // to measure runtime

clock_t start;

int i = 0;

void handler(int signum)
{ 
  //signal handler
  printf("Hello World!\n");
  
  // change i to 1
  i = 1;
  alarm(1);
  //exit(1); //exit after printing
}

// handler to stop the code from running
void stop(int num){

  

  clock_t end = clock();

  
  double time_elapsed = 2 * ((double)(end - start) / CLOCKS_PER_SEC);

  printf("Time Spent:  %f seconds\n", time_elapsed);

  exit(0);
}

int main(int argc, char * argv[])
{
  start = clock(); // start the runtime 

  signal(SIGALRM,handler); //register handler to handle SIGALRM

  signal(SIGINT, stop);

  alarm(1); //Schedule a SIGALRM for 1 second

  while(1){
    while(i == 0);
    printf("Turing was right!\n\n");
    i = 0;
    
  }; //busy wait for signal to be delivered

}