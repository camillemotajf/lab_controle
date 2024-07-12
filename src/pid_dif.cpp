#include <Arduino.h>
#include <TimerOne.h>

// Definições de pinos para o motor e encoder
const int ENCA = 2;  // Pino A do encoder
const int ENCB = 3;  // Pino B do encoder

const int IN1 = 9;   // Pino IN1 da ponte H (controle de direção)
const int IN2 = 8;   // Pino IN2 da ponte H (controle de direção)
const int ENA = 5;   // Pino ENA da ponte H (controle de velocidade)

volatile unsigned long pulseCount = 0;
unsigned long lastTime;
unsigned long currentTime;
float rpm;
const int pulsesPerRevolution = 200;
volatile unsigned long count;

// Definição dos Coeficientes do Controlador PID Digital
double a1 = 3.025;  // Ganho Proporcional (Kp)
double a2 = -2.975;  // Ganho Integral (Ki)
double b1 = 1; // Coeficiente de Realimentação

double Setpoint, Input, Output;
double e[2] = {0, 0}; // Erros passados (e[0] é o erro atual)
double u[2] = {0, 0}; // Saídas passadas (u[0] é a saída atual)

void countPulse() {
  pulseCount++;
}

void pwmInterrupt() {
    count = pulseCount;
    pulseCount = 0;

    // Calcula RPM
    rpm = (count * 6000.0) / pulsesPerRevolution;
    Input = rpm;

    // Calcula o erro atual
    e[0] = Setpoint - Input;

    // Aplica a equação de diferença para o controlador PID
    u[0] = a1 * e[0] + a2 * e[1] - b1 * u[1];

    // Limita a saída entre 0 e 255
    if (u[0] > 255) {
        u[0] = 255;
    } else if (u[0] < 0) {
        u[0] = 0;
    }

    // Atualiza as saídas e erros passados para a próxima iteração
    e[1] = e[0];
    u[1] = u[0];

    Output = u[0];
    analogWrite(ENA, Output);
}

void setup() {
  Serial.begin(115200); // Inicia a comunicação serial
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENCA, INPUT);
  pinMode(ENCB, INPUT);

  attachInterrupt(digitalPinToInterrupt(ENCA), countPulse, RISING);
  lastTime = millis();

  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  Timer1.initialize(10000); // Inicializa o Timer1 com período de 10 milissegundos (10000 microssegundos)
  Timer1.attachInterrupt(pwmInterrupt); // Anexa a função de interrupção

  // Configura o Setpoint
  Setpoint = 2000; // Velocidade desejada em RPM
}

void loop() {
    Serial.println(rpm);
}
