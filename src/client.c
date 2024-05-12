#include "../include/connection.h"
#include "../include/charge.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
  // Initialize Game and Stablish the Connection
  struct sockaddr_in server_address;
  int client_socket;
  init_client_connection(&server_address, &client_socket, argc, argv[0], argv[1], atoi(argv[2]));

  int charge = 0;
  bool isGameComplete = false;
  displayInstructions();
  //Game Loop 

  while(!isGameComplete){
    displaySeparator();
    printf("Waiting for Oppoenent...\n\n");
    char buffer[256];
    int n = recv(client_socket, buffer, 255, 0);
    if (n < 0) exit_with_error("Error: send() Failed."); 

    int enemyMove = atoi(buffer);
    bzero(buffer, 256);
    printf("Opponent Move Received\n\n");

    bool validMove = false;
    while(!validMove){
      printf("Enter Your Move: ");
      fgets(buffer, 255, stdin);

      int userMove = atoi(buffer);

      if (computeCharge(userMove, &charge)){
        printf("You don't have enough charge for that move!\n");
        fflush(stdout);
      }
      else{
        validMove = true;
      }
    }
    int userMove = atoi(buffer);
    printf("You Used %s!\n", translateMove(userMove));
    
    n = send(client_socket, buffer, strlen(buffer)-1, 0);
    if (n < 0) exit_with_error("Error: recv() Failed.");
    
    printf("Opponent Used %s!\n", translateMove(enemyMove));

    //Determine Winner
    int state = calculateTurn(userMove, enemyMove);

    switch(state){
      case 1:
        displayWin();
        isGameComplete = true;
        break;
      case 0:
        displayLose();
        isGameComplete = true;
        break;
      default:
        displayState(charge);
    }
  }

  close(client_socket);
  return 0;
}
