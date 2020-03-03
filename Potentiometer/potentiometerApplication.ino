#define LIMITARR 10
int potPin=A5; //set potentiometer to analog pin
int ledPin[]={13, 12, 11, 10};//LED corresponding to 2^0 is pin 13, in a decreasing order
int dt = 0; //usually put 250 to debug;
int valueAna;
float valueVolt;
int dimBit = 4;
int digVal;
int maxDigVal=pow(2,4)-1;
int binaryArr[LIMITARR];
//position for 0-F (16) based on a-f (7)
int segLED[16][7]={
  {1,1,1,1,1,1,0},
  {0,1,1,0,0,0,0},
  {1,1,0,1,1,0,1},
  {1,1,1,1,0,0,1},
  {0,1,1,0,0,1,1},
  {1,0,1,1,0,1,1},
  {1,0,1,1,1,1,1},
  {1,1,1,0,0,0,0},
  {1,1,1,1,1,1,1},
  {1,1,1,1,0,1,1},
  {1,1,1,0,1,1,1},
  {0,0,1,1,1,1,1},
  {1,0,0,1,1,1,0},
  {0,1,1,1,1,0,1},
  {1,0,0,1,1,1,1},
  {1,0,0,0,1,1,1}
  };
int segPin[]={9,8,7,6,5,4,3};

void setup() {
  Serial.begin(9600); //9600 baude rate on serial monitor
  pinMode(potPin, INPUT);
  for(int i=0; i<dimBit;i++){
     pinMode(ledPin[i],OUTPUT);
    };
  for(int j=0; j<7; j++){
    pinMode(segPin[j],OUTPUT);
    };
  
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

  //expression for data conversion
  //max number
  //Serial.println(maxDigVal);
  digVal = maxDigVal/5 * valueVolt;
  //Serial.println(digVal);
  binaryCoder(dimBit, digVal);
  ledFlasher(dimBit);
  segLEDFlasher(digVal);
}

void binaryCoder(int inputBit, int inputNum){
    int quotient, remainder, devidend, devisor, i, j;
    // initial variables
    devidend = inputNum;
    devisor = 2; //in binary, so 2
    for(i=0; i<inputBit; i++){
      quotient = devidend / devisor;
      remainder = devidend % devisor;
      devidend = quotient;
      binaryArr[i] = remainder; 
      };
    Serial.print("Input number is: ");
    for(j=inputBit-1; j>=0; j--){
      
      Serial.print(binaryArr[j]);
      };
    Serial.println("");
  }
void ledFlasher(int inputBit){
  int i;
  for(i=0; i<inputBit; i++){
      if(binaryArr[i]==1){
        digitalWrite(ledPin[i],HIGH);
        }
      else if(binaryArr[i]==0){
        digitalWrite(ledPin[i],LOW);
        };
    };
  
  }

void segLEDFlasher(int inputNum){
  for(int i=0; i<7; i++){
    if(segLED[inputNum][i]==1){
      digitalWrite(segPin[i],HIGH);
      }
    else{
      digitalWrite(segPin[i],LOW);
      };
    
    Serial.print(segLED[inputNum][i]);
      
  
  }
  Serial.println("");
}
  
