void setup() {
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);

  pinMode(8, INPUT_PULLUP);
  pinMode(7, INPUT_PULLUP);
  pinMode(6, INPUT_PULLUP);
  pinMode(5, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);
  
  digitalWrite(13, LOW);
  digitalWrite(12, LOW);
  digitalWrite(11, LOW);
  digitalWrite(10, LOW);
  digitalWrite(9, LOW);

  //playWinner(12);
}

void playWinner(int pin){
  digitalWrite(13, LOW);
  digitalWrite(12, LOW);
  digitalWrite(11, LOW);
  digitalWrite(10, LOW);
  digitalWrite(9, LOW);

  digitalWrite(pin, HIGH);
  delay(7000);
}

void loop() {
   int sv1 = digitalRead(8);
   int sv2 = digitalRead(7);
   int sv3 = digitalRead(6);
   int sv4 = digitalRead(5);
   int sv5 = digitalRead(4);
   
   if (sv1 == HIGH) {
    digitalWrite(13, LOW);
  } else {
    playWinner(13);
  }
  if (sv2 == HIGH) {
    digitalWrite(12, LOW);
  } else {
    playWinner(12);
  }
    if (sv3 == HIGH) {
    digitalWrite(11, LOW);
  } else {
    playWinner(11);
  }
    if (sv4 == HIGH) {
    digitalWrite(10, LOW);
  } else {
    playWinner(10);
  }
}
