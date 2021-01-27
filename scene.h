//
// Created by s200490 on 25/01/2021.
//
#include "raylib.h"
#include <vector>
#include "gameobject.h"
#ifndef DEFAULT_SCENE_H
#define DEFAULT_SCENE_H


class scene {
public:

    scene();
    ~scene();
    void Init();
    void Update(float deltaTime);
    void Draw();

    gameobject* player;
    gameobject* obstacle;

    std::vector<gameobject*> obstacles;
    std::vector<gameobject*> floor;

    float gravity = 5.0f;
    float defaultGravity = 5.0f;

    bool gravityFlipped = false;
};


#endif //DEFAULT_SCENE_H
