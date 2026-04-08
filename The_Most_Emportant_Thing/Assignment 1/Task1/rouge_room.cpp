//
//  rouge_room.cpp
//  Advanced Software Assignment
//
//  Created by Harry Powell-Evans on 27/01/2026.
//


//iostream enables cin and cout for input and output operations
//string allows us to use the string class for handling text
//thread and chrono are used for adding a delay between each frame of the game, creating a moother user experience
#include <iostream>
#include <string> 
#include <thread>
#include <chrono>

//namespace std allows us to use standard library features without prefixing them with std::
using namespace std;

//the room class contains all the properties and methods related to the room, including its dimensions, the player's position, and the characters used for drawing the room
class Room{
//private memebers can only be accessed within the Room Class 
private:
    int width;  //room width 
    int height; //room height
    int x;  //player's x position
    int y;  //player's y position
    char floor_marker;  //character for the floor
    char player_marker; //character for the player
    char wall_s_marker; //character for the vertical walls
    char wall_t_marker; //character for the horizontal walls
    char corner_marker; //character for the corners


//public constructor is set up setting required paramiters and optional parameters with default values, as well as methods for drawing the room and handling player movement
    public:
    Room(int w, int h, char floor = '.', char player = '@', char wall_s = '|', char wall_t = '-', char corner = '+'){
        width = w;
        height = h;
        x=0;    //player starts at the left edge
        y=0;    //player starts at the top edge
        floor_marker = floor;
        player_marker = player;
        wall_s_marker = wall_s;
        wall_t_marker = wall_t;
        corner_marker = corner;
    }
    
    //Setters
    void set_player_marker(char marker){
        player_marker = marker;     //updates the character used to represent the player
    }
    void set_wall_marker(char marker_s, char marker_t){
        wall_s_marker = marker_s;   //updates the character used for vertical walls
        wall_t_marker = marker_t;   //updates the character used for horizontal walls
    }
    void set_floor_marker(char marker){
        floor_marker = marker;      //updates the character used to represent the floor
    }
    void set_corner_marker(char marker){
        corner_marker = marker;     //updates the character used for room corners
    }

    //Draw Method 
    void draw(){
        //Draw the top wall
        cout << corner_marker << string(width, wall_t_marker) << corner_marker << endl;

        //iterate over each row of the room
        for (int i=0; i < height; i++){
            if (i != y){
                //Draw a row of floor
                cout << wall_s_marker << string(width, floor_marker) << wall_s_marker << endl;
            }
            else{
                //Draw a row with the player, padding either side with floor characters based on the player's x position
                cout << wall_s_marker << string(x, floor_marker) << player_marker << string(width-x-1, floor_marker) << wall_s_marker << endl;
            }
        }

        //Draw the bottom wall
        cout << corner_marker << string(width, wall_t_marker) << corner_marker << endl;
    }

    //Movement
    void left(){
        if (x > 0){
            x--;    //move the player one step to the left
        }
        else{
            cout << "You can't move left!" << endl;     //player is at the left wall
        }
    }

    void right(){
        if (x < width - 1){
            x++;    //move the player one step to the right
        }
        else{
            cout << "You can't move right!" << endl;    //player is at the right wall
        }
    }

    void up(){
        if (y > 0){
            y--;    //move the player one step up
        }
        else{
            cout << "You can't move up!" << endl;       //player is at the top wall
        }
    }

    void down(){
        if (y < height - 1){
            y++;    //move the player one step down
        }
        else{
            cout << "You can't move down!" << endl;     //player is at the bottom wall
        }
    }
};

int main(){
    
    //Creat a room with dimensions 8X6
    Room room(8, 6);

    //game loop runs continuously until the player chooses to exit
    while (true){
        //draw the room 
        room.draw();

        //Get user input
        cout << "Enter command (w/a/s/d & x to exit): ";
        char input;
        cin >> input;   

        //Handle input
        if (input == 'w'){
            room.up();      //w moves the player up
        }
        else if (input == 'a'){
            room.left();    //a moves the player left
        }
        else if (input == 's'){
            room.down();    //s moves the player down
        }
        else if (input == 'd'){
            room.right();   //d moves the player right
        }
        else if (input == 'x'){
            cout << "Exiting game..." << endl;
            break;          //exit the game loop
        }
        else{
            cout << "Invalid command!" << endl;     //input did not match any known command
        }

        //sleep for 0.5 seconds to create a brief pause between frames
        this_thread::sleep_for(chrono::milliseconds(500));

        //clear the screen using an ANSI escape code to reset the cursor to the top before redrawing
        cout << "\033[2J\033[1;1H";
    }
    return 0;
}
