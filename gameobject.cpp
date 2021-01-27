//
// Created by s200490 on 25/01/2021.
//

#include "gameobject.h"

gameobject::gameobject() {}

gameobject::~gameobject() {}

void gameobject::SetCollider() {




}

void gameobject::SetTextureFromImage() {

    Image image = LoadImage("player.png");
    m_texture = LoadTextureFromImage(image);
    m_collisionBox.height = (float)m_texture.height;
    m_collisionBox.width = (float)m_texture.width;
    m_textureLoaded = true;
}

void gameobject::SetObjectShape(char *shapeName) {
    if(shapeName == "circle") p_isCircle = true;
    if(shapeName == "box") p_isBox = true;
    if(shapeName == "rect") p_isRect = true;

}

void gameobject::SetColour(Color color) {
    objectColor = color;
}

void gameobject::Draw() {

    DrawTextureEx(m_texture, m_position, 0, 2.0f, WHITE);

    if(p_isRect){

    }

}


void gameobject::Update(float deltaTime){

    m_collisionBox.x = m_position.x - 16.5f;
    m_collisionBox.y = m_position.y - 16.5f;

    if(m_textureLoaded){
        m_collisionBox.x = m_position.x - (float)m_texture.width;
        m_collisionBox.y = m_position.y - (float)m_texture.height;
    }



}

Vector2 gameobject::GetPosition() {return m_position;}

void gameobject::SetPosition(Vector2 position) {m_position = position;}

Vector2 gameobject::GetVelocity() {return m_velocity;}

void gameobject::SetVelocity(Vector2 vel) {m_velocity = vel;}


bool gameobject::checkColliders(Rectangle other) {
    auto collision = CheckCollisionRecs(m_collisionBox, other);
    if (collision) m_boxcollision = GetCollisionRec(m_collisionBox, other);
    if (collision) return true;
    return false;
}

