#ifndef _SDLJEU_H
#define _SDLJEU_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>

#include "Jeu.h"

//! \brief Pour gérer une image avec SDL2
class Image {

private:

    SDL_Surface * m_surface;
    SDL_Texture * m_texture;
    bool m_hasChanged;

public:
    Image () ;
    ~Image();
    void loadFromFile (const char* filename, SDL_Renderer * renderer);
    void loadFromCurrentSurface (SDL_Renderer * renderer);
    void draw (SDL_Renderer * renderer, int x, int y, int w=-1, int h=-1);
    SDL_Texture * getTexture() const;
    void setSurface(SDL_Surface * surf);
};



/**
    La classe gerant le jeu avec un affichage SDL
*/
class SDLSimple {

private :

	

    SDL_Window * window;
    SDL_Renderer * renderer;

    TTF_Font * font;
    Image font_im;
    SDL_Color font_color;

    Mix_Chunk * sound;
    Mix_Chunk * sound2;
    Mix_Chunk * sound3;


    bool withSound;

    Image im_zombi;
    Image im_plaine;
    Image im_batdef;
    Image im_go1;
    Image im_go2;
    Image im_go3;
    Image im_go4;
    Image im_go5;
    Image im_go6;
    Image im_go7;
    Image im_go8;
    Image im_go9;
    Image im_go10;
    Image im_menu1;
    Image im_Option1;
    Image im_Option2;
    Image im_Option3;
    Image im_Credit;
    Image im_die_1;
    Image im_die_2;
    Image im_die_3;
    Image im_die_4;
    Image im_die_5;
    Image im_die_6;
    Image im_die_7;
    Image im_die_8;
    Image im_ferme;
    Image im_ferme_2;
    Image im_ferme_3;
    Image im_ferme_4;
    Image im_CarteMenu;
    Image im_Croix;
    Image im_GameOver;


    bool souris;
    bool touche;

    SDL_Texture* buttonTexture;
    int inc,inc2;

    int TEMPS;


public :
    Jeu jeu_sdl;

    SDLSimple ();
    ~SDLSimple ();
    void sdlBoucle ();
    void sdlAff ();
    void sdlMenu ();
    void sdlOption(int img);
    void sdlCredit();
    void sdlMenu2(bool Bat1, float pos1, float pos2);

};

#endif
