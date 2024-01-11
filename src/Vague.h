


#ifndef VAGUE_H
#define VAGUE_H

#include <vector>

#include <queue>
#include "Ennemi.h"

class Vague {
public:
    Vague();
    Ennemi getNextEnnemi();

private:
    std::queue<Ennemi> m_ennemis;
};



#endif 