#include "JeuModeTexte.h"
#include "BatimentDefense.h"
//#include "Jeu.h"
#include <iostream>
#include "StockageRessources.h"
#include "Ferme.h"
#include <ctime> // pour la fonction time()
#include <unistd.h>
#include "BaseCentrale.h"
#include "winTxt.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <cassert>
/*
#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif // WIN32
#include <conio.h>
#include "winTxt.h"
*/

#if _WIN32
#include <windef.h>
#include <winbase.h>
#include <wincon.h>
#include <windows.h>
#include <conio.h>
#else
#include <unistd.h>
#include <termios.h>
#include <unistd.h>
#endif

#include <stdio.h>
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>


using namespace std;

JeuModeTexte::JeuModeTexte(float largeur, float hauteur) : m_largeur(largeur), m_hauteur(hauteur) {
    m_carte = new char*[int(m_hauteur)];
    for (int i = 0; i < int(m_hauteur); i++) {
        m_carte[i] = new char[int(m_largeur)];
    }

    for (int i = 0; i < int(m_hauteur); i++) {
        for (int j = 0; j < int(m_largeur); j++) {
            if (i == 0 || j == 0 || i == int(m_hauteur)-1 || j == int(m_largeur)-1) {
                m_carte[i][j] = '+';
            } else {
                m_carte[i][j] = '.';
            }
        }
    }

    for (int i = (int(m_hauteur)/2)-2; i<=(int(m_hauteur)/2)+1; i++){
        for (int j = 0; j<int(m_largeur); j=j+(int(m_largeur)-1)){
            m_carte[i][j] = '#';
        }
    }

    for (int i = (int(m_hauteur)/2)-1;i <= int(m_hauteur)/2 ; i++){
        for (int j = 0;j<=int((m_largeur)/2)-2;j++){
            m_carte[i][j] = '>';
        }
        for (int j = (int(m_largeur)/2)+1;j<=int(m_largeur)-1;j++){
            m_carte[i][j] = '<';
        }
    }

    m_carte[int(m_hauteur)-1][(int(m_largeur)/2)-2] = '#';
    m_carte[int(m_hauteur)-1][(int(m_largeur)/2)+1] = '#';
    for (int i = int(m_hauteur)-1; i >= (int(m_hauteur)/2)+1; i--){
        for (int j = (int(m_largeur)/2)-1;j<=int(m_largeur)/2;j++){
            m_carte[i][j] = '^';
        }
    }
}

void JeuModeTexte::affObj(Vect2 post, int size, char car){
    bool condition_verifiee = true;
    if (size == 1) {
        if ((m_carte[int(post.y)][int(post.x)] == '.')||(m_carte[int(post.y)][int(post.x)] == 'Z') ||(m_carte[int(post.y)][int(post.x)] == '>') ||(m_carte[int(post.y)][int(post.x)] == '<') ){
            m_carte[int(post.y)][int(post.x)] = car;
        }
    }
    else if(size == 2){
        if (m_carte[int(post.y)][int(post.x)] == '.' && m_carte[int(post.y)][int(post.x+1)] == '.'){
            m_carte[int(post.y)][int(post.x)] = car;
            m_carte[int(post.y)][int(post.x+1)] = car;
        }
    } 
    else {
        for (int i = int(post.y); i < int(post.y) + (size/2); i++) {
            for (int j = int(post.x); j < int(post.x) + (size/2); j++) {
                if (m_carte[i][j] != '.') {
                    condition_verifiee = false;
                    break;
                }
            }
            if (!condition_verifiee) {
                break;
            }

            if (i == int(post.y) + (size/2)-1 && int(post.x) + (size/2)-1 && condition_verifiee) {
                for (int i = int(post.y); i < int(post.y) + (size/2); i++) {
                    for (int j = int(post.x); j < int(post.x) + (size/2); j++) {
                        m_carte[i][j] = car;
                    }
                }
            }
        }
    }    
} 


