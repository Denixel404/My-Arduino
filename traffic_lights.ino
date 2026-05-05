int red_car = 2;
int yellow_car = 3;
int green_car = 4;
int red_people = 5;
int green_people = 6;

void setup() {
  // put your setup code here, to run once:
  pinMode(red_car, OUTPUT);
  pinMode(yellow_car, OUTPUT);
  pinMode(green_car, OUTPUT);
  pinMode(red_people, OUTPUT);
  pinMode(green_people, OUTPUT);

}

void loop() {
  
  // Красный для машин, зелёный для людей
  digitalWrite(red_car, HIGH);
  digitalWrite(green_people, HIGH);
  delay(5000);

  // Мигание зелёного для людей
  for (int i; i < 5; i++) {
    digitalWrite(green_people, LOW);
    delay(1000);
    digitalWrite(green_people, HIGH);
    delay(1000);
  }

  // Жёлтый для машин, красный для людей
  digitalWrite(green_people, LOW);
  digitalWrite(red_people, HIGH);
  digitalWrite(red_car, LOW);
  digitalWrite(yellow_car, HIGH);
  delay(2000);

  // Зелёный для машин, красный для людей
  digitalWrite(yellow_car, LOW);
  digitalWrite(green_car, HIGH);
  delay(8000);

  // Мигание зелёного для машин
  for (int i; i < 5; i++) {
    digitalWrite(green_car, LOW);
    delay(1000);
    digitalWrite(green_car, HIGH);
    delay(1000);
  }

  // Жёлтый для машин
  digitalWrite(green_car, LOW);
  digitalWrite(yellow_car, HIGH);
  delay(2000);
  digitalWrite(yellow_car, LOW);
  digitalWrite(red_people, LOW);

}
