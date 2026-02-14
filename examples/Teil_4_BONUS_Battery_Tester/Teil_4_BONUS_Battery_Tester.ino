// BONUS - Bitte NICHT benutzen ohne Absprache mit dem Trainer
// Batterietester einer 1,5 Volt Batterie

//🚦 Logik der Ampel (1,5 V Batterie)
//Spannung	LED
//≥ 1,3 V	🟢 Grün (gut)
//1,1 – 1,29 V	🟡 Gelb (mittel)
//< 1,1 V	🔴 Rot (leer)

//Alle LEDs sind LOW aktiv!

//🔌 Annahme (wichtig)

//Arduino misst:
//0–5 V → Wert 0–1023
//Formel:
//Spannung = Messwert × 5.0 / 1023.0

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



