// #include <Arduino.h>
// #include <PID_v1.h>

// // Definições de pinos para o motor e encoder
// const int ENCA = 2;  // Pino A do encoder
// const int ENCB = 3;  // Pino B do encoder

// const int IN1 = 9;   // Pino IN1 da ponte H (controle de direção)
// const int IN2 = 8;   // Pino IN2 da ponte H (controle de direção)
// const int ENA = 5;  // Pino ENA da ponte H (controle de velocidade)

// volatile unsigned long pulseCount = 0;
// unsigned long lastTime;
// unsigned long currentTime;
// float rpm;
// const int pulsesPerRevolution = 200;

// void countPulse() {
//   int stateA = digitalRead(ENCA);
//   int stateB = digitalRead(ENCB);
  
//   if (stateA == stateB) {
//     pulseCount++;
//   } else {
//     pulseCount--;
//   }
// }

// void setup() {

//     Serial.begin(115200); // Inicia a comunicação serial
//     pinMode(IN1, OUTPUT);
//     pinMode(IN2, OUTPUT);
//     pinMode(ENA, OUTPUT);
//     pinMode(ENCA, INPUT);
//     pinMode(ENCB, INPUT);

//     attachInterrupt(digitalPinToInterrupt(ENCA), countPulse, RISING);
//     lastTime = millis();

//     digitalWrite(IN1,HIGH);
//     digitalWrite(IN2,LOW);
// }


// void loop() {
//   currentTime = millis();
//   if (currentTime - lastTime >= 1000) {  // Atualiza a cada 1 segundo
//     noInterrupts();
//     long count = pulseCount;
//     pulseCount = 0;
//     interrupts();
    
//     // Calcula RPM
//     rpm = (count * 60.0) / pulsesPerRevolution;
//     analogWrite(ENA, 200);
    
//     // Printa a velocidade na porta serial
//     Serial.print("Velocidade do motor: ");
//     Serial.print(rpm);
//     Serial.println(" RPM");
    
//     // Atualiza o tempo
//     lastTime = currentTime;
//   }
// }

