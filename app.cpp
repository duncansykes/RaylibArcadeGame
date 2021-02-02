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

    HideCursor();
    while(running){
        float deltaTime = GetFrameTime();
        m_update(deltaTime);
        if(mainScene->running) {
            mainScene->Update(deltaTime);
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
        SCORE = mainScene->score;
        DrawText("Game Over", ((int)m_windowW /2) - 43, (int)m_windowH/2, 19, RED);
        DrawText("Refer to console.....",((int)m_windowW /2) - 80, (int)m_windowH/2 + 50, 19, WHITE);
        running = false;


    }


    EndDrawing();

}

void app::m_update(float deltaTime) {
    mousePos = GetMousePosition();

}