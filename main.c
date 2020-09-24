#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <time.h> // to measure runtime

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

int main(int argc, char * argv[])
{
  signal(SIGALRM,handler); //register handler to handle SIGALRM

  alarm(1); //Schedule a SIGALRM for 1 second

  while(1){
    while(i == 0);
    printf("Turing was right!\n\n");
    i = 0;
    
  }; //busy wait for signal to be delivered

}