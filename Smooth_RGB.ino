
// Порты для РГБ светодиода
const int redP = 9;
const int greenP = 10;
const int blueP = 11;

const int t = 10; // Задержка между переходом цветов

void setup() {
  // Инициализация портов
  pinMode(redP, OUTPUT);
  pinMode(greenP, OUTPUT);
  pinMode(blueP, OUTPUT);
}

  void setColor(int R, int G, int B) { // Смена цветов
    analogWrite(redP, R);
    analogWrite(greenP, G);
    analogWrite(blueP, B);
}

void loop() {
  for (int i = 0; i <= 255; i++) { // От красного к зелёному
    setColor(255 - i, i, 0);
    delay(t);
  }

  for (int i = 0; i <= 255; i++) { // От зелёного к синему
    setColor(0, 255 - i, i);
    delay(t);
  }

  for (int i = 0; i <= 255; i++) { // От синего к красному
    setColor(i, 0, 255 - i);
    delay(t);
  }

}
