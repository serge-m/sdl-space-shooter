/*******************************************************************//*
 * This class is a wrapper for the collection of GameEntity objects
 * used in the game. Also acts as a pseudo-contract for the collection
 * used.
 *
 * @author      Brandon To
 * @version     1.0
 * @since       2014-08-10
 * @modified    2014-08-20
 *********************************************************************/
#ifndef SPACESHOOTER_GAMEENTITYCOLLECTION_H_
    #define SPACESHOOTER_GAMEENTITYCOLLECTION_H_

#include <list>

class GameEntity;

class GameEntityCollection
{
    private:
        std::list<GameEntity*> collection;

    public:
        void add(GameEntity* gameEntity);
        void remove(GameEntity* gameEntity);
        void onRender();
};

#endif
