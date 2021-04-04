void setup(){
  Serial.begin(9600);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);
}

String readString;
int num = -1;

void loop(){
  while(Serial.available() > 0){
    char c = Serial.read();
    readString += c;
    delay(2);
  }
  
  if(readString > 0){
    Serial.println(readString);  
    num = readString.toInt();
    Serial.println(num);
  }
  else{
    num = -1;
  }
  
  
  if(num == 0){
    digitalWrite(10, LOW);
  }
  else if(num == 1){
    digitalWrite(10, HIGH);
  }
  else if(num == 10){
    digitalWrite(9, LOW);
  }
  else if(num == 11){
    digitalWrite(9, HIGH);
  }
  
  readString = "";
}
