//
// Created by s200490 on 25/01/2021.
//

#include "scene.h"
scene::scene() {}
scene::~scene() {}


void scene::Init(){

    player = new gameobject();
    player->SetPosition({30,320});
    player->SetObjectShape("box", 20,20);
    player->SetColour(RED);


    gameobject* a1 = new gameobject();
    a1->SetPosition({0,400});
    a1->SetObjectShape("rect",200,50);
    a1->SetColour(GRAY);
    obstacles.push_back(a1);

    gameobject* a2 = new gameobject();
    a2->SetPosition({300, 300});
    a2->SetObjectShape("rect", 150, 150);
    a2->SetColour(GREEN);
    obstacles.push_back(a2);

}




void scene::Update(float deltaTime) {
    float Xpos = 0;
    float Ypos = 0;

    player->Update(deltaTime);

    player->SetPosition({player->GetPosition().x, player->GetPosition().y + gravity});


    for (auto barrier : obstacles){
        barrier->Update(deltaTime);
        if(barrier->checkColliders(player->GetCollider())){
            gravity = 0;
            break;
        }
        if(!barrier->checkColliders(player->GetCollider())){
            gravity = 2;
            if (IsKeyDown(KEY_S)) Ypos =5;
        }

    }



    if(IsKeyPressed(KEY_SPACE)) Ypos = -50;
    if (IsKeyDown(KEY_D)) Xpos =5;
    if (IsKeyDown(KEY_A)) Xpos = -5;

    if (IsKeyDown(KEY_W)) Ypos = -5;

    player->SetPosition({(Xpos + player->GetPosition().x),(Ypos+ player->GetPosition().y)});
}

void scene::Draw(){

    for(auto obs : obstacles){
        obs->Draw();
    }

    player->Draw();

}