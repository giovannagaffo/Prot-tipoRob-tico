#include <AFMotor.h>
#include <Servo.h> 

//Configuração dos motores
AF_DCMotor motorEsquerdo(1); 
AF_DCMotor motorDireito(2);

//Configuração do servo/arma
Servo armaServo;
int posArma = 0;        

// Ajuste de velocidade
int velocidadeArma = 10;   //AUMENTADO: Antes era 5. Pula 10 graus por vez.
const long intervalo = 5;  //DIMINUÍDO: Antes era 15. Espera só 5ms.

unsigned long tempoAnterior = 0; 

char comando = 'S'; 

void setup() {
  Serial.begin(9600); 
  
  armaServo.attach(10); // Pino Servo 1 da Shield

  motorEsquerdo.setSpeed(255);
  motorDireito.setSpeed(255);
  motorEsquerdo.run(RELEASE);
  motorDireito.run(RELEASE);
}

void loop() {
  //Lógica do bluetooth
  if (Serial.available() > 0) {
    comando = Serial.read(); 
  }

  //Controle do carrinho
  switch (comando) {
    case 'F': moverFrente(); break;
    case 'B': moverTras(); break;
    case 'L': virarEsquerda(); break;
    case 'R': virarDireita(); break;
    case 'S': pararTudo(); break;
  }

  //Lógica da arma
  moverArmaAutomaticamente();
}

//Função da arma
void moverArmaAutomaticamente() {
  unsigned long tempoAtual = millis();

  if (tempoAtual - tempoAnterior >= intervalo) {
    tempoAnterior = tempoAtual; 

    posArma = posArma + velocidadeArma;
    armaServo.write(posArma);

    //Se bateu nas pontas, inverte a direção
    if (posArma <= 0 || posArma >= 180) {
      velocidadeArma = -velocidadeArma; 
    }
  }
}

//Funções de movimento

void moverFrente() {
  motorEsquerdo.run(FORWARD);
  motorDireito.run(FORWARD);
}

void moverTras() {
  motorEsquerdo.run(BACKWARD);
  motorDireito.run(BACKWARD);
}

void virarEsquerda() {
  motorEsquerdo.run(BACKWARD); 
  motorDireito.run(FORWARD);
}

void virarDireita() {
  motorEsquerdo.run(FORWARD);
  motorDireito.run(BACKWARD);
}

void pararTudo() {
  motorEsquerdo.run(RELEASE);
  motorDireito.run(RELEASE);
}