// Programm 5 – SWITCH CASE (Menü mit Poti!)
//  SWITCH CASE  ergibt eine saubere Auswahlsteuerung und ersetzt viele if-Ketten
// Poti wählt Modus / Taster aktiviert Modus

// Poti Bereich	Modus
// 0–300	LED aus
// 301–600	LED an
// 601–900	Blinken
// >900	PWM dimmen


// Programm ist Teil des Grundkurses Arduino Einsteiger VHS 2026


void setup() {
  pinMode(11, OUTPUT);
  pinMode(8, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {

  int poti = analogRead(A0);
  int modus;

  if (poti < 300) modus = 0;
  else if (poti < 600) modus = 1;
  else if (poti < 900) modus = 2;
  else modus = 3;

  if (digitalRead(8) == LOW) {

    switch (modus) {

      case 0:
        digitalWrite(11, HIGH);
        Serial.println("LED AUS");
        break;

      case 1:
        digitalWrite(11, LOW);
        Serial.println("LED AN");
        break;

      case 2:
        digitalWrite(11, LOW);
        delay(200);
        digitalWrite(11, HIGH);
        delay(200);
        Serial.println("Blinken");
        break;

      case 3:
        int hell = map(poti, 0, 1023, 0, 255);
        analogWrite(11, 255 - hell);
        Serial.println("Dimmen");
        break;
    }
  }
}




