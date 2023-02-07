#include <stdio.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int main(void){
    int process_id=0;
    pid_t id_fils = 0;
    process_id=getpid();
    printf("Voici le pid du process actuel: %d\n", process_id);
    switch (fork()){
    case -1:
        puts("Erreur ! Le fork a echoue :'(");
        return 1;
    case 0:
        puts("Je suis le fils");
        id_fils =getpid(); 
        return 0;
    default:
        waitpid(0,0,0);
    }
    if(id_fils != 0 )
        printf("L'id du fils était: %d\n", id_fils);
    return 0;
}