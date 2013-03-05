#ifndef WORLD_H
#define WORLD_H

#include <vector>
#include <string>

class Game;
class Entity;
class Tower;
class Minion;

using namespace std;

class World
{
private:

    vector<Entity *> redEntities;
    vector<Entity *> blueEntities;

    vector<Tower *> redTowers;
    vector<Tower *> blueTowers;

    vector<Minion *> redMinions;
    vector<Minion *> blueMinions;
/*
    vector<PlCh *> redPlChs;
    vector<PlCh *> bluePlChs;
*/
    vector<Entity *> allEntities;

    vector<Tower *> allTowers;
    vector<Minion *> allMinions;
 /*   vector<PlCh *> allPlChs;

    vector<bool> redAlive;
    bool redVulnerable;

    vector<bool> blueAlive;
    bool blueVulnerable;

    vector<User *> redUsers;
    vector<User *> blueUsers;

    vector<towerShot *> shots;
    */

    Game *game;

public:
    World();

    //returns a pointer to the nearest available enemy, All parameters come from the attacker
    Entity* getNAE(int x, int y, int team, double &distance);

    //performs bounds check against all walls, towers, and cores, returns false if outside of movable space
    bool boundsCheck(int x, int y);

    Entity* getByID(int entID);

    void onTick();

    string save();

    void load(string loadString);

    string Display();

    //Team denotes the losing side
    void endGame(int team);
};

#endif // WORLD_H