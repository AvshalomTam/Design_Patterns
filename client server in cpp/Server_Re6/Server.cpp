//
// Created by steve on 12/5/17.
//

#include "Server.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <string.h>
#include <iostream>
#include <stdio.h>

using namespace std;
#define MAX_CONNEVTED_CLIENTS 10

Server::Server(int port): port(port), serverSocket(0) {
  cout << "Server" << endl;
}

void Server::start() {
  // create a socket point
  serverSocket = socket(AF_INET, SOCK_STREAM, 0);
  if (serverSocket == -1) {
    throw "Error opening socket";
  }
  // Assign a local address to the socket
  struct sockaddr_in serverAddress;
  bzero((void *)&serverAddress, sizeof(serverAddress));
  serverAddress.sin_family = AF_INET;
  serverAddress.sin_addr.s_addr = INADDR_ANY;
  serverAddress.sin_port = htons(port);
  if (bind(serverSocket, (struct sockaddr *)&serverAddress, sizeof(serverAddress)) == -1) {
    throw "Error on binding";
  }

  // Start listening to incoming connections
  listen(serverSocket, MAX_CONNEVTED_CLIENTS);

  // Define the client socket's structures
  struct sockaddr_in clientAddress;
  socklen_t clientAddressLen;

  while (true) {
    cout << "Waiting for client connections..." << endl;

    // Accept a new client connection
    int clientSocket = accept(serverSocket, (struct sockaddr *)&clientAddress, &clientAddressLen);

    cout << "Client connected" << endl;
    if (clientSocket == -1)
      throw "Error on accept";

    handleClient(clientSocket);

    // Close communication with the client
    close(clientSocket);
  }
}

// Handle requests from a specific client
void Server::handleClient(int clientSocket) {
  int arg1, arg2;
  char op;

  while (true) {
    // Read new exercice arguments
    int n = read(clientSocket, &arg1, sizeof(arg1));
    if (n == -1) {
      cout << "Error reading arg1" << endl;
      return;
    }
    if (n == 0) {
      cout << "Client disconnected" << endl;
      return;
    }
    n = read(clientSocket, &op, sizeof(op));
    if (n == -1) {
      cout << "Error reading operator" << endl;
      return;
    }
    n = read(clientSocket, &arg2, sizeof(arg2));
    if (n == -1) {
      cout << "Error reading arg2" << endl;
      return;
    }

    cout << "Got exercise: " << arg1 << op << arg2 << endl;
    int result = calc(arg1, op, arg2);

    // Write the result back to the client
    n = write(clientSocket, &result, sizeof(result));
    if (n == -1) {
      cout << "Error writing to socket" << endl;
      return;
    }
  }
}

int Server::calc(int arg1, const char op, int arg2) const {
  switch (op) {
    case '+':return arg1 + arg2;
    case '-':return arg1 - arg2;
    case '*':return arg1 * arg2;
    case '/':return arg1 / arg2;
    default:
      cout << "Invalid operator" << endl;
      return 0;
  }
}

void Server::stop() {
  close(serverSocket);
}