#include <Arduino.h>
#include <TimerOne.h>

// --------------------------------------------------------------
#include <Encoder.h>

#define AMPLITUDE 100
#define FREQUENCIA 100 // Defina a frequência desejada aqui
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
   // Calcula o tempo decorrido desde a última atualização em segundos (delta t)
   unsigned long currentTime = micros();
   double elapsedTime = (currentTime - lastTime) / 1000000.0;  // Tempo decorrido em segundos

   // Calcula a mudança na posição do encoder desde a última atualização
   long currentPosition = encoder.read();
   long positionChange = currentPosition - lastPos_i;
   lastPos_i = currentPosition;

   // Calcula a velocidade em rotações por segundo (RPS)
   double speedRPS = (double)positionChange / (PPR * elapsedTime);  // RPS = ΔPos / (PPR * Δt)

   // Converte a velocidade para rotações por minuto (RPM)
   double speedRPM = speedRPS * 60.0;  // RPM = RPS * 60

   // Atualiza o último tempo para o próximo cálculo
   lastTime = currentTime;
   float timeInSeconds = currentTime / 1000000.0;

   // Exibe a velocidade calculada no Serial Monitor
  //  Serial.print("Velocidade (RPM): ");
    Serial.println(speedRPM);
//    Serial.print(",");
//    Serial.println(timeInSeconds);
}

int t = 0;

void setup() {
  Serial.begin(115200); // Inicia a comunicação serial
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENCA, INPUT);
  pinMode(ENCB, INPUT);

  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);

}

void loop() {
//   for (int t = 0; t < 360; t++) { // Loop de 0 a 360 graus
    
  unsigned long currentTime = micros();
  // float radianos = t * (PI / 180.0); // Converte graus para radianos
  int valor = AMPLITUDE * sin(2*PI*FREQUENCIA * micros()/1000000.0) + AMPLITUDE; // Calcula o valor da onda senoidal
  float elapsedTime = (currentTime)/ 1000000.0;
  analogWrite(ENA, valor);
  calculateCurrentSpeed();
  // Serial.println(valor);
  // Serial.print(",");
  // Serial.println(elapsedTime);

}