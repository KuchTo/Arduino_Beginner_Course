// Das ist das Blink-Programm für die interne LED des Arduino Uno
// Die interne LED ist mit dem Pin 13 verbunden

void setup() {
  // setup() wird genau EINMAL beim Start des Arduino ausgeführt

  // Wir legen fest, dass Pin 13 ein Ausgang ist
  pinMode(13, OUTPUT);
}

void loop() {
  // loop() wird immer wieder ausgeführt – endlos

  // LED einschalten
  digitalWrite(13, HIGH);

  // Pause von 1000 Millisekunden (1 Sekunde)
  delay(500);

  // LED ausschalten
  digitalWrite(13, LOW);

  // Wieder 1 Sekunde Pause
  delay(500);
}