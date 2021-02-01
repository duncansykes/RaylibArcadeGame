//
// Created by s200490 on 25/01/2021.
//
#include "raylib.h"
#include <vector>
#include <random>
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
    void SpawnSpikes(int type);
    gameobject* player;
    gameobject* obstacle;


    gameobject* createSpikes(gameobject* Data){
        auto* spike = new gameobject();
        spike->SetPosition(Data->GetPosition());
        spike->SetObjectShape(Data->name, Data->GetObjectShape());
        spike->SetColour(RED);
        spikes.push_back(spike);
        return spike;


    }

    float spawnTimer = 0;
    std::vector<gameobject*> obstacles;
    std::vector<gameobject*> floor;

    std::vector<gameobject*> spikes;
    std::vector<gameobject*> renderedSpikes;
    std::vector<gameobject*> enemy;

    void GravityUpdate();

    float gravity = -5.0f;
    float defaultGravity = 5.0f;

    bool gravityFlipped = false;
};


#endif //DEFAULT_SCENE_H
