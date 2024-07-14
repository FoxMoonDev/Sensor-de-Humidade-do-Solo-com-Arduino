## Sensor de Humidade do Solo com Arduino: Detalhes e Desenvolvimento do Projeto

**Objetivo:**

Criar um sensor de humidade do solo funcional para uso doméstico, utilizando Arduino UNO, Mini Protoboard, LEDs, resistor e sensor de humidade do solo. O sistema fornecerá indicações visuais sobre o nível de humidade do solo através de LEDs:

* **Verde:** Nível ideal de humidade.
* **Amarelo:** Nível baixo de humidade, necessitando de rega.
* **Vermelho:** Nível muito baixo de humidade, necessitando de regar urgente.

**Componentes:**

* Arduino UNO
* Mini Protoboard
* 3 LEDs (verde, amarelo e vermelho)
* 1 Resistor (220Ω)
* Sensor de Humidade do Solo
* Cabos Jumper
* Fonte de Alimentação (5V)

**Funcionamento:**

1. O sensor de humidade do solo lê a umidade do solo e envia um sinal analógico para o Arduino.
2. O Arduino converte o sinal analógico em um valor digital.
3. O Arduino compara o valor digital com valores pré-definidos para cada nível de humidade.
4. O Arduino acende o LED correspondente ao nível de humidade:
    * Verde: Nível ideal (entre 40% e 60%).
    * Amarelo: Nível baixo (entre 20% e 40%).
    * Vermelho: Nível muito baixo (abaixo de 20%).

**Desenvolvimento do Projeto:**

**Planejamento:**

1. Definir os requisitos do projeto, como os níveis de humidade para cada LED, a faixa de leitura do sensor e a resolução desejada.

**Esquema de Ligação:**

1. Criar o esquema de ligação dos componentes na protoboard.

**Codificação:**

1. Implementar o código no Arduino IDE de acordo com o funcionamento desejado.

**Teste e Depuração:**

1. Testar o funcionamento do sensor e corrigir possíveis erros no código.

**Montagem:**

1. Montar o circuito na protoboard e instalar o sensor no solo.

**Calibração:**

1. Ajustar os valores de referência para cada nível de humidade de acordo com o tipo de solo utilizado.

**Testes de Software:**

* **Testes unitários:** Testar individualmente as funções do código, como a leitura do sensor e o acendimento dos LEDs.
* **Testes de integração:** Testar a interação entre os diferentes componentes do sistema, como o sensor, o Arduino e os LEDs.
* **Testes de sistema:** Testar o funcionamento geral do sistema em diferentes cenários, como solo seco, úmido e saturado
