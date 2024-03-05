#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<stdbool.h>


#define ROCK 1
#define PAPER 2
#define SISSORS 3

void displayMenu() {
    printf("\n=== Rock-Paper-Sissors Game ===\n");
    printf("1: rock\n");
    printf("2: paper\n");
    printf("3: sissors\n");
    printf("====================================\n");
       
}

void displayResult(int player, int computer) {
    printf("\nPlayer's choice: ");
    switch (player) {
        case ROCK:
            printf("Rock\n");
            break;
        case PAPER :
            printf("Paper\n");
            break;
        case SISSORS:
            printf("Sissors\n");
            break;
    }

    printf("Computer's choice: ");
    switch(computer){
    case ROCK:
            printf("Rock\n");
            break;
        case PAPER :
            printf("Paper\n");
            break;
        case SISSORS:
            printf("Sissors\n");
            break;
    }
}

void displayOutcome(int result) {
    if(result == 0) {
        printf("\nIt's a DRAW Play again. \n");
    } else if(result < 0) {
        printf("\nYou Win!\n");
    } else {
        printf("\nYou Lose!\n");
    }
}

void displayLives(int lives) {
    printf("Lives remaining: %d\n", lives);
}

void displayPlayAgainPrompt() {
    printf("Do you want to play another round? (y/n): ");
}

int getPlayerChoice() {
    int choice;
    printf("Enter your choice: ");
    scanf("%d", &choice);
    return choice;
}

bool playAgainPrompt() {
    char response;
    displayPlayAgainPrompt();
    scanf(" %c", &response);
    return (response == 'y' || response == 'Y');
}

void game() {
    srand(time(NULL));
    int player, computer;
    int lives = 5;

    do {
        // system("clear");
        displayMenu();
        player = getPlayerChoice();
        if(player < 1 || player > 3) {
            printf("Invalid choice, please enter again.\n");
            continue;
        }

        computer = (rand() % 3) + 1;
        int result = (player - computer + 3) % 3;
        displayResult(player, computer);

        displayOutcome(result);

        printf("\n-------------------------------\n");
        if(result != 0) {
            lives--;
            displayLives(lives);
        }


    } while(lives > 0);

    if (playAgainPrompt()) {
        game();
    } else {
        printf("\nThanks for playing!\n");
    }
}



int main( ) {
    game();
    return 0;
}