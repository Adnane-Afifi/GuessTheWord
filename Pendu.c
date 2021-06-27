#include "Pendu.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <time.h>

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
    printf("OH ! maybe next time it was %s ! \n",word);
}


}
int  getNumberElementFile(){
   const char * namefile = "names.txt";
   FILE * file = fopen(namefile,"r");
   int count =0 ;
   char endofLine = ' ';
   if(file!=NULL){
   while(endofLine!=EOF){
       endofLine=fgetc(file);
      if(endofLine=='\n')count++;
   }
   }
   else{
       printf("ERROR can not read  %s   !",namefile);
   }
   fclose(file);
   
 return count;
}
int generateNumber(){
    srand(time(NULL));
    int generateNumber = 1;
     generateNumber=rand()%getNumberElementFile()+1;
    return generateNumber;
}

char * getSecretWord(){
    int count=0;
    FILE * file = fopen("names.txt","r");
    char * word = (char *) malloc(sizeof(char )*20);
    while(count!=generateNumber() && word!=NULL){
        word=fgets(word,100,file);
        count++;
    }
    return word;
}

 char * genGuessWord(char * word){
   size_t length = strlen(word);
   char * guessWord =(char *) malloc(sizeof(char )*length);
   for( size_t i =0 ; i<length;i++){
    guessWord[i]='*';
   } 
   return guessWord;
}