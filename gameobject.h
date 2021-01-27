//
// Created by s200490 on 25/01/2021.
//
#include "raylib.h"
#include "raymath.h"
#ifndef DEFAULT_GAMEOBJECT_H
#define DEFAULT_GAMEOBJECT_H


class gameobject {
public:

    gameobject();
    virtual ~gameobject();


    void Update(float deltaTime);

    void Draw();

    void SetVelocity(Vector2 vel);
    Vector2 GetVelocity();

    void SetPosition(Vector2 position);
    Vector2 GetPosition();

    bool checkColliders(Rectangle other);

    void SetTextureFromImage();
    void SetObjectShape(char* shapeName, float width, float height);
    void SetColour(Color color);
    Rectangle GetCollider(){return m_collisionBox;}

    bool isActive = true;

private:

    bool p_isCircle;
    bool p_isBox;
    bool p_isRect;

    bool showDebugColliders = false;

    Color objectColor = WHITE;
    Vector2 shapeSize = {0,0};

protected:

    Vector2 m_position = {0,0};
    Vector2 m_velocity = {0,0};

    Rectangle m_collisionBox = {0,0,0,0};

    Rectangle m_boxcollision = {0};

    Texture2D m_texture;
    Vector3 m_textureTransform = {0,0,0};




    bool m_textureLoaded = false;
};


#endif //DEFAULT_GAMEOBJECT_H
