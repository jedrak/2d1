/*This source code copyrighted by Lazy Foo' Productions (2004-2019)
and may not be redistributed without written permission.*/

//Using SDL, SDL_image, standard IO, math, and strings
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <string>
#include <cmath>
#include <iostream>
#include <Player.h>

const int LEVEL_WIDTH = 1080;
const int LEVEL_HEIGHT = 720;
//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
//Analog joystick dead zone
const int JOYSTICK_DEAD_ZONE = 8000;
//Starts up SDL and creates window
bool init();
//Loads media
bool loadMedia();
//Frees media and shuts down SDL
void close();

void drawTriangle(SDL_Renderer* renderer, float* X, float* Y);
//Loads individual image as texture
SDL_Texture* loadTexture( std::string path );
//The window we'll be rendering to
SDL_Window* gWindow = NULL;
//The window renderer
SDL_Renderer* gRenderer = NULL;
//Current displayed texture
SDL_Texture* gTexture = NULL;
//Game Controller 1 handler
SDL_Joystick* gGameController = NULL;

bool init()
{
    //Initialization flag
    bool success = true;

    //Initialize SDL
    if( SDL_Init( SDL_INIT_VIDEO | SDL_INIT_JOYSTICK ) < 0 )
    {
        printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
        success = false;
    }
    else
    {
        //Set texture filtering to linear
        if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
        {
            printf( "Warning: Linear texture filtering not enabled!" );
        }

        //Create window
        gWindow = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
        if( gWindow == NULL )
        {
            printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
            success = false;
        }
        else
        {
            //Create renderer for window
            gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED );
            if( gRenderer == NULL )
            {
                printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
                success = false;
            }
            else
            {
                //Initialize renderer color
                SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );

                //Initialize PNG loading
                int imgFlags = IMG_INIT_PNG;
                if( !( IMG_Init( imgFlags ) & imgFlags ) )
                {
                    printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
                    success = false;
                }
            }
        }
        if( SDL_NumJoysticks() < 1 )
        {
            printf( "Warning: No joysticks connected!\n" );
        }
        else
        {
            //Load joystick
            gGameController = SDL_JoystickOpen( 0 );
            if( gGameController == NULL )
            {
                printf( "Warning: Unable to open game controller! SDL Error: %s\n", SDL_GetError() );
            }
        }
    }

    return success;
}

bool loadMedia()
{
    //Loading success flag
    bool success = true;

    //Load PNG texture
    gTexture = loadTexture( "../assets/bcg.png" );
    if( gTexture == NULL )
    {
        printf( "Failed to load texture image!\n" );
        success = false;
    }

    return success;
}


void close()
{
    //Destroy window
    SDL_DestroyRenderer( gRenderer );
    SDL_DestroyWindow( gWindow );
    gWindow = NULL;
    gRenderer = NULL;
    SDL_JoystickClose( gGameController );
    gGameController = NULL;
    //Quit SDL subsystems
    IMG_Quit();
    SDL_Quit();
}

