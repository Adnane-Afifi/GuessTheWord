
#include "Pendu.h"
#include <stdio.h>



int main(){
char * word = getSecretWord();
char * guess =  genGuessWord(word);
int attempt = 10;
introduceUser(word,guess,attempt);
startGame(word,guess,attempt);

// printf("There is %d lines on names .txt \n",getNumberElementFile());
// printf("The random number is %d  \n",generateNumber());
// printf("%s",getSecretWord());

}