/*
---------------------------------------------------------------------------------------------------------------------------------
|	ESME Sudria 2017-2018								CONTASSOT Alexandre						GAME V0.0.1						|
|														LAPORTE Nathan							09/04/18						|
|	Modelisation objet									PASTRE Raphael								 							|
|	Interfaces Homme-Machine							Ingé 2C - 1					https://github.com/Sysmetryx/Game-Project	|
|																																|
---------------------------------------------------------------------------------------------------------------------------------
*/
#ifndef UNIT_H
#define UNIT_H
#include "item.h"
#include <QList>

class Unit : public Item
{
public:
    Unit(QPointF *pos, QString imagePath, int xSize = 200, int ySize = 200);
    ~Unit();
    void attack();
    void die();
    //getters :
    int getHealthPoints() const {
        return this->healthPoints;
    }
    float getMoveSpeed() const;
    float getAttackSpeed() const {
        return this->attackSpeed;
    }
    int getAttackValue() const {
        return this->attackValue;
    }
    //seters :
    void setHealthPoints(int newHealthPoints){
        this->healthPoints = newHealthPoints;
    }
    void addMovePoint(QPointF *nextPoint);
    QList<QPointF *> * getMovePoints();
    virtual void harvest();
    virtual void setCanHarvest(bool condition);
    bool getCanHarvest();
    virtual bool getBringBack();
    virtual void setBringBack(bool condition);
    virtual bool getIsHarvester();
protected:
    QList<QPointF*> *mouvements;
    int healthPoints; //Defines the health of the unit.
    float moveSpeed; //Defines the movement speed of the unit.
    float attackSpeed; //Defines the attack speed of the unit per second. For example, an attackSpeed value of 1 is 1 hit per second.
    int attackValue; //Defines the attack value of the unit (total DPS is calculated using attackSpeed * attack)
    bool canHarvest;
    bool bringBack;
};
#endif // UNIT_H
