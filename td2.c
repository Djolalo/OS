#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <time.h>
#define NBPAQUETS 10

void charger(){
pid_t pere = fork();
srand(time(NULL));
    if(pere>0){
        puts("Je suis le fils et je me mets à empaqueter");
        if(sleep(rand()%2)==0){

        }
    }
}

/**
 * @param void
 * @brief Main function
 * On retrouve en constantes SIGUSR1 =10
 * et SIGUSR2 = 12. On notera également que l'empaqueteur et le père s'en serviront
 * Elles sont définies dans la bibliothèque standard signal.h
 * @return int 
 */
int main(void){
int i=0;
    for(i; i<NBPAQUETS;i++){

    }
}