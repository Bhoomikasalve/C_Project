/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*
Computer randomly selects a number 
between 1 and 100. You have 7 chances to guess that 
number.
*/
int main()
{
    time_t t;
    srand((unsigned) time(&t));
    int trials, guess;
    printf("Welcome to guess the number game.\n Guess number between 1 and 100.\n");
    
    char choice;
    int secret_num = rand() % 100 + 1; //random number is being generated here
    //printf("secret number is: %d\n", secret_num);
    for(trials = 7; trials > -1; trials--){
        printf("Welcome ! You have %d trials\n", trials);
        //printf("secret number is: %d\n", secret_num);
        scanf("%d", &guess);
        if(trials == 0){
            printf("Sorry..out of trials..press 'y' to play again..\n");
         scanf(" %c", &choice);
         if(choice == 'y') 
         {
             trials = 8;
             secret_num = rand()%100 + 1;
        }
        else {
            printf("Bye Bye\n"); 
            break;
        }
        }
        else if(guess == secret_num){
         printf("Correct !..press 'y' to play again..\n");
         scanf(" %c", &choice);
         if(choice == 'y') 
         {
             trials = 8;
             secret_num = rand()%100 + 1;
        }
        else {
            printf("Bye Bye\n"); 
            break;
        }
        }
        //checking for higher value
        else if(guess < secret_num) printf("Go higher..");
        //checking for lower value 
        else if(guess > secret_num) printf("Go lower..");
    }
    //trials--;
    return 0;
}
