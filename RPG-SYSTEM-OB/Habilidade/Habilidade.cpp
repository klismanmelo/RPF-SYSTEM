#include "Habilidade.hpp"

Habilidade::Habilidade(const std::string& nome, int pontosEsforco, int dadosDano, int tipoDado, int cooldown)
    : nome(nome), pontosEsforco(pontosEsforco), dadosDano(dadosDano), tipoDado(tipoDado), cooldown(cooldown), ultimoUso(-cooldown) {}

std::string Habilidade::getNome() const {
    return nome;
}

int Habilidade::getPontosEsforco() const {
    return pontosEsforco;
}

int Habilidade::getDadosDano() const {
    return dadosDano;
}

int Habilidade::getTipoDado() const {
    return tipoDado;
}

int Habilidade::getCooldown() const {
    return cooldown;
}

int Habilidade::getUltimoUso() const {
    return ultimoUso;
}

void Habilidade::setUltimoUso(int turno) {
    ultimoUso = turno;
}
