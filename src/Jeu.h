    /**
    @brief Description brève du fichier Jeu.h
    Description détaillée du fichier Jeu.h
    @author Ahmed/Alexandre/Sara
    @file Image.h
    @version 1.0
    @date 01/05/2023
    */    

    #ifndef JEU_H
    #define JEU_H

    #include "BatimentDefense.h"
    #include "Ennemi.h"
    #include "StockageRessources.h"
    #include "Ferme.h"
    #include "BaseCentrale.h"
    #include <iostream>
    #include <vector>

    

    

    /**
@brief Classe représentant un jeu de défense
*/
class Jeu {
public:
StockageRessources stockage; /**< Stockage des ressources du jeu */

vector<Ennemi> tabEnnemi; /**< Tableau des ennemis présents sur la carte */

vector<BatimentDefense> tabBatDef; /**< Tableau des bâtiments de défense présents sur la carte */

vector<Ferme> TabFerme; /**< Tableau des fermes présentes sur la carte */

float jeu_largeur; /**< Largeur de la carte */

float jeu_hauteur; /**< Hauteur de la carte */

/**
@brief Vérifie si un ennemi est proche de la base centrale et calcule la distance et la cible la plus proche
@param enboucle Ennemi en cours de traitement
@param distance Distance minimale entre la base centrale et un ennemi
@param cible Position de l'ennemi le plus proche de la base centrale
*/
void baseCentrale_proche_ennemi(Ennemi & enboucle, float & distance,Vect2 & cible );

/**
@brief Vérifie si un bâtiment de défense est proche d'un ennemi et calcule la distance et la cible la plus proche
@param enboucle Ennemi en cours de traitement
@param initBat Indique si on doit initialiser la distance minimale
@param distanceMinimale Distance minimale entre le bâtiment de défense et un ennemi
@param cible Position de l'ennemi le plus proche du bâtiment de défense
@param indiceMinDistance Indice du bâtiment de défense le plus proche de l'ennemi
*/
void bat_proche_ennemi(Ennemi & enboucle, bool & initBat,float & distanceMinimale,Vect2 & cible,long unsigned int & indiceMinDistance );

/**
@brief Vérifie si une ferme est proche d'un ennemi et calcule la distance et la cible la plus proche
@param enboucle Ennemi en cours de traitement
@param initFerme Indique si on doit initialiser la distance minimale
@param distanceMinimale Distance minimale entre la ferme et un ennemi
@param cible Position de l'ennemi le plus proche de la ferme
@param indiceMinDistance Indice de la ferme la plus proche de l'ennemi
*/
void ferme_proche_ennemi(Ennemi & enboucle, bool & initFerme,float & distanceMinimale,Vect2 & cible, long unsigned int & indiceMinDistance);

/**
@brief Déplace tous les ennemis présents sur la carte
*/
void deplacerEnnemis();

/**
@brief Supprime tous les entités détruites du jeu
*/
void enleveEntDetruites();

/**
@brief Ajoute un temps mort pour les ennemis
@param tempsMort Temps mort en secondes
*/
void ajouteTempsMortEnnemis(float tempsMort);

/**
@brief Constructeur par défaut: Initialise les dimensions de la carte à 0 et les tableaux d'entités vides
*/
Jeu();

    /**
    @brief Destructeur de la classe Jeu
    Libère la mémoire allouée pour les ennemis et les bâtiments de défense
    */
    ~Jeu();

    /**
    @brief Place un nombre donné d'ennemis d'un certain type sur la carte
    @param type_en Type d'ennemi à placer
    @param effectif Nombre d'ennemis à placer
    */
    void placerEnnemis(Type_ennemi type_en, int effectif);

    /**
    @brief Trouve l'ennemi le plus proche d'un bâtiment de défense et met à jour les paramètres d'initialisation et l'indice de la distance minimale
    @param batiment Bâtiment de défense à protéger
    @param initEnne Booléen indiquant si un ennemi a été initialisé
    @param indiceMinDistance Indice de l'ennemi le plus proche du bâtiment
    */
    void ennemi_vivant_proche_bat(BatimentDefense batiment, bool& initEnne, long unsigned int& indiceMinDistance);

    /**
    @brief Applique les dégâts infligés par les bâtiments de défense aux ennemis proches
    */
    void faireDegatBat();

    /**
    @brief Fonction qui gère la production de nouveaux bâtiments de défense
    @param est_vivant Booléen indiquant si le bâtiment est en vie
    */
    void BCproduction(bool est_vivant);

    /**
    @brief Fonction qui gère les dégâts infligés aux bâtiments de défense
    @param degat Dégât infligé
    */
    void BCdegat(int degat);

    /**
    @brief Fonction qui vérifie si le bâtiment de défense est vivant
    @return Booléen indiquant si le bâtiment est en vie
    */
    bool BCest_vivant();

    /**
    @brief Caractère représentant le bâtiment de défense
    */
    char BCm_carac;

    /**
    @brief Taille du bâtiment de défense
    */
    int BCm_size;

    /**
    @brief Dégât infligé par le bâtiment de défense
    */
    float BCfloatdeg;

    /**
    @brief Position du bâtiment de défense
    */
    Vect2 BCpos;

    /**
    @brief Modifie la position du bâtiment de défense
    @param x Coordonnée x de la nouvelle position
    @param y Coordonnée y de la nouvelle position
    */
    void BCsetPos(float x, float y);

    /**
    @brief Récupère la position actuelle du bâtiment de défense
    @return Vecteur contenant les coordonnées x et y du bâtiment
    */
    Vect2 BCgetPos();

    /**
    @brief Déclenche une vague d'attaque d'ennemis
    @param num_vague Numéro de la vague à déclencher
    */
    void declancherVague(int num_vague);

    /**
    @brief Fonction qui gère l'attaque du bâtiment de défense
    */
    void BCAttaque();

        private:
        
        int BCm_pointsDeVie;

    };

    #endif