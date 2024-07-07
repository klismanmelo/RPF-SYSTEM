# RPG System - Projeto de Estudo em C++

Este projeto é um sistema de RPG desenvolvido em C++ como parte de um estudo para aprender e praticar programação orientada a objetos. Ele simula uma mecânica básica de combate entre personagens, onde cada personagem possui habilidades diferentes que podem ser usadas estrategicamente durante o combate.

## Funcionalidades Implementadas

- Criação e gestão de personagens com atributos como vida, ataque, defesa e pontos de esforço.
- Adição de habilidades específicas a cada personagem.
- Implementação de um sistema de combate por turnos, onde cada personagem pode atacar ou usar habilidades.
- Uso de dados de RPG (d6, d8, d12, d20) para determinar resultados de ataques e habilidades.
- Controle de cooldown das habilidades, permitindo seu uso apenas após um número específico de turnos.

## Estrutura do Projeto

O projeto está estruturado em classes para melhor organização e reutilização de código:

- **Personagem**: Representa cada personagem do jogo, com métodos para gerenciar suas habilidades e interações durante o combate.
- **Habilidade**: Define as características de cada habilidade que um personagem pode usar.
- **Combate**: Gerencia o fluxo de turnos entre dois personagens, aplicando regras de combate e determinando o vencedor com base nos pontos de vida.
- **Dados**: Classe auxiliar para simular rolagem de dados de RPG.

## Como Usar

1. **Compilação**: Compile o código utilizando um compilador C++ compatível com o padrão C++11 ou superior.
   
   Exemplo usando g++ no terminal:
    g++ -std=c++11 *.cpp -o RPGSystem
   
2. **Execução**: Execute o programa compilado para iniciar o sistema de RPG.

  ./RPGSystem

3. **Interatividade**: Siga as instruções no console para criar personagens, adicionar habilidades e iniciar combates.

## Contribuições

Contribuições são bem-vindas! Sinta-se à vontade para sugerir melhorias, correções de bugs ou novas funcionalidades através de pull requests.

## Autor

Este projeto foi desenvolvido por [Klisman Melo](https://github.com/klismanmelo).


