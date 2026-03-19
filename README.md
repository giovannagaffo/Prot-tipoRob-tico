# ProtótipoRobótico
Protótipo de robô de combate desenvolvido com Arduino (C/C++). O sistema integra controle de tração diferencial via Adafruit Motor Shield, comunicação sem fio Bluetooth para operação em tempo real e um sistema de arma automatizado com lógica de varredura por interrupção temporal (non-blocking) para máxima responsividade.

# Funcionamento do código
1. A leitura dos comandos via Serial (Bluetooth).
2. O movimento dos motores através da biblioteca AFMotor.
3. A movimentação constante da arma sem interromper os outros comandos, utilizando a função millis() em vez de delay().

# Hardware utilizado:
- Arduino Uno R3
- 1 Chassi de Carrinho 2WD que veio com:
2x Motores DC, 2x Rodas, 1x Roda boba (caster), placa do chassi, parafusos e suportes.
- 1 Ponte H (Motor Shield) L293D. O Arduino não tem força para ligar os motores diretamente. A Ponte H funciona como um "acelerador" que o Arduino controla.
- 1 Módulo Bluetooth HC-05 pra controle remoto.
- 1 Micro Servo Motor (SG90). Pra conseguir girar as agulhas e furar os balões de outros robôs. 
- 1 Suporte para 2 baterias de lítio 9800mah 3,7V e 2 baterias de lítio 9800mah 3,7V.
- 1 Suporte para bateria de 9v e 1 Bateria de 9V (para alimentar o Arduino).
- Fios Jumper (macho-macho, macho-fêmea), para ligar os componentes 
- Mini Protoboard para ligar os componentes de forma organizada.