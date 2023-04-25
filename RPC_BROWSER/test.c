#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>

int main(void){
  static DIR *dp;
  struct dirent *ep;
  dp = opendir("./");
  if (dp!=NULL)
    {
      while((ep=readdir(dp))){
	printf("%s\t%d\n",ep->d_name,ep->d_reclen);
      }
      (void)closedir(dp);
    }
  else
    perror("Unable to open folder");
  
  static char cwd[256];
  getcwd(cwd,sizeof(cwd));
  puts(cwd);
  return 0;
}
