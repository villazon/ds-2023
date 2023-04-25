#include <stdio.h>
#include <rpc/rpc.h>
#include "browser.h"
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main (int argc, char *argv[]) {

  CLIENT *cl;
  static char *p;
  if (argc !=2) {
    printf("Usage: client hostname\n");
    exit(1);
  }

  printf("connecting to..%s\n", argv[1]);
  cl = clnt_create(argv[1],DSFILEBROWSER, DSVER, "tcp");
  if (cl == NULL) {
    clnt_pcreateerror(argv[1]);
    exit(1);
  }

  printf("Getting ready to browse\n");
  struct fileinfo *file;
  p = "";
  file = getfileinfo_2020(&p,cl);

  printf("Back from browser\n");
  if (file == NULL) {
    clnt_perror(cl,argv[1]);
    exit(1);
  }

  while (strcmp(file->nextfile,"")!=0){
    printf("%s\t%s\t%d\n",file->filename,file->fullpath,file->size);
    char *next = file->nextfile;
    file = getfileinfo_2020(&next,cl);
    if (file == NULL) {
      clnt_perror(cl,argv[1]);
      exit(1);
    }
  }
  return 0;
}
