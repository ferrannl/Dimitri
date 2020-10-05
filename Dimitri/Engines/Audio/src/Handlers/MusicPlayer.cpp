#include "MusicPlayer.h"


////The music that will be played
//Mix_Music* gMusic = NULL;
//
////The sound effects that will be used
//Mix_Chunk* gScratch = NULL;
//Mix_Chunk* gHigh = NULL;
//Mix_Chunk* gMedium = NULL;
//Mix_Chunk* gLow = NULL;
//
//void init() {
//    //Initialize SDL
//    if (SDL_Init(SDL_INIT_AUDIO) < 0)
//    {
//        printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
//    }
//    //Initialize SDL_mixer
//    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
//    {
//        printf("SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError());
//    }
//    
//    std::string path = (SDL_GetBasePath() + std::string{ "resources/audio/beat.wav" });
//    //Load music
//    gMusic = Mix_LoadMUS(path.c_str());
//    if (gMusic == NULL)
//    {
//        printf("Failed to load beat music! SDL_mixer Error: %s\n", Mix_GetError());
//    }
//    
//    path = (SDL_GetBasePath() + std::string{ "resources/audio/scratch.wav" });
//    //Load sound effects
//    gScratch = Mix_LoadWAV(path.c_str());
//    if (gScratch == NULL)
//    {
//        printf("Failed to load scratch sound effect! SDL_mixer Error: %s\n", Mix_GetError());
//        
//    }
//
//    path = (SDL_GetBasePath() + std::string{ "resources/audio/high.wav" });
//    gHigh = Mix_LoadWAV(path.c_str());
//    if (gHigh == NULL)
//    {
//        printf("Failed to load high sound effect! SDL_mixer Error: %s\n", Mix_GetError());
//     
//    }
//
//    path = (SDL_GetBasePath() + std::string{ "resources/audio/medium.wav" });
//    gMedium = Mix_LoadWAV(path.c_str());
//    if (gMedium == NULL)
//    {
//        printf("Failed to load medium sound effect! SDL_mixer Error: %s\n", Mix_GetError());
//        
//    }
//
//    path = (SDL_GetBasePath() + std::string{ "resources/audio/low.wav" });
//    gLow = Mix_LoadWAV(path.c_str());
//    if (gLow == NULL)
//    {
//        printf("Failed to load low sound effect! SDL_mixer Error: %s\n", Mix_GetError());
//        
//    }
//}
//
//void play_music() {
//    //Play the music
//    Mix_PlayMusic(gMusic, -1);
//}
//
//void play_sound() {
//
//}

//void close()
//{
//    //Free the sound effects
//    Mix_FreeChunk(gScratch);
//    Mix_FreeChunk(gHigh);
//    Mix_FreeChunk(gMedium);
//    Mix_FreeChunk(gLow);
//    gScratch = NULL;
//    gHigh = NULL;
//    gMedium = NULL;
//    gLow = NULL;
//
//    //Free the music
//    Mix_FreeMusic(gMusic);
//    gMusic = NULL;
//
//    //Quit SDL subsystems
//    Mix_Quit();
//    SDL_Quit();
//}


