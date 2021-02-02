//
// Created by s200490 on 25/01/2021.
//

#include "gameobject.h"

gameobject::gameobject() {}

gameobject::~gameobject() {}

void gameobject::SetTextureFromImage() {

    Image image = LoadImage("player.png");
    m_texture = LoadTextureFromImage(image);
    m_collisionBox.height = (float)m_texture.height;
    m_collisionBox.width = (float)m_texture.width;
    m_textureLoaded = true;
}

void gameobject::SetObjectShape(char *shapeName, float width, float height) {
    if(shapeName == "circle") {
        p_isCircle = true;
    }
    if(shapeName == "box") {
        p_isBox = true;
    }
    if(shapeName == "rect") {
        p_isRect = true;
    }
    shapename = shapeName;
    shapeSize = {width, height};
    m_collisionBox.height = height;
    m_collisionBox.width =width;

}

void gameobject::SetObjectShape(std::string name, Vector2 size) {
    if(name == "circle") {
        p_isCircle = true;
    }
    if(name == "box") {
        p_isBox = true;
    }
    if(name == "rect") {
        p_isRect = true;
    }

    shapename = name;
    shapeSize = size;
    m_collisionBox.height = size.y;
    m_collisionBox.width = size.x;

}

void gameobject::SetColour(Color color) {
    objectColor = color;
}

void gameobject::Draw() {
    if(isActive) {
        if (p_isRect) {
            DrawRectangle((int) m_position.x, (int) m_position.y, (int) shapeSize.x, (int) shapeSize.y, objectColor);
        }
        if (p_isBox) {
            DrawRectangleLines((int) m_position.x, (int) m_position.y, (int) shapeSize.x, (int) shapeSize.y,
                               objectColor);
        }

        if (showDebugColliders) {
            DrawRectangleLinesEx(m_collisionBox, 2, WHITE);
        }
    }

}
Vector2 gameobject::GetObjectShape() {

    return shapeSize;
}

void gameobject::Update(float deltaTime){

    m_collisionBox.x = m_position.x;
    m_collisionBox.y = m_position.y;

    if(IsKeyPressed(KEY_TAB)) {
        if (!showDebugColliders) {
            showDebugColliders = true;
            return;
        }
        if(showDebugColliders){
            showDebugColliders = false;
            return;
        }
    }


}

Vector2 gameobject::GetPosition() {return m_position;}

void gameobject::SetPosition(Vector2 position) {m_position = position;}

Vector2 gameobject::GetVelocity() {return m_velocity;}

void gameobject::SetVelocity(Vector2 vel) {m_velocity = vel;}


bool gameobject::checkColliders(Rectangle other) {
    auto collision = CheckCollisionRecs(m_collisionBox, other);
    if (collision) m_boxcollision = GetCollisionRec(m_collisionBox, other);
    if (collision) {
        return true;
    }
    return false;
}

spike::spike() {

}

spike::~spike() noexcept {}
