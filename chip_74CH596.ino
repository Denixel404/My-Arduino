// Работа с микросхемой 74СН595
// Перебор чисел от 0 до 256 в виде двоичного кода на примере 8 светодиодов

int latchPin = 3; // Пин для начала отсчёта
int clockPin = 2; // Пин для конца отсчёта
int dataPin = 4; // Пин для передачи данных
int t = 1000; // Задержка основного цикла

void setup() { // Инициализация портов на плате
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);

}

void loop() {
  for (int num = 0; num < 256; num++) {
    digitalWrite(latchPin, LOW); // Подготовка к записи
    shiftOut(dataPin, clockPin, LSBFIRST, num); // Передача двоичного кода с инструкцией для микросхемы
    digitalWrite(latchPin, HIGH); // Стоп-сигнал для окончания записи на микросхеме
    delay(t); // Задержка
  }

}
