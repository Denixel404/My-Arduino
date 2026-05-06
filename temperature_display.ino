#include <DHT.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define DHTPIN 2 // Цифровой пин для датчика температуры
#define DHTTYPE DHT11 // Тип датчика температуры


DHT dht(DHTPIN, DHTTYPE); // Установка значений
LiquidCrystal_I2C lcd(0x27, 16, 2); // Уставка адреса и размера экрана дисплея
int sec = 1000; // 1 секунда
int error = 13; // Пин встроенного светодиода
bool debug = false;

void setup() {
  if (debug) {
    Serial.begin(9600);
    Serial.println("Температура, влажность");
  }
  pinMode(error, OUTPUT); // Инициализация порта для светодиода
  dht.begin(); // Запуск датчика температуры

  // Проверка светодиода
  digitalWrite(error, HIGH);
  delay(250);
  digitalWrite(error, LOW);
}

void loop() {
  delay(10*sec); // Задержка между обновлениями

  lcd.begin(); // Инициализация дисплея
  lcd.backlight(); // Включение подсветки дисплея
  lcd.clear(); // Очистка дисплея
  lcd.display(); // Включение отображения дисплея
  delay(75); // Задержка против зависаний

  int8_t tem = (int8_t)(dht.readTemperature()); // Получение данных о теммпературе
  int8_t hum = (int8_t)(dht.readHumidity()); // Получение данных о влажности

  if (isnan(tem) || isnan(hum)) { // Проверка данных
    digitalWrite(error, HIGH);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Error");
    return;
  }

  // Обновление значений на экране
  lcd.setCursor(0, 0);
  lcd.print("tem: " + String(tem - 1));
  lcd.setCursor(7, 0);
  lcd.write(223);
  lcd.setCursor(8, 0);
  lcd.print("C");
  lcd.setCursor(0, 1);
  lcd.print("hum: " + String(hum) + "%");

  //Отправка данных в монитор порта
  if (debug) Serial.println(String(tem) + ", " + String(hum));
}
