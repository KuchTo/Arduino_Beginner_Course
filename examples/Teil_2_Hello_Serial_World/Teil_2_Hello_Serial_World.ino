String benutzerName = "";
String besitzerName = "Tobias";   // <-- Hier den Namen des Besitzers eintragen

void setup() {
  Serial.begin(9600);
  delay(1000);
  Serial.println("Hallo!");
  Serial.println("Wie heisst du?");
}

void loop() {
  // Prüfen, ob Daten über die serielle Schnittstelle angekommen sind
  if (Serial.available() > 0) {
    benutzerName = Serial.readStringUntil('\n');
    benutzerName.trim();  // Entfernt Leerzeichen und Zeilenumbrüche

    Serial.print("Hallo ");
    Serial.print(benutzerName);
    Serial.print(". Ich bin der Arduino von ");
    Serial.println(besitzerName);
    Serial.print(". Willkommen in der Welt der Microcontroller. ");
    // Damit die Antwort nur einmal kommt
    while (true);
  }
}

auto.reifen.anzahl = 4;