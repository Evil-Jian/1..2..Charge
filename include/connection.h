# ifndef MY_HEADER_FILE_H
# define MY_HEADER_FILE_H
#include "charge.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>
void init_server_connection(struct sockaddr_in*, int*, int*, const int, const char*, const int);
void init_client_connection(struct sockaddr_in*, int*, int, char *, char*, int);
void exit_with_error(char*);
void init_server(struct sockaddr_in*, const int);
void connect_client_to_server(struct hostent*, struct sockaddr_in*, int, int*);
int listen_and_accept_connections(int, int);
// void send_t(int, Sungka*);
// void recv_t(int, Sungka*);
# endif