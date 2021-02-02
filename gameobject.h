//
// Created by s200490 on 25/01/2021.
//
#include <string>
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
    void SetObjectShape(std::string name, Vector2 size);
    Vector2 GetObjectShape();
    Color getColor(){return objectColor;}

    void SetColour(Color color);
    Rectangle GetCollider(){return m_collisionBox;}

    void TakeDamage(float amount)
    {
        lives -= amount;
    }

    float getHealth()
    {
        return lives;
    }

    bool isActive = true;
    std::string name;

protected:

    Vector2 point1T = {};
    Vector2 point2T = {};
    Vector2 point3T = {};

    Vector2 m_position = {0,0};
    Vector2 m_velocity = {0,0};

    Rectangle m_collisionBox = {0,0,0,0};
    Rectangle m_boxcollision = {0};

    Texture2D m_texture;
    Vector3 m_textureTransform = {0,0,0};

    bool p_isCircle = false;
    bool p_isBox;
    bool p_isRect;
    bool p_isSpikes;
    std::string shapename;

    bool showDebugColliders = false;

    Color objectColor = WHITE;
    Vector2 shapeSize = {0,0};

    float lives = 50;
    bool m_textureLoaded = false;
};

class spike : public gameobject{
public:

    spike();
    ~spike();

    Color color;
    float damageAmount;


};


#endif //DEFAULT_GAMEOBJECT_H
