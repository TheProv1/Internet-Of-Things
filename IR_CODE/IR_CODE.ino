void setup() {
  // put your setup code here, to run once:
  pinMode(D0, INPUT); //IR Sensor - OUT pin - connected
  pinMode(D1, OUTPUT); // LED
  Serial.begin(9600);
}

int count = 0;

void loop() {
  // put your main code here, to run repeatedly:
  int data = digitalRead(D0);
  Serial.print(data);

  if (data == 0){
    digitalWrite(D1, HIGH);
    count++;
  }

  else{
    digitalWrite(D1, LOW);
  }

  delay(2000);
  Serial.print("Count: "); Serial.print(count); Serial.println(" times");
}
