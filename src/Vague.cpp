#include "Vague.h"

using namespace std;

Vague::Vague() {
    // Vague 1
    for (int i = 0; i < 5; i++) {
        m_ennemis.push(Ennemi(TypeEnnemi::a));
    }

    // Vague 2
    for (int i = 0; i < 10; i++) {
        m_ennemis.push(Ennemi(TypeEnnemi::b));
    }

    // Vague 3
    for (int i = 0; i < 3; i++) {
        m_ennemis.push(Ennemi(TypeEnnemi::c));
    }
}

Ennemi Vague::getNextEnnemi() {
    Ennemi ennemi = m_ennemis.front();
    m_ennemis.pop();
    m_ennemis.push(ennemi); // Ajoute l'ennemi en fin de file pour faire tourner les vagues
    return ennemi;
}