SDL_Texture* loadTexture( std::string path )
{
    //The final texture
    SDL_Texture* newTexture = NULL;

    //Load image at specified path
    SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
    if( loadedSurface == NULL )
    {
        printf( "Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError() );
    }
    else
    {
        //Create texture from surface pixels
        newTexture = SDL_CreateTextureFromSurface( gRenderer, loadedSurface );
        if( newTexture == NULL )
        {
            printf( "Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
        }

        //Get rid of old loaded surface
        SDL_FreeSurface( loadedSurface );
    }

    return newTexture;
}

void drawEquilateralTriangle(SDL_Renderer *renderer, int x, int y, int a, int h) {
    if(h>0) {
        SDL_SetRenderDrawColor(gRenderer, 0x00, 0xFF, 0x00, 0xFF);
        int pointsX[] = {
                x, x - (a / 2), x + (a / 2)
        };

        int pointsY[] = {
                y - (2 * (h / 3)), y + (h / 3), y + (h / 3)
        };
        for(int i = 0; i<(pointsX[2]-pointsX[1]); i++){
            SDL_RenderDrawLine(renderer, pointsX[0], pointsY[0], pointsX[1]+i, pointsY[1]);
        }
    }
}

int main( int argc, char* args[] )
{
    auto* player1 = new Player(SCREEN_WIDTH/2, SCREEN_HEIGHT/2);
    auto* player2 = new Player(SCREEN_WIDTH/2, SCREEN_HEIGHT/2);
    player1->start();
    player2->start();
    //Start up SDL and create window
    if( !init() )
    {
        printf( "Failed to initialize!\n" );
    }
    else
    {
        //Load media
        if( !loadMedia() )
        {
            printf( "Failed to load media!\n" );
        }
        else
        {
            //Main loop flag
            bool quit = false;

            //Event handler
            SDL_Event e;

            //While application is running
            while( !quit )
            {
                //Handle events on queue
                while( SDL_PollEvent( &e ) != 0 )
                {
                    //User requests quit
                    if( e.type == SDL_QUIT )
                    {
                        quit = true;
                    }
                    //Handling player 1 input
                    else if( e.type == SDL_KEYDOWN ) {
                        //Select surfaces based on key press
                        switch (e.key.keysym.sym) {
                            case SDLK_UP:
                                player1->setSpeedY(-1);
                                break;

                            case SDLK_DOWN:
                                player1->setSpeedY(1);
                                break;

                            case SDLK_LEFT:
                                player1->setSpeedX(-1);
                                break;

                            case SDLK_RIGHT:
                                player1->setSpeedX(1);
                                break;

                        }

                    } else if(e.type == SDL_KEYUP){
                        switch(e.key.keysym.sym){
                            case SDLK_UP:
                                player1->setSpeedY(0);
                                break;

                            case SDLK_DOWN:
                                player1->setSpeedY(0);
                                break;

                            case SDLK_LEFT:
                                player1->setSpeedX(0);
                                break;

                            case SDLK_RIGHT:
                                player1->setSpeedX(0);
                                break;
                        }
                    }else if(e.type == SDL_JOYAXISMOTION){
                        if(e.jaxis.which == 0){
                            //X axis motion
                            if( e.jaxis.axis == 0 )
                            {
                                //Left of dead zone
                                if( e.jaxis.value < -JOYSTICK_DEAD_ZONE )
                                {
                                    player2->setSpeedX(-1);
                                }
                                    //Right of dead zone
                                else if( e.jaxis.value > JOYSTICK_DEAD_ZONE )
                                {
                                    player2->setSpeedX(1);
                                }
                                else
                                {
                                    player2->setSpeedX(0);
                                }
                            }
                            else if(e.jaxis.axis == 1){
                                //Below of dead zone
                                if( e.jaxis.value < -JOYSTICK_DEAD_ZONE )
                                {
                                    player2->setSpeedY(-1);
                                }
                                    //Above of dead zone
                                else if( e.jaxis.value > JOYSTICK_DEAD_ZONE )
                                {
                                    player2->setSpeedY(1);
                                }
                                else
                                {
                                    player2->setSpeedY(0);
                                }
                            }
                        }
                    }

                }

                //Update game objects
                if(SDL_GetTicks()%30==0){
                    player1->update();
                    player2->update();
                }

                //Clear screen
                SDL_RenderClear( gRenderer );
                SDL_RenderCopy( gRenderer, gTexture, NULL, NULL );
                //Render red filled quad
                SDL_Rect fillRect = { player1->getX() - 25, player1->getY() - 25, 50, 50 };
                SDL_SetRenderDrawColor( gRenderer, 0xFF, 0x00, 0x00, 0xFF );
                SDL_RenderFillRect( gRenderer, &fillRect );
                drawEquilateralTriangle(gRenderer, player2->getX(), player2->getY(), 50, 43);
                //Update screen
                SDL_RenderPresent( gRenderer );
            }
        }
    }

    //Free resources and close SDL
    close();

    return 0;
}