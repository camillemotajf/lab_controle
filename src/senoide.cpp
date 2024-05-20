#include <Arduino.h>
#include <TimerOne.h>

// int F = 10;                                                   //frequency of the signal
// int Fs = 500;                                                //sampling frequency
// int n = 500;                                                 //number of samples
// float t;                                                     //Time instance
// int sampling_interval;
// byte samples[500];                                           // to store the samples

// int ENA = 10;
// int IN1 = 9;
// int IN2 = 8;


// void setup() {
//   Serial.begin(9600);
//   pinMode(ENA, OUTPUT);
//   pinMode(IN1, OUTPUT);
//   pinMode(IN2, OUTPUT);

//   digitalWrite(IN1, HIGH);
//   digitalWrite(IN2, LOW);


//   for (int n = 0; n < 500; n++)
//   {
//     t = (float) n / Fs;                                       //creating time isntance to find the 500 samples
//     samples[n] = (byte) (100.0 * sin(2 * 3.1415 * t) + 100.0 ); //calculating the sin value at each time instance
//   }
//   sampling_interval = 1000000 / (F * n);                      
//   //sampling interval Ts = 1/frequency x number of sample (Ts = 1/Fn or Ts = T/n)x1000000 to convert it in µS
// }

// void loop() {
//   for (int j = 0; j < 500; j++) {
//     analogWrite(ENA, samples[j]);
//     Serial.println(samples[j]);
//     delayMicroseconds(sampling_interval);                      //time interval
//   }
// }

// void myPwm(unsigned char duty, float freq) {
//   TCCR1A = 0x21;
//   TCCR1B = 0x14;
//   OCR1A = 0x7A12 / freq;
//   OCR1B = OCR1A * (duty / 255.0);
// }




// --------------------------------------------------------------
#include <Encoder.h>

#define AMPLITUDE 100
#define FREQUENCIA 10 // Defina a frequência desejada aqui
// #include <typeinfo>

// Definições de pinos para o motor e encoder
const int ENCA = 2;  // Pino A do encoder
const int ENCB = 3;  // Pino B do encoder
const int IN1 = 9;   // Pino IN1 da ponte H (controle de direção)
const int IN2 = 8;   // Pino IN2 da ponte H (controle de direção)
const int ENA = 5;  // Pino ENA da ponte H (controle de velocidade)
const int PWM_VALUE = 50; // Valor arbitrário de PWM (0 a 255)

// Constantes para configuração do encoder
const float PPR = 200.0; // Pulsos por rotação do encoder

// Variáveis para controle de posição e velocidade
volatile long pos_i = 0;             // Posição atual do encoder
volatile unsigned long lastTime = 0; // Último tempo registrado para cálculo de velocidade
volatile long lastPos_i = 0;         // Última posição do encoder para cálculo de velocidade
double speed = 0.0;                   // Velocidade calculada do encoder em unidades de posição por segundo

// Objeto Encoder
Encoder encoder(ENCA, ENCB);

// void calculateCurrentSpeed() {
//   // Calcula o tempo decorrido desde a última atualização
//   unsigned long currentTime = micros();
// //   Serial.print(currentTime);
// //   long elapsedTime = (currentTime - lastTime);  // Tempo decorrido em segundos
// //   lastTime = currentTime;

//   // Calcula a mudança na posição do encoder desde a última atualização
//   long currentPosition = encoder.read();
// //   long positionChange = (currentPosition - lastPos_i);
// //   lastPos_i = currentPosition;

//   // Calcula a velocidade em unidades de posição por segundo
//   speed = (currentPosition * 60)/(200 * currentTime * 1000000);

//   // Converte a velocidade para RPM
// //   float rpm = (speed / PPR) * 60.0;  // RPM = (velocidade / PPR) * 60

//   // Exibe a velocidade calculada em RPM no Serial Monitor
// //   Serial.print(typedef(speed));
//   Serial.print("PWM: ");
//   Serial.print(PWM_VALUE); // Exibe o valor de PWM utilizado
//   Serial.print(", Velocidade: ");
//   Serial.print(speed);
//   Serial.print(" Revolucoes/tempo ");
//   Serial.print(currentTime);
//   Serial.print(" vasco ");
//   Serial.print(currentPosition);
//   Serial.println("posicao atual");
// }

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
//    Serial.print(speedRPM);
//    Serial.print(",");
//    Serial.println(timeInSeconds);
}