void JeuModeTexte::effacerObj(Vect2 post, int size){
    bool condition_verifiee = true;
   char car='.';
    if (size == 1) {
        if ((m_carte[int(post.y)][int(post.x)] == '.')||(m_carte[int(post.y)][int(post.x)] == 'Z') ||(m_carte[int(post.y)][int(post.x)] == '>') ||(m_carte[int(post.y)][int(post.x)] == '<') ){
            m_carte[int(post.y)][int(post.x)] = car;
        }
    }
    else if(size == 2){
        //if (m_carte[int(post.y)][int(post.x)] == '.' && m_carte[int(post.y)][int(post.x+1)] == '.'){
            m_carte[int(post.y)][int(post.x)] = car;
            m_carte[int(post.y)][int(post.x+1)] = car;
        //}
    } 
    else {
        for (int i = int(post.y); i < int(post.y) + (size/2); i++) {
            for (int j = int(post.x); j < int(post.x) + (size/2); j++) {
                if (m_carte[i][j] != '.') {
                    condition_verifiee = true;    //false
                    break;
                }
            }
            if (!condition_verifiee) {
                break;
            }

            if (i == int(post.y) + (size/2)-1 && int(post.x) + (size/2)-1 && condition_verifiee) {
                for (int i = int(post.y); i < int(post.y) + (size/2); i++) {
                    for (int j = int(post.x); j < int(post.x) + (size/2); j++) {
                        m_carte[i][j] = car;
                    }
                }
            }
        }
    }  
} 




JeuModeTexte::~JeuModeTexte() {
    for (int i = 0; i < m_hauteur; i++) {
        delete[] m_carte[i];
    }
    delete[] m_carte;


}

int JeuModeTexte::getLargeur() const {
    return m_largeur;
}

int JeuModeTexte::getHauteur() const {
    return m_hauteur;
}

void JeuModeTexte::afficher() const {
    for (int i = 0; i < m_hauteur; i++) {
        for (int j = 0; j < m_largeur; j++) {
            std::cout << m_carte[i][j];
        }
        std::cout << std::endl;
    }
}

void H(int h)
{
    if(h < 10){
        cout<<"0"<<h;
    }else{
    cout<<h;}
}

void M(int m)
{
    if(m < 10){
        cout<<"0"<<m;
    }else{
    cout<<m;}
}

void S(int s)
{
    if(s < 10){
        cout<<"0"<<s;
    }else{
    cout<<s;}
}

void JeuModeTexte::initTab(){
    for (int i = 0; i < int(m_hauteur); i++) {
        for (int j = 0; j < int(m_largeur); j++) {
            if (i == 0 || j == 0 || i == int(m_hauteur)-1 || j == int(m_largeur)-1) {
                m_carte[i][j] = '+';
            } else {
                m_carte[i][j] = '.';
            }
        }
    }

    for (int i = (int(m_hauteur)/2)-2; i<=(int(m_hauteur)/2)+1; i++){
        for (int j = 0; j<int(m_largeur); j=j+(int(m_largeur)-1)){
            m_carte[i][j] = '#';
        }
    }

    for (int i = (int(m_hauteur)/2)-1;i <= int(m_hauteur)/2 ; i++){
        for (int j = 0;j<=int((m_largeur)/2)-2;j++){
            m_carte[i][j] = '>';
        }
        for (int j = (int(m_largeur)/2)+1;j<=int(m_largeur)-1;j++){
            m_carte[i][j] = '<';
        }
    }

    m_carte[int(m_hauteur)-1][(int(m_largeur)/2)-2] = '#';
    m_carte[int(m_hauteur)-1][(int(m_largeur)/2)+1] = '#';
    for (int i = int(m_hauteur)-1; i >= (int(m_hauteur)/2)+1; i--){
        for (int j = (int(m_largeur)/2)-1;j<=int(m_largeur)/2;j++){
            m_carte[i][j] = '^';
        }
    }
}

