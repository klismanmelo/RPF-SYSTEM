#ifndef PERSONAGEM_H
#define PERSONAGEM_H

#include <string>
#include <vector>
#include "Habilidade.hpp"

class Personagem {
private:
    std::string nome;
    int vida;
    int ataque;
    int defesa;
    int pontosEsforco;
    std::vector<Habilidade> habilidades;

public:
    Personagem(const std::string& nome, int vida, int ataque, int defesa, int pontosEsforco);

    void adicionarHabilidade(const Habilidade& habilidade);
    int getVida() const;
    void setVida(int vida);
    int getAtaque() const;
    int getDefesa() const;
    int getPontosEsforco() const;
    void setPontosEsforco(int pontosEsforco);
    std::string getNome() const;
    const std::vector<Habilidade>& getHabilidades() const;

    void usarHabilidade(int indiceHabilidade, Personagem& alvo, int turnoAtual);
    void ataqueBasico(Personagem& alvo);
    int encontrarHabilidadeDisponivel(int turnoAtual);
    void exibir() const;
};

#endif // PERSONAGEM_H
