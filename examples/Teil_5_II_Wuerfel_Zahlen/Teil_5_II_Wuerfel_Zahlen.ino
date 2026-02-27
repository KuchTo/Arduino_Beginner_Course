// ----- Pinbelegung (LOW aktiv!) -----

const int led1 = 2;
const int led2 = 3;
const int led3 = 4;
const int led4 = 5;
const int led5 = 6;
const int led6 = 7;
const int ledMitte = 11;

const int tasterPin = 8;

int wurf = 0;
bool letzterTaster = HIGH;

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

  randomSeed(analogRead(A0));

  // alles aus
  digitalWrite(led1, HIGH);
  digitalWrite(led2, HIGH);
  digitalWrite(led3, HIGH);
  digitalWrite(led4, HIGH);
  digitalWrite(led5, HIGH);
  digitalWrite(led6, HIGH);
  digitalWrite(ledMitte, HIGH);
}

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

// ----- Anzeige-Funktion -----

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

// ----- Hauptloop -----


void loop() {

  for (int zahl = 1; zahl <= 6; zahl++) {

    Serial.print("Zeige: ");
    Serial.println(zahl);

    zeigeWuerfel(zahl);

    delay(1000);  // 1 Sekunden Pause
  }
  delay(2000);  //2 Sekunden Pause
}


