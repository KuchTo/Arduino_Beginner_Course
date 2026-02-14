// Programm 5 – SWITCH CASE (Menü mit Poti!)
//  SWITCH CASE  ergibt eine saubere Auswahlsteuerung und ersetzt viele if-Ketten
// Poti wählt Modus / Taster aktiviert Modus

// Poti Bereich	Modus
// 0–300	LED aus
// 301–600	LED an
// 601–900	Blinken
// >900	PWM dimmen


// Programm ist Teil des Grundkurses Arduino Einsteiger VHS 2026

// LED Pins (LOW aktiv!)
const int ledRot   = 11;
const int ledGelb  = 10;
const int ledGruen = 9;

const int batteriePin = A0;

float spannung;   // Kommazahl!

void setup() {
  pinMode(ledRot, OUTPUT);
  pinMode(ledGelb, OUTPUT);
  pinMode(ledGruen, OUTPUT);

  Serial.begin(9600);

  // Alle LEDs aus
  digitalWrite(ledRot, HIGH);
  digitalWrite(ledGelb, HIGH);
  digitalWrite(ledGruen, HIGH);
}

void loop() {

  int messwert = analogRead(batteriePin);

  // Umrechnung in Volt
  spannung = messwert * 5.0 / 1023.0;

  Serial.print("Spannung: ");
  Serial.print(spannung);
  Serial.println(" V");

  // Alle LEDs erstmal aus
  digitalWrite(ledRot, HIGH);
  digitalWrite(ledGelb, HIGH);
  digitalWrite(ledGruen, HIGH);

  // Ampel-Logik
  if (spannung >= 1.3) {
    digitalWrite(ledGruen, LOW);   // gut
  }
  else if (spannung >= 1.1) {
    digitalWrite(ledGelb, LOW);    // mittel
  }
  else {
    digitalWrite(ledRot, LOW);     // leer
  }

  delay(500);
}



