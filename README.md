# SPRINT 1 - TECH MAHINDRA E FIAP

Este projeto foi desenvolvido como parte da **Sprint 1** da disciplina de **Edge Computing & Computer Systems**, para os alunos do primeiro semestre de **Engenharia de Software da FIAP**. O objetivo principal dessa Sprint foi desenvolver uma solução IoT que fosse capaz de captar informações sobre a Fórmula E, transmitindo-as de maneira criativa e acessível, permitindo que pessoas de todas as idades e níveis de conhecimento sobre automobilismo se envolvam e se emocionem com a competição.

<div style="display: flex; justify-content: space-between;">
  <img src="https://e-formula.news/files/e-formel/uploads/_NEWS/2023/12%20Dezember/Mahindra%20Livery/Mahindra-Livery-Formula-E-Season-2024.jpg" width="36.5%" alt="Carro Mahindra">
  <img src="https://mms.businesswire.com/media/20210709005496/pt/890318/22/New_Tech_M_Logo_High-res_square.jpg" width="49%" style="margin-left:" auto; alt="Logo Tech Mahindra">
</div>

## Descrição do Projeto

O projeto consiste em um dispositivo integrado ao cockpit dos carros da Fórmula E, projetado para monitorar e alertar sobre condições adversas dentro do mesmo, tais como **temperatura, umidade e luminosidade**. Além disso, o sistema possui a funcionalidade de abrir automaticamente um compartimento de ventilação e resfriamento para melhorar as condições internas do veículo. Por meio desse dispositivo IoT integrado ao cockpit do piloto, informações cruciais são captadas e processadas em tempo real, garantindo a segurança e o conforto do piloto durante a corrida.

<div style="display: flex; justify-content: space-between;">
  <img src="https://upload.wikimedia.org/wikipedia/commons/thumb/8/8c/Formula-e-logo-championship_2023.svg/2560px-Formula-e-logo-championship_2023.svg.png" width="49%" style="margin-left: auto;" alt="Logo da FIA Fórmula E">
</div>

## Funcionalidades Principais do Sistema

- Monitoramento da temperatura, umidade e luminosidade dentro do cockpit.
- Abertura automática do compartimento de ventilação e resfriamento em caso de temperatura elevada.
- Exibição das informações de temperatura e umidade em um display LCD.
- Indicação visual de alertas por meio de LEDs de diferentes cores.
- Controle de um servomotor para abrir e fechar o compartimento de ventilação e resfriamento.

## Nosso Objetivo

**Você sabia que um carro de Fórmula E pode chegar a temperaturas internas de até 60°C?** A segurança dos pilotos é de extrema importância em corridas de alta velocidade como a Fórmula E. Condições adversas dentro do cockpit, como altas temperaturas e umidade, podem afetar negativamente o desempenho do piloto e até mesmo colocar sua vida em risco. Portanto, a implementação de um sistema inteligente de monitoramento e controle é essencial para garantir um ambiente seguro e confortável durante a corrida.

<br>

<div style="display: flex; justify-content: space-between;">
  <img src="https://tm.ibxk.com.br/2014/08/25/25151040365302.jpg?ims=1200x675" width="49%" style="margin-left: auto;" alt="Roda de um carro da Fórmula E superaquecendo">
</div>

## Componentes

### Lista de dispositivos utilizados nesse sistema:

- Um sensor de luz (fotoresistor) para medir a luminosidade ambiente.
- Um sensor de temperatura e umidade DHT22 para medir as condições dentro do cockpit.
- Três LEDs (vermelho, amarelo e verde) para indicar diferentes níveis de alerta.
- Um servomotor para abrir e fechar automaticamente o sistema de ventilação e resfriamento do cockpit.
- Um display LCD para exibir as informações ao piloto.
- Um Arduino Uno R3 para controlar todos os componentes.

<br>

<div style="display: flex; justify-content: space-between;">
  <img src="https://cdn.awsli.com.br/600x700/980/980586/produto/181023040/kit-completo-arduino-na-maleta-cshawd.jpg" width="49%" style="margin-left: auto;" alt="Kit Arduino">
</div>

## Instalação e Uso

### Para utilizar o sistema, siga as etapas abaixo:

1. Monte os componentes seguindo a imagem fornecida pelo circuito ou através do link do [simulador](https://wokwi.com/projects/400912299707834369) no **Wokwi**.
2. Importe todas as bibliotecas necessárias **(como LiquidCrystal, DHT e Servo)**.
3. Carregue o código-fonte para o **Arduino Uno R3**.
4. Ligue o sistema e monitore as condições ambientais durante a corrida.

<div style="display: flex; justify-content: space-between;">
<img alt="C++" height="50" width="60" src="https://cdn.jsdelivr.net/gh/devicons/devicon@latest/icons/cplusplus/cplusplus-original.svg"> 
<img alt="Arduino" height="50" width="60"src="https://cdn.jsdelivr.net/gh/devicons/devicon@latest/icons/arduino/arduino-original-wordmark.svg">
</div>

## Circuito Final

![Esquemático do Circuito](circuit.png)

## Participantes

- Arthur Amaral: RM556951
- CAUE GARAUDE: RM554838
- LUIZ HENRIQUE: RM556001
- Rafael Jango: RM555297
- Rafael Bocchi: RM557603

## Referências

- [Link do Circuito](https://wokwi.com/projects/400912299707834369)

## Licença

Este projeto está licenciado sob a [MIT License](LICENSE).

## Direitos Reservados

Todos os direitos reservados à FIAP ©️

<div style="display: flex; justify-content: space-between;">
  <img src="https://www.fiap.com.br/empresas/svg/home/fiap-plus-alura/fiap.svg" width="49%" style="margin-left: auto;" alt="Logo FIAP">
</div>