// ----- Pinbelegung (LOW aktiv!) -----

const int led1 = 2;   // oben links
const int led2 = 3;   // oben rechts
const int led3 = 4;   // mitte links
const int led4 = 5;   // mitte rechts
const int led5 = 6;   // unten links
const int led6 = 7;   // unten rechts
const int ledMitte = 11;

const int tasterPin = 8;

int wurf;   // speichert die Zufallszahl 1–6

// ----- Initialisierung -----

void setup() {

  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
  pinMode(led6, OUTPUT);
  pinMode(ledMitte, OUTPUT);

  pinMode(tasterPin, INPUT_PULLUP);

  Serial.begin(9600);

  // Alle LEDs aus
  digitalWrite(led1, HIGH);
  digitalWrite(led2, HIGH);
  digitalWrite(led3, HIGH);
  digitalWrite(led4, HIGH);
  digitalWrite(led5, HIGH);
  digitalWrite(led6, HIGH);
  digitalWrite(ledMitte, HIGH);

  // Zufall initialisieren
  randomSeed(analogRead(A0));
}

// ----- Hilfsfunktion: alles ausschalten -----

void allesAus() {
  digitalWrite(led1, HIGH);
  digitalWrite(led2, HIGH);
  digitalWrite(led3, HIGH);
  digitalWrite(led4, HIGH);
  digitalWrite(led5, HIGH);
  digitalWrite(led6, HIGH);
  digitalWrite(ledMitte, HIGH);
}

// ----- Würfelanzeige mit SWITCH -----

void zeigeWuerfel(int wurf) {

  allesAus();

  switch (wurf) {

    case 1:
      digitalWrite(ledMitte, LOW);
      break;

    case 2:
      digitalWrite(led1, LOW);
      digitalWrite(led6, LOW);
      break;

    case 3:
      digitalWrite(led1, LOW);
      digitalWrite(ledMitte, LOW);
      digitalWrite(led6, LOW);
      break;

    case 4:
      digitalWrite(led1, LOW);
      digitalWrite(led2, LOW);
      digitalWrite(led5, LOW);
      digitalWrite(led6, LOW);
      break;

    case 5:
      digitalWrite(led1, LOW);
      digitalWrite(led2, LOW);
      digitalWrite(ledMitte, LOW);
      digitalWrite(led5, LOW);
      digitalWrite(led6, LOW);
      break;

    case 6:
      digitalWrite(led1, LOW);
      digitalWrite(led2, LOW);
      digitalWrite(led3, LOW);
      digitalWrite(led4, LOW);
      digitalWrite(led5, LOW);
      digitalWrite(led6, LOW);
      break;
  }
}

// ----- Hauptprogramm -----

void loop() {

  if (digitalRead(tasterPin) == LOW) {

    Serial.println("Wuerfeln...");

    // kleine Animation
    for (int i = 0; i < 15; i++) {
      digitalWrite(ledMitte, LOW);
      delay(50);
      digitalWrite(ledMitte, HIGH);
      delay(50);
    }

    // Zufallswurf 1–6
    wurf = random(1, 7);

    Serial.print("Ergebnis: ");
    Serial.println(wurf);

    // Anzeige
    zeigeWuerfel(wurf);

    // warten bis Taste losgelassen
    while (digitalRead(tasterPin) == LOW) {}
  }
}