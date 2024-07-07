#include "Dados.hpp"
#include <cstdlib>

int Dados::rolarDado(int lados) {
    return rand() % lados + 1;
}
