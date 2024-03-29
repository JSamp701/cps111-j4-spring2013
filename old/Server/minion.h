#ifndef MINION_H
#define MINION_H

class World;
class Entity;
class Unit;
class Counter;

class Minion : public Unit
{
    Minion();
protected:
    int cpX;
    int cpY;
    int laneX;
    int laneY;
    int tombX;
    int tombY;
    int newTombX;
    int newTombY;

    //OUT OF LANE
    bool OOL;
    bool tombstone;
public:
    Minion(int cTeam, int newX, int newY, World *newMap);
    virtual bool damage(int value);
    virtual void onTick();
    virtual string save();
    virtual Entity* load(std::string loadString);
    virtual string displayString();
    virtual void die();
    virtual bool Attack();
    World* world;

};

#endif // MINION_H
