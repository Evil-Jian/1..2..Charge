#include "../include/connection.h"
#include "../include/charge.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
  // Initialize Game and Stablish the Connection
  struct sockaddr_in server_address;
  int server_socket, client_socket;
  init_server_connection(&server_address, &server_socket, &client_socket, argc, argv[0], atoi(argv[1]));
  //Game Loop
  int charge = 0;
  bool isGameComplete = false;
  displayInstructions();

  while(!isGameComplete){
    displaySeparator();
    printf("Enter Your Move: ");
    char buffer[256];
    fgets(buffer, sizeof(buffer), stdin);
    int userMove = atoi(buffer);

    if (computeCharge(userMove, &charge)){
      printf("You don't have enough charge for that move!\n");
      fflush(stdout);
      continue;
    }
    else{
      int n = send(client_socket, buffer, strlen(buffer)-1, 0);
      if (n < 0) exit_with_error("Error: send() Failed.");
      printf("You Used %s!\n", translateMove(userMove));
      printf("Waiting for Oppoenent...\n\n");

      n = recv(client_socket, buffer, 255, 0);
      if (n < 0) exit_with_error("Error: recv() Failed."); 
      printf("Opponent Move Received\n\n");
    }

  int enemyMove = atoi(buffer);
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

  // close the sockets
  close(server_socket);
  close(client_socket);
  return 0;
}
