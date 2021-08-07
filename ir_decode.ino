#include <IRremote.h>

int ir_receiver = 2;

IRrecv ir_recv(ir_receiver);
decode_results results;

void setup()
{
  Serial.begin(9600);
  ir_recv.enableIRIn(); // Start the receiver
}

void loop()
{
  if (ir_recv.decode(&results)) 
  {
    Serial.println(results.value,HEX);
    ir_recv.resume(); // Receive the next value }
  }
}
