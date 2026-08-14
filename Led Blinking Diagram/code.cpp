int Led1 = 33;
void setup(){
  Serial.begin(115200);
  pinMode(Led1, OUTPUT);
}


void loop(){
  digitalWrite(Led1, HIGH);
  delay(1000);
  digitalWrite(Led1, LOW);
  delay(1000);
}
