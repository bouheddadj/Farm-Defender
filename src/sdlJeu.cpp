#include <cassert>
#include <time.h>
#include "sdlJeu.h"
#include <stdlib.h>
#include <X11/Xlib.h>
#include <unistd.h> 
#define HAUTEUR 55
#define LARGEUR 200



#include <iostream>
using namespace std;

const int TAILLE_SPRITE = 32;

float temps () {
    return float(SDL_GetTicks()) / CLOCKS_PER_SEC;  // conversion des ms en secondes en divisant par 1000
}


// ============= CLASS IMAGE =============== //

Image::Image () : m_surface(nullptr), m_texture(nullptr), m_hasChanged(false) {
}

Image::~Image()
{
    SDL_FreeSurface(m_surface);
    SDL_DestroyTexture(m_texture);

    m_surface = nullptr;
    m_texture = nullptr;
    m_hasChanged = false;
}

void Image::loadFromFile (const char* filename, SDL_Renderer * renderer) {
    m_surface = IMG_Load(filename);
    if (m_surface == nullptr) {
        string nfn = string("../") + filename;
        cout << "Error: cannot load "<< filename <<". Trying "<<nfn<<endl;
        m_surface = IMG_Load(nfn.c_str());
        if (m_surface == nullptr) {
            nfn = string("../") + nfn;
            m_surface = IMG_Load(nfn.c_str());
        }
    }
    if (m_surface == nullptr) {
        cout<<"Error: cannot load "<< filename <<endl;
        SDL_Quit();
        exit(1);
    }

    SDL_Surface * surfaceCorrectPixelFormat = SDL_ConvertSurfaceFormat(m_surface,SDL_PIXELFORMAT_ARGB8888,0);
    SDL_FreeSurface(m_surface);
    m_surface = surfaceCorrectPixelFormat;

    m_texture = SDL_CreateTextureFromSurface(renderer,surfaceCorrectPixelFormat);
    if (m_texture == NULL) {
        cout << "Error: problem to create the texture of "<< filename<< endl;
        SDL_Quit();
        exit(1);
    }
}

void Image::loadFromCurrentSurface (SDL_Renderer * renderer) {
    m_texture = SDL_CreateTextureFromSurface(renderer,m_surface);
    if (m_texture == nullptr) {
        cout << "Error: problem to create the texture from surface " << endl;
        SDL_Quit();
        exit(1);
    }
}

void Image::draw (SDL_Renderer * renderer, int x, int y, int w, int h) {
    int ok;
    SDL_Rect r;
    r.x = x;
    r.y = y;
    r.w = (w<0)?m_surface->w:w;
    r.h = (h<0)?m_surface->h:h;

    if (m_hasChanged) {
        ok = SDL_UpdateTexture(m_texture,nullptr,m_surface->pixels,m_surface->pitch);
        assert(ok == 0);
        m_hasChanged = false;
    }

    ok = SDL_RenderCopy(renderer,m_texture,nullptr,&r);
    assert(ok == 0);

    
}

SDL_Texture * Image::getTexture() const {return m_texture;}

void Image::setSurface(SDL_Surface * surf) {m_surface = surf;}


// ============= CLASS SDLJEU =============== //

