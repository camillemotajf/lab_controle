#include <Arduino.h>
#include <PID_v1.h>
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

// Variáveis PID
double Setpoint, Input, Output;
double Kp = 2, Ki = 5, Kd = 0;

// Instancia o objeto PID
PID myPID(&Input, &Output, &Setpoint, Kp, Ki, Kd, DIRECT);

void countPulse() {
  // int stateA = digitalRead(ENCA);
  // int stateB = digitalRead(ENCB);

  pulseCount++;
  
  // if (stateA == stateB) {
  //   pulseCount++;
  // } else {
  //   pulseCount--;
  // }
}

void pwmInterrupt()
{
    // noInterrupts();
    count = pulseCount;
    pulseCount = 0;
    // interrupts();
    
    // Calcula RPM
    rpm = (count * 60.0) / pulsesPerRevolution;
    Input = rpm;
    
    // Printa a velocidade na porta serial
    // Serial.print("Velocidade do motor: ");
    
    // Serial.println(" RPM");

  // Cálculo do controle PID
  myPID.Compute();

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

  Timer1.initialize(100); // Inicializa o Timer1 com período de 100 microssegundos
  Timer1.attachInterrupt(pwmInterrupt); // Anexa a função de interrupção

  // Configura o PID
  Setpoint = 2000; // Velocidade desejada em RPM
  myPID.SetMode(AUTOMATIC);
  myPID.SetOutputLimits(0, 255); // Limites da saída do PID
}

void loop() {
  // currentTime = millis();
  // if (currentTime - lastTime >= 1000) {  // Atualiza a cada 1 segundo
  //   noInterrupts();
  //   long count = pulseCount;
  //   pulseCount = 0;
  //   interrupts();
  // Serial.println(rpm);
  Serial.println(pulseCount);
 
    
  //   // Calcula RPM
  //   rpm = (count * 60.0) / pulsesPerRevolution;
  //   Input = rpm;
    
  //   // Printa a velocidade na porta serial
  //   // Serial.print("Velocidade do motor: ");
  //   Serial.println(rpm);
  //   // Serial.println(" RPM");
    
  //   // Atualiza o tempo
  //   lastTime = currentTime;
  // }
}
