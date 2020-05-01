#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
int main(){
  pid_t zombie;
  while(1){
    zombie = fork();
    if(zombie > 0){
      printf("i need brains lmao\n");
      sleep(7);
      printf("lets kill'em\n");
      wait(NULL);
    }
    else{
      exit(0);
    }
  }
  return 0;
}
