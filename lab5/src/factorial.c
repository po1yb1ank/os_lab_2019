#include <errno.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <getopt.h>

pthread_mutex_t mut = PTHREAD_MUTEX_INITIALIZER;
int factorial = 1;

struct fact_args {
    int begin;
    int end;
    int mod;
};

void ParFact(void*);

int main(int argc, char **argv)
{
  int threads_num = 0;
  int fact_n = -1;
  int mod_n = 0;
  pthread_t threads[threads_num];
  while (true) {
    int current_optind = optind ? optind : 1;

    static struct option options[] = {{"fact_n", required_argument, NULL, 'k'},
                                      {"mod", required_argument, 0, 0},
                                      {"pnum", required_argument, 0, 0},
                                      {0, 0, 0, 0}};

    int option_index = 0;
    int c = getopt_long(argc, argv, "k:", options, &option_index);

    if (c == -1) break;

    switch (c) {
      case 0:
        switch (option_index) {
          case 1:
            mod_n = atoi(optarg);
            if (mod_n <= 0) {
                printf("array_size is a positive number\n");
                return 1;
            }
            break;
          case 2:
            threads_num = atoi(optarg);
            if (threads_num <= 0) {
                printf("threads_num is a positive number\n");
                return 1;
            }
            break;
          defalut:
            printf("Index %d is out of options\n", option_index);
        }
        break;
      case 'k':
        fact_n = atoi(optarg);
        if (fact_n < 0) {
                printf("seed is a positive number\n");
                return 1;
            }
            break;
      case '?':
        break;

      default:
        printf("getopt returned character code 0%o?\n", c);
    }
  }
  if (threads_num == 0 || mod_n == 0 || fact_n == -1) {
    printf("Usage: %s -k \"num\" --pnum \"num\" --mod \"num\" \n",
           argv[0]);
    return 1;
  }
  struct fact_args args[threads_num];
  int part=fact_n/threads_num;
  for(int i=0;i<threads_num;i++){
      args[i].begin=i*part+1;
      args[i].end=(i == (threads_num - 1) ) ? fact_n: (i + 1) * part;
      args[i].mod=mod_n;
  }
  for(int i=0;i<threads_num;i++){
      if (pthread_create(&threads[i], NULL, (void *)ParFact, (void *)&args[i])) {
      printf("Error: pthread_create failed!\n");
      return 1;
    }
  }
  for(int i=0;i<threads_num;i++){
    if (pthread_join(threads[i], NULL) != 0) {
    perror("pthread_join");
    exit(1);
    }
  }
  printf("Factorial - %d\n",factorial);

}

void ParFact(void* args){
    struct fact_args* str=(struct fact_args*)args;
    pthread_mutex_lock(&mut);
    int buf=1;
    for(int i=str->begin;i<=str->end;i++){
      buf=((buf*i)%(str->mod));
        printf("Buf - %d\n",buf);
    }
    factorial=(factorial*buf)%str->mod;
    pthread_mutex_unlock(&mut);
}
