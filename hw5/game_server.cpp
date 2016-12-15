/*
For now just going to brainstorm in this file

skeleton code:

main method(){
  app = create_gtk_app()
  create_server()

  2)
    - go into loop and wait for the client to connect
    - initialize the return parameters for the Accecpt call
    - Make Accecpt call and wait for a client to connect
    
  3) 
    - once client connects, use peersocket() to complete the connection between server and client

  4) - send write command to the client with the initial json file to client
  
  5) recieve a gameInstance json packet from the client
    - call, createWindow() to create the initial game window.
    
  6) call g_application_run and wait for user input
  
  7) unref the application and close
}

Select_candy_signal(){
  send a json object to the gameclient with a json object containing
  instructions on how to select an object. 
}

Swap_candy_signal(){
  send json object instructing model telling it which direction to swap the direction in.
}

Send_SaveGame_signal(){
  - signal to model to send a serialized version of the game instance over
  - save the game instance out to a file
}

send_gameInstance_to_client(){
  - create character buffer 
  - while( writebuff returns a non-zero value ){
      write the json file to the game-client
    }

}

create_gtk_app(){
  1) initialize GTK object

  2) connect the open function to the app

  3) connect the activate function to the app

  4) return app object
}

create_server(port#){
  1) convert the port# argument from a string into an int

  2) create a server socket using the Serversocket.cc provided code
  
  3) (possibly call bind and listen ???)

  4) return a thing?
}

write_to_Client(output){
  go through output message loop and send output to client
}

create_game_window(app){
  //all the stuff in the game_window.c class
}

*/