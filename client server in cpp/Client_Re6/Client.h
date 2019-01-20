//
// Created by steve on 12/6/17.
//

#ifndef CLIENT_CLIENT_H
#define CLIENT_CLIENT_H

class Client {
 public:
  Client(const char *serverIP, int serverPort);
  void connectToServer();
  int sendExercise(int arg1, char op, int arg2);
 private:
  const char *serverIP;
  int serverPort;
  int clientSocket;
};

#endif //CLIENT_CLIENT_H
