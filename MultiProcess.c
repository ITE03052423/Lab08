#include <stdio.h>
#include <sys/types.h>

int main()
{
  int pid,status=0;
  int i;
  for(i=0;i<3;i++)
  {
    pid=fork();
    if(pid!=0)
    {
      printf("Child PID:%d\n",pid);    
      pid=wait(&status);
//      printf("Child PID:%d\n",pid);
    }
    else
    {
      printf("My PID:%d  My parent's PID:%d\n",getpid(),getppid());
      exit(status);
    }
  }

  return 0;
}
