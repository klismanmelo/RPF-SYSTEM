#ifndef COMBATE_H
#define COMBATE_H

#include "Personagem.hpp"

class Combate {
private:
    Personagem* p1;
    Personagem* p2;
    int turnoAtual;
    const int MAX_TURNOS = 100;

public:
    Combate(Personagem* p1, Personagem* p2);

    void iniciarCombate();
};

#endif // COMBATE_H
