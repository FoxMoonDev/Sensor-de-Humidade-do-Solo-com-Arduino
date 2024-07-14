#include <LiquidCrystal.h>

const int rs = 12, en = 11, d4 = 5, d3 = 4, d2 = 3, d1 = 2;
LiquidCrystal lcd(rs, en, d4, d3, d2, d1);

int sensorUmidade = A0;
int sensorTemperatura = A1;

int ledVermelho = 10;
int ledVerde = 8;
int ledAzul = 9;

float umidadeSolo;
float temperaturaSolo;
float umidadePorcentagem;
float temperaturaPorcentagem;

void setup() {
  lcd.begin(16, 2);
  pinMode(ledVermelho, OUTPUT);
  pinMode(ledVerde, OUTPUT);
  pinMode(ledAzul, OUTPUT);
}

void loop() {
  lcd.clear();
  // Leitura da umidade do solo
  umidadeSolo = analogRead(sensorUmidade);
  umidadeSolo = map(umidadeSolo, 0, 1023, 0, 100);

  // Cálculo da porcentagem de umidade
  umidadePorcentagem = umidadeSolo;

  // Leitura da temperatura do solo
  temperaturaSolo = analogRead(sensorTemperatura);
  temperaturaSolo = (temperaturaSolo * 5.0 / 1024.0 - 0.5) * 100.0; // Converte para Celsius

  // Cálculo da porcentagem de temperatura
  temperaturaPorcentagem = map(temperaturaSolo, -40.0, 125.0, 0.0, 100.0); // Ajuste a faixa de temperatura ideal

  // Atualiza o LCD com os valores de umidade e temperatura
  lcd.setCursor(0, 0);
  lcd.print("Umidade: ");
  lcd.print(umidadePorcentagem);
  lcd.print("%");

  lcd.setCursor(0, 1);
  lcd.print("Temperatura: ");
  lcd.print(temperaturaSolo); // Mostra a temperatura em Celsius
  lcd.print("C");

  // Controla a cor do LED com base nas condições
  if (temperaturaSolo > 30) {
    // Temperatura ruim CALOR VERMELHO
    digitalWrite(ledVermelho, HIGH);
    digitalWrite(ledVerde, LOW);
    digitalWrite(ledAzul, LOW);
  } else if (umidadePorcentagem < 50) {
    // Seco
    digitalWrite(ledVermelho, HIGH);
    digitalWrite(ledVerde, HIGH);
    digitalWrite(ledAzul, LOW); // Amarelo (Vermelho + Verde)
  } else if (umidadePorcentagem >= 80) {
    // Molhado
    digitalWrite(ledVermelho, LOW);
    digitalWrite(ledVerde, LOW);
    digitalWrite(ledAzul, HIGH);
  } else if (temperaturaSolo <= 30 && umidadePorcentagem >= 50 && umidadePorcentagem < 80) {
    // Temperatura e umidade ideais VERDE
    digitalWrite(ledVermelho, LOW);
    digitalWrite(ledVerde, HIGH);
    digitalWrite(ledAzul, LOW);
  }

  delay(1000); // Atualiza as informações a cada segundo
}