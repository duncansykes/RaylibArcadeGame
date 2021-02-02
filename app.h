//
// Created by s200490 on 25/01/2021.
//
#include "raylib.h"
#include "scene.h"
#ifndef DEFAULT_APP_H
#define DEFAULT_APP_H
#define MAX_INPUT_CHARS 4


class app {
public:

    app(int window_width, int window_height, float fps, char* title);
    ~app();
    int counter = 0;
    void run();
    bool running = false;
    float SCORE = 0;
private:
    Vector2 mousePos;
    Rectangle textBox = {(float)GetScreenWidth()/2 + 70 , 290, 120, 50};
    bool mouseHover = false;
    char name[MAX_INPUT_CHARS + 1] = "\0";

protected:
    void m_update(float deltaTime);
    void m_draw();
    int m_letterCount = 0;
    int m_windowH = 0;
    int m_windowW = 0;

    float m_fps = 0;

    char* m_windowTitle;

    scene* mainScene;


};


#endif //DEFAULT_APP_H
