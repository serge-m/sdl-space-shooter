/*******************************************************************//*
 * Interface containing one method that all render components must
 * implement
 *
 * @author      Brandon To
 * @version     1.0
 * @since       2014-08-17
 * @modified    2014-09-06
 *********************************************************************/
#ifndef SPACESHOOTER_RENDERCOMPONENT_
    #define SPACESHOOTER_RENDERCOMPONENT_

class RenderComponent
{
    public:
        //Destructor
        virtual ~RenderComponent(){};

        //Methods
        virtual void update() = 0;
};

#endif
