// Blink-Programm mit millis()
// Die LED blinkt, ohne den Arduino anzuhalten

const int ledPin = 13;              // Interne LED am Pin 13
unsigned long letzteZeit = 0;       // Merkt sich den letzten Umschaltzeitpunkt
const unsigned long intervall = 500; // Blink-Intervall in Millisekunden (1 Sekunde)

bool ledStatus = false;             // Merkt sich, ob die LED an oder aus ist

void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // millis() gibt die vergangene Zeit seit dem Start des Arduino zurück
  unsigned long aktuelleZeit = millis();

  // Prüfen, ob das Intervall abgelaufen ist
  if (aktuelleZeit - letzteZeit >= intervall) {

    // Zeitpunkt merken
    letzteZeit = aktuelleZeit;

    // LED-Zustand umschalten
    ledStatus = !ledStatus;
    digitalWrite(ledPin, ledStatus);
  }

  // Hier könnte der Arduino parallel noch andere Dinge tun:
  // - Taster abfragen
  // - Sensoren lesen
  // - Serielle Daten verarbeiten
}