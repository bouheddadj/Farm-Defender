/**
@brief Description brève du fichier Ferme.h
Description détaillée du fichier Ferme.h
@author Alexandre
@file Ferme.h
@version 1.0
@date 07/03/2023
*/
/**
@brief Classe permettant la gestion des fermes.
*/

#ifndef FERME_H
#define FERME_H

#include "StockageRessources.h"
#include "Vect2.h"

using namespace std;

class Ferme {
public:

    /**
    @brief Constructeur par défaut: Initialise la position de base a 0, définie les points de vie a 20 et le connecte au stockage de la classe StockageRessources.
    */
    Ferme(StockageRessources& stockage);

    //Ferme(StockageRessources& stockage, int pointsDeVie, Vect2 posi);

    /**
    @brief Fonction production qui incrémente les ressources de 2 a chaques appels de cette fonction seulement si la Ferme est vivante.
    @param Booléen : est_vivant renvoie true si la ferme est toujour vivante(vie>0) false sinon.
    */
    void production(bool est_vivant);

    /**
    @brief Fonction degat qui permet de soustraire les dégats passer en paramètre et la vie de la Ferme.
    @param Entier : degat les dégats a soustraire a la vie.
    */
    void degat(int degat);

    /**
    @brief Fonction qui renvoie true si la ferme est vivante.
    */
   bool est_vivant();
   
   /**
    @brief Fonction qui va donner vie a une ferme.
    @param Vect2 : vecteur de position de la ferme.
   */
   void creation(Vect2 posi);

   /**
    @param StockageRessources : m_stockage le stockage des ressources que produiront la Ferme.
    */
    //StockageRessources m_stockage;
    StockageRessources* m_stockage;

    /**
    @brief Accesseur pour position de la ferme
    @return valeur de type Vect2
    */
   Vect2 get_position();


private:

    

    /**
    @param Entier : m_pointsDeVie la vie de la Ferme.
    */
    int m_pointsDeVie;

    /**
    @param Vect2 : pos la position de la Ferme.
    */
    Vect2 pos;
};

#endif // FERME_H