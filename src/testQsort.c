#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define STRINGSIZE 30

typedef struct{
    char name[STRINGSIZE+1];
    int num;
}Fiche;
int compareNumerique(const void *f1,const void *f2){
    Fiche *preums=(Fiche *) f1;
    Fiche *deuz=((Fiche *) f2);
    return (*preums).num>(*deuz).num;
}
int compareChaines(const void *f1,const void *f2){
    Fiche *preums=(Fiche *) f1;
    Fiche *deuz=(Fiche *) f2;
    return strcmp((*preums).name,(*deuz).name);
}
void afficheFiche(Fiche *tab, int indice){
    printf("%s - %d\n", tab[indice].name, tab[indice].num);
}
void afficheTab(int size, Fiche *tab){
    for(int i=0;i<size;i++){
        afficheFiche(tab,i);
    }
}


int main(int argc, char **argv){
    Fiche tab[]={
        {"Patrick",1},
        {"Norbert",3},
        {"Enrique",2},
        {"Isaac",0}
    };
    puts("Tableau de base:");
    afficheTab(sizeof(tab)/sizeof(Fiche), tab);
    qsort(tab,sizeof(tab)/sizeof(Fiche),sizeof(Fiche), &compareChaines);
    puts("Tableau par ordre alphabetique:");
    afficheTab(sizeof(tab)/sizeof(Fiche),tab);
    qsort(tab,sizeof(tab)/sizeof(Fiche),sizeof(Fiche),&compareNumerique);
    puts("Tableau par ordre numerique:");
    afficheTab(sizeof(tab)/sizeof(Fiche),tab);
    return 0;
}