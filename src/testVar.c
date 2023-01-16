#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(void){
    int process_id=0;
    pid_t forque =fork();
    process_id=getpid();
    switch (forque)
    {
    case -1:
        puts("Erreur ! Le fork a echoue :'(");
    case 0:
        puts("Je suis le fils");
        return getpid();
    default:
        waitpid()
    }
}