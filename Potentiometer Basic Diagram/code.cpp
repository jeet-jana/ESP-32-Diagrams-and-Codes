int pot = 35;
int led = 32;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println("Hello, ESP32!");
  pinMode(pot, INPUT);
  pinMode(led, OUTPUT);
}

void loop() {
  float analogValue = analogRead(pot);
  Serial.println(analogValue);
  float f1 = analogValue * 3.3/4095;
  if(f1 > 2){
    digitalWrite(led, HIGH);
  }
  else{
    digitalWrite(led, LOW);
  }
}
