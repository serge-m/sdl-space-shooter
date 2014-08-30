/*******************************************************************//*
 * Implementation of SDL_util class
 *
 * @author      Brandon To
 * @version     1.0
 * @since       2014-08-10
 * @modified    2014-08-28
 *********************************************************************/
#include "SDL_util.h"

#include <cstdio>
#include <cstddef>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "WindowElements.h"

namespace SDL_util
{
    bool initialize()
    {
        if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
        {
            return false;
        }

        int imgFlags = IMG_INIT_PNG;
        if( !( IMG_Init( imgFlags ) & imgFlags ) )
        {
            printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
            return false;
        }

        return true;
    }

    SDL_Texture* load_image(WindowElements* windowElements, std::string path)
    {
        SDL_Texture* texture = NULL;
        SDL_Surface* surface = IMG_Load(path.c_str());
        if (surface==NULL)
        {
            printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
        }
        else
        {
            texture = SDL_CreateTextureFromSurface(windowElements->renderer, surface);
            if(texture==NULL)
            {
                printf( "Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
            }

            SDL_FreeSurface(surface);
        }

        return texture;
    }

    SDL_Texture* load_background(WindowElements* windowElements, std::string path)
    {
        SDL_Surface* backgroundSurface = NULL;
        SDL_Surface* surface = NULL;
        SDL_Texture* texture = NULL;
        int fitWidth, fitHeight;
        SDL_Rect temp;

        backgroundSurface = SDL_CreateRGBSurface(0, windowElements->WINDOW_WIDTH, windowElements->WINDOW_HEIGHT, 32, 0, 0, 0, 0);
        if (backgroundSurface==NULL)
        {
            printf("Unable to create SDL_Surface! SDL Error: %s\n", SDL_GetError());
            return texture;
        }

        surface = IMG_Load(path.c_str());
        if (surface==NULL)
        {
            printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
            return texture;
        }

        fitWidth = windowElements->WINDOW_HEIGHT / surface->w;
        fitHeight = windowElements->WINDOW_HEIGHT / surface->h;
        temp.w = surface->w;
        temp.h = surface->h;
        for (int i=0; i<=fitWidth; i++)
        {
            for (int j=0; j<=fitHeight; j++)
            {
                temp.x = i * surface->w;
                temp.y = j * surface->h;
                SDL_BlitSurface(surface, NULL, backgroundSurface, &(temp));
            }
        }

        texture = SDL_CreateTextureFromSurface(windowElements->renderer, backgroundSurface);
        if(texture==NULL)
        {
            printf( "Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
            return texture;
        }

        SDL_FreeSurface(backgroundSurface);
        SDL_FreeSurface(surface);

        return texture;
    }

    //SDL_Renderer* create
}