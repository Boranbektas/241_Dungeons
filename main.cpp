#include <iostream>
#include <stdlib.h>
#include <string>
#include "Map.h"
#include "Map.cpp"
// gençler test yapmak için buraları sildim bi daha eklerirz sonra
using namespace std;

// function to move cursor to top
void gotoxy(int x, int y) { 
    COORD pos = {x, y};
    HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(output, pos);
}
// function to move cursor to top

int main(){

      // variables for main
      string name;
      int answer;
      char event = '.';
      int game_is_on = 1;
      // variables for main

      cout << "The voice: Welcome stranger, what is your name ? "<< endl;
      cin >> name;
      cout << endl;
      cout << "Well met " << name << ". Here is the deal " << name << ", you were camping with your girlfriend in the forest but somehow you end up here and your girlfirend is missing" << endl;
      cout << "'ask a question' "<< endl;
      cout << endl;
      do{
            cout << "1. Wait a minute, who are you ? "<< endl;
            cout << "2. Where is my girlfriend ? Tell me NOW !!!! " << endl;
            cout << "3. Explore the dungeon !!"<<endl;
            cin >> answer;
            cout << endl;
            if(answer == 1){
                  cout << "The voice: It really doesn't matter who i am. I am just here to help you this is a wired place to be in you need a guide"<<endl;
            }
            else if(answer == 2){
                  cout << "The voice: Thats a good question my friend but i think the answer is deep down in the dungeon"<<endl;
            }
      }while(answer != 3);

      system("cls");

      Map game_map;
      while(game_is_on){
            gotoxy(0,0);
            game_map.printMap();
            Sleep(100);
            
            if (_kbhit()){
                  switch (getch()){  
                  case 'w':
                        event = game_map.movePlayer_up();
                        break;
                  case 's':
                        event = game_map.movePlayer_down();
                        break;
                  case 'a':
                        event = game_map.movePlayer_left();
                        break;
                  case 'd':
                        event = game_map.movePlayer_right();
                        break;
                  default:
                        
                        break;
                        
                  }
            }
            if(event == 'M'){
                  system("cls");
                  cout << "monster event !!!";
                  Sleep(1000);
                  
            }
            else if(event == 'I'){
                  system("cls");
                  cout << "item event!!!";
            }
            // reseting the event variable
            event = '.';
      }
      return 0;
}

