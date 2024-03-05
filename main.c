/*
===============================================================================
  Rock-Paper-Scissors Game
  main.c

  Author: Jordy Ore KONDA
  Date:   March 6, 2024
  Licence: MIT

  Description:
  This program implements a simple console-based Rock-Paper-Scissors game in C.
  The player competes against a computer opponent, making choices of Rock, Paper,
  or Scissors. The game continues until the player runs out of lives.

  Enjoy the game!
===============================================================================
*/


#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<stdbool.h>


#define ROCK 1
#define PAPER 2
#define SISSORS 3

// ANSI color escape codes
#define COLOR_RESET "\x1b[0m"
#define COLOR_BOLD "\x1b[1m"
#define COLOR_RED "\x1b[31m"
#define COLOR_GREEN "\x1b[32m"
#define COLOR_YELLOW "\x1b[33m"

void displayMenu() {
    printf("\n%s%s=== Rock-Paper-Scissors Game ===%s\n", COLOR_BOLD, COLOR_YELLOW, COLOR_RESET);
    printf("%s1:%s %sRock\n", COLOR_GREEN, COLOR_RESET, COLOR_BOLD);
    printf("%s2:%s %sPaper\n", COLOR_GREEN, COLOR_RESET, COLOR_BOLD);
    printf("%s3:%s %sScissors\n", COLOR_GREEN, COLOR_RESET, COLOR_BOLD);
    printf("%s====================================%s\n", COLOR_YELLOW, COLOR_RESET);
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
        printf("\n%sIt's a DRAW!%s Play again. \n", COLOR_GREEN, COLOR_RESET);
    } else if(result < 0) {
        printf("\n%sYou Win!%s\n", COLOR_GREEN, COLOR_RESET);
    } else {
        printf("\n%sYou Lose!%s\n", COLOR_RED, COLOR_RESET);
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
