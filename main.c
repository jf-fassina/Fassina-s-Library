#include "main.h"

const char _winName[] = "Fassina's Library";
const int _winWidth = 1600;
const int _winHeight = 1200;


static Rectangle btnSelector[4] = {
    { 30,  65, 155, 50 },
    { 30, 145, 155, 50 },
    { 30, 225, 155, 50 },
    { 30, 305, 155, 50 }
};



void screenLayout(void);
void showGames(void);


int main(void) {
  InitWindow(_winWidth, _winHeight, _winName);
  SetTargetFPS(30);
  
  while(!WindowShouldClose()){
    BeginDrawing();
    screenLayout();
    clicked();
    EndDrawing();
  }
  CloseWindow();

}


void screenLayout(void){
  
  ClearBackground(RAYWHITE);
  

  //Up Menu
  DrawRectangle(0, 0, _winWidth, 50, LIGHTGRAY);
  DrawText("Bem-Vindo a Fassina's Library!", 675, 12, 30, GRAY);

  
  //Side Menu
  DrawRectangle(0, 0, 250, _winHeight, LIGHTGRAY);

  DrawRectangleRec(btnSelector[0], RAYWHITE);
  DrawText("Steam", 40, 80, 25, GRAY);

  DrawRectangleRec(btnSelector[1], RAYWHITE);
  DrawText("Epic Games", 40, 160, 25, GRAY);
 
  DrawRectangleRec(btnSelector[2], RAYWHITE);
  DrawText("Xbox", 40, 240, 25, GRAY);
  
  DrawRectangleRec(btnSelector[3], RAYWHITE);
  DrawText("Other", 40, 320, 25, GRAY);
}


void showGames(void){

  Vector2 mouse = GetMousePosition();
  
  if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON)){

    for(int i = 0; i < 4; i++){
      if(CheckCollisionPointRec(mouse, btnSelector[index])){

        switch(i){
          case 0: // Steam
            //TODO: Show games in the Steam directory 
            break;
          case 1: // Epic Games
            // Handle Epic Games
            break;
          case 2: // Xbox
            // Handle Xbox
            break;
          case 3: // Other
            // Handle Other
            break;

          default:
            //Show list with all games

        }

      }
    }
  }
}



    


