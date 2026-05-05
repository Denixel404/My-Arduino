#include <DHT.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define DHTPIN 2 // Цифровой пин для датчика температуры
#define DHTTYPE DHT11 // Тип датчика температуры


DHT dht(DHTPIN, DHTTYPE); // Установка значений
LiquidCrystal_I2C lcd(0x27, 16, 2); // Уставка адреса и размера экрана дисплея
int sec = 1000; // 1 секунда
int error = 13; // Пин встроенного светодиода

void setup() {
  pinMode(13, OUTPUT); // Инициализация порта для светодиода
  dht.begin(); // Запуск датчика температуры

  // Проверка светодиода
  digitalWrite(13, HIGH);
  delay(250);
  digitalWrite(13, LOW);
}

void loop() {
  delay(10*sec); // Задержка между обновлениями

  lcd.begin(); // Инициализация дисплея
  lcd.backlight(); // Включение подсветки дисплея
  lcd.clear(); // Очистка дисплея
  lcd.display(); // Включение отображения дисплея
  delay(75); // Задержка против зависаний

  float tem = dht.readTemperature(); // Получение данных о теммпературе
  float hum = dht.readHumidity(); // Получение данных о влажности

  if (isnan(tem) || isnan(hum)) { // Проверка данных
    digitalWrite(13, HIGH);
    return;
  }

  // Обновление значений на экране
  lcd.setCursor(0, 0);
  lcd.print("tem: " + String(tem));
  lcd.setCursor(10, 0);
  lcd.write(223);
  lcd.setCursor(11, 0);
  lcd.print("C");
  lcd.setCursor(0, 1);
  lcd.print("hum: " + String(hum) + "%");
}