SDLSimple::SDLSimple ()  : jeu_sdl() {
    // Initialisation de la SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        cout << "Erreur lors de l'initialisation de la SDL : " << SDL_GetError() << endl;
        SDL_Quit();
        exit(1);
    }

    if (TTF_Init() != 0) {
        cout << "Erreur lors de l'initialisation de la SDL_ttf : " << TTF_GetError() << endl;
        SDL_Quit();
        exit(1);
    }

    int imgFlags = IMG_INIT_PNG | IMG_INIT_JPG;
    if( !(IMG_Init(imgFlags) & imgFlags)) {
        cout << "SDL_image could not initialize! SDL_image Error: " << IMG_GetError() << endl;
        SDL_Quit();
        exit(1);
    }

    
    if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 )
    {
        cout << "SDL_mixer could not initialize! SDL_mixer Error: " << Mix_GetError() << endl;
        cout << "No sound !!!" << endl;
        SDL_Quit();exit(1);
        withSound = false;
    }
    else withSound = true;

	cout<<" SDL COUT : "<< 960<< " " << 640 <<endl;
    // Creation de la fenetre
    window = SDL_CreateWindow("FarmDefender", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 960, 640, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
    if (window == nullptr) {
        cout << "Erreur lors de la creation de la fenetre : " << SDL_GetError() << endl; 
        SDL_Quit(); 
        exit(1);
    }

    renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);

    // IMAGES
    im_plaine.loadFromFile("data/Carte.png",renderer);
    im_CarteMenu.loadFromFile("data/CarteMenu.png",renderer);
    im_batdef.loadFromFile("data/batdef.png",renderer);
    im_go1.loadFromFile("data/go_1.png",renderer);
    im_go2.loadFromFile("data/go_2.png",renderer);
    im_go3.loadFromFile("data/go_3.png",renderer);
    im_go4.loadFromFile("data/go_4.png",renderer);
    im_go5.loadFromFile("data/go_5.png",renderer);
    im_go6.loadFromFile("data/go_6.png",renderer);
    im_go7.loadFromFile("data/go_7.png",renderer);
    im_go8.loadFromFile("data/go_8.png",renderer);
    im_go9.loadFromFile("data/go_9.png",renderer);
    im_go10.loadFromFile("data/go_10.png",renderer);
    im_menu1.loadFromFile("data/MENU.png",renderer);
    im_Option1.loadFromFile("data/OPTION1.png",renderer);
    im_Option2.loadFromFile("data/OPTION2.png",renderer);
    im_Option3.loadFromFile("data/OPTION3.png",renderer);
    im_Credit.loadFromFile("data/CREDIT.png",renderer);
    im_die_1.loadFromFile("data/die_1.png",renderer);
    im_die_2.loadFromFile("data/die_2.png",renderer);
    im_die_3.loadFromFile("data/die_3.png",renderer);
    im_die_4.loadFromFile("data/die_4.png",renderer);
    im_die_5.loadFromFile("data/die_5.png",renderer);
    im_die_6.loadFromFile("data/die_6.png",renderer);
    im_die_7.loadFromFile("data/die_7.png",renderer);
    im_die_8.loadFromFile("data/die_8.png",renderer);
    im_ferme.loadFromFile("data/fermeGH.png",renderer);
    im_ferme_2.loadFromFile("data/fermeDH.png",renderer);
    im_ferme_3.loadFromFile("data/fermeGB.png",renderer);
    im_ferme_4.loadFromFile("data/fermeDB.png",renderer);
    im_Croix.loadFromFile("data/Croix.png",renderer);
    im_GameOver.loadFromFile("data/GameOver.png",renderer);



    // FONTS
    
    font = TTF_OpenFont("data/DejaVuSansCondensed.ttf",20);
    if (font == nullptr)
        font = TTF_OpenFont("../data/DejaVuSansCondensed.ttf",20);
    if (font == nullptr) {
            cout << "Failed to load DejaVuSansCondensed.ttf! SDL_TTF Error: " << TTF_GetError() << endl; 
            SDL_Quit(); 
            exit(1);
	}
    
    
    
	// font_color.r = 50;font_color.g = 50;font_color.b = 255;
	// font_im.setSurface(TTF_RenderText_Solid(font,"TEST",font_color));
	// font_im.loadFromCurrentSurface(renderer);
    

    // SONS
    
    if (withSound)
    {
        sound = Mix_LoadWAV("../data/son.wav");
        if (sound == nullptr)
          sound = Mix_LoadWAV("data/son.wav");
        if (sound == nullptr) {
                cout << "Failed to load son.wav :( SDL_mixer Error: " << Mix_GetError() << endl; 
                SDL_Quit();
                exit(1);
        }
    }

        if (withSound)
    {
        sound2 = Mix_LoadWAV("../data/son2.wav");
        if (sound2 == nullptr)
          sound2 = Mix_LoadWAV("data/son2.wav");
        if (sound2 == nullptr) {
                cout << "Failed to load son2.wav :( SDL_mixer Error: " << Mix_GetError() << endl; 
                SDL_Quit();
                exit(1);
        }
    }

         if (withSound)
    {
        sound3 = Mix_LoadWAV("../data/son3.wav");
        if (sound3 == nullptr)
          sound3 = Mix_LoadWAV("data/son3.wav");
        if (sound3 == nullptr) {
                cout << "Failed to load son3.wav :( SDL_mixer Error: " << Mix_GetError() << endl; 
                SDL_Quit();
                exit(1);
        }
    }
}


