// #include <Encoder.h>
// #include <Arduino.h>
// // #include <typeinfo>

// // Definições de pinos para o motor e encoder
// const int ENCA = 2;  // Pino A do encoder
// const int ENCB = 3;  // Pino B do encoder
// const int IN1 = 9;   // Pino IN1 da ponte H (controle de direção)
// const int IN2 = 8;   // Pino IN2 da ponte H (controle de direção)
// const int ENA = 5;  // Pino ENA da ponte H (controle de velocidade)
// const int PWM_VALUE = 255; // Valor arbitrário de PWM (0 a 255)

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
//     // Serial.print("Velocidade: ");
//     Serial.println(velocidadeRPM);

//     // Atualizar as variáveis para a próxima leitura
//     ultimoTempo = tempoAtual;
//     ultimoPulsos = pulsosAtuais;
// }

// // Tensão para dutycicle de 255: 18 V
// // Tensão senoide ditycicle de 255 (rms):  

// void setup() {
//   // Configura os pinos como saída ou entrada conforme necessário
//   pinMode(IN1, OUTPUT);
//   pinMode(IN2, OUTPUT);
//   pinMode(ENA, OUTPUT);
//   pinMode(ENCA, INPUT);
//   pinMode(ENCB, INPUT);

//   // Inicializa a comunicação serial
//   Serial.begin(9600);
// }

// void loop() {
//   // Define a direção do motor (sentido horário)
//   digitalWrite(IN1, HIGH);
//   digitalWrite(IN2, LOW);

//   // Define a velocidade do motor com base no valor arbitrário de PWM
//   analogWrite(ENA, PWM_VALUE);  // Define o PWM para controlar a velocidade do motor

//   // Calcula e exibe a velocidade do motor em RPM
//   calcularVelocidadeRPM();

//   // Aguarda um intervalo de tempo antes de calcular a velocidade novamente
// //   delay(100);
// }

