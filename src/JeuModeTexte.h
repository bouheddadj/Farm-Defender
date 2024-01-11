    

    #ifndef JEUMODETEXTE_H
    #define JEUMODETEXTE_H

    #include "Vect2.h"
    #include "Jeu.h"

    
    class JeuModeTexte {
    private:
        float m_largeur, m_hauteur;
        char** m_carte;
        char* win;      //!< \brief stocke le contenu de la fen�tre dans un tableau 1D mais on y accede en 2D

    public:
 
        JeuModeTexte(float largeur, float hauteur);
        void affObj(Vect2 post, int size, char car);
        void effacerObj(Vect2 post, int size);
        void initTab();
        ~JeuModeTexte();
        void afficher() const;
        int getHauteur() const;
        int getLargeur() const;
        void BoucleJeu(Jeu &j);

    };

    

    #endif