#include <LiquidCrystal.h>

// Configuração do sensor de fluxo
const int sensorPin = 2;
volatile int pulseCount;
float flowRate;
unsigned int flowMilliLitres;
unsigned long totalMilliLitres;
unsigned long oldTime;

// Configuração do display LCD
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  // Configuração do sensor de fluxo
  pinMode(sensorPin, INPUT);
  pulseCount = 0;
  flowRate = 0.0;
  flowMilliLitres = 0;
  totalMilliLitres = 0;
  oldTime = 0;
  
  // Configuração do display LCD
  lcd.begin(16, 2);
  lcd.print("Nivel de agua:");
}

void loop() {
  // Leitura do sensor de fluxo
  unsigned long currentTime = millis();
  if (currentTime - oldTime > 1000) {
    float calibrationFactor = 4.5;
    pulseCount = pulseIn(sensorPin, HIGH);
    flowRate = ((1000.0 / (currentTime - oldTime)) * pulseCount) / calibrationFactor;
    old
