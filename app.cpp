//
// Created by s200490 on 25/01/2021.
//
#include "raylib.h"
#include "app.h"
#include "gameobject.h"
#include "scene.h"
#include <iostream>

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


    while(!WindowShouldClose()){
        float deltaTime = GetFrameTime();
        m_update(deltaTime);
        mainScene->Update(deltaTime);

        m_draw();
    }


}

void app::m_draw() {

    BeginDrawing();
    ClearBackground(BLACK);
    // Code to draw here

    DrawText("YOU",100,100, 50, RED);
    mainScene->Draw();

    EndDrawing();

}

void app::m_update(float deltaTime) {


}