int t = 0;

void setup() {
  Serial.begin(9600); // Inicia a comunicação serial
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
  // Serial.print(valor);
  // Serial.print(","); // Imprime o valor no Serial Plotter
  // delay(1000/(360*FREQUENCIA)); // Pausa por aproximadamente 0,278 milissegundos
  // double delayMs = 1000.0 / (360.0 * FREQUENCIA); // Calcula o atraso em milissegundos
  // delay(delayMs); // Pausa para manter a frequência correta
  // tempoSimulacao += delayMs / 1000.0; 
  // Serial.println(elapsedTime, 5);
//   }

  Serial.print(valor);
  Serial.print(",");
  Serial.println(elapsedTime);

}





// --------------------------------------------------------------
// #define AMPLITUDE 100
// #define FREQUENCIA 1 // Defina a frequência desejada aqui
// bool gerouOnda = false;

// void setup() {
//   Serial.begin(9600); // Inicia a comunicação serial
// }

// void loop() {
//   delay(4000);
//   if (!gerouOnda) {
//     for (int t = 0; t < 360; t++) { // Loop de 0 a 360 graus
//       float radianos = t * (PI / 180.0); // Converte graus para radianos
//       int valor = AMPLITUDE * sin(FREQUENCIA * radianos) + AMPLITUDE; // Calcula o valor da onda senoidal
//       Serial.println(valor); // Imprime o valor no Serial Plotter
//       delay(1000/(360*FREQUENCIA)); // Pausa por aproximadamente 0,278 milissegundos
//     }
//     gerouOnda = true; // Marca que a onda foi gerada
//   }
//   Serial.println(0);
// }


//------------------------------------------------------------------
// const int pwmPin = 10; // Escolha um pino PWM, por exemplo, o pino 9
// const int frequency = 1000; // Frequência da senoide em Hz
// const int sampleRate = 500; // Taxa de amostragem em Hz
// const int numSamples = sampleRate / frequency;
// int pwmValue = 0;
// float sinePWM;
// double buffer[1000];  // Buffer circular para armazenar as amostras
// volatile int bufferIndex = 0;  

// void sample() {
//     double pwm = analogRead(pwmPin);
//     buffer[bufferIndex] = pwm;  // Armazena o valor lido no buffer
//     bufferIndex = (bufferIndex + 1) % 1000;
// }

// const int pwmPin = 10; // Pino PWM para a saída
// float amplitude = 100; // Amplitude da onda senoidal
// float offset = 100; // Deslocamento para garantir que a onda esteja no intervalo de 0 a 255

// void setup() {
//   Serial.begin(9600);
//   pinMode(pwmPin, OUTPUT);
//     pinMode(9, OUTPUT);
//     pinMode(8, OUTPUT);

//     digitalWrite(9,HIGH);
//     digitalWrite(8,LOW);
// }

// void loop() {
//   // Obtém o tempo atual em microssegundos
//   unsigned long currentTime = micros();

//   // Calcula o tempo em segundos (usando a divisão correta)
//   double timeInSeconds = currentTime / 1000000.0;

//   // Calcula a frequência desejada da onda senoidal (por exemplo, 1 Hz)
//   float frequency = 10.0; // Frequência da onda senoidal em Hz

//   // Calcula o valor da onda senoidal baseado no tempo e na frequência
//   float sinValue = amplitude * sin(2 * PI * frequency * timeInSeconds) + offset;

//   // Converte o valor da onda senoidal para um valor PWM (0-255)
//   int pwmValue = (int)sinValue;

//   // Escreve o valor PWM no pino de saída
//   analogWrite(pwmPin, pwmValue);

//   // Exibe informações no Monitor Serial (opcional)
//   // Serial.print("PWM: ");
//   Serial.print(pwmValue);
//   Serial.print(",");
//   Serial.println(timeInSeconds);

//   // Aguarda um curto período de tempo antes da próxima iteração
//   // delay(1); // Ajuste este valor conforme necessário para a taxa de atualização desejada
// }