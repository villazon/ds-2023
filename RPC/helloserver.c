#include <rpc/rpc.h>
#include "hello.h"
#include <string.h>
#include <stdio.h>

char **helloworld_1_svc(void *n, struct svc_req *rqstp) {
  static char msg[256];
  static char *p;

  printf("getting ready to return value\n");
  strcpy(msg, "Hello world");
  p = msg;
  printf("Returning\n");

  return(&p);
}
