
#include <LiquidCrystal.h>  // Biblioteca para controle do display LCD
#include <DHT.h>            // Biblioteca para o sensor de temperatura e umidade DHT22
#include <Servo.h>          // Biblioteca para controle do servomotor

LiquidCrystal lcd(12, 11, 10, 5, 4, 3, 2); // Inicialização do display LCD

int ldr = A2; // Pino analógico conectado ao sensor de luz (fotoresistor)
#define DHT_PIN 13 // Pino digital conectado ao sensor DHT22
#define DHT_TYPE DHT22 // Tipo do sensor (DHT22)
DHT dht(DHT_PIN, DHT_TYPE); // Inicialização do sensor DHT22

int ledRed = 7; // Pino digital conectado ao LED vermelho
int ledYellow = 6; // Pino digital conectado ao LED amarelo
int ledGreen = 9; // Pino digital conectado ao LED verde

int servoPin = 8; // Pino digital conectado ao servomotor
Servo ejectServo; // Instância do servomotor para chamar alguns métodos

int num_readings = 5; // Número de leituras para calcular a média da luminosidade
float light_avg = 0; // Variável para armazenar a média da luminosidade
bool sistemaAtivo = false; // Variável para indicar se o sistema de refrigeração está ativado

byte raio[] = { // Definição de um símbolo personalizado de um raio para o display LCD
  B00010,
  B00110,
  B01100,
  B11111,
  B11111,
  B00110,
  B01100,
  B01000
};

void setup() {
  lcd.createChar(0, raio); // Criação do símbolo personalizado
  lcd.begin(16, 2); // Inicialização do display LCD com 16 colunas e 2 linhas
  lcd.print("Mahindra Racing"); // Exibição do texto inicial no display LCD
  lcd.setCursor(0, 1);
  lcd.print("#ChasingSuccess");
  delay(3000); // Aguarda 3 segundos
  lcd.clear(); // Limpa o display LCD
  lcd.setCursor(1, 0);
  lcd.write(byte(0)); // Exibe o símbolo personalizado no display LCD
  lcd.print(" Bem-vindo,");
  lcd.setCursor(14, 0);
  lcd.write(byte(0));
  lcd.setCursor(0, 1);
  lcd.print(" Nyck de Vries!");
  delay(5000); // Aguarda 5 segundos
  lcd.clear(); // Limpa o display LCD
  pinMode(ldr, INPUT); // Configura o pino do sensor de luz como entrada
  pinMode(ledRed, OUTPUT); // Configura o pino do LED vermelho como saída
  pinMode(ledYellow, OUTPUT); // Configura o pino do LED amarelo como saída
  pinMode(ledGreen, OUTPUT); // Configura o pino do LED verde como saída
  ejectServo.attach(servoPin); // Conecta o servo motor ao pino correspondente
  Serial.begin(9600); // Inicializa a comunicação serial
  dht.begin(); // Inicializa o sensor DHT22
  digitalWrite(ledRed, LOW); // Desliga o LED vermelho
  digitalWrite(ledYellow, LOW); // Desliga o LED amarelo
  digitalWrite(ledGreen, LOW); // Desliga o LED verde
  ejectServo.write(90); // Define a posição inicial do servo motor
}

void openVentilation() {
  light_avg = 0;
  
  for (int i = 0; i < num_readings; i++) {
    light_avg += analogRead(ldr); // Realiza leituras do sensor de luz
    delay(100);
  }
  
  light_avg /= num_readings; // Calcula a média da luminosidade
  float light_level = map(light_avg, 1023, 0, 0, 100); // Converte a média para uma escala de 0 a 100
  
  if (light_level < 40) { // Verifica se a luminosidade é baixa
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Luz BAIXA");
    lcd.setCursor(0, 1);
    lcd.print("Aguardar");
    delay(5000); // Aguarda 5 segundos
    return;
  }
  
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("  INICIANDO");
  lcd.setCursor(0, 1);
  lcd.print(" RESFRIAMENTO");
  
  digitalWrite(ledRed, HIGH); // Liga o LED vermelho
  delay(1000); // Aguarda 1 segundo
  digitalWrite(ledRed, LOW); // Desliga o LED vermelho
  
  digitalWrite(ledYellow, HIGH); // Liga o LED amarelo
  delay(1000); // Aguarda 1 segundo
  digitalWrite(ledYellow, LOW); // Desliga o LED amarelo
  
  digitalWrite(ledGreen, HIGH); // Liga o LED verde
  delay(1000); // Aguarda 1 segundo
  digitalWrite(ledGreen, LOW); // Desliga o LED verde
  
  ejectServo.write(0); // Move o servo para a posição de ventilação
  
  sistemaAtivo = true; // Ativa o sistema de refrigeração

  lcd.clear(); // Limpa o display LCD
}

