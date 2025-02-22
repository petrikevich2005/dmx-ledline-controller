#include <Wire.h>
#include <Adafruit_MCP4725.h>

// Инициализация ЦАП
Adafruit_MCP4725 dac;

void setup() {
  Wire.begin();
  dac.begin(0x60); // Адрес MCP4725 по умолчанию
  
  // Инициализация пинов
  pinMode(5, OUTPUT); // Пин для управления MOSFET (если нужно подключить другие компоненты)
}

void loop() {
  // Плавное изменение яркости (0-4095 для 12-битного ЦАП)
  for (int i = 0; i <= 4095; i++) {
    dac.setVoltage(i, false); // Установка напряжения на выходе ЦАП
    delay(10); // Плавное изменение
  }
  
  for (int i = 4095; i >= 0; i--) {
    dac.setVoltage(i, false);
    delay(10); // Плавное уменьшение яркости
  }
}