void BoucleJeu(Jeu & j){

    //Jeu jeuUnique;
    //Taille : (50,25) / (40,20) / (60,30)
    JeuModeTexte map(60,30);
    StockageRessources stockage;

    Ferme ferme1(stockage);
    Ferme ferme2(stockage);
    Ferme ferme3(stockage);

    
    time_t startTime = time(NULL); // temps de départ
    time_t currentTime;
    int elapsedSeconds;
    int hours, minutes, seconds;
    
    WinTXT win (60,30);
    int c;

    do{
        termClear();
		
        c = win.getCh();



        // obtenir le temps actuel et calculer le temps écoulé depuis le début
        currentTime = time(NULL);
        elapsedSeconds = difftime(currentTime, startTime);

        // convertir en heures, minutes et secondes
        hours = elapsedSeconds / 3600;
        minutes = (elapsedSeconds % 3600) / 60;
        seconds = elapsedSeconds % 60;

        for (unsigned int i = 0; i<j.tabBatDef.size();i++){
        switch (j.tabBatDef.at(i).getType()){
            case TypeBatiment::Tourelle:
                j.tabBatDef.at(i).setSize(4);
                j.tabBatDef.at(i).setCarac('.');
                break;
            case TypeBatiment::Canon:
                j.tabBatDef.at(i).setSize(4); //2
                j.tabBatDef.at(i).setCarac('.'); 
                break;            
        }

        //map.effacerObj(j.tabBatDef.at(i).getPosition(),j.tabBatDef.at(i).getSize());


    }
    	//map.affObj(j.tabEnnemi.at(0).get_position(),1,'.');
    	//map.affObj(j.tabEnnemi.at(1).get_position(),1,'.');
    	//map.affObj(j.tabEnnemi.at(2).get_position(),1,'.');


        //j.enleveEntDestruites();
    
        //    map.affObj(j.tabEnnemi.at(0).get_position(),1,'.');
      
        j.deplacerEnnemis();
     //   map.affObj(j.tabEnnemi.at(0).get_position(),1,'Z');

	    map.affObj(j.tabEnnemi.at(0).get_position(),1,'Z');
    	map.affObj(j.tabEnnemi.at(1).get_position(),1,'Z');
    	map.affObj(j.tabEnnemi.at(2).get_position(),1,'Z');


        for (unsigned int i = 0; i<j.tabBatDef.size();i++){
        switch (j.tabBatDef.at(i).getType()){
            case TypeBatiment::Tourelle:
                j.tabBatDef.at(i).setSize(4);
                j.tabBatDef.at(i).setCarac('T');
                break;
            case TypeBatiment::Canon:
                j.tabBatDef.at(i).setSize(4); //2
                j.tabBatDef.at(i).setCarac('C'); 
                break;            
        }
        map.affObj(j.tabBatDef.at(i).getPosition(),j.tabBatDef.at(i).getSize(),j.tabBatDef.at(i).getCarac());
        }
        cout<<"POS : "<<j.BCpos.x<<" "<<j.BCpos.y<<endl;
        cout<<"char : "<<j.BCm_carac<<endl;
        map.affObj(j.BCpos,2,j.BCm_carac);



        //afficher toutes les entites

        map.afficher();
        map.initTab();


        // afficher le timer
        cout << "Temps écoulé : ";
        H(hours);
        cout << ":";
        M(minutes);
        cout << ":";
        S(seconds);
        cout << endl;

        
        /*ferme1.degat(1);
        ferme2.degat(2);
        ferme3.degat(3);*/

        //BC.degat(50);
        
        ferme1.production(ferme1.est_vivant());
        ferme2.production(ferme2.est_vivant());
        ferme3.production(ferme3.est_vivant());

        //BC.production(BC.est_vivant());
        
        //cout << "                                       Ressources actuel :" << endl;
        stockage.afficherRessources();
        
        
        /*cout << "****************************Gestion Ennemi's" <<endl;

        j.tabEnnemi.at(0).afficher();*/

        cout << "****************************Gestion BatimentDefense's" <<endl;

        cout << "Batiment N° " << 0 <<endl;
       

	    cout<<" --- STATUS BATIMENTS --- "<<endl;
        //j.tabBatDef.at(0).afficher();

        
        //j.tabBatDef.at(1).afficher();

        if (c == 'm'){
            char ch;
            int x,y;
            cout << "Menu: " <<endl;
            cout << "1.Pour construire un batiment" <<endl;
            cout << "2.Pour quitter" <<endl;
            cin >> ch;
            switch (ch){
                case '1':
                {
                    cout << j.tabBatDef.size() <<endl;  
                    cout << "Donner la coord x: "; cin >> x; cout << endl;
                    cout << "Donner la coord y: "; cin >> y;
                    BatimentDefense bat(TypeBatiment::Tourelle);
                    j.tabBatDef.push_back(bat); 
                    j.tabBatDef.at(j.tabBatDef.size()-1).setPosition(y,x);
                    map.affObj(j.tabBatDef.at(j.tabBatDef.size()-1).getPosition(),4,'T');
                    break;
                }
                case '2':
                {
                    c = 'q';
                    break;
                }
                default:
                {
                    cout << "MENU ERROR" <<endl;
                    break;
                }
            }
        }
        
        usleep(100000);
    }while (c != 'q');
}

int main(){

    termClear();
    Jeu jeuUnique;
    //Taille : (50,25) / (40,20) / (60,30)
    JeuModeTexte map(60,30);

    // Création d'un stockage de ressources
    StockageRessources stockage;

    // BaseCentrale base(stockage);

    jeuUnique.BCsetPos(((map.getLargeur()/2)+0.5)-1,((map.getHauteur()*map.getHauteur())/50)-(map.getHauteur()/2)+11);
    // map.affObj(jeuUnique.BCpos,jeuUnique.BCm_size,jeuUnique.BCm_carac);

    /*
    Vect2 pos;
    pos.x = 0;
    pos.y = 0;
    Ennemi zombiTest;
    */

    cout << "Ressources initiales :" << endl;
    stockage.afficherRessources();

    BoucleJeu(jeuUnique);

    return 0;
}
