// ----- Pinbelegung (LOW aktiv!) -----

const int led1 = 2;   // oben links
const int led2 = 3;   // oben rechts
const int led3 = 4;   // mitte links
const int led4 = 5;   // mitte rechts
const int led5 = 6;   // unten links
const int led6 = 7;   // unten rechts
const int ledMitte = 11;

// ----- Alles ausschalten -----

void allesAus() {
  digitalWrite(led1, HIGH);
  digitalWrite(led2, HIGH);
  digitalWrite(led3, HIGH);
  digitalWrite(led4, HIGH);
  digitalWrite(led5, HIGH);
  digitalWrite(led6, HIGH);
  digitalWrite(ledMitte, HIGH);
}



// ----- Setup -----

void setup() {

  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
  pinMode(led6, OUTPUT);
  pinMode(ledMitte, OUTPUT);

  Serial.begin(9600);

  allesAus();

  Serial.println("=== LED-Wuerfel Hardware-Test ===");
  Serial.println("Teil 1: Einzel-LED-Test");
}

// ----- Loop -----

void loop() {

  // ===== Teil 1: Einzel-LED-Test =====

  int leds[] = {led1, led2, led3, led4, led5, led6, ledMitte};
  const char* namen[] = {
    "Oben Links",
    "Oben Rechts",
    "Mitte Links",
    "Mitte Rechts",
    "Unten Links",
    "Unten Rechts",
    "Mitte"
  };

  for (int i = 0; i < 7; i++) {

    allesAus();

    Serial.print("Teste LED: ");
    Serial.print(namen[i]);
    Serial.print(" (Pin ");
    Serial.print(leds[i]);
    Serial.println(")");

    digitalWrite(leds[i], LOW);
    delay(3000);
  }

  

  Serial.println("Testdurchlauf abgeschlossen.");
  Serial.println("------------------------------");

  delay(5000);
}