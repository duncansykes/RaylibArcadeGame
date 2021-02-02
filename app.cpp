//
// Created by s200490 on 25/01/2021.
//
#include "raylib.h"
#include "app.h"
#include "gameobject.h"
#include "scene.h"
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

void saveToFile( const char* path, char* name, float score){

    std::ofstream outFile;
    outFile.open(path, std::ios_base::app);
    outFile << name << " : " << score << "\n";
    outFile.close();

}


app::app(int window_width, int window_height, float fps, char* title) {

    m_windowH = window_height;
    m_windowW = window_width;

    m_fps = fps;
    m_windowTitle = title;

    running = true;
}

app::~app() {


}



void app::run() {

    InitWindow(m_windowW,m_windowH,m_windowTitle);
    SetTargetFPS(m_fps);

    mainScene = new scene();

    mainScene->Init();


  //  HideCursor();
    while(running){
        float deltaTime = GetFrameTime();
        m_update(deltaTime);

        if(mainScene->running) {
            mainScene->Update(deltaTime);
        }
        else{

            if(CheckCollisionPointRec(GetMousePosition(), textBox)) mouseHover = true;
            else mouseHover = false;

            if (mouseHover) {
                SetMouseCursor(MOUSE_CURSOR_IBEAM);
                int key = GetCharPressed();
                while (key > 0){
                    // only allow for keys between [32..125]
                    if((key >= 32) && (key <= 125) && (m_letterCount < MAX_INPUT_CHARS)){
                        name[m_letterCount] = (char)key;
                        m_letterCount++;
                    }
                    key = GetCharPressed();
                }
                if(IsKeyPressed(KEY_BACKSPACE)){
                    m_letterCount--;
                    if(m_letterCount < 0) m_letterCount = 0;
                    name[m_letterCount] = '\0';
                }
            }
            else if(GetMouseCursor() != MOUSE_CURSOR_DEFAULT) SetMouseCursor(MOUSE_CURSOR_DEFAULT);
            if(mouseHover) counter++;
            else counter = 0;

        }
        m_draw();
    }


}

void app::m_draw() {

    BeginDrawing();
    ClearBackground(BLACK);
    // Code to draw here

    if(mainScene->running) {
        mainScene->Draw();
        std::ostringstream mPosX;
        mPosX << (int)mainScene->score;
        std::ostringstream mPosY;
        mPosY << (int)mainScene->player->getHealth();

        std::string posTitle = "Player Score: ";
        std::string stringX(mPosX.str());
        std::string stringY(mPosY.str());
        std::string displayUpdateMousePosition = posTitle + stringX + ". Health: " + stringY;
        DrawText(displayUpdateMousePosition.c_str(), 0, 10, 19, WHITE);
    }
    else{
        DrawText("Enter Name", ((int)m_windowW /2) - 50, (int)m_windowH/2, 19, RED);
        DrawRectangleRec(textBox, LIGHTGRAY);
        if(mouseHover) DrawRectangleLines(textBox.x, textBox.y, textBox.width, textBox.height, RED);
        else DrawRectangleLines(textBox.x, textBox.y, textBox.width, textBox.height, DARKGRAY);

        DrawText(name, textBox.x + 5, textBox.y + 8, 40, MAROON);
        DrawText(TextFormat("INPUT CHARS: %i/%i", m_letterCount, MAX_INPUT_CHARS), 315, 250,20, BLACK);

        std::ostringstream finalscore;
        finalscore << (int)mainScene->score;
        std::string scoreFinalString(finalscore.str());
        std::string ass = "Final score: " + scoreFinalString;

        DrawText(ass.c_str(), 15, 20, 25, GREEN);

        if (mouseHover){
            if (m_letterCount < MAX_INPUT_CHARS){
                if (((counter/20)%2)==0) DrawText("_", textBox.x + 8 + MeasureText(name, 40), textBox.y + 12, 40, MAROON);
            }
            else{


                if(IsKeyPressed(KEY_ENTER)){
                    saveToFile("scores.txt", name, mainScene->score);
                    CloseWindow();
                }
                DrawText("Press enter to save", 0,380, 20, WHITE);
            }
        }
        if(WindowShouldClose())
        {
            CloseWindow();
        }




    }


    EndDrawing();

}

void app::m_update(float deltaTime) {
    mousePos = GetMousePosition();

}