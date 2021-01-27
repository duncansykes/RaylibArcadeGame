//
// Created by s200490 on 25/01/2021.
//

#include "scene.h"
scene::scene() {}
scene::~scene() {}


void scene::Init(){

    player = new gameobject();
    player->SetPosition({200,200});
    player->SetObjectShape("box");
    player->SetColour(RED);


    obstacle = new gameobject();
    obstacle->SetPosition({300,100});
    obstacle->SetObjectShape("rect");
    obstacle->SetColour(WHITE);
    obstacles.push_back(obstacle);

    gameobject* newfloor = new gameobject();
    newfloor->SetPosition({10,900});

    floor.push_back(newfloor);


}




void scene::Update(float deltaTime) {

    player->Update(deltaTime);

    for (auto barrier : obstacles){
        barrier->Update(deltaTime);
    }
    for (auto ground : floor){
        ground->Update(deltaTime);
    }

    float Xpos = 0;
    float Ypos = 0;


    if (IsKeyDown(KEY_D)){
        Xpos =5;
    }

    if (IsKeyDown(KEY_A)){
        Xpos = -5;
    }


    if (IsKeyDown(KEY_S)){
        Ypos =5;
    }
    if (IsKeyDown(KEY_W)){
        Ypos = -5;
    }


    player->SetPosition({(Xpos + player->GetPosition().x),(Ypos+ player->GetPosition().y)});
}

void scene::Draw(){

    player->Draw();

}