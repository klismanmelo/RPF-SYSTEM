#include "Combate.hpp"
#include <iostream>
#include <ctime>
#include "Dados.hpp"

Combate::Combate(Personagem* p1, Personagem* p2)
    : p1(p1), p2(p2), turnoAtual(1) {}

void Combate::iniciarCombate() {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    while (turnoAtual <= MAX_TURNOS) {
        std::cout << "\n--- Turno " << turnoAtual << " ---\n";
        
        // Personagem 1 ataca
        int habilidadeIndex = p1->encontrarHabilidadeDisponivel(turnoAtual);
        if (habilidadeIndex != -1) {
            p1->usarHabilidade(habilidadeIndex, *p2, turnoAtual);
        } else {
            p1->ataqueBasico(*p2);
        }

        // Verificar se o Personagem 2 ainda está vivo
        if (p2->getVida() <= 0) {
            std::cout << p1->getNome() << " venceu!\n";
            break;
        }

        // Personagem 2 ataca
        habilidadeIndex = p2->encontrarHabilidadeDisponivel(turnoAtual);
        if (habilidadeIndex != -1) {
            p2->usarHabilidade(habilidadeIndex, *p1, turnoAtual);
        } else {
            p2->ataqueBasico(*p1);
        }

        // Verificar se o Personagem 1 ainda está vivo
        if (p1->getVida() <= 0) {
            std::cout << p2->getNome() << " venceu!\n";
            break;
        }

        turnoAtual++;
    }

    if (turnoAtual > MAX_TURNOS) {
        std::cout << "O combate terminou em empate após " << MAX_TURNOS << " turnos.\n";
    }
}
