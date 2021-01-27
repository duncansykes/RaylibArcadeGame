//
// Created by s200490 on 25/01/2021.
//

#include "scene.h"
scene::scene() {}
scene::~scene() {}


void scene::Init(){

    float greenboxX = 200;


    player = new gameobject();
    player->SetPosition({30,320});
    player->SetObjectShape("box", 20,20);
    player->SetColour(RED);

    // Grey platform
    gameobject* a1 = new gameobject();
    a1->SetPosition({0,400});
    a1->SetObjectShape("rect",200,50);
    a1->SetColour(GRAY);
    obstacles.push_back(a1);

    // Green Box
    gameobject* a2 = new gameobject();
    a2->SetPosition({greenboxX, 200});
    a2->SetObjectShape("rect", 60, 60);
    a2->SetColour(GREEN);
    obstacles.push_back(a2);

    gameobject* a24 = new gameobject();
    a24->SetPosition({greenboxX, 300});
    a24->SetObjectShape("rect", 60, 60);
    a24->SetColour(GREEN);
    obstacles.push_back(a24);

    


}




void scene::Update(float deltaTime) {
    float Xpos = 0;
    float Ypos = 0;

    player->Update(deltaTime);



    if(player->GetPosition().y >= 500){
        player->SetPosition({1,310});
    }


    for (auto barrier : obstacles){
        barrier->Update(deltaTime);
        if(barrier->checkColliders(player->GetCollider())){
            if (IsKeyDown(KEY_W)) Ypos = -5;
            gravity = 0;
            break;
        }
        if(!barrier->checkColliders(player->GetCollider())){
            if(gravityFlipped){
                gravity = -defaultGravity;
            }
            else{
                gravity = defaultGravity;
            }
            if (IsKeyDown(KEY_S)) Ypos =5;
        }
    }

    if(IsKeyPressed(KEY_SPACE)){
        if(gravityFlipped == true){
            gravityFlipped = false;
            return;
        }
        if (gravityFlipped == false){
            gravityFlipped = true;
            return;
        }
    }
    if (IsKeyDown(KEY_D)) Xpos =5;
    if (IsKeyDown(KEY_A)) Xpos = -5;


    player->SetPosition({player->GetPosition().x, player->GetPosition().y + gravity});
    player->SetPosition({(Xpos + player->GetPosition().x),(Ypos+ player->GetPosition().y)});
}

void scene::Draw(){

    for(auto obs : obstacles){
        obs->Draw();
    }

    player->Draw();

}