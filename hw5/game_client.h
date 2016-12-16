/*
Network client for playing Candy Crush Clone
*/

#ifndef _GAME_NETWORK_CLIENT_H_
#define _GAME_NETWORK_CLIENT_H_

#include "socketCode\CSE333.h"
#include "socketCode\ClientSocket.h"
#include "socketCode\CSE333Socket.h"
#include "socketCode\ServerSocket.h"
#include "game_server.h"
#include "../hw4/game_model.h"
#include "../jansson/include/jansson.h"
#include <iostream>


  class GameNetworkClient {
  public:
    // --- Constructors ---

    // 
  private:
    void usage(const char* exeName);
    void InitializeGameInstance();
    void SerializeGameInstance();
    void SelectCandy();
    void SwapCandy();
    void SaveGame();
    void WriteToServer(json_t data);
  };


#endif // !_GAME_NETWORK_CLIENT_H_
