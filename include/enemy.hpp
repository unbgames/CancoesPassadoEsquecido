#ifndef __GAME_ENEMY_OBJECT__
#define __GAME_ENEMY_OBJECT__

#include <string>
#include "gameobject.hpp"
#include "components/image.hpp"
#include "customimagecomponent.hpp"
#include "player.hpp"


using namespace engine;

class Enemy : public GameObject {
public:
    Enemy() : GameObject() {}
    Enemy(std::string _name, int _x, int _y, Player * target, int enemy_life)
        : GameObject(_name,_x,_y), m_target(target), life(enemy_life) {}
 	
 	~Enemy() {}
    virtual bool init();
    virtual bool shutdown();
    virtual bool update();
    virtual bool draw();
 	void setTilemap();
    void minimumPath(Vector2D pos);
    void discoverNextMove();
    void hold();
    void moveDown();
    void moveUp();
    void moveLeft();
    void moveRight();
    void makeNextMove();

    int life;
    bool canMove = true;
    int matrix[22][32];
    int matrixMinimumPath[22][32];
    int positionX, positionY;
    //0 Parado, 1 Esquerda, 2 Direita, 3 Cima, 4 Baixo
    int nextMove = 0;


private:
    Player* m_target;
    int defaultVel = 3;
    int distance;
};

#endif
