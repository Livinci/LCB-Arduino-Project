//Create a toggable button to turn on light
int readPin = 12;
int ledInput = 5;
int dt = 200;
int buttonRead;
int ledState=1;
void setup() {
 Serial.begin(9600);
 pinMode(readPin, INPUT);
 pinMode(ledInput, OUTPUT); 

}

void loop() {
 buttonRead = digitalRead(readPin);
 Serial.println(buttonRead);
 delay(dt); 
 //toggle led state
 if(buttonRead==0){
    if(ledState==0){
        ledState=1;
      }
    else if(ledState==1){
        ledState=0;
      };
  };
 while(buttonRead==0){
    buttonRead = digitalRead(readPin);
  };

 if(ledState==0){
    digitalWrite(ledInput,HIGH);
  }
 else if(ledState==1){
    digitalWrite(ledInput,LOW);
  };
}
