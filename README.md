## Rock-Paper-Scissors Game

### Overview

This is a simple console-based Rock-Paper-Scissors game written in C. The game allows the player to choose between Rock, Paper, and Scissors and plays against a computer opponent. The player has a limited number of lives, and the game continues until the player runs out of lives.

### How to Play

1. Run the executable `main` to start the game.
2. Choose your move by entering the corresponding number:
   - 1: Rock
   - 2: Paper
   - 3: Scissors
3. The computer will randomly select its move.
4. The game will display the choices made by both the player and the computer.
5. The outcome of the round (Win, Lose, or Draw) will be shown.
6. If the game is not a draw, the player loses a life, and the remaining lives are displayed.
7. The game continues until the player runs out of lives.
8. After the game ends, you have the option to play again.

### Compilation

To compile the program, use the provided Makefile. Open a terminal and navigate to the directory containing the source code and the Makefile. Then, run the following command:

```
make
```

### Execution

After compilation, run the executable with the following command:

```
./main
```

### Cleaning Up

To remove the compiled files, use the following command:

```
make clean
```

### Notes

- The game uses a simple formula to determine the winner: `(player - computer + 3) % 3`. This ensures that the result is either 0 (draw), 1 (win), or 2 (lose).
- The player starts with 5 lives, and one life is deducted for each loss.
- The game prompts the player if they want to play another round after running out of lives.