SDLSimple::~SDLSimple () {
    if (withSound) Mix_Quit();
    TTF_CloseFont(font);
    TTF_Quit();
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void SDLSimple::sdlAff () {

	//Remplir l'écran de blanc
    SDL_SetRenderDrawColor(renderer, 230, 240, 255, 255);
    SDL_RenderClear(renderer);

    //Afficher l'image du background
    im_plaine.draw(renderer,0,0,960,640);

    Vect2 pos;
    for (unsigned int i = 0; i<jeu_sdl.TabFerme.size();i++){
    pos = jeu_sdl.TabFerme.at(i).get_position();
    // cout<<pos.x<<" X et "<<pos.y<<" Y "<<endl;
    
    if(pos.x == 14 && pos.y == 6){im_ferme.draw(renderer,0,0,960,640);}
    if(pos.x == 45 && pos.y == 6){im_ferme_2.draw(renderer,0,0,960,640);}
    if(pos.x == 14 && pos.y == 23){im_ferme_3.draw(renderer,0,0,960,640);}
    if(pos.x == 45 && pos.y == 23){im_ferme_4.draw(renderer,0,0,960,640);}
    }

   if(inc > 9){inc = 0;}
   
   for (unsigned int i = 0; i<jeu_sdl.tabEnnemi.size();i++){
            float tm=jeu_sdl.tabEnnemi.at(i).get_temps_mort();
            // cout<<tm<<" temps "<<endl;

    if(jeu_sdl.tabEnnemi.at(i).get_statut() == 1){
        if(inc == 0){im_go1.draw(renderer,jeu_sdl.tabEnnemi.at(i).splitX()*16,jeu_sdl.tabEnnemi.at(i).splitY()*21.33,TAILLE_SPRITE,TAILLE_SPRITE);}
        if(inc == 1){im_go2.draw(renderer,jeu_sdl.tabEnnemi.at(i).splitX()*16,jeu_sdl.tabEnnemi.at(i).splitY()*21.33,TAILLE_SPRITE,TAILLE_SPRITE);}
        if(inc == 2){im_go3.draw(renderer,jeu_sdl.tabEnnemi.at(i).splitX()*16,jeu_sdl.tabEnnemi.at(i).splitY()*21.33,TAILLE_SPRITE,TAILLE_SPRITE);}
        if(inc == 3){im_go4.draw(renderer,jeu_sdl.tabEnnemi.at(i).splitX()*16,jeu_sdl.tabEnnemi.at(i).splitY()*21.33,TAILLE_SPRITE,TAILLE_SPRITE);}
        if(inc == 4){im_go5.draw(renderer,jeu_sdl.tabEnnemi.at(i).splitX()*16,jeu_sdl.tabEnnemi.at(i).splitY()*21.33,TAILLE_SPRITE,TAILLE_SPRITE);}
        if(inc == 5){im_go6.draw(renderer,jeu_sdl.tabEnnemi.at(i).splitX()*16,jeu_sdl.tabEnnemi.at(i).splitY()*21.33,TAILLE_SPRITE,TAILLE_SPRITE);}
        if(inc == 6){im_go7.draw(renderer,jeu_sdl.tabEnnemi.at(i).splitX()*16,jeu_sdl.tabEnnemi.at(i).splitY()*21.33,TAILLE_SPRITE,TAILLE_SPRITE);}
        if(inc == 7){im_go8.draw(renderer,jeu_sdl.tabEnnemi.at(i).splitX()*16,jeu_sdl.tabEnnemi.at(i).splitY()*21.33,TAILLE_SPRITE,TAILLE_SPRITE);}
        if(inc == 8){im_go9.draw(renderer,jeu_sdl.tabEnnemi.at(i).splitX()*16,jeu_sdl.tabEnnemi.at(i).splitY()*21.33,TAILLE_SPRITE,TAILLE_SPRITE);}
        if(inc == 9){im_go10.draw(renderer,jeu_sdl.tabEnnemi.at(i).splitX()*16,jeu_sdl.tabEnnemi.at(i).splitY()*21.33,TAILLE_SPRITE,TAILLE_SPRITE);}          
    }else if (jeu_sdl.tabEnnemi.at(i).get_statut() == 0){
        if(tm <= 10 && tm >0){im_die_1.draw(renderer,jeu_sdl.tabEnnemi.at(i).splitX()*16,jeu_sdl.tabEnnemi.at(i).splitY()*21.33,TAILLE_SPRITE,TAILLE_SPRITE); Mix_PlayChannel(-1,sound3,0); }
        if(tm <= 20 && tm >10){im_die_2.draw(renderer,jeu_sdl.tabEnnemi.at(i).splitX()*16,jeu_sdl.tabEnnemi.at(i).splitY()*21.33,TAILLE_SPRITE,TAILLE_SPRITE);}
        if(tm <= 30 && tm >20){im_die_3.draw(renderer,jeu_sdl.tabEnnemi.at(i).splitX()*16,jeu_sdl.tabEnnemi.at(i).splitY()*21.33,TAILLE_SPRITE,TAILLE_SPRITE);}
        if(tm <= 40 && tm >30){im_die_4.draw(renderer,jeu_sdl.tabEnnemi.at(i).splitX()*16,jeu_sdl.tabEnnemi.at(i).splitY()*21.33,TAILLE_SPRITE,TAILLE_SPRITE);}
        if(tm <= 50 && tm >40){im_die_5.draw(renderer,jeu_sdl.tabEnnemi.at(i).splitX()*16,jeu_sdl.tabEnnemi.at(i).splitY()*21.33,TAILLE_SPRITE,TAILLE_SPRITE);}
        if(tm <= 60 && tm >50){im_die_6.draw(renderer,jeu_sdl.tabEnnemi.at(i).splitX()*16,jeu_sdl.tabEnnemi.at(i).splitY()*21.33,TAILLE_SPRITE,TAILLE_SPRITE);}
        if(tm <= 75 && tm >60){im_die_7.draw(renderer,jeu_sdl.tabEnnemi.at(i).splitX()*16,jeu_sdl.tabEnnemi.at(i).splitY()*21.33,TAILLE_SPRITE,TAILLE_SPRITE);}
        if(tm <= 100 && tm >75){im_die_8.draw(renderer,jeu_sdl.tabEnnemi.at(i).splitX()*16,jeu_sdl.tabEnnemi.at(i).splitY()*21.33,TAILLE_SPRITE,TAILLE_SPRITE);}

    } 


    
    }
    inc++;

    for (unsigned int i = 0; i<jeu_sdl.tabBatDef.size();i++){
    im_batdef.draw(renderer,jeu_sdl.tabBatDef.at(i).splitX()*16,jeu_sdl.tabBatDef.at(i).splitY()*21.33,TAILLE_SPRITE*1.5,TAILLE_SPRITE*1.5);}

    // // Ecrire un titre par dessus
    // SDL_Rect positionTitre;
    // positionTitre.x = 270;positionTitre.y = 49;positionTitre.w = 100;positionTitre.h = 30;
    // SDL_RenderCopy(renderer,font_im.getTexture(),nullptr,&positionTitre);

    // Création de la surface de texte
    string texte = "Temps : " + to_string(TEMPS);
    const char* Aff_temps = texte.c_str();

    string texte2 = to_string(jeu_sdl.stockage.gold);
    const char* Aff_golds = texte2.c_str();

    string texte3 = to_string(jeu_sdl.stockage.nourriture);
    const char* Aff_nourriture = texte3.c_str();


    SDL_Color color = {255, 0, 0}; // blanc
    SDL_Surface* textSurface = TTF_RenderText_Solid(font, Aff_temps, color);
    SDL_Surface* textSurface2 = TTF_RenderText_Solid(font, Aff_golds, color);
    SDL_Surface* textSurface3 = TTF_RenderText_Solid(font, Aff_nourriture, color);

    if (textSurface == nullptr) {
        printf("Erreur de création de la surface de texte : %s\n", TTF_GetError());
        //return 1;
    }

    // Création de la texture à partir de la surface
    SDL_Texture* textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
    SDL_Texture* textTexture2 = SDL_CreateTextureFromSurface(renderer, textSurface2);
    SDL_Texture* textTexture3 = SDL_CreateTextureFromSurface(renderer, textSurface3);

    if (textTexture == nullptr) {
        printf("Erreur de création de la texture : %s\n", SDL_GetError());
        //return 1;
    }

    // Affichage du texte à l'écran
    SDL_Rect destRect = {0, 0, textSurface->w, textSurface->h};
    SDL_Rect destRect2 = {480, 0, textSurface2->w, textSurface2->h};
    SDL_Rect destRect3 = {400, 0, textSurface3->w, textSurface3->h};


    SDL_RenderCopy(renderer, textTexture, nullptr, &destRect);
    SDL_RenderCopy(renderer, textTexture2, nullptr, &destRect2);
    SDL_RenderCopy(renderer, textTexture3, nullptr, &destRect3);

    // SDL_RenderPresent(renderer);

    
}

void SDLSimple::sdlMenu () {
	//Remplir l'écran de blanc
    SDL_SetRenderDrawColor(renderer, 230, 240, 255, 255);
    SDL_RenderClear(renderer);

    im_menu1.draw(renderer,0,0,960,640);

}

void SDLSimple::sdlOption (int img) {
	//Remplir l'écran de blanc
    SDL_SetRenderDrawColor(renderer, 230, 240, 255, 255);
    SDL_RenderClear(renderer);
    
    if(img == 1){
        im_Option1.draw(renderer,0,0,960,640);
    }

    if(img == 2){
        im_Option2.draw(renderer,0,0,960,640);
    }

    if(img == 3){
        im_Option3.draw(renderer,0,0,960,640);
    }
}

void SDLSimple::sdlCredit () {
    //Remplir l'écran de blanc
    SDL_SetRenderDrawColor(renderer, 230, 240, 255, 255);
    SDL_RenderClear(renderer);

    im_Credit.draw(renderer,0,0,960,640);

}

void SDLSimple::sdlMenu2(bool Bat1, float pos1, float pos2){
    //Remplir l'écran de blanc
    SDL_SetRenderDrawColor(renderer, 230, 240, 255, 255);
    SDL_RenderClear(renderer);



    im_CarteMenu.draw(renderer,0,0,960,640);

    Vect2 pos;
    for (unsigned int i = 0; i<jeu_sdl.TabFerme.size();i++){
    pos = jeu_sdl.TabFerme.at(i).get_position();
    // cout<<pos.x<<" X et "<<pos.y<<" Y "<<endl;
    
    if(pos.x == 14 && pos.y == 6){im_ferme.draw(renderer,0,0,960,640);}
    if(pos.x == 45 && pos.y == 6){im_ferme_2.draw(renderer,0,0,960,640);}
    if(pos.x == 14 && pos.y == 23){im_ferme_3.draw(renderer,0,0,960,640);}
    if(pos.x == 45 && pos.y == 23){im_ferme_4.draw(renderer,0,0,960,640);}
    }

   if(inc > 9){inc = 0;}
   
   for (unsigned int i = 0; i<jeu_sdl.tabEnnemi.size();i++){
            float tm=jeu_sdl.tabEnnemi.at(i).get_temps_mort();
            // cout<<tm<<" temps "<<endl;

    if(jeu_sdl.tabEnnemi.at(i).get_statut() == 1){
        if(inc == 0){im_go1.draw(renderer,jeu_sdl.tabEnnemi.at(i).splitX()*16,jeu_sdl.tabEnnemi.at(i).splitY()*21.33,TAILLE_SPRITE,TAILLE_SPRITE);}
        if(inc == 1){im_go2.draw(renderer,jeu_sdl.tabEnnemi.at(i).splitX()*16,jeu_sdl.tabEnnemi.at(i).splitY()*21.33,TAILLE_SPRITE,TAILLE_SPRITE);}
        if(inc == 2){im_go3.draw(renderer,jeu_sdl.tabEnnemi.at(i).splitX()*16,jeu_sdl.tabEnnemi.at(i).splitY()*21.33,TAILLE_SPRITE,TAILLE_SPRITE);}
        if(inc == 3){im_go4.draw(renderer,jeu_sdl.tabEnnemi.at(i).splitX()*16,jeu_sdl.tabEnnemi.at(i).splitY()*21.33,TAILLE_SPRITE,TAILLE_SPRITE);}
        if(inc == 4){im_go5.draw(renderer,jeu_sdl.tabEnnemi.at(i).splitX()*16,jeu_sdl.tabEnnemi.at(i).splitY()*21.33,TAILLE_SPRITE,TAILLE_SPRITE);}
        if(inc == 5){im_go6.draw(renderer,jeu_sdl.tabEnnemi.at(i).splitX()*16,jeu_sdl.tabEnnemi.at(i).splitY()*21.33,TAILLE_SPRITE,TAILLE_SPRITE);}
        if(inc == 6){im_go7.draw(renderer,jeu_sdl.tabEnnemi.at(i).splitX()*16,jeu_sdl.tabEnnemi.at(i).splitY()*21.33,TAILLE_SPRITE,TAILLE_SPRITE);}
        if(inc == 7){im_go8.draw(renderer,jeu_sdl.tabEnnemi.at(i).splitX()*16,jeu_sdl.tabEnnemi.at(i).splitY()*21.33,TAILLE_SPRITE,TAILLE_SPRITE);}
        if(inc == 8){im_go9.draw(renderer,jeu_sdl.tabEnnemi.at(i).splitX()*16,jeu_sdl.tabEnnemi.at(i).splitY()*21.33,TAILLE_SPRITE,TAILLE_SPRITE);}
        if(inc == 9){im_go10.draw(renderer,jeu_sdl.tabEnnemi.at(i).splitX()*16,jeu_sdl.tabEnnemi.at(i).splitY()*21.33,TAILLE_SPRITE,TAILLE_SPRITE);}          
    }else{
        if(tm <= 10 && tm >0){im_die_1.draw(renderer,jeu_sdl.tabEnnemi.at(i).splitX()*16,jeu_sdl.tabEnnemi.at(i).splitY()*21.33,TAILLE_SPRITE,TAILLE_SPRITE);}
        if(tm <= 20 && tm >10){im_die_2.draw(renderer,jeu_sdl.tabEnnemi.at(i).splitX()*16,jeu_sdl.tabEnnemi.at(i).splitY()*21.33,TAILLE_SPRITE,TAILLE_SPRITE);}
        if(tm <= 30 && tm >20){im_die_3.draw(renderer,jeu_sdl.tabEnnemi.at(i).splitX()*16,jeu_sdl.tabEnnemi.at(i).splitY()*21.33,TAILLE_SPRITE,TAILLE_SPRITE);}
        if(tm <= 40 && tm >30){im_die_4.draw(renderer,jeu_sdl.tabEnnemi.at(i).splitX()*16,jeu_sdl.tabEnnemi.at(i).splitY()*21.33,TAILLE_SPRITE,TAILLE_SPRITE);}
        if(tm <= 50 && tm >40){im_die_5.draw(renderer,jeu_sdl.tabEnnemi.at(i).splitX()*16,jeu_sdl.tabEnnemi.at(i).splitY()*21.33,TAILLE_SPRITE,TAILLE_SPRITE);}
        if(tm <= 60 && tm >50){im_die_6.draw(renderer,jeu_sdl.tabEnnemi.at(i).splitX()*16,jeu_sdl.tabEnnemi.at(i).splitY()*21.33,TAILLE_SPRITE,TAILLE_SPRITE);}
        if(tm <= 75 && tm >60){im_die_7.draw(renderer,jeu_sdl.tabEnnemi.at(i).splitX()*16,jeu_sdl.tabEnnemi.at(i).splitY()*21.33,TAILLE_SPRITE,TAILLE_SPRITE);}
        if(tm <= 100 && tm >75){im_die_8.draw(renderer,jeu_sdl.tabEnnemi.at(i).splitX()*16,jeu_sdl.tabEnnemi.at(i).splitY()*21.33,TAILLE_SPRITE,TAILLE_SPRITE);}

    }}
    inc++;

    for (unsigned int i = 0; i<jeu_sdl.tabBatDef.size();i++){
    im_batdef.draw(renderer,jeu_sdl.tabBatDef.at(i).splitX()*16,jeu_sdl.tabBatDef.at(i).splitY()*21.33,TAILLE_SPRITE*1.5,TAILLE_SPRITE*1.5);}

    if(Bat1){im_batdef.draw(renderer, pos1, pos2,TAILLE_SPRITE*1.5,TAILLE_SPRITE*1.5);}

    if(jeu_sdl.stockage.gold<300){im_Croix.draw(renderer,890,60,TAILLE_SPRITE*2,TAILLE_SPRITE*2);}
    if(jeu_sdl.stockage.gold<900){im_Croix.draw(renderer,890,140,TAILLE_SPRITE*2,TAILLE_SPRITE*2);}
    if(jeu_sdl.stockage.gold<1000){im_Croix.draw(renderer,890,210,TAILLE_SPRITE*2,TAILLE_SPRITE*2);}

}





void SDLSimple::sdlBoucle () {
    SDL_Event events;
	bool quit = false;
    bool menu = false;
    bool option = false;
    bool credit = false;
    bool Boutique = false;
    bool Bat1 = false;
    bool Bat1_2 = false;
    bool GameOver = false;
    bool Bat2 = false;
    bool Bat2_2 = false;


    float pos1,pos2;

    //Uint32 t = SDL_GetTicks(), nt;
    //Ennemi enm1;
    //Vect2 dir(0.5,0.5);
    //enm1.set_direction(dir);
    //jeu_sdl.tabEnnemi.clear();
    //jeu_sdl.tabEnnemi.push_back(enm1);

    BatimentDefense bat(TypeBatiment::Tourelle);

	// tant que ce n'est pas la fin ...
    Uint32 Time1,T1,Time2;

    int img = 1;

    Uint32 t = SDL_GetTicks(), nt;
    Uint32 init=SDL_GetTicks();
    
    bool vague1=false;
    int nbVague=0;

    while(!menu)
    {
        while (SDL_PollEvent(&events)) {
    if (events.type == SDL_QUIT) quit = true; // Si l'utilisateur a cliqué sur la croix de fermeture
    else if (events.type == SDL_KEYDOWN) { // Si une touche est enfoncée
        switch (events.key.keysym.scancode) {
            case SDL_SCANCODE_ESCAPE:
            case SDL_SCANCODE_Q:
                menu = true;
                break;
            default:
                break;
        }
    }


            switch(events.type){
        case SDL_WINDOWEVENT:
            if (events.window.event == SDL_WINDOWEVENT_CLOSE)
                quit != SDL_FALSE;
                break;
        case SDL_KEYDOWN:
            SDL_Log("+key");

            if (events.key.keysym.scancode == SDL_SCANCODE_W)
                SDL_Log("Scancode W");

            if (events.key.keysym.sym == SDLK_w)
                SDL_Log("Keycode W");

            if (events.key.keysym.sym == SDLK_z)
                SDL_Log("Keycode Z");

            break;
        case SDL_KEYUP: 
            SDL_Log("-key");
            break;
        case SDL_MOUSEMOTION: // Déplacement de souris
            SDL_Log("Mouvement de souris (%d %d) (%d %d)", events.motion.x, events.motion.y, events.motion.xrel, events.motion.yrel);
            
            break;
        case SDL_MOUSEBUTTONDOWN: // Click de souris 
            SDL_Log("+clic");
            if (events.motion.x >= 360 && events.motion.x <= 559 && events.motion.y >= 117 && events.motion.y <= 188){cout<<"BOUTON JOUER"<<endl; Mix_PlayChannel(-1,sound2,0); menu = true;}
            if (events.motion.x >= 360 && events.motion.x <= 559 && events.motion.y >= 257 && events.motion.y <= 326){cout<<"BOUTON OPTION"<<endl; Mix_PlayChannel(-1,sound2,0); option = true;}
            if (events.motion.x >= 360 && events.motion.x <= 559 && events.motion.y >= 395 && events.motion.y <= 466){cout<<"BOUTON CREDITS"<<endl; Mix_PlayChannel(-1,sound2,0); credit = true;}
            break;
        case SDL_MOUSEBUTTONUP: // Click de souris relâché
            SDL_Log("-clic");
            break;
        case SDL_MOUSEWHEEL: // Scroll de la molette
            SDL_Log("wheel");
            break;
        }
		}

        Time2 = SDL_GetTicks();

        if(!option){sdlMenu();
        SDL_RenderPresent(renderer);}
            
        while(option)
        {
            
            sdlOption(img);

            while (SDL_PollEvent(&events)) {
    if (events.type == SDL_QUIT) option = false; // Si l'utilisateur a cliqué sur la croix de fermeture
    else if (events.type == SDL_KEYDOWN) { // Si une touche est enfoncée
        switch (events.key.keysym.scancode) {
            case SDL_SCANCODE_ESCAPE:
            case SDL_SCANCODE_Q:
                option = false;
                break;
            default:
                break;
        }
    }


            switch(events.type){
        case SDL_WINDOWEVENT:
            if (events.window.event == SDL_WINDOWEVENT_CLOSE)
                quit != SDL_FALSE;
                break;
        case SDL_KEYDOWN:
            SDL_Log("+key");

            if (events.key.keysym.scancode == SDL_SCANCODE_W)
                SDL_Log("Scancode W");

            if (events.key.keysym.sym == SDLK_w)
                SDL_Log("Keycode W");

            if (events.key.keysym.sym == SDLK_z)
                SDL_Log("Keycode Z");

            break;
        case SDL_KEYUP: 
            SDL_Log("-key");
            break;
        case SDL_MOUSEMOTION: // Déplacement de souris
            SDL_Log("Mouvement de souris (%d %d) (%d %d)", events.motion.x, events.motion.y, events.motion.xrel, events.motion.yrel);
            
            break;
        case SDL_MOUSEBUTTONDOWN: // Click de souris 
            SDL_Log("+clic");
            if (events.motion.x >= 379 && events.motion.x <= 402 && events.motion.y >= 292 && events.motion.y <= 318){Mix_PlayChannel(-1,sound2,0); img = 1;}
            if (events.motion.x >= 379 && events.motion.x <= 402 && events.motion.y >= 337 && events.motion.y <= 361){Mix_PlayChannel(-1,sound2,0); img = 2;}
            if (events.motion.x >= 379 && events.motion.x <= 402 && events.motion.y >= 378 && events.motion.y <= 407){Mix_PlayChannel(-1,sound2,0); img = 3;}
            break;
        case SDL_MOUSEBUTTONUP: // Click de souris relâché
            SDL_Log("-clic");
            break;
        case SDL_MOUSEWHEEL: // Scroll de la molette
            SDL_Log("wheel");
            break;
        }
		}
        SDL_RenderPresent(renderer);

        }

        while(credit)
        {
            
            sdlCredit();

            while (SDL_PollEvent(&events)) {
    if (events.type == SDL_QUIT) credit = false; // Si l'utilisateur a cliqué sur la croix de fermeture
    else if (events.type == SDL_KEYDOWN) { // Si une touche est enfoncée
        switch (events.key.keysym.scancode) {
            case SDL_SCANCODE_ESCAPE:
            case SDL_SCANCODE_Q:
                credit = false;
                break;
            default:
                break;
        }
    }


            switch(events.type){
        case SDL_WINDOWEVENT:
            if (events.window.event == SDL_WINDOWEVENT_CLOSE)
                quit != SDL_FALSE;
                break;
        case SDL_KEYDOWN:
            SDL_Log("+key");

            if (events.key.keysym.scancode == SDL_SCANCODE_W)
                SDL_Log("Scancode W");

            if (events.key.keysym.sym == SDLK_w)
                SDL_Log("Keycode W");

            if (events.key.keysym.sym == SDLK_z)
                SDL_Log("Keycode Z");

            break;
        case SDL_KEYUP: 
            SDL_Log("-key");
            break;
        case SDL_MOUSEMOTION: // Déplacement de souris
            SDL_Log("Mouvement de souris (%d %d) (%d %d)", events.motion.x, events.motion.y, events.motion.xrel, events.motion.yrel);
            
            break;
        }
		}

        SDL_RenderPresent(renderer);

        }
    }
                //Son du jeu
            Mix_PlayChannel(-1,sound,0);
	while (!quit) {

        nt = SDL_GetTicks();
        if (nt-init>10000  ) {
            if(nbVague>2){jeu_sdl.declancherVague(nbVague-2);}
            nbVague=nbVague+1;
		    init=nt;
        }

        if (nt-t>60) {
            jeu_sdl.ajouteTempsMortEnnemis((nt-t)/1000); //cout<<nt-t<<" nt-t "<<endl;
            jeu_sdl.enleveEntDetruites();
            //jeu_sdl.BCAttaque();
            t = nt;

            jeu_sdl.deplacerEnnemis();
            jeu_sdl.faireDegatBat();
            
            // Affichage du timer
            Time1 = SDL_GetTicks() - Time2;
            T1 = (Time1/1000);
            TEMPS = T1;
            // cout<<T1<<endl;

            // tant qu'il y a des évenements à traiter (cette boucle n'est pas bloquante)
            while (SDL_PollEvent(&events)) {
                if (events.type == SDL_QUIT) quit = true;           // Si l'utilisateur a clique sur la croix de fermeture
                else if (events.type == SDL_KEYDOWN) {              // Si une touche est enfoncee
                    switch (events.key.keysym.scancode) {
                        case SDL_SCANCODE_ESCAPE:
                        case SDL_SCANCODE_Q:
                        quit = true;
                        break;
                    default: break;
                    }            
                }
                switch(events.type){
            case SDL_WINDOWEVENT:
                if (events.window.event == SDL_WINDOWEVENT_CLOSE)
                    quit != SDL_FALSE;
                    break;
            case SDL_MOUSEMOTION: // Déplacement de souris
                // SDL_Log("Mouvement de souris (%d %d) (%d %d)", events.motion.x, events.motion.y, events.motion.xrel, events.motion.yrel);
                break;
            case SDL_MOUSEBUTTONDOWN: // Click de souris 

                if (events.motion.x >= 900 && events.motion.x <= 941 && events.motion.y >= 15 && events.motion.y <= 35){Mix_PlayChannel(-1,sound2,0); Boutique = true;}
                break;
            }
            }

            while(Boutique)
            {
                sdlMenu2(Bat1, pos1, pos2);

            while (SDL_PollEvent(&events)) {
    if (events.type == SDL_QUIT) Boutique = false; // Si l'utilisateur a cliqué sur la croix de fermeture
    else if (events.type == SDL_KEYDOWN) { // Si une touche est enfoncée
        switch (events.key.keysym.scancode) {
            case SDL_SCANCODE_ESCAPE:
            case SDL_SCANCODE_Q:
                Boutique = false;
                break;
            default:
                break;
        }
    }


            switch(events.type){
        case SDL_WINDOWEVENT:
            if (events.window.event == SDL_WINDOWEVENT_CLOSE)
                quit != SDL_FALSE;
                break;

        case SDL_MOUSEMOTION: // Déplacement de souris
            pos1 = events.motion.x;
            pos2 = events.motion.y;
            
            break;
        case SDL_MOUSEBUTTONDOWN: // Click de souris 
            if (events.motion.x >= 900 && events.motion.x <= 941 && events.motion.y >= 15 && events.motion.y <= 35){Mix_PlayChannel(-1,sound2,0); Boutique = false;}
            if (events.motion.x >= 904 && events.motion.x <= 940 && events.motion.y >= 73 && events.motion.y <= 131){Mix_PlayChannel(-1,sound2,0); Bat1 = true;}
            if(!(events.motion.x >= 904 && events.motion.x <= 940 && events.motion.y >= 73 && events.motion.y <= 131) && Bat1 == true){Bat1_2 = true;}
            if (Bat1_2 && jeu_sdl.stockage.gold >= 300){                
                jeu_sdl.tabBatDef.push_back(bat);
                jeu_sdl.tabBatDef.at(jeu_sdl.tabBatDef.size()-1).setPosition(events.motion.x/16,events.motion.y/21.33);
                Bat1 = false;
                Bat1_2 = false;
                jeu_sdl.stockage.retirerRessource("gold",300);}
            break;
        }
		}
                

                SDL_RenderPresent(renderer);


            }      
        


            // on affiche le jeu sur le buffer cach�
            sdlAff();

            jeu_sdl.stockage.afficherRessources();
            for(int i = 0; i < jeu_sdl.TabFerme.size() ; i++){
                jeu_sdl.TabFerme.at(i).production(jeu_sdl.TabFerme.at(i).est_vivant());
            }

            // on permute les deux buffers (cette fonction ne doit se faire qu'une seule fois dans la boucle)
            SDL_RenderPresent(renderer);

            if(!jeu_sdl.BCest_vivant()){quit = true;}
        }

        

    }
    while(!GameOver){
            sdlAff();
            im_GameOver.draw(renderer,0,0,960,640);

            SDL_RenderPresent(renderer);


            while (SDL_PollEvent(&events)) {
    if (events.type == SDL_QUIT) GameOver = true; // Si l'utilisateur a cliqué sur la croix de fermeture
    else if (events.type == SDL_KEYDOWN) { // Si une touche est enfoncée
        switch (events.key.keysym.scancode) {
            case SDL_SCANCODE_ESCAPE:
            case SDL_SCANCODE_Q:
                GameOver = true;
                break;
            default:
                break;
        }
    }}
        }
}
