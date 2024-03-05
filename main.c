#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<stdbool.h>


#define ROCK 1
#define PAPER 2
#define SISSORS 3

void menu() {
    printf("Enter your choioce.\n");
        printf("1: rock\n");
        printf("2: paper\n");
        printf("3: sissors\n");
       
}

bool game() {
   
   srand(time(NULL));
   int player = 0;
   int computer = 0;
   bool draw = false;
   int lives = 5;

   while(lives > 0) {
        menu();
        printf("Your choice: ");
        scanf("%d", &player);

        if(player < 1 || player > 3) {
            printf("Invalid choice please enter again. \n");
            continue;
        }

        computer = (rand() % 3) + 1;
        if(computer == ROCK)
            printf("\n Computer's choice is Rock");
        else if (computer == PAPER)
            printf("\n Computer's choice is Paper");
        else if(computer == SISSORS)
            printf("\n Computer's choice is Sissors");
        
        draw = false;
        if ((player == ROCK && computer ==  SISSORS) || 
            (player == SISSORS && computer == PAPER) || 
            (player == PAPER && computer == ROCK)){
            printf("\nYou Win!\n\n");
        } else if ((player == ROCK && computer == PAPER) || 
                    (player == SISSORS && computer == ROCK) || 
                    (player == PAPER && computer == SISSORS)) {
            printf("\nYou Lose!\n\n");
            lives--;
        } else {
            printf("\n It's DRAW! pay again\n\n");
            draw = true;
        }
        printf("Lives ramaining: %d\n", lives);

    }

    char choice;
    printf("Do you want to play again? (Press 's' to stop and any other key to continue): ");
    while ((getchar()) != '\n');
    scanf("%c", &choice);
    return (choice != 's');
}


int main( ) {

    game();

    return 0;
}