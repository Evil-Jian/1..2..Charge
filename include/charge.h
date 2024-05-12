# ifndef CHARGE_H
# define CHARGE_H
#include <ctype.h>
#include <stdio.h>
#include <stdbool.h>
#include <unistd.h> 
#include <stdlib.h>
#include <string.h>

int calculateTurn(int, int);
int computeCharge(int, int*);
int moveCost(int);
void displayWin();
void displayLose();
void displayState(int);
void displayInstructions();
void displaySeparator();
const char* translateMove(int);

# endif