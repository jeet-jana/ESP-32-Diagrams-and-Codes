int pingpin = 26;
int echopin = 25;
int allpin = 13;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println("Hello, ESP32!");
  pinMode(pingpin, OUTPUT);
  pinMode(echopin, INPUT);
  pinMode(allpin, OUTPUT);
}

void loop() {
  long inches,cm,duration;
  digitalWrite(pingpin, LOW);
  delayMicroseconds(2);
  digitalWrite(pingpin, HIGH);
  delayMicroseconds(10);
  digitalWrite(pingpin, LOW);
  duration = pulseIn(echopin,HIGH);
  inches = microsecondsToInches(duration);

  cm = microsecondsToCentimeters(duration);
  // Control buzzer
  if (cm < 100) {
      digitalWrite(allpin, HIGH);
  }
  else {
      digitalWrite(allpin, LOW);
  }
  // Print distance
  Serial.print(inches);
  Serial.print("in, ");
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();
  delay(100);
}
long microsecondsToInches(long microseconds) {
    return microseconds / 74 / 2;
}

long microsecondsToCentimeters(long microseconds) {
    return microseconds / 29 / 2;
}
