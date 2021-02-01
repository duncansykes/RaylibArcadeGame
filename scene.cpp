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
}

void scene::SpawnSpikes(int type) {

    if(type == 1) {
        spike *spikeVariationOne = new spike();
        spikeVariationOne->SetPosition({40, 0});
        spikeVariationOne->SetObjectShape("box", 20, 20);
        createSpikes(spikeVariationOne);

        renderedSpikes.push_back(spikes[0]);
        spikes.pop_back();
    }

    if (type == 2) {
        spike *spikeVariationOne = new spike();
        spikeVariationOne->SetPosition({180, 0});
        spikeVariationOne->SetObjectShape("box", 20, 20);
        createSpikes(spikeVariationOne);

        renderedSpikes.push_back(spikes[0]);
        spikes.pop_back();
    }


}

void scene::GravityUpdate(){
    player->SetPosition({player->GetPosition().x, player->GetPosition().y + gravity});

}

void scene::Update(float deltaTime) {

    float Xpos = 0;
    float Ypos = 0;
    float aTime = GetFrameTime();

    spawnTimer += aTime * 1;

    if(spawnTimer >= 0.3) {
        int randomSelection = rand() % 2 + 1;
        std::cout << randomSelection << std::endl;
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
                }
            }
            if(barrier->name == "Left Wall") {
                if (IsKeyPressed(KEY_SPACE)) {
                    Xpos = 140;
             }
            }
            break;
        }
        if(!barrier->checkColliders(player->GetCollider())){}
    }


    if(!renderedSpikes.empty()){
        for(auto spike : renderedSpikes){
            spike->Update(deltaTime);
            spike->SetPosition({spike->GetPosition().x, spike->GetPosition().y + 5});
            if(spike->checkColliders(player->GetCollider())){
                player->SetColour(GREEN);
               // player->isActive = false;
                spike->isActive = false;
                renderedSpikes.pop_back();

                break;
            }
            if(spike->GetPosition().y >= 500){
                //std::cout << spike->GetPosition().y << std::endl;
              //  spike->SetPosition({spike->GetPosition().x, 0});
            }
        }
    }

    if(IsMouseButtonDown(3)) player->SetColour(BLUE);
    if(IsMouseButtonDown(1)) player->SetColour(RED);

    player->SetPosition({(Xpos + player->GetPosition().x),(Ypos+ player->GetPosition().y)});
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