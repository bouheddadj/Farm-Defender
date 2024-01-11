/**
@brief Description brève du fichier BatimentDefense.h
Description détaillée du fichier BatimentDefense.h
@author Ahmed/Alexandre/Sara
@file Image.h
@version 1.0
@date 01/05/2023
*/
    
    #ifndef BATIMENTDEFENSE_H
    #define BATIMENTDEFENSE_H

    #include "Vect2.h"
    #include <iostream>



/**
@brief Enumération représentant les types de bâtiments de défense disponibles
*/
enum class TypeBatiment {
Tourelle, ///< Tourelle: bâtiment de défense à distance, tire des projectiles
Canon ///< Canon: bâtiment de défense au corps-à-corps, inflige des dégâts de zone
};

/**
@brief Classe représentant un bâtiment de défense dans un jeu
*/
class BatimentDefense
{
public:

/**
@brief Constructeur par défaut: Initialise les attributs du bâtiment à des valeurs par défaut
*/
BatimentDefense();

/**
@brief Constructeur avec paramètre
Initialise les attributs du bâtiment avec les valeurs passées en paramètre
@param type Type de bâtiment
*/
BatimentDefense(TypeBatiment type);

/**
@brief Destructeur de la classe BatimentDefense
Libère la mémoire allouée pour l'objet
*/
~BatimentDefense();

/**
@brief Accesseur pour l'attribut m_type
@return Type de bâtiment
*/
TypeBatiment getType() const;

/**
@brief Accesseur pour l'attribut m_niveau
@return Niveau du bâtiment
*/
int getNiveau() const;

/**
@brief Accesseur pour l'attribut m_pointsDeVie
@return Points de vie du bâtiment
*/
int getPointsDeVie() const;

/**
@brief Accesseur pour l'attribut m_degats
@return Dégâts infligés par le bâtiment
*/
int getDegats() const;

/**
@brief Accesseur pour l'attribut m_vitesse
@return Vitesse d'attaque du bâtiment
*/
float getVitesseAttaque() const;

/**
@brief Accesseur pour l'attribut m_rayonAttaque
@return Rayon d'attaque du bâtiment
*/
float getRayonAttaque() const;

/**
@brief Accesseur pour l'attribut m_position
@return Vecteur représentant la position du bâtiment sur la carte
*/
Vect2 getPosition() const;

/**
@brief Accesseur pour l'attribut m_size
@return Taille du bâtiment
*/
int getSize() const;

/**
@brief Accesseur pour l'attribut m_carac
@return Caractère représentant le bâtiment sur la carte
*/
char getCarac() const;

/**
@brief Mutateur pour l'attribut m_position
@param x Coordonnée X de la position du bâtiment sur la carte
@param y Coordonnée Y de la position du bâtiment sur la carte
*/
void setPosition(int x, int y);

/**
@brief Mutateur pour l'attribut m_size
@param s Taille du bâtiment
*/
void setSize(int s);

/**
@brief Mutateur pour l'attribut m_carac
@param c Caractère représentant le bâtiment sur la carte
*/
void setCarac(char c);

/**
@brief Mutateur pour l'attribut m_estDetruit
@param estDetruit Booléen indiquant si le bâtiment a été
*/
void setDetruit (bool estDetruit);

/**
    @brief Méthode pour améliorer le niveau du bâtiment
    Incrémente le niveau du bâtiment et met à jour ses caractéristiques
    */
    void upgrade();

    /**
    @brief Méthode pour augmenter le niveau du bâtiment avec des paramètres personnalisés
    Modifie les caractéristiques du bâtiment en fonction des paramètres passés
    @param pointsDeVie Points de vie du bâtiment
    @param degats Dégâts infligés par le bâtiment
    @param vitesseAttaque Vitesse d'attaque du bâtiment
    @param rayonAttaque Rayon d'attaque du bâtiment
    */
    void augmenterNiveau(int pointsDeVie, int degats, float vitesseAttaque, float rayonAttaque);

    /**
    @brief Méthode pour afficher les caractéristiques du bâtiment
    Affiche les caractéristiques du bâtiment à l'écran
    */
    void afficher();

    /**
    @brief Méthode pour enlever des points de vie au bâtiment
    Diminue les points de vie du bâtiment en fonction du nombre de points passés en paramètre
    @param points_enleves Nombre de points de vie à enlever
    */
    void enleverPointsVie(int points_enleves);

    /**
    @brief Accesseur pour savoir si le bâtiment est détruit
    @return True si le bâtiment est détruit, false sinon
    */
    bool getDetruit ();

    /**
    @brief Méthode pour diviser la position X du bâtiment en deux
    @return La position X divisée par deux
    */
    float splitX();

    /**
    @brief Méthode pour diviser la position Y du bâtiment en deux
    @return La position Y divisée par deux
    */
    float splitY();

    /**
    @brief Accesseur pour obtenir la position X du bâtiment
    @return La position X du bâtiment
    */
    float getX () const;

    /**
    @brief Accesseur pour obtenir la position Y du bâtiment
    @return La position Y du bâtiment
    */
    float getY () const;


private:
    int m_size; /**< Taille du bâtiment */
    char m_carac; /**< Caractère représentant le bâtiment */
    TypeBatiment m_type; /**< Type de bâtiment */
    Vect2 m_position; /**< Position du bâtiment */
    bool m_estDetruit; /**< Indique si le bâtiment est détruit ou non */
    float m_vitesse; /**< Vitesse de tir du bâtiment */
    int m_degats; /**< Dégâts infligés par le bâtiment */
    int m_pointsDeVie; /**< Points de vie du bâtiment */
    int m_niveau; /**< Niveau du bâtiment */
    float m_rayonAttaque; /**< Rayon d'attaque du bâtiment */
};
#endif

    


