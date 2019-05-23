
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char * argv[])
{
        printf("hello: %d\n", getpid());
        int result = execl("/bin/echo", "echo", "Moe",(char *)0);
        if(-1 == result) perror("couldnt execute");
        else {
                printf("what happened?");
        }
        printf("world: %d\n", getpid());
        return 0;
}