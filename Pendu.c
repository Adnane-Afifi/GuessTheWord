#include "Pendu.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

void introduceUser(char* word , char guess[],int attempt){
int lengthWord=6;
char * name = (char *) malloc(sizeof(char)*20);
printf("Hello,What is your name ?\n");
scanf("%s",name);
printf("Welcome %s ,THE GAME WILL START -->\n",name);
printf("You have %d attempt to play !\n",attempt);
}

char getCharactere() 
{ 
    char caractere = 0;
 
    caractere = getchar(); // On lit le premier caractère
    caractere = toupper(caractere); // On met la lettre en majuscule si elle ne l'est pas déjà
 
    // On lit les autres caractères mémorisés un à un jusqu'au \n (pour les effacer) 
    while (getchar() != '\n') ;
 
    return caractere; // On retourne le premier caractère qu'on a lu 
}

//CHECK COMPLEXITY !
void startGame(char * word,char guess[],int attempt){
    char caractere = ' ';
    int count=0;
   while(strcmp(word,guess)!=0 && attempt!=0){
     printf("What is the secret word %s ?\n",guess);
    caractere= getCharactere();
    for(int i =0 ; i<strlen(word);i++){
       if(caractere==word[i]){
           guess[i]=caractere;
       }
       else{
         count++;
         printf("----->%d\n",count);
       }
    }
    printf("FINALCOUNT----->%d\n",count);
    printf("FINALWORD----->%zu\n",strlen(word));
    if(count==strlen(word)){
        attempt--;
    }
    count=0;
    printf("Number of attempt remaining  ::%d  \n",attempt);
}
if(attempt>0 && strcmp(word,guess)==0){
    printf("GG , YOU WIN!!! the word was %s \n",guess);
}
else{
    printf("OH ! maybe next time ! \n");
}
}