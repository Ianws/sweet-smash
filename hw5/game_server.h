/*
Network client for playing Candy Crush Clone
*/

#ifndef _GAME_NETWORK_SERVER_H_
#define _GAME_NETWORK_SERVER_H_

#include "socketCode\ServerSocket.h"

using hw5_net::ServerSocket;

  class GameNetworkServer {
    // --- Constructors ---
  public:
    // 
  private:
    void usage(const char* exeName);
    void SelectCandySignal(int idx);
    void SwapCandySignal(char dir);
    void SendSaveGameSignal();
    void SendGameinstanceSignal();
    void CreateGtkApp();
    void CreateGameWindow();
    void CreateServer(const int& portNumber, ServerSocket* s_socket);
    void WriteToClient();
  };


#endif // !_GAME_NETWORK_SERVER_H_
