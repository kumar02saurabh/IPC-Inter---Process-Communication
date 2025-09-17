// WAP to program to find the size of pipe

// METHOD 1:

#if 0
#include <stdio.h>
int main()
{
    int fd[2], count = 0, ret;
    char ch = 'a';
    if(pipe(fd)<0)
    {
        perror("pipe");
        return 0;
    }
    while ((ret = write(fd[1], &ch, 1)) > 0)
    {
        count++;
        printf("Size of pipe is %d\n", count);
    }
}
#elif 1
 
// METHOD 2:
#include <stdio.h>
#include<unistd.h>
#include<fcntl.h>
int main()
{
    int fd[2], count = 0, ret;
    char ch = 'a';
    pipe2(fd,O_NONBLOCK); 
    while ((ret = write(fd[1], &ch, 1)) > 0)
        count++;
    printf("ret value is %d\n",ret);
    printf("Size of pipe is %d\n", count);
    
}
#endif
