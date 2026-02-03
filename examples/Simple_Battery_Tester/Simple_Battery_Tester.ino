const int batteryPin = A0;

// LED Pins
const int ledGreen = 8;
const int ledYellow = 9;
const int ledRed = 10;

// ADC Referenzspannung (kalibriert!)
const float realVcc = 4.92;   // << HIER deinen gemessenen Wert eintragen

void setup() {
  Serial.begin(9600);

  pinMode(ledGreen, OUTPUT);
  pinMode(ledYellow, OUTPUT);
  pinMode(ledRed, OUTPUT);

  // DEFAULT = Vcc (5V)
  analogReference(DEFAULT);
}

void loop() {
  int raw = analogRead(batteryPin);

  // Batteriespannung berechnen
  float batteryVoltage = (raw / 1023.0) * realVcc;

  // serielle Ausgabe
  Serial.print("Batteriespannung: ");
  Serial.print(batteryVoltage, 3);
  Serial.println(" V");

  // LEDs aus
  digitalWrite(ledGreen, LOW);
  digitalWrite(ledYellow, LOW);
  digitalWrite(ledRed, LOW);

  // Ladezustand anzeigen
  if (batteryVoltage >= 1.3) {
    digitalWrite(ledGreen, HIGH);
  }
  else if (batteryVoltage >= 1.1) {
    digitalWrite(ledYellow, HIGH);
  }
  else {
    digitalWrite(ledRed, HIGH);
  }

  delay(1000);
}
