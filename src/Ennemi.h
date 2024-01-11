/**
@brief Description brève du fichier Ennemi.h
Description détaillée du fichier Ennemi.h
@author Ahmed/Alexandre/Sara
@file Image.h
@version 1.0
@date 01/05/2023
*/

#ifndef ENNEMI_H
#define ENNEMI_H

#include "Vect2.h"
#include <stdlib.h>





/**
 * @brief Énumération des types d'ennemis possibles
 */
enum Type_ennemi
{
    zombi,
    z_infectieu,
    z_berserker,
    pillard
};

/**
 * @brief Classe représentant un ennemi dans un jeu vidéo
 */
class Ennemi
{
private:
    bool statut; /**< Statut de l'ennemi (vivant ou mort) */
    Type_ennemi type_en; /**< Type de l'ennemi */
    int sante; /**< Santé de l'ennemi */
    int degat; /**< Dégâts infligés par l'ennemi */
    float vitesse; /**< Vitesse de déplacement de l'ennemi */
    Vect2 direction; /**< Direction de déplacement de l'ennemi */
    Vect2 position; /**< Position de l'ennemi */
    float temps_mort; /**< Temps pendant lequel l'ennemi est mort */

public:
    /**
     * @brief Calcule le point de division en X de l'ennemi
     * @return La valeur du point de division en X
     */
    float splitX();

    /**
     * @brief Calcule le point de division en Y de l'ennemi
     * @return La valeur du point de division en Y
     */
    float splitY();

    /**
     * @brief Constructeur par défaut de la classe Ennemi
     * Initialise les attributs de l'ennemi à des valeurs par défaut
     */
    Ennemi();

    /**
     * @brief Destructeur de la classe Ennemi
     * Libère la mémoire allouée pour l'objet Ennemi
     */
    ~Ennemi();

    /**
     * @brief Constructeur de la classe Ennemi avec paramètres
     * Initialise les attributs de l'ennemi avec les valeurs passées en paramètres
     * @param typeEnnemi Type de l'ennemi
     */
    Ennemi(Type_ennemi typeEnnemi);

    /**
     * @brief Déplace l'ennemi dans la direction courante
     */
    void deplacer();

    /**
     * @brief Enlève des points de santé à l'ennemi
     * @param points_enleves Le nombre de points de santé à enlever
     */
    void enleverSante(int points_enleves);

    /**
     * @brief Récupère le nombre de dégâts infligés par l'ennemi
     * @return Le nombre de dégâts infligés par l'ennemi
     */
    int get_degat();

    /**
     * @brief Récupère le type de l'ennemi
     * @return Le type de l'ennemi
     */
    Type_ennemi getType() const;

    /**
     * @brief Affiche les informations de l'ennemi dans la console
     */
    void afficher();

    /**
     * @brief Définit la direction de l'ennemi
     * @param dir La nouvelle direction de l'ennemi
     */
    void set_direction(Vect2 dir);

    /**
     * @brief Récupère la position de l'ennemi
     * @return La position de l'ennemi
     */
    Vect2 get_position();

    /**
    @brief Modifie la position de l'ennemi
    @param posi Nouvelle position de l'ennemi
    */
    void set_pos(Vect2 posi);

    /**
    @brief Obtient la santé actuelle de l'ennemi
    @return Santé de l'ennemi
    */
    int get_sante ();

    /**
    @brief Obtient le statut de vie/death de l'ennemi
    @return true si l'ennemi est en vie, false sinon
    */
    bool get_statut();

    /**
    @brief Obtient le temps de mort de l'ennemi
    @return Temps de mort de l'ennemi
    */
    float get_temps_mort();

    /**
    @brief Ajoute du temps de mort à l'ennemi
    @param tempsMort Temps de mort à ajouter à l'ennemi
    */
    void add_temps_mort(float tempsMort);

    };

    #endif 