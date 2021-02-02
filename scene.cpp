//
// Created by s200490 on 25/01/2021.
//
#include <string>
#include "scene.h"
#include <random>
#include <iostream>
#include <time.h>
scene::scene() {}
scene::~scene() {}


void scene::Init(){
    player = new gameobject();
    player->SetPosition({45,290});
    player->SetObjectShape("box", 20,20);
    player->SetColour(GREEN);


    auto* wall_one = new gameobject();
    wall_one->name = "Left Wall";
    wall_one->SetColour(GRAY);
    wall_one->SetPosition({0, 0});
    wall_one->SetObjectShape("rect", 50, 500);
    obstacles.push_back(wall_one);

    auto* wall_two = new gameobject();
    wall_two->name = "Right Wall";
    wall_two->SetColour(GRAY);
    wall_two->SetPosition({200,0});
    wall_two->SetObjectShape("rect", 50, 500);
    obstacles.push_back(wall_two);

    srand(time(NULL));
    system("cls");
}







void scene::SpawnSpikes(int type) {

    if(type == 1) {
        spike *spikeVariationOne = new spike();
        spikeVariationOne->SetPosition({40, 0});
        spikeVariationOne->SetObjectShape("box", 20, 20);
        spikeVariationOne->SetColour(RED);
        createSpikes(spikeVariationOne);

        renderedSpikes.push_back(spikes[0]);
        spikes.pop_back();
    }

    if (type == 2) {
        spike *spikeVariationOne = new spike();
        spikeVariationOne->SetColour(RED);
        spikeVariationOne->SetPosition({185, 0});
        spikeVariationOne->SetObjectShape("box", 15, 20);
        createSpikes(spikeVariationOne);

        renderedSpikes.push_back(spikes[0]);
        spikes.pop_back();
    }

    if(type == 3)
    {
        gameobject* alien = new gameobject();
        alien->SetPosition({100, 0});
        alien->SetObjectShape("rect",{15,15});
        alien->SetColour(WHITE);
        createSpikes(alien);
        renderedSpikes.push_back(spikes[0]);
        spikes.pop_back();
    }

}

void scene::GravityUpdate(){
    player->SetPosition({player->GetPosition().x, player->GetPosition().y + gravity});

}

void scene::Update(float deltaTime) {

   // std::cout << speedTimer << std::endl;

    float Xpos = 0;
    float Ypos = 0;
    float aTime = GetFrameTime();

    spawnTimer += aTime * 1;
    speedTimer += aTime * 0.05f;

    if(IsKeyDown(KEY_E) && IsKeyDown(KEY_P)) speedTimer = 0;

    if(spawnTimer >= 0.26) {
        int randomSelection = rand() % 3 + 1;

        SpawnSpikes(randomSelection);
        spawnTimer = 0;
    }

    player->Update(deltaTime);

    for (auto barrier : obstacles){
        barrier->Update(deltaTime);
        if(barrier->checkColliders(player->GetCollider())){
            // If touching walls
            if(barrier->name == "Right Wall"){
                if (IsKeyPressed(KEY_SPACE)) {
                    Xpos = -140;
                    score += 1 + speedTimer;
                }
            }
            if(barrier->name == "Left Wall") {
                if (IsKeyPressed(KEY_SPACE)) {
                    Xpos = 140;
                    score += 1 + speedTimer;
             }
            }
            break;
        }
        if(!barrier->checkColliders(player->GetCollider())){}
    }

    if(WindowShouldClose())
    {
        CloseWindow();
    }

    if(!renderedSpikes.empty()){
        for(auto spike : renderedSpikes){
            spike->Update(deltaTime);
            spike->SetPosition({spike->GetPosition().x, spike->GetPosition().y + 5 + speedTimer});
            if(spike->checkColliders(player->GetCollider())){
                player->SetColour(GREEN);
                spike->isActive = false;
                player->TakeDamage(1);
                break;
            }

        }
    }

    if(IsMouseButtonDown(3)) player->SetColour(BLUE);
    if(IsMouseButtonDown(1)) player->SetColour(RED);


    player->SetPosition({(Xpos + player->GetPosition().x),(Ypos+ player->GetPosition().y)});

    if(player->getHealth() <= 0)
    {
        running = false;
    }


}

void scene::Draw(){

    for(auto obs : obstacles){
        obs->Draw();
    }
    if(!renderedSpikes.empty()) {
        for(auto sp : renderedSpikes){
            sp->Draw();
        }
    }

    player->Draw();

}