void desativarVentilacao() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(" RESFRIAMENTO");
  lcd.setCursor(0, 1);
  lcd.print("   EFETUADO");
  delay(5000); // Aguarda 5 segundos
  
  ejectServo.write(90); // Retorna o servo à posição inicial
  
  sistemaAtivo = false; // Desativa o sistema de refrigeração
  lcd.clear(); // Limpa o display LCD
}

void loop() {
  light_avg = 0;
  
  for (int i = 0; i < num_readings; i++) {
    light_avg += analogRead(ldr); // Realiza leituras do sensor de luz
    delay(100);
  }
  
  light_avg /= num_readings; // Calcula a média da luminosidade
  float light_level = map(light_avg, 1023, 0, 0, 100); // Converte a média para uma escala de 0 a 100
  
  float temp = dht.readTemperature(); // Lê a temperatura ambiente
  float hum = dht.readHumidity(); // Lê a umidade ambiente
  
  if (isnan(temp) || isnan(hum)) { // Verifica se os valores de temperatura e umidade são válidos
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Erro no DHT22");
    delay(5000); // Aguarda 5 segundos
    return;
  }
  
  lcd.clear();
  lcd.setCursor(0, 0);
  if (temp >= 30 && temp <= 50) { // Verifica se a temperatura está dentro da faixa normal
    lcd.print("Temp. NORMAL");
    lcd.setCursor(0, 1);
    lcd.print("Temp. = ");
    lcd.print(temp);
    lcd.write(223); // Exibe o símbolo de graus Celsius
    lcd.print("C");
  } else if (temp > 50) { // Verifica se a temperatura está alta
    if (!sistemaAtivo) { // Verifica se o sistema de refrigeração está inativo
      openVentilation(); // Abre a ventilação se o sistema estiver inativo
    }
    lcd.print("Temp. ALTA");
    lcd.setCursor(0, 1);
    lcd.print("Temp. = ");
    lcd.print(temp);
    lcd.write(223); // Exibe o símbolo de graus Celsius
    lcd.print("C");
  } else { // Se a temperatura estiver baixa
    if (sistemaAtivo) { // Verifica se o sistema de refrigeração está ativo
      desativarVentilacao(); // Desativa o sistema de refrigeração se a temperatura voltar ao normal
    }
    lcd.print("Temp. BAIXA");
    lcd.setCursor(0, 1);
    lcd.print("Temp. = ");
    lcd.print(temp);
    lcd.write(223); // Exibe o símbolo de graus Celsius
    lcd.print("C");
  }
  
  if (sistemaAtivo) { // Se o sistema de refrigeração estiver ativo, exibir a temperatura
    lcd.clear();
    lcd.print("Temp. ALTA");
    lcd.setCursor(0, 1);
    lcd.print("Temp. = ");
    lcd.print(temp);
    lcd.write(223); // Exibe o símbolo de graus Celsius
    lcd.print("C");
  } else if (!sistemaAtivo && light_level < 40) { // Se o sistema estiver inativo e a luminosidade for baixa
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Luz BAIXA");
    lcd.setCursor(0, 1);
    lcd.print("Aguardar");
  }
  
  delay(5000); // Aguarda 5 segundos
  
  lcd.clear();
  lcd.setCursor(0, 0);
  if (hum >= 50 && hum <= 70) { // Verifica se a umidade está dentro da faixa normal
    lcd.print("Umidade. OK");
  } else if (hum > 70) { // Verifica se a umidade está alta
    lcd.print("Umidade. ALTA");
  } else { // Se a umidade estiver baixa
    lcd.print("Umidade. BAIXA");
  }
  
  if (!sistemaAtivo && light_level < 40) { // Se o sistema estiver inativo e a luminosidade for baixa
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Luz BAIXA");
    lcd.setCursor(0, 1);
    lcd.print("Aguardar");
  } else { // Se a luminosidade estiver normal
    lcd.setCursor(0, 1);
    lcd.print("Umid. = ");
    lcd.print(hum);
    lcd.print("%");
  }
  
  delay(5000); // Aguarda 5 segundos
  
  lcd.clear();
  lcd.setCursor(0, 0);
  
  if (light_level < 40) { // Verifica se a luminosidade é baixa
    lcd.print("Luz BAIXA");
  } else { // Se a luminosidade for normal
    lcd.print("Luz NORMAL");
  }
  
  lcd.setCursor(0, 1);
  lcd.print("Luz = ");
  lcd.print(light_level);
  lcd.print("%");
  
  delay(5000); // Aguarda 5 segundos
}
