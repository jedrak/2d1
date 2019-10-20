#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <vector>
#include <GameObject.h>

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

std::vector<GameObject> gGameObjects;
SDL_Window * gWindow = nullptr;
SDL_Surface * gScreenSurface = nullptr;
SDL_Surface *gXOut;

bool init();
bool loadMedia();
void close();
void update();




int main( int argc, char* args[] ) {
    bool quit = false;
    SDL_Event e;
    if(!init()){
        SDL_Log("Failed to initialize!");
    }
    else {
        if(!loadMedia()) {
            SDL_Log("Failed to load media!");
        }
        else{
            while(!quit){
                while(SDL_PollEvent(&e) != 0){
                    if(e.type == SDL_QUIT){
                        quit = true;
                    }
                }
                //Update surface
                SDL_BlitSurface(gXOut, NULL, gScreenSurface, NULL);
                //Update window
                SDL_UpdateWindowSurface(gWindow);
            }

        }
    }
    close();
    return 0;
}

bool init() {
    if(SDL_Init(SDL_INIT_VIDEO)<0){
        SDL_Log("Error: %s", SDL_GetError());
        return false;
    }
    else{
        gWindow = SDL_CreateWindow( "2D Ex1", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        if(gWindow == nullptr){
            printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
            return false;
        }
        else{
            gScreenSurface = SDL_GetWindowSurface(gWindow);
        }
    }
    return true;
}
SDL_Surface* loadSurface( const std::string& path )
{
    //The final optimized image
    SDL_Surface* optimizedSurface = NULL;

    //Load image at specified path
    SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
    if( loadedSurface == NULL )
    {
        printf( "Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError() );
    }
    else
    {
        //Convert surface to screen format
        optimizedSurface = SDL_ConvertSurface( loadedSurface, gScreenSurface->format, 0 );
        if( optimizedSurface == NULL )
        {
            printf( "Unable to optimize image %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
        }

        //Get rid of old loaded surface
        SDL_FreeSurface( loadedSurface );
    }

    return optimizedSurface;
}
bool loadMedia() {
    gXOut = loadSurface(R"(..\assets\bcg.png)");
    if(gScreenSurface == nullptr){
        SDL_Log("SDL Error: %s", SDL_GetError());
        return false;
    }
    else {
        return true;
    }
}

void close() {
    SDL_FreeSurface( gScreenSurface );
    gScreenSurface = NULL;
    //Destroy window
    SDL_DestroyWindow( gWindow );
    gWindow = NULL;
    //Quit SDL subsystems
    SDL_Quit();
}





