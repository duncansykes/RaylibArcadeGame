//
// Created by s200490 on 25/01/2021.
//
#include "raylib.h"
#include "scene.h"
#ifndef DEFAULT_APP_H
#define DEFAULT_APP_H


class app {
public:

    app(int window_width, int window_height, float fps, char* title);
    ~app();

    void run();
    bool running = false;
    float SCORE = 0;
private:
    Vector2 mousePos;

protected:
    void m_update(float deltaTime);
    void m_draw();

    int m_windowH = 0;
    int m_windowW = 0;

    float m_fps = 0;

    char* m_windowTitle;

    scene* mainScene;


};


#endif //DEFAULT_APP_H
