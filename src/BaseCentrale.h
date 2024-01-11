/**
@brief Description brève du fichier BaseCentral.h
Description détaillée du fichier BaseCentral.h
@author Ahmed/Alexandre/Sara
@file Image.h
@version 1.0
@date 01/05/2023
*/

#ifndef BaseCentrale_H
#define BaseCentrale_H

#include "StockageRessources.h"
#include "Vect2.h"

using namespace std;


/**
@brief Classe représentant une base centrale dans un jeu
*/
class BaseCentrale {
public:

/**
@brief Constructeur avec paramètre
Initialise une base centrale avec un objet StockageRessources passé en référence, qui sera utilisé pour stocker les ressources de la base
@param stockage Un objet StockageRessources référencé
*/
BaseCentrale(StockageRessources& stockage);

/**
@brief Fonction de production de ressources
Permet à la base de produire des ressources en fonction de son état de vie et du stockage de ressources associé
@param est_vivant Un booléen indiquant si la base est en vie
*/
void production(bool est_vivant);

/**
@brief Fonction de gestion des dégâts subis par la base
Réduit les points de vie de la base en fonction des dégâts subis en paramètre
@param degat Un entier représentant les dégâts subis par la base
*/
void degat(int degat);

/**
@brief Fonction indiquant si la base est en vie
@return Un booléen indiquant si la base est en vie
*/
bool est_vivant();

/**
@brief Attribut représentant la caractéristique de la base
*/
int m_carac;

/**
@brief Attribut représentant la taille de la base
*/
int m_size;

/**
@brief Attribut représentant la position de la base dans l'espace de jeu
*/
Vect2 pos;

/**
@brief Fonction de modification de la position de la base dans l'espace de jeu
@param x La coordonnée x de la nouvelle position
@param y La coordonnée y de la nouvelle position
*/
void setPos (int x, int y);

/**
@brief Fonction de récupération de la position de la base dans l'espace de jeu
@return Un objet Vect2 représentant la position de la base dans l'espace de jeu
*/
Vect2 getPos();


private:
/**
@brief Pointeur vers l'objet StockageRessources associé à la base
*/
StockageRessources* m_stockage;

/**
@brief Attribut représentant les points de vie de la base
*/
int m_pointsDeVie;


};

#endif