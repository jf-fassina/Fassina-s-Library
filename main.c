#include "main.h"

//CONST DECLARATIONS
const char _winName[] = "Fassina's Library";
const int _winWidth = 1600;
const int _winHeight = 1200;


//'OBJECTS' DECLARATIONS --------------------------
struct Platforms{
  char name[50];
 
  struct Games{
      char nome[50];
      char dirName[50];
  } *games;
};
struct Platforms plataform[4];


static Rectangle btnSelector[4] = {
    { 30,  65, 155, 50 },
    { 30, 145, 155, 50 },
    { 30, 225, 155, 50 },
    { 30, 305, 155, 50 }
};


//FUNCTION DECLARATIONS --------------------------
void screenLayout(void);
void showGames(void);
void getGames(const char path[]);

//LOGIC ------------------------------------- 
int main(void) { 
  InitWindow(_winWidth, _winHeight, _winName); 
  SetTargetFPS(30); 
  while(!WindowShouldClose()){ BeginDrawing();
    screenLayout();
    showGames();
    //getGames(STEAM_PATH);
    EndDrawing();
  }
  CloseWindow();

}

//FRONT END -----------------------------------------------
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
      if(CheckCollisionPointRec(mouse, btnSelector[i])){

        switch(i){
          case 0: // Steam
            /*TODO:
             * Get in the STEAM_PATH, search for the .exe file in the folder, get the icon and name of the file
             * 
             * Maybe make the design like pages/cards that show ALL executables from the folder?
             */ 
             getGames(STEAM_PATH);

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


//BACK END ---------------------------------------

void getGames(const char path[]){

    struct dirent *de;
    DIR *dr = opendir(path);

    if (dr == NULL){
      DrawRectangle(300, 100, (_winWidth-350) , 100, LIGHTGRAY);
      DrawText("Não foi possível abrir o diretório atual", 320, 120, 60, GRAY);
      return;
    }

    while ((de = readdir(dr)) != NULL){
      printf("%s\n", de->d_name);
      DrawRectangle(300, 300, 300, 50, LIGHTGRAY);
    }
    closedir(dr);

}



