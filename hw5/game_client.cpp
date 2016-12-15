/*
BRAINSTORM

main{
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
}

Initialize_game_instance(){
  1) wait until signal is received from the server 

  2) when received use the received json file to initialize game instance
    - make call to game_model and create a game_model object
}

Serialize_game_instance(){
  **note** this method needs to be called at the end of every update method
  1) make call to model to output a serialized game instance
  
  2) write the json file to the server 
}

select_candy(){
  call model to select specified candy
}

swap_candy(){
  call model to swap selected candy in specified direction
}

save_game(){
  serialize game instance and send to server
}

Write_to_server(output){
  go through while loop that sends data to server to read
}
*/