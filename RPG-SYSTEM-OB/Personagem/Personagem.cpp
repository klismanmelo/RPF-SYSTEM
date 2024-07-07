#include "Personagem.hpp"
#include <iostream>
#include "Dados.hpp"

Personagem::Personagem(const std::string& nome, int vida, int ataque, int defesa, int pontosEsforco)
    : nome(nome), vida(vida), ataque(ataque), defesa(defesa), pontosEsforco(pontosEsforco) {}

void Personagem::adicionarHabilidade(const Habilidade& habilidade) {
    if (habilidades.size() < 5) {
        habilidades.push_back(habilidade);
    }
}

int Personagem::getVida() const {
    return vida;
}

void Personagem::setVida(int vida) {
    this->vida = vida;
}

int Personagem::getAtaque() const {
    return ataque;
}

int Personagem::getDefesa() const {
    return defesa;
}

int Personagem::getPontosEsforco() const {
    return pontosEsforco;
}

void Personagem::setPontosEsforco(int pontosEsforco) {
    this->pontosEsforco = pontosEsforco;
}

std::string Personagem::getNome() const {
    return nome;
}

const std::vector<Habilidade>& Personagem::getHabilidades() const {
    return habilidades;
}

void Personagem::usarHabilidade(int indiceHabilidade, Personagem& alvo, int turnoAtual) {
    if (indiceHabilidade < habilidades.size()) {
        Habilidade& h = habilidades[indiceHabilidade];
        if (pontosEsforco >= h.getPontosEsforco() && (turnoAtual - h.getUltimoUso()) >= h.getCooldown()) {
            int rolagemAtaque = Dados::rolarDado(20) + ataque;
            int rolagemDefesa = Dados::rolarDado(20) + alvo.getDefesa();

            std::cout << nome << " tenta usar " << h.getNome() << " em " << alvo.getNome() << "...\n";
            std::cout << "Rolagem de ataque: " << rolagemAtaque << " (Ataque: " << ataque << " + D20)\n";
            std::cout << "Rolagem de defesa: " << rolagemDefesa << " (Defesa: " << alvo.getDefesa() << " + D20)\n";

            if (rolagemAtaque > rolagemDefesa) {
                pontosEsforco -= h.getPontosEsforco();
                int danoTotal = 0;

                for (int i = 0; i < h.getDadosDano(); i++) {
                    danoTotal += Dados::rolarDado(h.getTipoDado());
                }

                int danoFinal = danoTotal - alvo.getDefesa();
                if (danoFinal < 0) danoFinal = 0;

                alvo.setVida(alvo.getVida() - danoFinal);
                if (alvo.getVida() < 0) alvo.setVida(0);

                std::cout << nome << " usou " << h.getNome() << " em " << alvo.getNome() << " causando " << danoFinal << " de dano!\n";
            } else {
                std::cout << nome << " tentou usar " << h.getNome() << " em " << alvo.getNome() << ", mas falhou.\n";
            }

            h.setUltimoUso(turnoAtual);
        } else {
            std::cout << nome << " não pode usar " << h.getNome() << " agora.\n";
        }
    }
}

void Personagem::ataqueBasico(Personagem& alvo) {
    int rolagemAtaque = Dados::rolarDado(20) + ataque;
    int rolagemDefesa = Dados::rolarDado(20) + alvo.getDefesa();

    std::cout << nome << " tenta realizar um ataque básico em " << alvo.getNome() << "...\n";
    std::cout << "Rolagem de ataque: " << rolagemAtaque << " (Ataque: " << ataque << " + D20)\n";
    std::cout << "Rolagem de defesa: " << rolagemDefesa << " (Defesa: " << alvo.getDefesa() << " + D20)\n";

    if (rolagemAtaque > rolagemDefesa) {
        int danoFinal = ataque - alvo.getDefesa();
        if (danoFinal < 0) danoFinal = 0;

        alvo.setVida(alvo.getVida() - danoFinal);
        if (alvo.getVida() < 0) alvo.setVida(0);

        std::cout << nome << " realizou um ataque básico em " << alvo.getNome() << " causando " << danoFinal << " de dano!\n";
    } else {
        std::cout << nome << " tentou realizar um ataque básico em " << alvo.getNome() << ", mas falhou.\n";
    }
}

int Personagem::encontrarHabilidadeDisponivel(int turnoAtual) {
    for (int i = 0; i < habilidades.size(); i++) {
        Habilidade& h = habilidades[i];
        if (pontosEsforco >= h.getPontosEsforco() && (turnoAtual - h.getUltimoUso()) >= h.getCooldown()) {
            return i;
        }
    }
    return -1;
}

void Personagem::exibir() const {
    std::cout << "Nome: " << nome << "\n";
    std::cout << "Vida: " << vida << "\n";
    std::cout << "Ataque: " << ataque << "\n";
    std::cout << "Defesa: " << defesa << "\n";
    std::cout << "Pontos de Esforço: " << pontosEsforco << "\n";
    std::cout << "Habilidades:\n";
    for (const auto& habilidade : habilidades) {
        std::cout << "- " << habilidade.getNome() << "\n";
    }
    std::cout << "\n";
}
