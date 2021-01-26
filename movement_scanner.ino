#include<Servo.h>
Servo servo;

void check_my_sensor(){
  int s = digitalRead(10);
  if (s == 1){
    digitalWrite(6,HIGH);
    delay(100);
    digitalWrite(6,LOW);
  }
}

void setup() {
  Serial.begin(9600);
  servo.attach(8);//servo
  servo.write(0);
  pinMode(10,INPUT);//sensor
  pinMode(6,OUTPUT);//lampe
  delay(2000);
}

void loop() { 
  for(int angle = 10; angle < 180; angle++){
    check_my_sensor();                                
    servo.write(angle);               
    delay(15);
    } 
  for(int angle = 180; angle > 10; angle--){  
    check_my_sensor();  
    servo.write(angle);           
    delay(15);       
  } 
}


