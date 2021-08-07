#include <IRremote.h>
int led = 7;
int fan = 6;
int buzzer = 5;
int ir_receiver = 2;

IRrecv ir_recv(ir_receiver); //create an object

decode_results results; //stores result from ir dector

void setup()
{
  Serial.begin(9600);
  pinMode(led,OUTPUT);
  pinMode(fan,OUTPUT);
  pinMode(buzzer,OUTPUT);


  ir_recv.enableIRIn(); // Start the receiver
}

void loop() {
  if (ir_recv.decode(&results)) {
    Serial.println(results.value, HEX);    //showing decoded data on serial terminal
                  
      switch(results.value)
      {
        case 0xE0E0E01F:
        Serial.println("turn on bulb");
        digitalWrite(led,LOW); 
        break; 
        
        case 0xE0E0D02F: 
        Serial.println("turn off bulb");
        digitalWrite(led,HIGH); 
        break; 

        case 0xE0E048B7: 
        Serial.println("turm on fan");
        digitalWrite(fan,LOW); 
        break; 

        case 0xE0E008F7: 
        Serial.println("turn off fan");
        digitalWrite(fan,HIGH); 
        break; 

        case 0xE0E0F00F: 
        Serial.println("turn on buzzer");
        digitalWrite(buzzer,LOW); 
        break; 

        case 0xE0E0D629: 
        Serial.println("turn off buzzer");
        digitalWrite(buzzer,HIGH); 
        break;       
      }  
    ir_recv.resume(); // Receive the next value
  }
}
