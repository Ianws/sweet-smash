/*
BRAINSTORM
*/

#include "socketCode\CSE333.h"
#include "socketCode\ClientSocket.h"
#include "socketCode\CSE333Socket.h"
#include "socketCode\ServerSocket.h"
#include "game_client.h"
#include "game_server.h"
#include "../hw4/game_model.h"
#include <iostream>
#include "../jansson/include/jansson.h"

using namespace hw5_net;

// call when program was not initiated correctly
void usage(const char* exeName) {
  cout << "Usage: " << exeName << " host port" << endl;
  cout << "  Connect to host::port then send data and read replies" << endl;
  exit(1);
}

/*main{
  1) validate input
    - make sure that the number of arguments == 3

  2) get server DNS from arg[1]

  3) get port number form arg[2]
    try {
    - create a clientsocket object using methods from library
    - pass in DNS address and port number
    }

  4) once connection has been made: initialize game instance
     - serialize game instance after initialization has been finished and
       send json to server

  4) Enter listening loop waiting for input from server
    - when signal is received call HandleSignal() method
    - exit input loop when handleSignal returns some sort of quit flag

  5) once the server exist:
    - quits the client program and frees all the data structures allocated
}*/

int main(int argc, char* argv[]) {
  // 1) validate input
  // - make sure that the number of arguments == 3
  if (argc != 3) {
    usage(argv[0]);
  }

  // 2) get server name from arg[1]
  string serverName(argv[1]);

  // 3) get server port number from arg[2]
  int serverPort;
  try {
    serverPort = stoi(argv[2]);
  } catch (...) {
    usage(argv[0]);
  }

  //  3) get port number form arg[2]
  //  try {
  //  - create a clientsocket object using methods from library
  //    - pass in DNS address and port number
  //  }
  try {
    ClientSocket clientSocket(serverName, serverPort);

    // Possible check if the socket is connected, though for now we can just assume it is
    if (!clientSocket.isConnected()) {}

  } catch (string errinfo) {
    cerr << errinfo << endl;
    return EXIT_FAILURE;
  }

  InitializeGameInstance(ClientSocket c_socket);
  //4) once connection has been made: initialize game instance
  //- serialize game instance after initialization has been finished and
  //  send json to server

  //  4) Enter listening loop waiting for input from server
  //  - when signal is received call HandleSignal() method
  //  - exit input loop when handleSignal returns some sort of quit flag

  //  5) once the server exist:
  //  - quits the client program and frees all the data structures allocated
}

void InitializeGameInstance(){
  //1) wait until signal is received from the server

  //2) when received use the received json file to initialize game instance
  //  - make call to game_model and create a game_model object
}

void SerializeGameInstance(){
  //**note** this method needs to be called at the end of every update method
  //1) make call to model to output a serialized game instance

  //2) write the json file to the server
}

//call model to select specified candy
void SelectCandy() {

}

//call model to swap selected candy in specified direction
void SwapCandy() {

}

// serialize game instance and send to server
void SaveGame() {

}

// go through while loop that sends data to server to read
void WriteToServer(json_t data){
  
}
