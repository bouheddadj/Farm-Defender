

#ifndef STOCKAGERESSOURCES_H
#define STOCKAGERESSOURCES_H

#include <string>
using namespace std;




class StockageRessources {
    private:


    public:
        StockageRessources();
                void ajouterRessource(string type, int quantite);
        void retirerRessource(string type, int quantite);
        void afficherRessources();

        int gold;
        int bois;
        int pierre;
        int nourriture;
};

#endif 