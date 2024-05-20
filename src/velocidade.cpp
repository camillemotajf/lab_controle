// #include <Encoder.h>
// #include <Arduino.h>
// // #include <typeinfo>

// // Definições de pinos para o motor e encoder
// const int ENCA = 2;  // Pino A do encoder
// const int ENCB = 3;  // Pino B do encoder
// const int IN1 = 9;   // Pino IN1 da ponte H (controle de direção)
// const int IN2 = 8;   // Pino IN2 da ponte H (controle de direção)
// const int ENA = 10;  // Pino ENA da ponte H (controle de velocidade)
// const int PWM_VALUE = 50; // Valor arbitrário de PWM (0 a 255)

// // Constantes para configuração do encoder
// const float PPR = 200.0; // Pulsos por rotação do encoder

// // Variáveis para controle de posição e velocidade
// volatile long pos_i = 0;             // Posição atual do encoder
// volatile unsigned long lastTime = 0; // Último tempo registrado para cálculo de velocidade
// volatile long lastPos_i = 0;         // Última posição do encoder para cálculo de velocidade
// double speed = 0.0;                   // Velocidade calculada do encoder em unidades de posição por segundo

// // Objeto Encoder
// Encoder encoder(ENCA, ENCB);

// // void calculateCurrentSpeed() {
// //   // Calcula o tempo decorrido desde a última atualização
// //   unsigned long currentTime = micros();
// // //   Serial.print(currentTime);
// // //   long elapsedTime = (currentTime - lastTime);  // Tempo decorrido em segundos
// // //   lastTime = currentTime;

// //   // Calcula a mudança na posição do encoder desde a última atualização
// //   long currentPosition = encoder.read();
// // //   long positionChange = (currentPosition - lastPos_i);
// // //   lastPos_i = currentPosition;

// //   // Calcula a velocidade em unidades de posição por segundo
// //   speed = (currentPosition * 60)/(200 * currentTime * 1000000);

// //   // Converte a velocidade para RPM
// // //   float rpm = (speed / PPR) * 60.0;  // RPM = (velocidade / PPR) * 60

// //   // Exibe a velocidade calculada em RPM no Serial Monitor
// // //   Serial.print(typedef(speed));
// //   Serial.print("PWM: ");
// //   Serial.print(PWM_VALUE); // Exibe o valor de PWM utilizado
// //   Serial.print(", Velocidade: ");
// //   Serial.print(speed);
// //   Serial.print(" Revolucoes/tempo ");
// //   Serial.print(currentTime);
// //   Serial.print(" vasco ");
// //   Serial.print(currentPosition);
// //   Serial.println("posicao atual");
// // }

// void calculateCurrentSpeed() {
//    // Calcula o tempo decorrido desde a última atualização em segundos (delta t)
//    unsigned long currentTime = micros();
//    double elapsedTime = (currentTime - lastTime) / 1000000.0;  // Tempo decorrido em segundos

//    // Calcula a mudança na posição do encoder desde a última atualização
//    long currentPosition = encoder.read();
//    long positionChange = currentPosition - lastPos_i;
//    lastPos_i = currentPosition;

//    // Calcula a velocidade em rotações por segundo (RPS)
//    double speedRPS = (double)positionChange / (PPR * elapsedTime);  // RPS = ΔPos / (PPR * Δt)

//    // Converte a velocidade para rotações por minuto (RPM)
//    double speedRPM = speedRPS * 60.0;  // RPM = RPS * 60

//    // Atualiza o último tempo para o próximo cálculo
//    lastTime = currentTime;

//    // Exibe a velocidade calculada no Serial Monitor
//   //  Serial.print("Velocidade (RPM): ");
//    Serial.print(speedRPM);
//    Serial.print(",");
//    Serial.println(currentTime);
//   //  Serial.print(",");
// }



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
//   calculateCurrentSpeed();

//   // Aguarda um intervalo de tempo antes de calcular a velocidade novamente
// //   delay(100);
// }

// // Função para calcular a velocidade atual do encoder em RPM
