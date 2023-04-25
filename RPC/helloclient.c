#include <stdio.h>
#include <rpc/rpc.h>
#include "hello.h"
#include <stdlib.h>

int main (int argc, char *argv[]) {

  CLIENT *cl;
  char **p;
  
  if (argc != 2) {
    printf("Usage: client hostname\n");
    exit(1);
  }

  cl = clnt_create(argv[1],HELLOWORLDPROG, HELLOWORLDVERS, "tcp");
  if (cl == NULL) {
    clnt_pcreateerror(argv[1]);
    exit(1);
  }

  printf("Getting ready to call hello\n");
  p = helloworld_1(NULL,cl);

  printf("Back from hello\n");
  if (p == NULL) {
    clnt_perror(cl,argv[1]);
    exit(1);
  }

  printf("Returned string=%s\n",*p);

}
