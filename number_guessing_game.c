#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main(){
    int random,guess;
    int no_of_guess= 0;
    srand(time(NULL));
    printf("Welcome to world of guessing numbers\n");
    random = rand() % 100 + 1;
    //printf("number generated is %d\n",random);
    do {
    printf("please enter your guess(1 to 100)\n");
    scanf("%d",&guess);
    no_of_guess++;
         if (guess < random){
         printf("guess larger number\n");
         }
         else if (guess > random){
              printf("guess the smaller number\n");
              }else{
            printf("Congratulations!You haave sucessfully guessed the right number in%dattempts\n",no_of_guess);
        }
    }
    while(guess != random);
    printf("Bye thenks for playing the game\n");
    printf("Developed by Aishwarya Mishra\n");
}