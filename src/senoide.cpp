#include <Arduino.h>
#include <TimerOne.h>

// --------------------------------------------------------------
#include <Encoder.h>

#define AMPLITUDE 100
#define FREQUENCIA 0.1// Defina a frequência desejada aqui
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
volatile long pos_i = 0;             // Posição atual do encoder
volatile unsigned long lastTime = 0; // Último tempo registrado para cálculo de velocidade
volatile long lastPos_i = 0;         // Última posição do encoder para cálculo de velocidade
double speed = 0.0;                   // Velocidade calculada do encoder em unidades de posição por segundo

// Objeto Encoder
Encoder encoder(ENCA, ENCB);

void calculateCurrentSpeed() {

  // Calcula o tempo decorrido desde a última atualização
  unsigned long currentTime = micros();

  // Calcula a mudança na posição do encoder desde a última atualização
  long currentPosition = encoder.read();
  long positionChange = (currentPosition - lastPos_i);
  lastPos_i = currentPosition;

  // Calcula a velocidade em unidades de posição por segundo
  speed = (currentPosition * 60)/(200 * currentTime * 1000000);

  // Converte a velocidade para RPM
  float rpm = (speed / PPR) * 60.0;  // RPM = (velocidade / PPR) * 60

  // Exibe a velocidade calculada em RPM no Serial Monitor
  Serial.print("Velocidade: ");
  Serial.println(speed);

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
//   for (int t = 0; t < 360; t++) { // Loop de 0 a 360 graus
    // float radianos = t * (PI / 180.0); // Converte graus para radianos
  double valor = AMPLITUDE * sin(2*PI*FREQUENCIA * micros()/1000000.0) + AMPLITUDE; // Calcula o valor da onda senoidal
  analogWrite(ENA, valor);
  // calculateCurrentSpeed();
  Serial.println(valor);
  // Serial.print(",");
  // Serial.println(elapsedTime);

}