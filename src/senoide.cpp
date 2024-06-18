// #include <Arduino.h>
// #include <TimerOne.h>

// // --------------------------------------------------------------
// #include <Encoder.h>

// #define AMPLITUDE 100
// #define FREQUENCIA 0.1// Defina a frequência desejada aqui
// // #include <typeinfo>

// // Definições de pinos para o motor e encoder
// const int ENCA = 2;  // Pino A do encoder
// const int ENCB = 3;  // Pino B do encoder

// const int IN1 = 9;   // Pino IN1 da ponte H (controle de direção)
// const int IN2 = 8;   // Pino IN2 da ponte H (controle de direção)
// const int ENA = 5;  // Pino ENA da ponte H (controle de velocidade)

// // Constantes para configuração do encoder
// const float PPR = 200.0; // Pulsos por rotação do encoder

// // Objeto Encoder
// Encoder encoder(ENCA, ENCB);
// int PULSOS_POR_REVOLUCAO = 200;
// long ultimoTempo = 0;
// long ultimoPulsos = 0;

// void calcularVelocidadeRPM() {
//     // Obter o tempo atual em microssegundos
//     long tempoAtual = micros();
    
//     // Obter o número de pulsos do encoder
//     long pulsosAtuais = encoder.read();
    
//     // Calcular a diferença de tempo desde a última leitura em minutos
//     double deltaTempoMinutos = (tempoAtual - ultimoTempo) / 60000000.0;  // 60 * 1000000

//     // Calcular a diferença de pulsos desde a última leitura
//     long deltaPulsos = pulsosAtuais - ultimoPulsos;

//     // Calcular a velocidade em RPM
//     double velocidadeRPM = 0.25*((deltaPulsos / (double)PULSOS_POR_REVOLUCAO) / deltaTempoMinutos);

//     // Imprimir a velocidade

//     Serial.println(velocidadeRPM);

//     // Atualizar as variáveis para a próxima leitura
//     ultimoTempo = tempoAtual;
//     ultimoPulsos = pulsosAtuais;
// }

// // Multiplicado por 1/4 para bater com os valores do tacometro
// // Tensão RMS para 10 hz: 12,.3 V
// void setup() {

//   Serial.begin(115200); // Inicia a comunicação serial
//   pinMode(IN1, OUTPUT);
//   pinMode(IN2, OUTPUT);
//   pinMode(ENA, OUTPUT);
//   pinMode(ENCA, INPUT);
//   pinMode(ENCB, INPUT);

//   digitalWrite(IN1,HIGH);
//   digitalWrite(IN2,LOW);

// }

// void loop() {

//   // Calcula o valor da onda senoidal
//   double valor = AMPLITUDE * sin(2*PI*FREQUENCIA * micros()/1000000.0) + AMPLITUDE;
//   analogWrite(ENA, valor);
//   calcularVelocidadeRPM();
//   // Serial.println(valor);

// }
