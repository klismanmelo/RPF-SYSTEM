#ifndef HABILIDADE_H
#define HABILIDADE_H

#include <string>

class Habilidade {
private:
    std::string nome;
    int pontosEsforco;
    int dadosDano;
    int tipoDado;
    int cooldown;
    int ultimoUso;

public:
    Habilidade(const std::string& nome, int pontosEsforco, int dadosDano, int tipoDado, int cooldown);

    std::string getNome() const;
    int getPontosEsforco() const;
    int getDadosDano() const;
    int getTipoDado() const;
    int getCooldown() const;
    int getUltimoUso() const;
    void setUltimoUso(int turno);
};

#endif // HABILIDADE_H
