/* hello_signal.c */
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int flip = 1;
//handler
void handler(int signum)
{ 
  flip = 1;
  printf("Hello World!\n");
  alarm(1);
  flip = 0;
}

int main(int argc, char * argv[])
  //register handle SIGALRM
{
  for (;;){
  signal(SIGALRM,handler); 
  alarm(1); 
  while(flip);
      printf("Turing was right!\n");
      flip = 1;
  }
  return 0;
}