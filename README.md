# Physics-Sim

Este repositório contém um simulador de física 2D escrito em C++ com foco em integração e colisões básicas. O projeto foi desenvolvido para oferecer uma base robusta para simulações físicas, com o objetivo de, futuramente, integrá-lo a um motor gráfico para visualização em tempo real.

## Funcionalidades

- **Vetores 2D:**  
  Implementação da classe `Vector2D` com operações aritméticas, cálculo de magnitude e normalização.

- **Corpos Rígidos:**  
  A classe `RigidBody` representa objetos físicos com massa, posição, velocidade, aceleração e forças aplicadas.  
  Suporta propriedades como:
    - Massa
    - Coeficiente de restituição (para colisões)
    - Fator de damping (amortecimento)
    - Raio (usado na detecção de colisões)

- **Simulação Física:**  
  A classe `PhysicsSim` gerencia uma coleção de `RigidBody` e aplica forças globais (como a gravidade).  
  Possui também um método para detectar e tratar colisões (entre corpos e com o chão).

- **Testes Variados:**  
  Diversos cenários de simulação foram implementados em `tests/test_main.cpp` para validar:
    - Queda livre e colisão com o chão
    - Colisão entre dois corpos
    - Simulação com múltiplos corpos
    - Movimento horizontal e inercial com damping
    - Rebote repetido no chão

## Requisitos

- **C++17** ou superior.
- **CMake** (versão 3.16 ou superior).
- Um compilador compatível (GCC, Clang ou MinGW).

## Estrutura do Projeto

```
physics-sim/
├── include/
│   ├── Vector2D.h       # Declaração da classe Vector2D
│   ├── RigidBody.h      # Declaração da classe RigidBody
│   └── PhysicsSim.h     # Declaração da classe PhysicsSim
├── src/
│   ├── Vector2D.cpp     # Implementação da classe Vector2D
│   ├── RigidBody.cpp    # Implementação da classe RigidBody
│   └── PhysicsSim.cpp   # Implementação da classe PhysicsSim
├── tests/
│   └── test_main.cpp    # Código de teste para validar a simulação
└── CMakeLists.txt       # Script para configuração do projeto com CMake
```

## Compilação

O projeto utiliza CMake para gerenciar a construção. Para compilar:

1. **Clone o repositório:**

   ```bash
   git clone https://github.com/pinhorenan/physics-sim.git
   ```
   ```
   cd physics-sim
   ```

2. **Crie a pasta de build e configure o projeto:**

   ```bash
   mkdir build && cd build
   cmake ..
   ```

3. **Compile o projeto:**

   ```bash
   cmake --build .
   ```

Após a compilação, o executável `physics_sim` (ou `physics_sim.exe` no Windows) estará disponível na pasta de build.

## Execução dos Testes

Para rodar os testes, execute o executável gerado:

```bash
./physics_sim
```

Os testes implementados no `test_main.cpp` exibem diversos cenários no console, demonstrando o comportamento da simulação em termos de posição e velocidade dos corpos.

## Possíveis Melhorias e Futuro

- **Integração com Motor Gráfico:**  
  Futuramente, planeja-se integrar a simulação com uma engine gráfica (por exemplo, SFML ou SDL) para visualização em tempo real.

- **Refinamento da Física:**  
  Possíveis melhorias incluem:
    - Implementar colisões entre corpos com mais detalhes (considerando forças de atrito, momentos angulares, etc).
    - Adicionar outras forças e restrições (molas, juntas, etc).

- **Testes Automatizados:**  
  Adicionar um framework de testes (como Catch2 ou GoogleTest) para automatizar a validação dos cenários físicos.

## Contribuição

Contribuições são bem-vindas! Se você identificar alguma melhoria ou correção, sinta-se à vontade para abrir uma _issue_ ou enviar um _pull request_.

## Licença

Este projeto está licenciado sob a [MIT License](LICENSE).
