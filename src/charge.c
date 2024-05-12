#include "../include/charge.h"
#include "../include/connection.h"

int calculateTurn(int userMove,int enemyMove){
    // 0 - charge, 1 - shield, 2 - teleport, 3 - double shield, 4 - wave, 5 - telewave
    // 6 - double wave, 7 - electric, 8 - plasma, 9 - black hole

    if ((userMove == 0 && enemyMove >= 4) || 
        (userMove == 1 && enemyMove >= 6) || 
        (userMove == 2 && (enemyMove >= 5 && enemyMove <= 6)) ||
        ((userMove == 3 || userMove == 6) && enemyMove >= 7) ||
        (userMove == 4 && enemyMove >= 5) ||
        (userMove == 7 && enemyMove >= 8) ||
        (enemyMove == 9)){
        //enemy wins
        return 0;
    }
    else if ((enemyMove == 0 && userMove >= 4) || 
        (enemyMove == 1 && userMove  >= 6) || 
        (enemyMove == 2 && (userMove  >= 5 && userMove <= 6)) ||
        ((enemyMove == 3 || enemyMove == 6) && userMove >= 7) ||
        (enemyMove == 4 && userMove >= 5) ||
        (enemyMove == 7 && userMove >= 8) ||
        (userMove == 9)){
        //user wins
        return 1;   
    }
    else{
        //Draw
        return 2;
    }
        
}

int computeCharge(int move, int* charges){

    int cost = moveCost(move);
    //Validate Move
    if(cost > *charges){
        return 1;
    }
    else{
        *charges -= cost;
        return 0;
    }
}

int moveCost(int move){
    int cost;
    switch(move){
        case 0:
            cost = -1;
            break;
        case 2: case 3: case 4:
            cost = 1;
            break;
        case 5: case 6:
            cost = 2;
            break;
        case 7:
            cost = 3;
            break;
        case 8:
            cost = 4;
            break;
        case 9:
            cost = 5;
            break;
        default:
            cost = 0;       
    }
    return cost;
}

const char* translateMove(int move){
    switch(move){
        case 0:
            return "Charge";
        case 1:
            return "Shield";
        case 2: 
            return "Teleport";
        case 3:
            return "Double Shield";
        case 4:
            return "Wave";
        case 5: 
            return "Telewave";
        case 6:
            return "Double Wave";
        case 7:
            return "Electric";
        case 8:
            return "Plasma";
        case 9:
            return "Black Hole";
        default:
            return "Unknown";     
    }
}

void displayWin(){
    printf("You Win!\n");
}

void displayLose(){
    printf("You Lose!\n");
}

void displayState(int charge){
    printf("Your amount of charges left: %d\n\n", charge);
}

void displayInstructions(){
    system("clear");
    printf("\nInput a number from 0-9. Each number corresponds to a move in 1-2 Charge\n");
    printf("0 - Charge\n1 - Shield\n2 - Teleport\n3 - Double Shield\n4 - Wave\n5 - Telewave\n");
    printf("6 - Double Wave\n7 - Electric\n8 - Plasma\n9 - Black Hole\n\n");
}

void displaySeparator(){
    printf("------------------------------------------------------\n\n");
}