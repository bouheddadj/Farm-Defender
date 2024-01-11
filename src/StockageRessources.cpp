#include "StockageRessources.h"

#include <string>

#include <iostream>

using namespace std;

StockageRessources::StockageRessources(){
    gold = 0;
    bois = 0;
    pierre = 0;
    nourriture = 0;
}

/*StockageRessources::StockageRessources(int Rgold, int Rbois, int Rpierre, int Rnourriture) {
    gold = Rgold;
    bois = Rbois;
    pierre = Rpierre;
    nourriture = Rnourriture;
}*/

void StockageRessources::ajouterRessource(string type, int quantite) {
    if (type == "gold") {
        gold += quantite;
    } else if (type == "bois") {
        bois += quantite;
    } else if (type == "pierre") {
        pierre += quantite;
    } else if (type == "nourriture") {
        nourriture += quantite;
    }
}

void StockageRessources::retirerRessource(string type, int quantite) {
    if (type == "gold") {
        gold -= quantite;
    } else if (type == "bois") {
        bois -= quantite;
    } else if (type == "pierre") {
        pierre -= quantite;
    } else if (type == "nourriture") {
        nourriture -= quantite;
    }
}

void StockageRessources::afficherRessources() {
    cout << "       ----- MENU -----      "<< endl;
    cout << "        gold : " << gold << endl;
    cout << "        Bois : " << bois << endl;
    cout << "        Pierre : " << pierre << endl;
    cout << "        Nourriture : " << nourriture << endl;
}


