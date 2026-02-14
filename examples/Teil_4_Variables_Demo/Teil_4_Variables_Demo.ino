// Ganze Zahlen
int ganzeZahl = 42;
unsigned int positiveZahl = 60000;
long grosseZahl = 123456;
unsigned long zeitstempel = 987654;

// Kommazahlen
float spannung = 3.7;


// Wahr/Falsch
bool ledAn = true;

// Zeichen
char buchstabe = 'A';

// Text
String name = "Arduino Kurs";

void setup() {

  Serial.begin(9600);

  Serial.println("=== Arduino Variablentypen ===");

  Serial.print("int: ");
  Serial.println(ganzeZahl);

  Serial.print("unsigned int: ");
  Serial.println(positiveZahl);

  Serial.print("long: ");
  Serial.println(grosseZahl);

  Serial.print("unsigned long: ");
  Serial.println(zeitstempel);

  Serial.print("float: ");
  Serial.println(spannung);

  Serial.print("bool: ");
  Serial.println(ledAn);

  Serial.print("char: ");
  Serial.println(buchstabe);

  Serial.print("String: ");
  Serial.println(name);
}

void loop() {
  // nichts – wir zeigen nur einmal alles an
}



