// WAP to create Named Pipe 
#include<stdio.h>
int main()
{
    mkfifo("np",0644);
    perror("mkfifo");
return 0;
}
