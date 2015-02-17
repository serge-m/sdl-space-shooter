/*******************************************************************//*
 * Implementation of the MovementPattern class.
 *
 * @author      Brandon To
 * @version     1.0
 * @since       2015-02-16
 * @modified    2015-02-17
 *********************************************************************/
#include "MovementPattern.h"

#include <SDL2/SDL.h>

// Constructor
MovementPattern::MovementPattern()
:   currentVelocity(0,150)
{
    timer.start();
}

// Destructor
MovementPattern::~MovementPattern()
{
}

void MovementPattern::setMovementPattern(int patternId)
{
    if (patternId == MOVEMENT_STRAIGHT)
    {
        Vector2D vector(0, 150);
        int time = 6000;
        velocityQueue.push(vector);
        timeQueue.push(time);
    }
    else if (patternId == MOVEMENT_ZIGZAG)
    {
        Vector2D vector1(120, 120);
        Vector2D vector2(-120, 120);
        int time = 1500;
        velocityQueue.push(vector1);
        velocityQueue.push(vector2);
        velocityQueue.push(vector1);
        velocityQueue.push(vector2);
        timeQueue.push(time);
        timeQueue.push(time);
        timeQueue.push(time);
        timeQueue.push(time);
    }

    currentVelocity = velocityQueue.front();
    currentVelocityTime = timeQueue.front();
    velocityQueue.pop();
    timeQueue.pop();
    timer.stop();
    timer.start();
}

Vector2D MovementPattern::getCurrentVelocity()
{
    if (timer.getTimeOnTimer() > currentVelocityTime)
    {
        if (!velocityQueue.empty())
        {
            currentVelocity = velocityQueue.front();
            currentVelocityTime = timeQueue.front();
            velocityQueue.pop();
            timeQueue.pop();
            timer.stop();
            timer.start();
        }
    }
    return currentVelocity;
}
