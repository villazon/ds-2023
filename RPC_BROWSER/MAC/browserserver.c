#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>
#include <rpc/rpc.h>
#include "browser.h"
#include <unistd.h>
#include <string.h>

int get_file_size(char* filename ){
  FILE* f = fopen(filename,"r");
  if( f == 0 )
    return -1;
  fseek(f,0,SEEK_END);
  int size = ftell(f);
  fclose(f);

  return size;
}

fileinfo *getfileinfo_2020_svc(char **n, struct svc_req *rqstp) {
   printf("The file is: %s \n", *n);
    static char msg[256];
    static char *p;
    static DIR *dp;
    struct dirent *ep;
    int c = 0;
    static struct fileinfo *thefile;
    thefile = (fileinfo *) malloc(sizeof(fileinfo));

    dp = opendir("./");

    static char cwd[256];
    if(getcwd(cwd,sizeof(cwd))!= NULL) {
      printf("working dir %s \n", cwd);
    }else{
      perror("getcwd failed");
      return NULL;
    }
    strcat(cwd,"/");

    if (dp!=NULL){
      // Will get the first one
        if (strcmp(*n,"")==0){
            while((ep=readdir(dp))&&(c<2)){
                if (c==0){
                    thefile->filename = ep->d_name;
                    thefile->size = get_file_size(ep->d_name); // ep->d_reclen;
                    strcat(cwd,ep->d_name);
                    thefile->fullpath = cwd;
                }
                if(c==1){
                    thefile->nextfile = ep->d_name;
                }
                c=c+1;
	    }
	}
        else{
	  // Search for the next 
            while((ep=readdir(dp)) && (c<2)){
                if(c==1){
                    thefile->nextfile = ep->d_name;
		    c++;
                }
                if (c==0 && strcmp(*n, ep->d_name)==0){
		  //		  printf("FOUND CURRENT %s \n", ep->d_name);
                    thefile->filename = ep->d_name;
                    thefile->size = get_file_size(ep->d_name); //ep->d_reclen;
                    strcat(cwd,ep->d_name);
                    thefile->fullpath = cwd;
		    c++;
                }

            }
        }
        (void)closedir(dp);
    }
    else{
        perror("Unable to open folder");
    }
    if (c==1)
    {
        thefile->filename="";
        thefile->size = -1;
        thefile->fullpath="";
        thefile->nextfile="";
        thefile->nextfile="";
    }
    printf("FILE %s SIZE %d NEXT %s \n", thefile->filename, thefile->size, thefile->nextfile);
    printf("getting ready to return value\n");


    return(thefile);
}
