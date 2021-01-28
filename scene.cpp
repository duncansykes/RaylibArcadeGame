//
// Created by s200490 on 25/01/2021.
//
#include <string>
#include "scene.h"
#include <iostream>
scene::scene() {}
scene::~scene() {}


void scene::Init(){
    player = new gameobject();
    player->SetPosition({45,290});
    player->SetObjectShape("box", 20,20);
    player->SetColour(RED);


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




    float amount = 4;
    float offset = 0.5f;
    spike* spikeVariationOne;
    for(int x = 0; x < amount; x++){
        spikeVariationOne = new spike();
        spikeVariationOne->name = "Spike One";
        spikeVariationOne->damageAmount = 10;
        spikeVariationOne->SetPosition({40, 0 + ((float)x * offset) });
        spikeVariationOne->SetObjectShape("box", 20, 20);
        spikeVariationOne->SetColour(PINK);
        std::cout << x << std::endl;
    }

    spikes.push_back((spikeVariationOne));


}


void scene::GravityUpdate(){
    player->SetPosition({player->GetPosition().x, player->GetPosition().y + gravity});

}

void scene::Update(float deltaTime) {
    float Xpos = 0;
    float Ypos = 0;

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

    for (auto spike : spikes){
        spike->Update(deltaTime);
        spike->SetPosition({spike->GetPosition().x, spike->GetPosition().y + 5});

        if(spike->checkColliders(player->GetCollider())){
            player->SetColour(GREEN);
            player->isActive = false;
            spike->isActive = false;
            CloseWindow();
            break;
        }
        if(spike->GetPosition().y >= 500){
            spike->SetPosition({spike->GetPosition().x, 0});
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
    for(auto sk : spikes){
        sk->Draw();
    }
    player->Draw();

}