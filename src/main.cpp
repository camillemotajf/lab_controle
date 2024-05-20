// #include <Arduino.h>
// // Definindo os pinos do Encoder
// #define ENCA 2 // AZUL
// #define ENCB 3 // VERDE

// #define PWM 10 //Pino ENA da ponte H deve ser conectado ao pino 10 do Arduino
// #define IN1 9 //Pino IN1 da ponte H deve ser conectado ao pino 9 do Arduino
// #define IN2 8 //Pino IN2 da ponte H deve ser conectado ao pino 8 do Arduino

// int pos = 0;

// void setMotor(int dir, int pwmVal, int pwm, int in1, int in2){
//   analogWrite(pwm, pwmVal);
//   if(dir == 1){
//     digitalWrite(in1,HIGH);
//     digitalWrite(in2,LOW);
//     analogRead(pwm);
//   }
//   else if(dir == -1){
//     digitalWrite(in1,LOW);
//     digitalWrite(in2,HIGH);
//   }
//   else{
//     digitalWrite(in1,LOW);
//     digitalWrite(in2,LOW);
//   }
// }

// void readEncoder(){
//   int b = digitalRead(ENCB);
//   if(b>0){
//     pos++;
//   }
//   else{
//     pos--;
//   }
// }

// void setup() {
//   Serial.begin(9600);
//   pinMode(ENCA, INPUT);
//   pinMode(ENCB, INPUT);
//   attachInterrupt(digitalPinToInterrupt(ENCA), readEncoder, RISING);

//   pinMode(PWM, OUTPUT); //Define o pino ENA como um pino de saída
//   pinMode(IN1, OUTPUT); //Define o pino IN1 como um pino de saída
//   pinMode(IN2, OUTPUT); //Define o pino IN2 como um pino de saída

// }

// void loop() {
//   // Serial.println(pos);
//   setMotor(1, 50, PWM, IN1, IN2);
//   Serial.println(pos);
//   delay(2000);

//   setMotor(2, 0, PWM, IN1, IN2);
//   delay(1000);

// }



