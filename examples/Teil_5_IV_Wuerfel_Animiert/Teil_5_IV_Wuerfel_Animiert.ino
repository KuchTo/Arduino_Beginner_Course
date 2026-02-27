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

// ---------------------------
// Alle LEDs ausschalten
// ---------------------------
void allesAus(){
  digitalWrite(led1,HIGH);
  digitalWrite(led2,HIGH);
  digitalWrite(led3,HIGH);
  digitalWrite(led4,HIGH);
  digitalWrite(led5,HIGH);
  digitalWrite(led6,HIGH);
  digitalWrite(ledMitte,HIGH);
}

// ---------------------------
// Würfel anzeigen
// ---------------------------
void zeigeWuerfel(int zahl){

  allesAus();

  switch(zahl){

    case 1:
      digitalWrite(ledMitte,LOW);
      break;

    case 2:
      digitalWrite(led1,LOW);
      digitalWrite(led6,LOW);
      break;

    case 3:
      digitalWrite(led1,LOW);
      digitalWrite(ledMitte,LOW);
      digitalWrite(led6,LOW);
      break;

    case 4:
      digitalWrite(led1,LOW);
      digitalWrite(led2,LOW);
      digitalWrite(led5,LOW);
      digitalWrite(led6,LOW);
      break;

    case 5:
      digitalWrite(led1,LOW);
      digitalWrite(led2,LOW);
      digitalWrite(ledMitte,LOW);
      digitalWrite(led5,LOW);
      digitalWrite(led6,LOW);
      break;

    case 6:
      digitalWrite(led1,LOW);
      digitalWrite(led2,LOW);
      digitalWrite(led3,LOW);
      digitalWrite(led4,LOW);
      digitalWrite(led5,LOW);
      digitalWrite(led6,LOW);
      break;
  }
}

// ---------------------------
// Würfel-Animation
// ---------------------------
void animation(){

  // Schnellphase
  for(int i=0;i<10;i++){
    int zufall = random(1,7);
    zeigeWuerfel(zufall);
    delay(80);
  }

  // Langsamer werdend
  for(int i=0;i<6;i++){
    int zufall = random(1,7);
    zeigeWuerfel(zufall);
    delay(150 + i*50);  // wird langsamer
  }
}

// ---------------------------
// Setup
// ---------------------------
void setup(){

  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);
  pinMode(led4,OUTPUT);
  pinMode(led5,OUTPUT);
  pinMode(led6,OUTPUT);
  pinMode(ledMitte,OUTPUT);

  pinMode(tasterPin,INPUT_PULLUP);

  randomSeed(analogRead(A0));

  allesAus();   // ⭐ Wichtig: Startzustand alles aus
}

// ---------------------------
// Hauptprogramm
// ---------------------------
void loop(){

  bool aktuellerTaster = digitalRead(tasterPin);

  if(letzterTaster==HIGH && aktuellerTaster==LOW){
    delay(200);             // Taster enprellen
    animation();            // ⭐ neue Zwischenanimation

    wurf = random(1,7);     // echtes Ergebnis
    zeigeWuerfel(wurf);
  }

  letzterTaster = aktuellerTaster;
}
