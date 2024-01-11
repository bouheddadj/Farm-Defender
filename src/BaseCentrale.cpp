/**
@brief Description brève du fichier BaseCentrale.cpp
Description détaillée du fichier BaseCentrale.cpp
@author Alexandre
@file BaseCentrale.cpp
@version 1.0
@date 14/03/2023
*/

#include "BaseCentrale.h"
#include <iostream>

using namespace std;

BaseCentrale::BaseCentrale(StockageRessources& stockage){
    m_stockage = &stockage;
    m_pointsDeVie=200;
    m_size = 4;
    m_carac = 'O';
    pos.x = 0;
    pos.y = 0;
}

void BaseCentrale::production(bool est_vivant)
{
    if(est_vivant){
    m_stockage->ajouterRessource("gold", 10);
    m_stockage->ajouterRessource("pierre", 10);
    m_stockage->ajouterRessource("bois", 10);
    m_stockage->ajouterRessource("nourriture", 10);}
}

void BaseCentrale::degat(int degat)
{
    m_pointsDeVie -= degat;
}

bool BaseCentrale::est_vivant()
{
    if(m_pointsDeVie<=0){
        return false;
    }else{return true;}
}

void BaseCentrale::setPos (int x, int y){
    pos.x = x;
    pos.y = y;
}

Vect2 BaseCentrale::getPos(){
    return pos;
}
