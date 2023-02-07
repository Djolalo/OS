#include "../include/ipcTools.h"

static sem_t semaphore; 
key_t key;
int main(int argc, char const *argv[]) {
    /*parent process initializes a blocking semaphore...*/
    key= ftok("./tmp/patrick", 1);
    printf("bojoure jo suis la cle %d\n", key);
    int semaphore = semalloc(key, 1);
    /*...then initializes a child.*/
    int forque = fork();
    
    if (forque == 0) {
        /*child process attempts to pass the semaphore the prints a message and dies*/
        P(semaphore);
        puts("bojoure jo sui le fils punie");
        return 0;
    }
    else if (forque > 0){
        /* parent process increments semaphore after a second...*/
        if(sleep(1)<0)
            fprintf(stderr, "j'ai po pu attendre ;(");
        puts("attente terminer");
        V(semaphore);
        puts("semaphore validere");
        /*...then waits for the end of the child process to die*/
        while(waitpid(0,0,0)<0);
        puts("bojoure jo sui lo padre");
    }
    else{
        fprintf(stderr, "fork failed");
        exit(EXIT_FAILURE);
    }    
    return EXIT_SUCCESS;
}