#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
int main(){
  if (1) printf("sequential executed through myProgramm\n");
  execl("sequential_min_max"," ","10","10000",NULL);
  return 0;
}
