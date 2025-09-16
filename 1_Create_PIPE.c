// How to create Pipe

#include<stdio.h>
#include <unistd.h>
int main()
{
    int fd[2],ret;

    if((ret=pipe(fd))<0)
    {
        perror("pipe");
        return 0;
    }

    printf("fd[0] = %d\n",fd[0]);
    printf("fd[1] = %d\n",fd[1]);
}
