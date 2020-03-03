int potPin=A0; //set potentiometer to analog pin
int ledPin = 6; // important: use the pin with a ~beside the number!!
int dt = 0; //usually put 250 to debug;
int valueAna;
int valueLed;
float valueVolt;


void setup() {
  Serial.begin(9600); //9600 baude rate on serial monitor
  pinMode(potPin, INPUT);
  pinMode(ledPin, OUTPUT);
  
}

void loop() {
  valueAna = analogRead(potPin);
  //Serial.print("Analog value is ");
  //Serial.println(valueAna);
  delay(dt);
  
  //equation for voltage = (5/1023) * Read Value
  valueVolt = (5./1023.)*valueAna; //valueVolt in float!!
  //Serial.print("Real world voltage is ");
  //Serial.println(valueVolt);

  //equation for analog write = (225/1023) * Read Value
  valueLed = (255./1023.)*valueAna;
  analogWrite(ledPin,valueLed);
  Serial.println(valueLed);
  
}
