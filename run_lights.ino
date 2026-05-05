
int led[6] = {2, 3, 4, 5, 6, 7};
int t = 250;

void setup() {
  for(int i = 0; i < 6; i++) {
    pinMode(led[i], OUTPUT); // Инициализация
  }

}

void loop() {
  for(int i = 0; i < 6; i++) { // Прямой проход
    digitalWrite(led[i], HIGH);
    delay(t);
    if (i != 5)
      digitalWrite(led[i], LOW);
  }

  for(int j = 6; j > 0; j--) { // Обратный проход
    digitalWrite(led[j], HIGH);
    delay(t);
    digitalWrite(led[j], LOW);
  }

}
