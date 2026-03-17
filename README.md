# Prot-tipoRob-tico
Protótipo de robô de combate desenvolvido com Arduino (C/C++). O sistema integra controle de tração diferencial via Adafruit Motor Shield, comunicação sem fio Bluetooth para operação em tempo real e um sistema de arma automatizado com lógica de varredura por interrupção temporal (non-blocking) para máxima responsividade.

# Funcionalidades
- Controle preciso de movimento usando Adafruit Motor Shield.
- Sistema de varredura por interrupção temporal (non-blocking) para máxima eficiência.
- Operação em tempo real via comunicação sem fio Bluetooth.

# Componentes Utilizados
- Microcontrolador Arduino
- Adafruit Motor Shield (L293D)
- 2 Motores DC (Tração)
- 1 Micro Servo Motor (Arma)
- Módulo Bluetooth (HC-05/HC-06)

# Funcionamento do código
O código gerencia:
1. A leitura dos comandos via Serial (Bluetooth).
2. O movimento dos motores através da biblioteca AFMotor.
3. A movimentação constante da arma sem interromper os outros comandos, utilizando a função millis() em vez de delay().

