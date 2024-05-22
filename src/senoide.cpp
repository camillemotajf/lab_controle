#include <Arduino.h>
#include <TimerOne.h>

// --------------------------------------------------------------
#include <Encoder.h>

#define AMPLITUDE 100
#define FREQUENCIA 10// Defina a frequência desejada aqui
// #include <typeinfo>

// Definições de pinos para o motor e encoder
const int ENCA = 2;  // Pino A do encoder
const int ENCB = 3;  // Pino B do encoder
const int IN1 = 9;   // Pino IN1 da ponte H (controle de direção)
const int IN2 = 8;   // Pino IN2 da ponte H (controle de direção)
const int ENA = 5;  // Pino ENA da ponte H (controle de velocidade)

// Constantes para configuração do encoder
const float PPR = 200.0; // Pulsos por rotação do encoder

// Variáveis para controle de posição e velocidade
long lastPos_i = 0;
unsigned long lastTime = 0;

// Objeto Encoder
Encoder encoder(ENCA, ENCB);

void calculateCurrentSpeed() {
  // Calcula o tempo decorrido desde a última atualização
  unsigned long currentTime = micros();
  unsigned long timeChange = currentTime - lastTime;
  lastTime = currentTime;

  // Calcula a mudança na posição do encoder desde a última atualização
  long currentPosition = encoder.read();
  long positionChange = currentPosition - lastPos_i;
  lastPos_i = currentPosition;

  // Calcula a velocidade em unidades de posição por segundo
  float speed = (positionChange * 1000000.0) / timeChange; // pulsos por segundo

  // Converte a velocidade para RPM
  float rpm = (speed / PPR) * 60.0; // RPM = (velocidade em pulsos por segundo / PPR) * 60

  // Exibe a velocidade calculada em RPM no Serial Monitor
  Serial.println(rpm);
}

int t = 0;

void setup() {

  Serial.begin(115200); // Inicia a comunicação serial
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENCA, INPUT);
  pinMode(ENCB, INPUT);

  lastTime = micros();
  lastPos_i = encoder.read();

  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);

}

void loop() {

  // Calcula o valor da onda senoidal
  double valor = AMPLITUDE * sin(2*PI*FREQUENCIA * micros()/1000000.0) + AMPLITUDE;
  analogWrite(ENA, valor);
  // calculateCurrentSpeed();
  Serial.println(valor);

}
